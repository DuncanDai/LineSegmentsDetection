/**
 * Copyright 2011 B. Schauerte. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are 
 * met:
 * 
 *    1. Redistributions of source code must retain the above copyright 
 *       notice, this list of conditions and the following disclaimer.
 * 
 *    2. Redistributions in binary form must reproduce the above copyright 
 *       notice, this list of conditions and the following disclaimer in 
 *       the documentation and/or other materials provided with the 
 *       distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY B. SCHAUERTE ''AS IS'' AND ANY EXPRESS OR 
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL B. SCHAUERTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR 
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  
 * The views and conclusions contained in the software and documentation
 * are those of the authors and should not be interpreted as representing 
 * official policies, either expressed or implied, of B. Schauerte.
 */

/** opencv_matlab
 *  Conversion routines from OpenCV's (interleaved, row-major) images to Matlab 
 *  images (3-D matrices, column-major).
 *
 *  This is an example standalone program that demonstrates how to use the 
 *  conversions to run algorithms developed for Matlab in a program that
 *  is mainly based on C/C++ and OpenCV.
 *
 *  \author B. Schauerte
 *  \email  <schauerte@kit.edu>
 *  \date   2011,2013
 */

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "opencv_matlab.hpp"

using namespace cv;
using namespace std;

// do something (i.e., implement/test/integrate your Matlab image processing algorithm here)
template <typename T>
void
demo_algorithm(const T* from, T* to, int nrows, int ncols, int nchannels)
{
    int numel = nrows*ncols*nchannels;

    for (int i = 0; i < numel; i++)
        to[i] = from[i];
}

int
main(int argc, char* argv[])
{
    if(argc != 2)
    {
        cout <<" Usage: opencv_matlab test_image_path" << std::endl;
        exit(-1);
    }

    cv::Mat opencv_image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

    if (opencv_image.cols == 0 || opencv_image.rows == 0)
    {
        std::cerr << "Error: Could not load the specified image" << std::endl;
        exit(-1);
    }
    cv::Mat opencv_transformed_image(opencv_image.rows,opencv_image.cols,CV_8UC3);

    ////
    // Use the test routines
    ////

    // 1. convert from cv::Mat to Matlab
    unsigned char* matlab_image = om::allocateMatrixFromOpencv<unsigned char>(opencv_image);
    unsigned char* matlab_transformed_image = om::allocateMatrixFromOpencv<unsigned char>(opencv_transformed_image);
    om::copyMatrixToMatlab(opencv_image,matlab_image);

    // 2. run a simple algorithm on the Matlab format
    demo_algorithm(matlab_image,matlab_transformed_image,opencv_image.rows,opencv_image.cols,opencv_image.channels());

    // 3. convert from Matlab to cv::Mat
    om::copyMatrixFromMatlab(matlab_transformed_image,opencv_transformed_image);

    ////
    // Set up GUI
    ////
    cv::namedWindow( "opencv_image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "opencv_image", opencv_image );

    cv::namedWindow( "opencv_transformed_image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "opencv_transformed_image", opencv_transformed_image );

    waitKey(0);

    delete [] matlab_image;
    delete [] matlab_transformed_image;

    return 0;
}
