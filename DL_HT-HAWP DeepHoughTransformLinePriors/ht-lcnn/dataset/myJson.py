#!/usr/bin/env python
"""From my original JSON file to the format to be used in wireframe.py/myNpz.py
Usage:
    dataset/myJson.py <labelDir> <dst>
    dataset/myJson.py (-h | --help )

Examples:
    python dataset/myJson.py  \\os.lsdf.kit.edu\itiv-projects\Stents4Tomorrow\Data\2022-04-28\Data\Labels\mandrel_borders  U:/my_projs/LineSegmentsDetection/g_data

Arguments:
    <labelDir>           Directory of label JSON file
    <dst>                Directory of the output

Options:
   -h --help             Show this screen.
"""
import os
import json

from docopt import docopt

data_json = 'mandrel_border_manually_train_val_test_split.json'
label_json = 'mandrel_border_labels_manually.json'


def main():
    args = docopt(__doc__)
    # img_root = args["<imgDir>"]
    label_root = args["<labelDir>"]
    json_output = args["<dst>"]

    os.makedirs(json_output, exist_ok=True)
    for batch in ["train", "val", "test"]:
        data_split_file = os.path.join(label_root, f"{data_json}")
        label_file = os.path.join(label_root, f"{label_json}")

        with open(data_split_file, "r") as f:
            split_dict = json.load(f)
        with open(label_file, "r") as f:
            label_dict = json.load(f)

        img_dict = split_dict[batch]
        data = []
        i = 0
        j = 0
        for folder, img_list in img_dict.items():
            for img in img_list:  
                # case 1: image of split JSON is not labeled
                try:
                    img_label = label_dict[folder][img]
                except:
                    # add counter
                    i = i + 1
                    continue

                # case 2: labeled, but "image": null
                # case 3: labeled, but ["image"]["coords"]:  [null, null]
                if (img_label is None) or any([img_label["coords"][0] is None, img_label["coords"][1] is None]):
                    # add counter
                    j = j + 1
                    continue

                # case 4: labeled correctly
                filename = folder + 'sep' + img + '.png'
                # acquire the label data: notice to validation -> the situations are annouced in the email
                width = img_label["width"]
                height = img_label["height"]
                x_left = img_label["coords"][0]
                x_right = img_label["coords"][1]

                x_left_1 = x_left_2 = x_left
                y_left_1, y_left_2 = 0, height - 1

                x_right_1 = x_right_2 = x_right
                y_right_1, y_right_2 = 0, height - 1

                single_data = {
                    "filename": filename,
                    "lines": [[x_left_1, y_left_1, x_left_2, y_left_2], [x_right_1, y_right_1, x_right_2, y_right_2]],
                    "height": height,
                    "width": width,
                }
                data.append(single_data)

        print(f"unlabled image number is {i}, null value number is {j}")
        print(f"Total {batch} number is {len(data)}")
        JSON_FILE = os.path.join(json_output, f"{batch}.json") 
        with open(JSON_FILE, 'w') as f:
            json.dump(data, f)
        

if __name__ == "__main__":
    main()
