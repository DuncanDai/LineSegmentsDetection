#include <stdio.h>
#include <fstream>

#include "mex.hpp"
#include "mexAdapter.hpp"  // matlab API for C++
#include "opencv2/opencv.hpp"
//#include "opencv2/highgui.hpp"  // not included
//#include "opencv_matlab_converter/opencv_matlab.hpp"


// relative path to the lib directory
#include "../include/CannyPF.h"
#include "../include/ChainFromEdgeMap.h"

#define IDX(i,j,iSize) ((iSize)*(i)+(j))

using namespace cv;
using namespace std;
using namespace matlab::data;
using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function {
    // Pointer to MATLAB engine to call fprintf
    std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();

    // Factory to create MATLAB data arrays
    ArrayFactory factory;

    // Create an output stream
    std::ostringstream stream;
public:
    void operator()(ArgumentList outputs, ArgumentList inputs) {
        checkArguments(outputs, inputs);

//         matlabPtr->feval(u"fprintf", 0,
//             std::vector<Array>({ factory.createScalar("hey I'm here 0 \n") }));
        
        /* 1 determine input image properties  */
        stream << "hey I'm here 1:" << std::endl; displayOnMATLAB(stream);

        matlab::data::ArrayDimensions dims = inputs[0].getDimensions(); 
        stream << "hey I'm here 2:" << std::endl; displayOnMATLAB(stream);

        const size_t nDims      = dims.size();  //dims is a vector
        const size_t rows       = dims[0]; 
        const size_t cols       = dims[1];
        const size_t channels = (nDims == 3 ? dims[2] : 1);
        int i, j;
        stream << "This is a " << channels << " channel(s)' image"  << std::endl; displayOnMATLAB(stream);
        stream << "hey I'm here 3:" << "image size (rows, cols): (" << rows << " ," << cols << ")"  << std::endl; displayOnMATLAB(stream);
        
        /* 2 Data type convertion: from Matlab to C++  */
        // Allocate, copy, and convert the input image
        // @note: input[0]  is double image -> OpenCV Canny() requires 8-bit input image
        cv::Mat image(cv::Size( (int)cols, (int)rows ), CV_8UC1, Scalar(1));
//             = cv::Mat::zeros(cv::Size( (int)cols, (int)rows ), CV_8UC( (int)channels ));  // before is CV_64FC(channel)
        stream << "test: image size is -> " << image.size().height << "," << image.size().width << std::endl; displayOnMATLAB(stream);
        
//         const MemoryLayout layout = inputs[0].getMemoryLayout();
        const size_t num_eles = inputs[0].getNumberOfElements();
        stream << "hey I'm here 4: number of elements  " << num_eles << std::endl; displayOnMATLAB(stream);

//         unsigned char *imgPtr = image.data;
        const TypedArray<double> imageArray = std::move(inputs[0]);   // Issue: inputs[0] needs to the same double type, otherwise, Can't convert the Array(uint8s) to this TypedArray
        stream << "hey I'm here 4+:" << std::endl; displayOnMATLAB(stream);
        stream << "hey I'm here 4++: " << image.at<uchar>(0, 0) + 1  << " image arr " << imageArray.getNumberOfElements() << " to "  << " to " <<  std::endl; displayOnMATLAB(stream);
        stream << "hey I'm here 4+++: "<< imageArray[0][0] <<  " to " << imageArray[rows-1][cols-1] <<  " to "  << std::endl; displayOnMATLAB(stream);
        
//         i = 0;
//         for (auto&& elem: imageArray){
//             stream << "hey I'm here test:"<< elem   << std::endl; displayOnMATLAB(stream);
//             if(++i > 80)
//                 break;
//             
//         }

        // om::copyMatrixToOpencv(inputs[0], image); -> requires pointer (in matlab API for C)
        for(i=0; i<rows; ++i)
            for(j=0; j<cols; ++j)
                image.at<uchar>(i, j) = (int) (imageArray[i][j] * 255);  // from matlab(column major order (row, col)) to C++(row major order (col, row)) 

            
        // for debug
//         if (j > 3050) {
//             stream << "( "<< i << " , "  << j << " ) " ; displayOnMATLAB(stream);
//         }
//         if (j == 3088 || i == 2064){
//             break;
//         }
//         stream << std::endl ; displayOnMATLAB(stream);

                
                
   
        //image.convertFloatMatrixToUint8(image, CV_8U, 255);
        stream << "hey I'm here 5:" << std::endl; displayOnMATLAB(stream);
        
        /* 3 run c++ module  */
        const unsigned int GaussSize = inputs[1][0];
        const float VMGradient = (float)inputs[2][0];
        CannyPF cannyer;
        cv::Mat edgeMap;
        // get edge map by using canny filter
        cannyer.cannyPF(image, GaussSize, VMGradient, edgeMap);
        
        // get edge chains
        ChainFromEdgeMap chainer;
        std::vector< std::vector<cv::Point> > edgeChains;
        chainer.run(image, edgeMap, edgeChains);
        stream << "hey I'm here 6:" << std::endl; displayOnMATLAB(stream);
        
        /* 4 determine output image properties */
        // @note: outputs[0] is uint8 edge map
        // force it row major order as in OpenCV, C/C++
        const int output_rows = edgeMap.rows;
        const int output_cols = edgeMap.cols;
        uint8_t *edgePtr = edgeMap.data;
        outputs[0] = factory.createArray<uint8_t> ({(size_t)output_rows, (size_t)output_cols});  // the pixel value is 0-255
//                 std::vector<matlab::data::Array> ();
        stream << "hey I'm here 7: edgeChains.size is " << edgeChains.size() << std::endl; displayOnMATLAB(stream);     
        /* 5 Data type convertion: from c++ to Matlab */
        for(i=0; i<output_rows; ++i)
            for(j=0; j<output_cols; ++j){
                if (i==output_rows-1 && j==output_cols-1) break;
                outputs[0][i][j] = *edgePtr++; // attention: ++ operator -> memory overflow
            }
        outputs[0][output_rows-1][output_cols-1] = *edgePtr;
        stream << "hey I'm here 8: " << output_rows << " to " << output_cols <<  std::endl; displayOnMATLAB(stream);
        
        /* outputs[1] */
        CellArray out = factory.createCellArray ({edgeChains.size(), size_t(1)});
        stream << "hey I'm here 8+: " << out.getDimensions()[0] << " to " << out.getDimensions()[1]  <<  std::endl; displayOnMATLAB(stream);
        
        
        size_t edgeChainPointsCount;
        for(i=0; i<edgeChains.size(); ++i){
            edgeChainPointsCount = edgeChains[i].size();
            out[i] = factory.createArray<int> ({edgeChainPointsCount, size_t(2)}) ;  // the pixel coordinate value is around 3,000  ChainFromEdgeMap.cpp  cv::Point<int>
            stream << "hey I'm here 8++: " << out[i].getDimensions()[0]  << " to " << out[i].getDimensions()[1]  <<  std::endl; displayOnMATLAB(stream);

//             for(j=0; j<edgeChainPointsCount; ++j){
// //                 out[i][j] = factory.createArray<int> ({(size_t)1, (size_t)2}, {factory.createScalar(edgeChains[i][j].x), factory.createScalar(edgeChains[i][j].y)});
//                 out[i][j] = {factory.createScalar(edgeChains[i][j].x), factory.createScalar(edgeChains[i][j].y)};  // issue: before is only edgeChains[i][j].x -> data type not match
// //                 out[i][j][1] = factory.createScalar(edgeChains[i][j].y);  // issur: only [i][0] -> Array index is invalid.
//             }        
        }
        stream << "hey I'm here 9: OK!" << std::endl; displayOnMATLAB(stream);
        outputs[1] = std::move(out); 
    }


private:
    void displayOnMATLAB(std::ostringstream& stream) {
        // Pass stream content to MATLAB fprintf function
        matlabPtr->feval(u"fprintf", 0,
            std::vector<Array>({ factory.createScalar(stream.str()) }));
        // Clear stream buffer
        stream.str("");
    }

    void checkArguments(ArgumentList outputs, ArgumentList inputs) {
        std::shared_ptr<matlab::engine::MATLABEngine> matlabPtr = getEngine();
        ArrayFactory factory;
        
        /* check inputs */
        if (inputs.size() != 3) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Thress inputs required") }));
        }
        
        // inputs[0] is double grayscale image
        if (inputs[0].getType() != ArrayType::DOUBLE ||
            inputs[0].getType() == ArrayType::COMPLEX_DOUBLE) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be type DOUBLE") }));
        }
        
        if (inputs[0].getDimensions().size() != 2) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be m-by-n dimension") }));
        }
        
        if (inputs[1].getNumberOfElements() != 1) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[1] gaussian kernel size must be a scalar") }));
        }
        
        const unsigned char gauss_size = inputs[1][0];
        if (inputs[1].getType() != ArrayType::UINT8 ||
            inputs[1].getType() == ArrayType::COMPLEX_UINT8 ||
            gauss_size % 2 == 0) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[1] gaussian kernel size must be a noncomplex scalar odd UINT8") }));
        }
        
        if (inputs[2].getNumberOfElements() != 1) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[2] VMGradient must be a scalar") }));
        }
        
        if (inputs[2].getType() != ArrayType::DOUBLE ||
            inputs[2].getType() == ArrayType::COMPLEX_DOUBLE) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[2] VMGradient must be a noncomplex scalar double") }));
        }
        
        
        // check outputs
        if (outputs.size() != 2) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Two outputs required") }));
        }
        
    }
};

