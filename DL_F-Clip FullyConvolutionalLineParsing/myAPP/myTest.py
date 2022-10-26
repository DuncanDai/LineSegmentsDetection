#!/usr/bin/env python3
"""Train L-CNN
Usage:
    test.py [options] <MODEL-yaml-config> <ckpt> <test-json>
    test.py (-h | --help )

Examples: (path based on 'ht-lcnn/')
    python ./myAPP/myTest.py -d 0 -i HG2_LB_test config/fclip_HG1_D2.yaml E:/dl_save/221025-105752-HG1_D2/checkpoint_best.pth.tar  U:/my_projs/LineSegmentsDetection/g_data/original_vertical/test.json

Arguments:
   <MODEL-yaml-config>             Path to the yaml hyper-parameter file
   <ckpt>                          Path to ckpt
   <test-json>                     test JSON file to get image

Options:
   -h --help                       Show this screen.
   -d --devices <devices>          Comma seperated GPU devices [default: 0]
   -i --identifier <identifier>    Folder identifier [default: default-lr]
"""

import os
import os.path as osp
import sys
import time
import datetime
import pprint
import random
import json


import skimage.io
import skimage.transform

import matplotlib as mpl
mpl.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import torch
# import yaml
from docopt import docopt


try:
    sys.path.append(".")
    sys.path.append("..")
    import FClip
    from FClip.config import C, M
    from FClip.datasets import collate
    from FClip.datasets import LineDataset as WireframeDataset

    from FClip.models import MultitaskHead, hg, hgl, hr
    from FClip.models.stage_1 import FClip
except Exception:
    raise



_PLOT_nlines = 2 # original 100
_PLOT = False
_NPZ = True
PLTOPTS = {"color": "#33FFFF", "s": 1.2, "edgecolors": "none", "zorder": 5}
cmap = plt.get_cmap("jet")
norm = mpl.colors.Normalize(vmin=0.9, vmax=1.0)
sm = plt.cm.ScalarMappable(cmap=cmap, norm=norm)
sm.set_array([])


def imshow(im):
    sizes = im.shape
    height = float(sizes[0])
    width = float(sizes[1])

    fig = plt.figure()
    fig.set_size_inches(width / height, 1, forward=False)
    ax = plt.Axes(fig, [0.0, 0.0, 1.0, 1.0])
    ax.set_axis_off()
    fig.add_axes(ax)
    plt.xlim([-0.5, sizes[1] - 0.5])
    plt.ylim([sizes[0] - 0.5, -0.5])
    plt.imshow(im)


def c(x):
    return sm.to_rgba(x)


def build_model(cpu=False):
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

    model = FClip(model)

    if M.backbone == "hrnet":
        model = model.cuda()
        model = torch.nn.DataParallel(model)

    if C.io.model_initialize_file:
        if cpu:
            checkpoint = torch.load(C.io.model_initialize_file, map_location=torch.device('cpu'))
        else:
            checkpoint = torch.load(C.io.model_initialize_file)
        model.load_state_dict(checkpoint["model_state_dict"])
        del checkpoint
        print('=> loading model from {}'.format(C.io.model_initialize_file))

    print("Finished constructing model!")
    return model


def _map_to_folder_and_img(filename):
    (folder, img) = filename.split("sep")
    return folder, img

def _from_lines_to_coords(lines): # outputs coords are float
    juncs = [tuple(junction) for junction in lines.reshape(4, 2)]
    juncs.sort(key=lambda ele: ele[1])

    left_y0, left_x0 = juncs[0]
    left_y1, left_x1 = juncs[1]
    right_y0, right_x0 = juncs[2]
    right_y1, right_x1 = juncs[3]

    return left_y0, left_x0, left_y1, left_x1, right_y0, right_x0, right_y1, right_x1

def _calc_RMSE(predictions, targets):
    return np.sqrt(((predictions - targets) ** 2).sum())

def main():
    args = docopt(__doc__)
    C.update(C.from_yaml(filename='config/base.yaml'))
    config_file = args["<MODEL-yaml-config>"]
    C.update(C.from_yaml(filename=config_file))
    M.update(C.model)
    C.io.model_initialize_file = args["<ckpt>"]

    imgs_root = C.io.imgs_root
    outdir = os.path.join(C.io.logdir, args["--identifier"])

    # C.io.dataname = args["<dataname>"]
    # C.io.datadir = args["<datadir>"]

    # pprint.pprint(C, indent=4)
    # bs = 1
    # print("batch size: ", bs)
    # print("data name: ", args["<dataname>"])
    # print("data dir: ", args["<datadir>"])

    # WARNING: L-CNN is still not deterministic
    random.seed(0)
    np.random.seed(0)
    torch.manual_seed(0)

    os.environ["CUDA_VISIBLE_DEVICES"] = args["--devices"]
    if torch.cuda.is_available():
        torch.backends.cudnn.deterministic = True
        torch.cuda.manual_seed(0)
        print("Let's use", torch.cuda.device_count(), "GPU(s)!")
    else:
        print("CUDA is not available")

    # 0. dataset
    # datadir = C.io.datadir
    # kwargs = {
    #     "collate_fn": collate,
    #     "num_workers": C.io.num_workers,
    #     "pin_memory": True,
    # }

    # dataname = C.io.dataname
    # val_loader = torch.utils.data.DataLoader(
    #     WireframeDataset(datadir, split="valid", dataset=dataname), batch_size=bs, **kwargs
    # )
    # data_size = len(val_loader) * bs

    # 1. model
    model = build_model()
    model.cuda()

    print("outdir:", outdir)

    os.makedirs(f"{outdir}/npz/best", exist_ok=True)
    os.makedirs(f"{outdir}/viz", exist_ok=True)

    # eval_time_ = 0
    # eval_time = {
    #     'time_front': 0.0,
    #     'time_stack0': 0.0,
    #     'time_stack1': 0.0,
    #     'time_backbone': 0.0,
    # }

    model.eval()

    # 2. my dataset: using JSON file
    test_json = args["<test-json>"]  # one elment list with dicts
    with open(test_json, "r") as f:
        test_imgs = json.load(f) 
    num_test_imgs = len(test_imgs)

    data = []
    count = 0
    for img in test_imgs:  # img is a dict {"filename": "2022-04-28_13-09-34sep66101184000.png", "lines": [[718, 1, 718, 2064], [2177, 1, 2177, 2064]], "height": 2064, "width": 3088}
        count = count + 1
        left_label = img["lines"][0][0]
        right_label = img["lines"][1][0]
        
        filename = img["filename"]
        folder, img_png = _map_to_folder_and_img(filename)

        print(f"Processing {folder}, {img_png}. Now is {count}/{num_test_imgs}")
        # in nerwork driver of project
        img_path = os.path.join(imgs_root, folder, img_png)
        try:
            im = skimage.io.imread(img_path)
        except (ValueError, IOError):
            with open("Image_read_failed.txt", "a") as f:
                f.write(f"{count:04d}, {folder}, {img_png} \n")
            continue
        
        if im.ndim == 2:
            im = np.repeat(im[:, :, None], 3, 2)
        im = im[:, :, :3]
        im_resized = skimage.transform.resize(im, (512, 512)) * 255

        image = (im_resized - M.image.mean) / M.image.stddev
        image = torch.from_numpy(np.rollaxis(image, 2)[None].copy()).float()

        with torch.no_grad():
            input_dict = {
                "image": image.cuda(),  # need to add to cuda()
            }
            eval_t = time.time()
            result = model(input_dict, isTest=True)  # (in stage_1.py) test_forward(input_dict) return is a dict
            run_time = time.time() - eval_t

            H = result["heatmaps"]
            lines = H["lines"][0].cpu().numpy() / 128 * im.shape[:2]  # resize back to the original im size
            scores = H["score"][0].cpu().numpy()

            ### !!! restrict length=2
            # for i in range(1, len(lines)):  
            #     if (lines[i] == lines[0]).all():  # if find the same line at the first time: which implies duplicated lines
            #         lines = lines[:i]
            #         scores = scores[:i]
            #         break



            ### from line to coords in 2D
            left_y0, left_x0, left_y1, left_x1, right_y0, right_x0, right_y1, right_x1 = _from_lines_to_coords(lines[:_PLOT_nlines])
            preds = np.array([left_x0, right_x1])
            targets = np.array([left_label, right_label])
            rmse = _calc_RMSE(preds, targets)

            record = {
                "folder": folder,
                "img": img_png,
                "left_label": left_label,
                "left_junc0": (left_x0, left_y0),
                "left_junc1": (left_x1, left_y1),
                "right_label": right_label,
                "right_junc0": (right_x0, right_y0),
                "right_junc1": (right_x1, right_y1),
                "RMSE": rmse,
                "time": run_time  # unit: second
            }
            data.append(record)
            print(f"RMSE: {rmse} pixels, {run_time} s, succeeded! \n")

    df = pd.DataFrame.from_records(data)
    df.to_csv(os.path.join(outdir, f"test_{datetime.datetime.now().month}-{datetime.datetime.now().day}.csv"))









def tprint(*args):
    """Temporarily prints things on the screen"""
    print("\r", end="")
    print(*args, end="")


if __name__ == "__main__":

    main()
