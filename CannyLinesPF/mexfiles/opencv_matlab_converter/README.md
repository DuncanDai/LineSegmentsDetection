# opencv_matlab

## 1. GENERAL

opencv_matlab is a simple C++ template library that provides routines to
convert between Matlab's and OpenCV's primary image representatations.

This way it is possible to easily call OpenCV functions from C++-.mex-code
as well as to use C++ routines developed for Matlab in projects that
primarily use OpenCV. 

Naturally, converting images takes time and it's consequently not the best
solution for code with strong time constraints, but it's often more than
good enough for prototyping and/or demonstrators. And, most importantly,
you don't have to rewrite/reimplement code, thus saving hours of time.

I have used the code in several projects and if you want to cite something
(yay! but don't feel obliged to do so), then [1] might be most appropriate

[1] B. Schauerte, B. Kuehn, K. Kroschel, R. Stiefelhagen, "Multimodal 
    Saliency-based Attention for Object-based Scene Analysis". In Proc. 24th
    International Conference on Intelligent Robots and Systems (IROS), 
    IEEE/RSJ, San Francisco, CA, USA, September 25-30, 2011.

## 2. INSTALLATION

Since the whole code is contained in the header (.hpp) files, all you need
to do is copy these files into your project and include them.

## 3. DEMO CODE / USAGE EXAMPLES

### 3.1 EXAMPLE FOR OpenCV CODE USING FUNCTIONS WRITTEN FOR C++-.mex FILES

The demo code in *opencv_matlab_standalone.cpp* uses OpenCV to load an 
image, then converts the image to Matlab's image representation, runs an
arbitrary code, and then converts the result to OpenCV's format for further
operations/display.

You can compile and run it as follows:

    mkdir build
    cd build
    ccmake ..
    make
    ./opencv_matlab_standalone path_to_some_test_image

### 3.2 EXAMPLE FOR CALLING OpenCV FUNCTIONS FROM A C++-.mex FILE

The demo code that showcases how to invoke OpenCV functions from a C++-.mex
is distributed in several files:

- *build_opencv_matlab_mex.m* can be used to build the .mex file (take care
  and set the correct include/lib pathes)
- *opencv_matlab_mex.cpp* is the actual C++-.mex demo function, which calls 
  cv::GaussianBlur and does some type conversions
- *opencv_matlab_mex_demo.m* can be called to show a demo example  

To put it in order, run the following in Matlab:

    build_opencv_matlab_mex
    opencv_matlab_mex_demo

## 4. AUTHOR INFORMATION

### 4.1 CONTACT

[Boris Schauerte](http://cvhci.anthropomatik.kit.edu/~bschauer/ "Boris Schauerte, Homepage")

**NOTE** Please do not send me e-mails regarding problems with OpenCV, etc.
  in general; I am really not the best person to answer such questions and
  - in all honesty - I have too much other stuff to do, sorry.

### 4.2 CODE HOSTING

1. Stable/static version: [opencv_matlab@Mathworks](http://www.mathworks.com/matlabcentral/fileexchange/41530 "Mathworks File Exchange, stable version")
2. Development version, feel free to commit: [opencv_matlab@GitHub](https://github.com/bschauerte/opencv_matlab "GitHub repository, if you want to contribute")

### 4.3 ACKNOWLEDGEMENTS

#### 4.3.1 INSTITUTIONS

Part of this work was/is supported by the German Research Foundation (DFG)
within the Collaborative Research Program SFB 588 "Humanoid Robots" and the
Quaero Programme, funded by OSEO, French State agency for innovation.
