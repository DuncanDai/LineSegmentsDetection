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

        stream << "hey I'm here 0:" << std::endl; displayOnMATLAB(stream);
//         matlabPtr->feval(u"fprintf", 0,
//             std::vector<Array>({ factory.createScalar("hey I'm here 0 \n") }));
        
        /* 1 determine input image properties  */
//         matlab::data::TypedArray<double> IN_img = std::move(inputs[0]);
//         printf("hey I'm here 0 \n");
        stream << "hey I'm here 1:" << std::endl; displayOnMATLAB(stream);
//         ArrayDimensions dims = IN_img.getDimensions(); 
//         printf("hey I'm here 0 \n");
        matlab::data::ArrayDimensions dims = inputs[0].getDimensions(); 
        stream << "hey I'm here 2:" << dims.size() << std::endl; displayOnMATLAB(stream);

        const size_t nDims      = dims.size();  //dims is a vector
        const size_t rows       = dims[0]; 
        const size_t cols       = dims[1];
        const size_t channels = (nDims == 3 ? dims[2] : 1);
        int i, j;
        stream << "hey I'm here 3:" << std::endl; displayOnMATLAB(stream);
        /* 2 Data type convertion: from Matlab to C++  */
        // Allocate, copy, and convert the input image
        // @note: input[0]  is double image -> OpenCV Canny() requires 8-bit input image
        cv::Mat image = cv::Mat::zeros(cv::Size( (int)cols, (int)rows ), CV_64FC( (int)channels ));
        stream << "hey I'm here 4:" << std::endl; displayOnMATLAB(stream);
        unsigned char *imgPtr = image.data;
//         printf("hey I'm here 1 \n");
        // om::copyMatrixToOpencv(inputs[0], image); -> requires pointer (in matlab API for C)
        for(i=0; i<rows; ++i)
            for(j=0; j<cols; ++j)
                imgPtr[i*cols+j] = (unsigned char)inputs[0][IDX(j,i,rows)];
   
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
        int output_rows = edgeMap.rows;
        int output_cols = edgeMap.cols;
        unsigned char *edgePtr = edgeMap.data;
        outputs[0] = factory.createArray<uint8_t> ({(size_t)output_rows, (size_t)output_cols});  // the pixel value is 0-255
        outputs[1] = factory.createCellArray ({edgeChains.size(), size_t(1)});
//                 std::vector<matlab::data::Array> ();
        stream << "hey I'm here 7:" << std::endl; displayOnMATLAB(stream);
                
        /* 5 Data type convertion: from c++ to Matlab */
        for(i=0; i<output_rows; ++i)
            for(j=0; j<output_cols; ++j)
                outputs[0][IDX(j,i,output_rows)] = edgePtr[IDX(i,j,output_cols)];
        stream << "hey I'm here 8:" << std::endl; displayOnMATLAB(stream);
        
        size_t sub_array_rows;
        stream << "hey I'm here 9:" << std::endl; displayOnMATLAB(stream);
        for(i=0; i<edgeChains.size(); ++i){
            sub_array_rows = edgeChains[i].size();
            outputs[1][i] = factory.createArray<uint16_t> ({sub_array_rows, 2}) ;  // the pixel coordinate value is around 3,000
            for(j=0; j<sub_array_rows; ++j){
                outputs[1][i][0] = edgeChains[i][j].x;
                outputs[1][i][1] = edgeChains[i][j].y;
            }        
        }
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
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be type double") }));
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
                0, std::vector<Array>({ factory.createScalar("Input[1] gaussian kernel size must be a noncomplex scalar odd int") }));
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

