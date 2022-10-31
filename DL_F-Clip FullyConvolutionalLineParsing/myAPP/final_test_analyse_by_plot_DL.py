import os
from datetime import datetime as dt

import pandas as pd
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import seaborn as sns
import skimage.io

mpl.rcParams['font.size'] = 30

class Plot(object):
    def __init__(self, img, llabel, ljunc0, ljunc1, rlabel, rjunc0, rjunc1, rmse, linewidth, **kwargs):
        self.linewidth = linewidth

        self.img = img
        self.height = img.shape[0]
        self.width = img.shape[1]

        self.llabel = llabel
        self.ljunc0 = ljunc0
        self.ljunc1 = ljunc1
        self.rlabel = rlabel
        self.rjunc0 = rjunc0
        self.rjunc1 = rjunc1

        self.rmse = rmse

    def draw_all(self, is_show=False, is_save=False, save_png=None):
        mpl.style.use('seaborn-paper')  # mpl.style.available (total: 28)
        

        # fig = plt.figure(figsize=(8,4))
        fig = plt.figure(figsize=(16,9), dpi=120)  # width 3088 pixel_width = w * dpi  # figsize=(w,h)
        plt.imshow(self.img)

        cl = self.draw_center_line()
        l_left, l_right = self.draw_lines_label()
        p_left, p_right = self.draw_lines_pred()

        plt.title(f'RSE: {self.rmse:.04f} pixels', fontsize=24)
        plt.legend(loc='lower right', framealpha=0.4)

        if is_save:
            plt.savefig(save_png)
        if is_show:
            plt.show()
        plt.close()
        

    def draw_center_line(self):
        p = plt.plot([self.width // 2, self.width // 2], [0, self.height-1], 'k--', linewidth=self.linewidth, label='center of x-axis')
        return p
        
    def draw_lines_label(self):
        p1 = plt.plot([self.llabel, self.llabel], [0, self.height-1], 'r-', linewidth=self.linewidth, label='border labels')
        p2 = plt.plot([self.rlabel, self.rlabel], [0, self.height-1], 'r-', linewidth=self.linewidth)
        return p1, p2

    def draw_lines_pred(self):
        '''plot(x, y, color='green', marker='o', linestyle='dashed', linewidth=2, markersize=12)'''
        p1 = plt.plot([self.ljunc0[0], self.ljunc1[0]], [self.ljunc0[1], self.ljunc1[1]], color='#00FF00', marker='.', linestyle='--', linewidth=self.linewidth, label='border predictions')
        p2 = plt.plot([self.rjunc0[0], self.rjunc1[0]], [self.rjunc0[1], self.rjunc1[1]], color='#00FF00', marker='.', linestyle='--', linewidth=self.linewidth)
        return p1, p2


'''the resized image size is (512, 512)



blank_fig = np.zeros([512, 512])
plt.imshow(blank_fig)

for line in lines:
    plt.plot([line[0], line[2]], [line[1], line[3]], linewidth=1) 
    plt.scatter(line[0], line[1])
    plt.scatter(line[2], line[3])

plt.show()


### 00030043.png
original_lines = [[x], [y]]
draw_lines(original_lines)
'''

def parser_str_to_tuple(tuple_in_str):
    x, y = tuple_in_str.split(',')
    return (float(x[1:]), float(y[:-1]))

### only for test
if __name__ == "__main__":
    # data_path = 'E:/dl_save/HG2_LB_test/test_10-26.csv'  # for HG1-DB2
    # data_path = 'U:/my_projs/g_output_DL/_test_result_csv/test_10-26_FClip_HG1_D2.csv'  # for HG2-LB
    data_path = 'U:/my_projs/g_output_DL/_test_result_csv/test_10-19_HTLCNN.csv'  # for HG2-LB

    imgs_root = '\\\\os.lsdf.kit.edu\\itiv-projects\\Stents4Tomorrow\\Data\\2022-04-28\\Data\\Images'
    out_path = 'U:/my_projs/g_output_DL'
    os.makedirs(out_path, exist_ok=True)

    
    is_show=False
    is_save=True

    df = pd.read_csv(data_path)

    # select the result according to the RMSE value
    # (in test result.ipynb)total number: 350, 373, 125, 12, 6
    df_sub_0_20 = df[df.RMSE < 20]  
    df_sub_20_30 =  df[(df.RMSE >= 20) & (df.RMSE < 30)] 
    df_sub_30_40 =  df[(df.RMSE >= 30) & (df.RMSE < 40)] 
    df_sub_40_50 =  df[(df.RMSE >= 40) & (df.RMSE < 50)] 
    df_sub_over_50 =  df[(df.RMSE >50)] 

    df_to_plot = df_sub_40_50
    skip_step = np.ceil(df_to_plot.shape[0] / float(26))  # 1 , 5, 10  -> output number: maxmial 40 

    count = 0
    for record_tuple in df_to_plot.itertuples():
        count = count + 1
        # !!! only for number > 150
        if count % skip_step != 0:  
            continue


        # records_tuple = tuple(records.tolist())
        _, _, folder, img_png, l_label, ljunc0, ljunc1, r_label, rjunc0, rjunc1, rmse, time = record_tuple
        # img_path_train = os.path.join(imgs_root, 'dataset_train', folder, img_png)
        # img_path_valid = os.path.join(imgs_root, 'dataset_valid', folder, img_png)
        # img_path_test = os.path.join(imgs_root, 'dataset_test', folder, img_png)
        img_path = os.path.join(imgs_root, folder, img_png)

        save_pth = os.path.join(out_path, f"{folder}-{img_png}")

        ljunc0, ljunc1, rjunc0, rjunc1 = map(parser_str_to_tuple, (ljunc0, ljunc1, rjunc0, rjunc1))

        # try:
        #     im = skimage.io.imread(img_path_train)
        # except (ValueError, IOError):
        #     try:
        #         im = skimage.io.imread(img_path_valid)
        #     except (ValueError, IOError):
        #         im = skimage.io.imread(img_path_test)
            # finally:
            #     with open("Image_read_failed.txt", "a") as f:
            #         f.write(f"{count:04d}, {folder}, {img_png} \n")
            #     continue
        
        try:
            im = skimage.io.imread(img_path)
        except (ValueError, IOError):
            with open("Image_read_failed.txt", "a") as f:
                f.write(f"{count:04d}, {folder}, {img_png} \n")
            continue

        do_plot = Plot(im, l_label, ljunc0, ljunc1, r_label, rjunc0, rjunc1, rmse, 4)        
        do_plot.draw_all(is_show, is_save, save_png=save_pth)



        



