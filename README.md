# LineSegmentsDetection
Including classical image processing and deep learning based methods

## Overview of the homepage (current page)
1 The directories with a name prefix `g_` show the global data. 
- Each of the other directories represents one LSD method.

2 The related papers are in the `g_papers` directory. 
- The file with a name prefix `DL_` implies that DL-based method has been implemented.

## Classical image processing
1-1 CannyLines 2015 （source code: C/C++）
- Model 1: parameter free
- Model 2: CannyLines v3

1-2 LSM 2016 （source code: C/C++ & Matlab）

2 MCMLSD 2017 [CVPR] （source code: C/C++ & Matlab）

## Deep learning 
- Source code: PyTorch

Comparison of the LSD methods (metric: sAP10):
![](./g_results/Comparison%20of%20LSD%20methods(DL).png)


1 [L-CNN: End-to-End Wireframe Parsing ICCV2019](https://paperswithcode.com/paper/190503246)   
- [github repo](https://github.com/zhou13/lcnn)
- The previous state-of-the-art method
- Introduced metrics:
    - Structural mAP
    - Junction mAP  

2 [HAWP: Holistically-Attracted Wireframe Parsing CVPR 2020](https://paperswithcode.com/paper/holistically-attracted-wireframe-parsing)
- [github repo](https://github.com/cherubicXN/hawp)

3 [HT-HAWP: Deep Hough-Transform Line Priors ECCV 2020](https://paperswithcode.com/paper/deep-hough-transform-line-priors)
- [github repo](https://github.com/yanconglin/Deep-Hough-Transform-Line-Priors)

4 [F-Clip: Fully Convolutional Line Parsing 2021.04](https://paperswithcode.com/paper/fully-convolutional-line-parsing)
- [github repo](https://github.com/Delay-Xili/F-Clip)


Plus: [LETR: Line Segment Detection Using Transformers without Edges CVPR 2021](https://paperswithcode.com/paper/line-segment-detection-using-transformers)
- [github repo](https://github.com/mlpc-ucsd/LETR)
- Stage 1: 40M parameters
- Stage 2: by using 24G GPU