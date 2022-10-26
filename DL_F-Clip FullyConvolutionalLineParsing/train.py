#!/usr/bin/env python3
"""Train L-CNN
Usage:
    train.py [options] <MODEL-yaml-config>
    train.py (-h | --help )

Example: 
    Note: change the config in base.yaml   ->  after output: confirm the config.yaml again
    python train.py -d 0 -i HG1_D2 config/fclip_HG1_D2.yaml

    python train.py -d 0 -i HG1_D3 config/fclip_HG1_D3.yaml
    python train.py -d 0 -i HG1 config/fclip_HG1.yaml
    python train.py -d 0 -i HG2 config/fclip_HG2.yaml

    python train.py -d 0 -i HG2_LB config/fclip_HG2_LB.yaml

    python train.py -d 0 -i HR config/fclip_HR.yaml

Arguments:
   <MODEL-yaml-config>                   Path to the yaml hyper-parameter file of one model

Options:
   -h --help                       Show this screen.
   -d --devices <devices>          Comma seperated GPU devices [default: 0]
   -i --identifier <identifier>    Folder identifier [default: default-lr]
"""

import os
import glob
import pprint
import random
import shutil
import os.path as osp
import datetime

import numpy as np
import torch
from docopt import docopt

import FClip
from FClip.config import C, M
from FClip.datasets import collate
from FClip.datasets import LineDataset as WireframeDataset  # Notice: the name

from FClip.models.stage_1 import FClip
from FClip.models import MultitaskHead, hg, hgl, hr
from FClip.lr_schedulers import init_lr_scheduler
from FClip.trainer import Trainer


def get_outdir(identifier):
    # load config
    name = str(datetime.datetime.now().strftime("%y%m%d-%H%M%S"))
    name += "-%s" % identifier
    outdir = osp.join(osp.expanduser(C.io.logdir), name)
    if not osp.exists(outdir):
        os.makedirs(outdir)
    C.io.resume_from = outdir
    C.to_yaml(osp.join(outdir, "config.yaml"))
    return outdir


def build_model():
    if M.backbone == "stacked_hourglass":
        model = hg(
            depth=M.depth,
            head=lambda c_in, c_out: MultitaskHead(c_in, c_out),
            num_stacks=M.num_stacks,
            num_blocks=M.num_blocks,
            num_classes=sum(sum(MultitaskHead._get_head_size(), [])),
        )
    elif M.backbone == "hourglass_lines":
        model = hgl(
            depth=M.depth,
            head=lambda c_in, c_out: MultitaskHead(c_in, c_out),
            num_stacks=M.num_stacks,
            num_blocks=M.num_blocks,
            num_classes=sum(sum(MultitaskHead._get_head_size(), [])),
        )
    elif M.backbone == "hrnet":
        model = hr(
            head=lambda c_in, c_out: MultitaskHead(c_in, c_out),
            num_classes=sum(sum(MultitaskHead._get_head_size(), [])),
        )
    else:
        raise NotImplementedError

    model = FClip(model).cuda()

    # model = model.cuda()
    # model = DataParallel(model).cuda()

    if C.io.model_initialize_file:
        checkpoint = torch.load(C.io.model_initialize_file)
        model.load_state_dict(checkpoint["model_state_dict"])
        del checkpoint
        print('=> loading model from {}'.format(C.io.model_initialize_file))

    print("Finished constructing model!")
    return model


def main():
    args = docopt(__doc__)
    C.update(C.from_yaml(filename="config/base.yaml"))
    config_file = args["<MODEL-yaml-config>"]
    C.update(C.from_yaml(filename=config_file))  
    M.update(C.model)
    pprint.pprint(C, indent=4)
    resume_from = C.io.resume_from

    # WARNING: L-CNN is still not deterministic
    random.seed(0)
    np.random.seed(0)
    torch.manual_seed(0)

    device_name = "cpu"
    os.environ["CUDA_VISIBLE_DEVICES"] = args["--devices"]
    if torch.cuda.is_available():
        device_name = "cuda"
        torch.backends.cudnn.deterministic = True
        torch.cuda.manual_seed(0)
        print("Let's use", torch.cuda.device_count(), "GPU(s)!")
    else:
        print("CUDA is not available")
    device = torch.device(device_name)

    # 1. dataset
    datadir = C.io.datadir
    kwargs = {
        # "batch_size": M.batch_size,
        "collate_fn": collate,
        "num_workers": C.io.num_workers,
        "pin_memory": True,
    }
    dataname = C.io.dataname
    train_loader = torch.utils.data.DataLoader(
        WireframeDataset(datadir, split="train", dataset=dataname), batch_size=M.batch_size, shuffle=True, drop_last=True, **kwargs
    )
    val_loader = torch.utils.data.DataLoader(
        WireframeDataset(datadir, split="valid", dataset=dataname), batch_size=M.eval_batch_size, **kwargs
    )
    epoch_size = len(train_loader)

    # 2. model
    model = build_model()

    # 3. optimizer
    if C.optim.name == "Adam":
        optim = torch.optim.Adam(
            model.parameters(),
            lr=C.optim.lr,
            weight_decay=C.optim.weight_decay,
            amsgrad=C.optim.amsgrad,
        )
    else:
        raise NotImplementedError

    outdir = get_outdir(args["--identifier"])
    print("outdir:", outdir)
    if M.backbone in ["hrnet"]:
        shutil.copy("config/w32_384x288_adam_lr1e-3.yaml", f"{outdir}/w32_384x288_adam_lr1e-3.yaml")

    iteration = 0
    epoch = 0
    best_mean_loss = 1e1000
    if resume_from:
        ckpt_pth = osp.join(resume_from, "checkpoint_lastest.pth.tar")
        checkpoint = torch.load(ckpt_pth)
        iteration = checkpoint["iteration"]
        epoch = iteration // epoch_size
        best_mean_loss = checkpoint["best_mean_loss"]
        print(f"loading {epoch}-th ckpt: {ckpt_pth}")

        model.load_state_dict(checkpoint["model_state_dict"])
        optim.load_state_dict(checkpoint["optim_state_dict"])

        lr_scheduler = init_lr_scheduler(
            optim, C.optim.lr_scheduler,
            stepsize=C.optim.lr_decay_epoch,
            max_epoch=C.optim.max_epoch,
            last_epoch=iteration // epoch_size
        )
        lr_scheduler.load_state_dict(checkpoint['lr_scheduler'])
        del checkpoint

    else:
        lr_scheduler = init_lr_scheduler(
            optim,
            C.optim.lr_scheduler,
            stepsize=C.optim.lr_decay_epoch,
            max_epoch=C.optim.max_epoch
        )

    trainer = Trainer(
        device=device,
        model=model,
        optimizer=optim,
        lr_scheduler=lr_scheduler,
        train_loader=train_loader,
        val_loader=val_loader,
        out=outdir,
        iteration=iteration,
        epoch=epoch,
        bml=best_mean_loss,
    )

    try:
        trainer.train()

    except BaseException:
        if len(glob.glob(f"{outdir}/viz/*")) <= 1:
            shutil.rmtree(outdir)
        raise


if __name__ == "__main__":
    # print(git_hash())
    main()
