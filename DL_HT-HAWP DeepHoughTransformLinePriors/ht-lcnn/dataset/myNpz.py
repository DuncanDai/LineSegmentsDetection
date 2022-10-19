#!/usr/bin/env python
"""Parser JSON label data to npz label data
Usage:
    dataset/myNpz.py <srcJSON> <srcImg> <dst>
    dataset/myNpz.py (-h | --help )

Examples:
    python dataset/myNpz.py U:/my_projs/LineSegmentsDetection/g_data \\os.lsdf.kit.edu\itiv-projects\Stents4Tomorrow\Data\2022-04-28\Data\Images D:/dl_output

Arguments:
    <srcJSON>
    <srcImg>                Original data directory of Huang's wireframe dataset
    <dst>                   Directory of the output

Options:
   -h --help             Show this screen.
"""

import os
import sys
import json
from itertools import combinations

import cv2
import numpy as np
import skimage.draw
import matplotlib.pyplot as plt
from docopt import docopt
from scipy.ndimage import zoom

try:
    sys.path.append(".")
    sys.path.append("..")
    from lcnn.utils import parmap
except Exception:
    raise


def inrange(v, shape): # make sure: point v is in the resized image range
    return 0 <= v[0] < shape[0] and 0 <= v[1] < shape[1]


def to_int(x):
    return tuple(map(int, x))


def save_heatmap(prefix, image, lines):
    im_rescale = (512, 512)
    heatmap_scale = (128, 128)
    # image.shape[0] -> row of matrix -> y of coordinate
    fy, fx = heatmap_scale[1] / image.shape[0], heatmap_scale[0] / image.shape[1]  # 128/2064, 128/3088
    jmap = np.zeros((1,) + heatmap_scale, dtype=np.float32)   # (1, 128, 128)
    joff = np.zeros((1, 2) + heatmap_scale, dtype=np.float32)  # (1, 2, 128, 128)
    lmap = np.zeros(heatmap_scale, dtype=np.float32)  # (128, 128)

    lines[:, :, 0] = np.clip(lines[:, :, 0] * fx, 0, heatmap_scale[0] - 1e-4) # 2064 -> 128 (683 -> 28.3 -> 28)
    lines[:, :, 1] = np.clip(lines[:, :, 1] * fy, 0, heatmap_scale[1] - 1e-4) # only two values (1 -> 0, 2064 -> 127)
    lines = lines[:, :, ::-1]  # from (x, y) -> to (y or row, x or col)

    junc = []
    jids = {}  # dict{ (junc_y, jun_x): index, ... }

    def jid(jun): # junction index -> e.g. (0, 28) is an junction, and the index is 0; (127, 28) is another junction, index is 1
        jun = tuple(jun[:2])  # jun[:2]: (y, x)
        if jun in jids:
            return jids[jun]
        jids[jun] = len(junc)  # add the index number with the len of "junc" list
        junc.append(np.array(jun + (0,)))  # 0 represents the type of that junction
        return len(junc) - 1  # 0-based

    lnid = []  # line index  [(junction index of v0, junction index of v1)]
    lpos, lneg = [], []
    for v0, v1 in lines: # v0(row0, col0), v1(row1, col1) -> iterate all the junctions(pairs for each line) from the label data
        lnid.append((jid(v0), jid(v1)))
        lpos.append([junc[jid(v0)], junc[jid(v1)]])  # !!!here: how lpos to be calculated

        vint0, vint1 = to_int(v0), to_int(v1)  # junction coords to be used as index: must be int
        # jamp is [1, 128, 128] -> choose jamp[0] -> element:[128, 128]
        # !!!here: how jamp, lmap to be calculated
        jmap[0][vint0] = 1
        jmap[0][vint1] = 1
        rr, cc, value = skimage.draw.line_aa(*to_int(v0), *to_int(v1))  # Generate anti-aliased line pixel coordinates
        lmap[rr, cc] = np.maximum(lmap[rr, cc], value) # ref from the doc: rr, cc is all related pixels of the line

    for v in junc:
        vint = to_int(v[:2])
        joff[0, :, vint[0], vint[1]] = v[:2] - vint - 0.5  # !!!here: how joff to be calculated

    llmap = zoom(lmap, [0.5, 0.5])
    lineset = set([frozenset(l) for l in lnid])  # junction pairs for each labeled line
    for i0, i1 in combinations(range(len(junc)), 2):  # number of combinations: #junc * #junc
        if frozenset([i0, i1]) not in lineset:
            v0, v1 = junc[i0], junc[i1]
            vint0, vint1 = to_int(v0[:2] / 2), to_int(v1[:2] / 2)  # Note - above: already zoomed in.
            rr, cc, value = skimage.draw.line_aa(*vint0, *vint1)
            # v0 v1 are junction coords, i0 i1 are junction index
            # value for one lneg: get the smallest one from all related pixels(rr, cc), and calculate the average
            lneg.append([v0, v1, i0, i1, np.average(np.minimum(value, llmap[rr, cc]))]) # !!!here: how lneg to be calculated

    assert len(lneg) != 0
    lneg.sort(key=lambda l: -l[-1])  # based on the value, in a descending order -> choose most likely negtive line

    junc = np.array(junc, dtype=np.float32)
    Lpos = np.array(lnid, dtype=np.int)
    Lneg = np.array([l[2:4] for l in lneg][:4000], dtype=np.int)  # index (i0, i1), maximal: 4000 ([2:4] is [2, 3])-> attention the tiny difference between Lneg & lneg
    lpos = np.array(lpos, dtype=np.float32)
    lneg = np.array([l[:2] for l in lneg[:2000]], dtype=np.float32) # coords (v0, v1), maximal: 2000 ([:2] is [0, 1])
 
    # !!! here: resize the image to (512, 512)
    image = cv2.resize(image, im_rescale)  

    # plt.subplot(131), plt.imshow(lmap)
    # plt.subplot(132), plt.imshow(image)
    # for i0, i1 in Lpos:
    #     plt.scatter(junc[i0][1] * 4, junc[i0][0] * 4)
    #     plt.scatter(junc[i1][1] * 4, junc[i1][0] * 4)
    #     plt.plot([junc[i0][1] * 4, junc[i1][1] * 4], [junc[i0][0] * 4, junc[i1][0] * 4])
    # plt.subplot(133), plt.imshow(lmap)
    # for i0, i1 in Lneg[:150]:
    #     plt.plot([junc[i0][1], junc[i1][1]], [junc[i0][0], junc[i1][0]])
    # plt.show()

    # For junc, lpos, and lneg that stores the junction coordinates, the last
    # dimension is (y, x, t), where t represents the type of that junction.  In
    # the wireframe dataset, t is always zero.
    np.savez_compressed(
        f"{prefix}_label.npz",
        aspect_ratio=image.shape[1] / image.shape[0],  # 3088/2064
        jmap=jmap,  # [J, H, W]    Junction heat map
        joff=joff,  # [J, 2, H, W] Junction offset within each pixel
        lmap=lmap,  # [H, W]       Line heat map with anti-aliasing
        junc=junc,  # [Na, 3]      Junction coordinate
        Lpos=Lpos,  # [M, 2]       Positive lines represented with junction indices
        Lneg=Lneg,  # [M, 2]       Negative lines represented with junction indices
        lpos=lpos,  # [Np, 2, 3]   Positive lines represented with junction coordinates
        lneg=lneg,  # [Nn, 2, 3]   Negative lines represented with junction coordinates
    )
    cv2.imwrite(f"{prefix}.png", image)

    # plt.imshow(jmap[0])
    # plt.savefig("/tmp/1jmap0.jpg")
    # plt.imshow(jmap[1])
    # plt.savefig("/tmp/2jmap1.jpg")
    # plt.imshow(lmap)
    # plt.savefig("/tmp/3lmap.jpg")
    # plt.imshow(Lmap[2])
    # plt.savefig("/tmp/4ymap.jpg")
    # plt.imshow(jwgt[0])
    # plt.savefig("/tmp/5jwgt.jpg")
    # plt.cla()
    # plt.imshow(jmap[0])
    # for i in range(8):
    #     plt.quiver(
    #         8 * jmap[0] * cdir[i] * np.cos(2 * math.pi / 16 * i),
    #         8 * jmap[0] * cdir[i] * np.sin(2 * math.pi / 16 * i),
    #         units="xy",
    #         angles="xy",
    #         scale_units="xy",
    #         scale=1,
    #         minlength=0.01,
    #         width=0.1,
    #         zorder=10,
    #         color="w",
    #     )
    # plt.savefig("/tmp/6cdir.jpg")
    # plt.cla()
    # plt.imshow(lmap)
    # plt.quiver(
    #     2 * lmap * np.cos(ldir),
    #     2 * lmap * np.sin(ldir),
    #     units="xy",
    #     angles="xy",
    #     scale_units="xy",
    #     scale=1,
    #     minlength=0.01,
    #     width=0.1,
    #     zorder=10,
    #     color="w",
    # )
    # plt.savefig("/tmp/7ldir.jpg")
    # plt.cla()
    # plt.imshow(jmap[1])
    # plt.quiver(
    #     8 * jmap[1] * np.cos(tdir),
    #     8 * jmap[1] * np.sin(tdir),
    #     units="xy",
    #     angles="xy",
    #     scale_units="xy",
    #     scale=1,
    #     minlength=0.01,
    #     width=0.1,
    #     zorder=10,
    #     color="w",
    # )
    # plt.savefig("/tmp/8tdir.jpg")

def _map_to_folder_and_img(filename):
    (folder, img) = filename.split("sep")
    return folder, img

# def handle(dataset):   # me dinggen! AttributeError: Can't pickle local object 'main.<locals>.handle'  -> https://blog.csdn.net/qq_43331089/article/details/126227288
def handle(dataset, imgs_root, all_data_output, batch): 
    os.makedirs(os.path.join(all_data_output, batch), exist_ok=True)
    i = 0
    for data in dataset:
        filename = data["filename"]
        folder, imgName = _map_to_folder_and_img(filename)

        # "im" is the original image
        im = cv2.imread(os.path.join(imgs_root, folder, imgName))
        if im is None:
            with open("non_existed_in_imgs.txt", "a") as f:
                i = i + 1
                f.write(f"{i:04d}, {folder}, {imgName} \n")
            continue

        prefix = imgName.split(".")[0]
        lines = np.array(data["lines"]).reshape(-1, 2, 2)

        # from line0 to line3 -> symmetric augmentation: left-right up-down
        lines0 = lines.copy()

        lines1 = lines.copy()
        lines1[:, :, 0] = im.shape[1] - lines1[:, :, 0]

        lines2 = lines.copy()
        lines2[:, :, 1] = im.shape[0] - lines2[:, :, 1]

        lines3 = lines.copy()
        lines3[:, :, 0] = im.shape[1] - lines3[:, :, 0]
        lines3[:, :, 1] = im.shape[0] - lines3[:, :, 1]

        path = os.path.join(all_data_output, batch, folder+'sep'+prefix)
        save_heatmap(f"{path}_0", im[::, ::], lines0)
        if batch != "valid":
            save_heatmap(f"{path}_1", im[::, ::-1], lines1)
            save_heatmap(f"{path}_2", im[::-1, ::], lines2)
            save_heatmap(f"{path}_3", im[::-1, ::-1], lines3)
        print("Finishing", os.path.join(all_data_output, batch, folder+'sep'+prefix))


def main():
    args = docopt(__doc__)
    imgs_root = args["<srcImg>"]
    label_root = args["<srcJSON>"]
    all_data_output = args["<dst>"]

    os.makedirs(all_data_output, exist_ok=True)
    for batch in ["train", "valid"]:
        anno_file = os.path.join(label_root, f"{batch}.json")

        with open(anno_file, "r") as f:
            dataset = json.load(f)
        
        handle(dataset, imgs_root, all_data_output, batch)
    # parmap(handle, dataset, 2)   # me dinggen! - itiv 215 -> output of multiprocessing.cpu_count() is 6, less than 16  -> when it's 0, will be counted in utils.py in lcnn folder


if __name__ == "__main__":
    main()
