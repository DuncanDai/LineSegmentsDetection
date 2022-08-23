# LineSegmentsDetection
Including classical image processing and deep learning based methods

Note: all related papers are in the `papers` directory. 

## Classical image processing
1-1 CannyLines 2015 （source code: C++）
- Model 1: parameter free
- Model 2: CannyLines v3

1-2 LSM 2016 （source code: C++ & Matlab）

2 MCMLSD 2017 [CVPR] （source code: C++ & Matlab）

## Deep learning
1 [L-CNN: End-to-End Wireframe Parsing ICCV2019](https://paperswithcode.com/paper/190503246)   
- The previous state-of-the-art method
- Introduced metrics:
    - Structural mAP
    - Junction mAP  

2 [HAWP: Holistically-Attracted Wireframe Parsing CVPR 2020](https://paperswithcode.com/paper/holistically-attracted-wireframe-parsing)

3 [HT-HAWP: Deep Hough-Transform Line Priors ECCV 2020](https://paperswithcode.com/paper/deep-hough-transform-line-priors)

4 [F-Clip: Fully Convolutional Line Parsing 2021.04](https://paperswithcode.com/paper/fully-convolutional-line-parsing)


Plus: [LETR: Line Segment Detection Using Transformers without Edges](https://paperswithcode.com/paper/line-segment-detection-using-transformers)
- Stage 1: 400M parameters
- Stage 2: by using 24G GPU