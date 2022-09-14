/* Description
 *
 *  In C++:
 *      1 cannyer.cannyPF(image, GaussSize, VMGradient, edgeMap);
 *          get `edgeMap` by using canny filter
 *      2 chainer.run(image, edgeMap, edgeChains);
 *          get edge chains based on `edgeMap`
 *
 *  In Matlab:
 *      inputs[0]: grayscale image (double)
 *      inputs[1]: gaussian kernel size (odd uint8 scalar)
 *      inputs[2]: VMGradient (double scalar)
 *      
 *      outputs[1]: edgeMap (the same size as input grayscale image)
 *      outputs[2]: elements in one row -> （x, y, label_of_edgeChain）
 *          - input from C++: edgeChains (std::vector< std::vector<cv::Point> >   several edgeChains, each is composed of a set of points)
 *          - output in matlab: elements in one row -> （x, y, label_of_edgeChain）
 *
 * Author: Dinggen DAI (daidinggen@hotmail.com)
 * Date: 2022.08
 */
#include <stdio.h>
#include <fstream>
#include <windows.h>

#include "mex.hpp"
#include "mexAdapter.hpp"  // matlab API for C++
#include "opencv2/opencv.hpp"

// relative path to the lib directory -> pay attention to the directory change.
#include "./lib/CannyPF.h"
#include "./lib/ChainFromEdgeMap.h"

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
//         stream << "hey I'm here 0:" << std::endl; displayOnMATLAB(stream);
        
        /* 1 determine input image properties  */
        matlab::data::ArrayDimensions dims = inputs[0].getDimensions(); 
        
        const size_t nDims      = dims.size();  //dims is a vector
        const size_t rows       = dims[0]; 
        const size_t cols       = dims[1];
        const size_t channels = (nDims == 3 ? dims[2] : 1);
        int i, j;
        stream << "This is a " << channels << " channel(s)' image"  << std::endl; displayOnMATLAB(stream);
        stream << "hey I'm here 1. " << "Image size (rows, cols): (" << rows << " ," << cols << ")"  << std::endl; displayOnMATLAB(stream);
        
        /* 2 Data type convertion: from Matlab to C++  */
        // Allocate, copy, and convert the input image
        // @note: input[0] is double image -> OpenCV Canny() requires 8-bit input image
        cv::Mat image(cv::Size( (int)cols, (int)rows ), CV_8UC1, Scalar(1));
        const size_t num_eles = inputs[0].getNumberOfElements();
        const TypedArray<double> imageArray = std::move(inputs[0]);   // Issue: inputs[0] from Matlab needs to the same double type, otherwise, Can't convert the Array(uint8s) to this TypedArray
        stream << "hey I'm here 1+. Image size is -> " << image.size().height << ", " << image.size().width << std::endl; displayOnMATLAB(stream);
        stream << "hey I'm here 2. Number of elements  " << num_eles << std::endl; displayOnMATLAB(stream);

        for(i=0; i<rows; ++i)
            for(j=0; j<cols; ++j)
                image.at<uchar>(i, j) = (int) (imageArray[i][j] * 255);  // from matlab(column major order (row, col)) to C++(row major order (col, row)) 
        
        /////////////////////////////////////////
        /* 3 run c++ module  */
        /* calculate running time */
        LARGE_INTEGER t1,t2,tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);
        double time;

        // in C++: get edge map by using canny filter
        const unsigned int GaussSize = inputs[1][0];
        const float VMGradient = (float)inputs[2][0];
        CannyPF cannyer;
        cv::Mat edgeMap;
        
        cannyer.cannyPF(image, GaussSize, VMGradient, edgeMap);
        
        // in C++: get edge chains
        ChainFromEdgeMap chainer;
        std::vector< std::vector<cv::Point> > edgeChains;
        
        chainer.run(image, edgeMap, edgeChains);
        QueryPerformanceCounter(&t2);

        time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
        cout << "Running time = " << time * 1000 << "ms" << endl;  //output: ms
        
        TypedArray<double> run_time = factory.createScalar<double>(0);
        run_time[0] = time;
        outputs[0] = std::move(run_time);
        
        
        
        /////////////////////////////////////////
        /* 4 determine output image properties */
        /* outputs[1] */
        // @note: outputs[1] is uint8 edge map
        // force it row major order as in OpenCV, C/C++
        const int output_rows = edgeMap.rows;
        const int output_cols = edgeMap.cols;
        uint8_t *edgePtr = edgeMap.data;
        outputs[1] = factory.createArray<uint8_t> ({(size_t)output_rows, (size_t)output_cols});  // the pixel value is 0-255
       
        stream << "hey I'm here 3. EdgeChains.size is " << edgeChains.size() << std::endl; displayOnMATLAB(stream);     
        /* 5 Data type convertion: from c++ to Matlab */
//         for(i=0; i<output_rows; ++i)
//             for(j=0; j<output_cols; ++j){
//                 if (i==output_rows-1 && j==output_cols-1) break;
//                 outputs[1][i][j] = *edgePtr++; // attention: ++ operator -> memory overflow
//             }
//         outputs[1][output_rows-1][output_cols-1] = *edgePtr;
        for(i=0; i<output_rows; ++i) 
            for(j=0; j<output_cols; ++j){
                outputs[1][i][j] = *edgePtr++; // right hand: row major order
            }

        
        stream << "hey I'm here 4. The rows and cols of output is " << output_rows << " and " << output_cols <<  std::endl; displayOnMATLAB(stream); 
        /* outputs[2] */
//         CellArray allEdges = factory.createCellArray ({edgeChains.size(), size_t(1)});
//         stream << "hey I'm here 4+. The size of outputs[2] is " << allEdges.getDimensions()[0] << " and " << allEdges.getDimensions()[1]  <<  std::endl; displayOnMATLAB(stream);
        
        // edgesNumber is more than 87000 -> result is int32
        size_t edgesNumber = 0;
        // 1) calculate the total elements (x, y points pair) number in edgeChains
        for (auto &edgeChain: edgeChains){
            edgesNumber += edgeChain.size();
        }
        TypedArray<int> allEdges = factory.createArray<int> ({edgesNumber, 3}) ;  // the pixel coordinate value is around 3,000  ChainFromEdgeMap.cpp  cv::Point<int>  
        stream << "hey I'm here 4+. The (x, y) points pair number is " << edgesNumber << std::endl; displayOnMATLAB(stream); 
        
        size_t chainSize;
        size_t index = 0;
        for(i=0; i<edgeChains.size(); ++i){
            chainSize = edgeChains[i].size();
            for(j=0; j<chainSize; ++j){
                // matlab Topic: Access C++ Data Array Container Elements -> Copy Data from Container -> ref book: matlab::data::Reference<TypedArray<T>>
                allEdges[index][0] = edgeChains[i][j].x;
                allEdges[index][1] = edgeChains[i][j].y;
                allEdges[index][2] = i+1;
                index++;
            }
        }
        stream << "hey I'm here 4++. Final index of allEdges is " << index << std::endl; displayOnMATLAB(stream); 
          
//         size_t singleEdgeSize;
//         for(i=0; i<edgeChains.size(); ++i){
//             singleEdgeSize = edgeChains[i].size();
//             allEdges[i] = factory.createArray<int> ({singleEdgeSize, size_t(2)}) ;  // the pixel coordinate value is around 3,000  ChainFromEdgeMap.cpp  cv::Point<int>
//             TypedArrayRef<int> singleEdge = allEdges[i][0];
// 
//             for(j=0; j<singleEdgeSize; ++j){
//                 // matlab Topic: Access C++ Data Array Container Elements -> Copy Data from Container -> ref book: matlab::data::Reference<TypedArray<T>>
//                 singleEdge[j][0] = edgeChains[i][j].x;
//                 singleEdge[j][1] = edgeChains[i][j].y;
//             }
//         }
                 
        stream << "hey I'm OK!" << std::endl; displayOnMATLAB(stream);
        outputs[2] = std::move(allEdges); 
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
        
        // inputs[0] is double grayscale image -> Matrix/Array
        if (inputs[0].getType() != ArrayType::DOUBLE ||
            inputs[0].getType() == ArrayType::COMPLEX_DOUBLE) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be type DOUBLE") }));
        }
        
        if (inputs[0].getDimensions().size() != 2) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be m-by-n dimension") }));
        }
        
        // inputs[1] is gaussian kernel -> UINT8 scalar
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
        
        // inputs[1] is VMGradient -> double scalar
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
        if (outputs.size() != 3) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Three outputs required") }));
        }
        
    }
};

