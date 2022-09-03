/**
 * Copyright 2013 B. Schauerte. All rights reserved.
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

/** opencv_matlab - how to call OpenCV from Matlab
 *  A simple example (with some type conversions) on how to invoke OpenCV
 *  functions from a Matlab C++-.mex file.
 * 
 *  \author B. Schauerte
 *  \email  <schauerte@kit.edu>
 *  \date   2013
 */

#include <opencv2/opencv.hpp>
#include "mex.h"
#include "opencv_matlab.hpp"

void 
mexFunction(int nlhs, mxArray *plhs[], 
            int nrhs, const mxArray *prhs[])
{
    // default parameters
    int ksize = 3;
    double sigma = 2.0;

    //validate input
    if (nrhs == 0)
    {
        mexErrMsgTxt("An image is required!");
    }
    if (nlhs != 1)
    {
        mexErrMsgTxt("Only one output is provided.");
    }
    if(!mxIsDouble(prhs[0]) || ((mxGetNumberOfDimensions(prhs[0]) != 3) && (mxGetNumberOfDimensions(prhs[0]) != 2)))
    {
        mexErrMsgTxt("Type of the image has to be double.");
    }
    if((nrhs >= 2)  && ((!mxIsDouble(prhs[1])) || (mxGetScalar(prhs[1]) <= 0)))
    {
        mexErrMsgTxt("ksize has to be a positive integer.");
    } 
    else if (nrhs >= 2)
    {
        ksize = (int) mxGetScalar(prhs[1]);
    }
    if((nrhs >= 3)  && ((!mxIsDouble(prhs[2])) || (mxGetScalar(prhs[2]) <= 0)))
    {
        mexErrMsgTxt("sigma has to be a positive value.");
    } 
    else if (nrhs >= 3)
    {
        sigma = (double) mxGetScalar(prhs[2]);
    }
    
    // determine input/output image properties
    const int *dims    = mxGetDimensions(prhs[0]);
    const int nDims    = mxGetNumberOfDimensions(prhs[0]);
    const int rows     = dims[0];
    const int cols     = dims[1];
    const int channels = (nDims == 3 ? dims[2] : 1);
    
    // Allocate, copy, and convert the input image
    // @note: input is double
    cv::Mat image = cv::Mat::zeros(cv::Size(cols, rows), CV_64FC(channels));
    om::copyMatrixToOpencv(mxGetPr(prhs[0]), image);
    image.convertTo(image, CV_8U, 255);
    
    // Call OpenCV functions here and do the magic
    cv::Mat out = cv::Mat::zeros(cv::Size(cols, rows), CV_8UC(channels));
    cv::GaussianBlur(image,out,cv::Size(ksize,ksize),sigma);
    
    // Convert opencv to Matlab and set as output
    // @note: output is uint8
    plhs[0] = mxCreateNumericArray(nDims, dims, mxUINT8_CLASS, mxREAL);
    om::copyMatrixToMatlab<unsigned char>(out, (unsigned char*)mxGetPr(plhs[0]));
}