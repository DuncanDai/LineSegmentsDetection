import glob
import json
import math
import os
import random

import numpy as np
import numpy.linalg as LA
import torch
from skimage import io
from torch.utils.data import Dataset
from torch.utils.data.dataloader import default_collate

try:
    import sys
    sys.path.append(".")
    sys.path.append("..")
    from lcnn.config import M
except Exception:
    raise



class WireframeDataset(Dataset):  # Dataset base class
    def __init__(self, rootdir, split):
        self.rootdir = rootdir
        filelist = glob.glob(f"{rootdir}/{split}/*_label.npz")
        filelist.sort()

        ### experiments on subsets
        # filelist = filelist[0:int(len(filelist) * 0.1)]

        print(f"number of {split}:", len(filelist))
        self.split = split
        self.filelist = filelist  # .npz files

    def __len__(self):
        return len(self.filelist)

    def __getitem__(self, idx):
        # the images have already been resized into (512, 512) in "dataset/wireframe.py"
        # 2022-04-28_13-09-34sep35424000_0_label.npz -> 2022-04-28_13-09-34sep35424000_0.png
        iname = self.filelist[idx][:-10].replace("_a0", "").replace("_a1", "") + ".png"
        image = io.imread(iname).astype(float)[:, :, :3]  # image data: 3D
        if "a1" in self.filelist[idx]:
            image = image[:, ::-1, :]   # order reverse in the 2nd dimension
        
        mean = [np.mean(image[:,:,i]) for i in range(3)]  # [191.53355026245117, 191.11667251586914, 185.83449172973633]
        stddev = [np.std(image[:,:,i]) for i in range(3)] # [85.1173505648392, 85.10823170806391, 87.53856729061187]
        # image = (image - M.image.mean) / M.image.stddev  # normalized in 3D
        image = (image - mean) / stddev

        image = np.rollaxis(image, 2).copy()  # 3rd axis(channel) to 0-position

        # npz["jmap"]: [J, H, W]    Junction heat map
        # npz["joff"]: [J, 2, H, W] Junction offset within each pixel
        # npz["lmap"]: [H, W]       Line heat map with anti-aliasing
        # npz["junc"]: [Na, 3]      Junction coordinates
        # npz["Lpos"]: [M, 2]       Positive lines represented with junction indices
        # npz["Lneg"]: [M, 2]       Negative lines represented with junction indices
        # npz["lpos"]: [Np, 2, 3]   Positive lines represented with junction coordinates
        # npz["lneg"]: [Nn, 2, 3]   Negative lines represented with junction coordinates
        #
        # For junc, lpos, and lneg that stores the junction coordinates, the last
        # dimension is (y, x, t), where t represents the type of that junction. 
        # DINGGEN: what I saw -> (row, col, type=0)
        with np.load(self.filelist[idx]) as npz:
            target = {
                name: torch.from_numpy(npz[name]).float()
                for name in ["jmap", "joff", "lmap"]
            }
            lpos = np.random.permutation(npz["lpos"])[:M.n_stc_posl]  # M.n_stc_posl = 300  me: maximal 2
            lneg = np.random.permutation(npz["lneg"])[:M.n_stc_negl]   # M.n_stc_negl = 40  me: maximal 4
            npos, nneg = len(lpos), len(lneg)
            lpre = np.concatenate([lpos, lneg], 0)
            for i in range(len(lpre)):
                if random.random() > 0.5:
                    lpre[i] = lpre[i, ::-1]

            ###  removed by Yancong ###
            # ldir = lpre[:, 0, :2] - lpre[:, 1, :2]
            # ldir /= np.clip(LA.norm(ldir, axis=1, keepdims=True), 1e-6, None)
            # feat = [
            #     lpre[:, :, :2].reshape(-1, 4) / 128 * M.use_cood,
            #     ldir * M.use_slop,
            #     lpre[:, :, 2],
            # ]
            # feat = np.concatenate(feat, 1)
            meta = {
                "junc": torch.from_numpy(npz["junc"][:, :2]),
                "jtyp": torch.from_numpy(npz["junc"][:, 2]).byte(),
                "Lpos": self.adjacency_matrix(len(npz["junc"]), npz["Lpos"]),
                "Lneg": self.adjacency_matrix(len(npz["junc"]), npz["Lneg"]),
                "lpre": torch.from_numpy(lpre[:, :, :2]),
                "lpre_label": torch.cat([torch.ones(npos), torch.zeros(nneg)]),
                # "lpre_feat": torch.from_numpy(feat),
            }

        return torch.from_numpy(image).float(), meta, target

    def adjacency_matrix(self, n, link): # junc is 4 -> n=5; link (2, 2)
        mat = torch.zeros(n + 1, n + 1, dtype=torch.uint8)
        link = torch.from_numpy(link)
        if len(link) > 0: # len(link)=2
            mat[link[:, 0].long(), link[:, 1].long()] = 1
            mat[link[:, 1].long(), link[:, 0].long()] = 1
        return mat


def collate(batch):
    return (
        default_collate([b[0] for b in batch]),
        [b[1] for b in batch],
        default_collate([b[2] for b in batch]),
    )


### only for test
if __name__ == "__main__":
    rootdir = 'D:/dl_mydataset'
    split = 'train'
    dataset = WireframeDataset(rootdir, split)

    a = dataset[0]
    print(a)
