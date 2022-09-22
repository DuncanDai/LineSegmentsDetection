/* Description
 *  the general API for LSD, EDLines, CannyPF and CannyLines
 * 
 *  In C++: 
 *      void run_edge_detecter(Mat &image, vector<Vec4f> &edgeLines)
 *
 *  In Matlab:
 *      inputs[0]: 8 bit grayscale image (uint8_t)
 *      
 *      outputs[0]: run time of cpp function in this mex_edgeDetecter.cpp
 *      outputs[1]: edgeLines elements in one row -> （x1, y1, x2, y2）
 *
 *  Usage of stream display for debuging: 
 *       stream << " " << var << std::endl; displayOnMATLAB(stream);    
 * 
 *  
 * Author: Dinggen DAI (daidinggen@hotmail.com)
 * Date: 2022.09.20
 */

#include <stdio.h>
#include <fstream>
#include <windows.h>

#include "mex.hpp"
#include "mexAdapter.hpp"  // matlab API for C++
#include "opencv2/opencv.hpp"  // there are some other header of opencv2 in opencv.hpp

// relative path to the lib directory -> pay attention to the directory change.
#include "./lib/run_edge_detecter.hpp"


// #define IDX(i,j,iSize) ((iSize)*(i)+(j))  // matlab API for C pointer

using namespace std;
using namespace cv;
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

        /* 1 get the properties of input image */
        matlab::data::ArrayDimensions dims = inputs[0].getDimensions(); 
        const size_t rows       = dims[0]; 
        const size_t cols       = dims[1];
        size_t i, j;
        stream << "Image size (rows, cols): (" << rows << " ," << cols << ")"  << std::endl; displayOnMATLAB(stream);

        /* 2 Data type convertion: from Matlab to C++  */
        // NOTE: input[0] is double image -> OpenCV Canny() requires 8-bit input image
        cv::Mat image(cv::Size( (int)cols, (int)rows ), CV_8UC1, Scalar(0));
        vector<Vec4f> edgeLines;

        const TypedArray<uint8_t> imageFromMatlab = std::move(inputs[0]);   // Issue: inputs[0] from Matlab needs to the same double type, otherwise, Can't convert the Array(uint8s) to this TypedArray
        for(i=0; i<rows; ++i)
            for(j=0; j<cols; ++j)
                image.at<uchar>(i, j) = imageFromMatlab[i][j];  // from matlab(column major order (row, col)) to C++(row major order (col, row)) 

        
        /////* 3 run c++ module  */////
        // calculate running time
        LARGE_INTEGER t1,t2,tc;
        QueryPerformanceFrequency(&tc);
        QueryPerformanceCounter(&t1);
        double time;
        double timeStart = (double)getTickCount(); 
        
        // run cpp function
        run_edge_detecter(image, edgeLines);

        QueryPerformanceCounter(&t2);
        time = (double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
        double timeEnd = ((double)getTickCount() - timeStart) / getTickFrequency();
        cout << "Running time in C++ = " << time << "s" << endl;  //output: ms
        cout << "Running time in OpenCV = " << timeEnd  << "s" << endl;  //output: ms
        /////////////////////////////////////////

        /* 4 Data type convertion: from C++ to Matlab */
        // output[0]: run time of cpp function
        TypedArray<double> run_time = factory.createScalar<double>(0);
        run_time[0] = time;
        outputs[0] = std::move(run_time);

        // output[1]: edgeLines
        size_t edgeLinesNumber = edgeLines.size();
        TypedArray<float> edgeLinesInMatlab = factory.createArray<float> ({edgeLinesNumber, 4}); 

        for(i=0; i<edgeLinesNumber; ++i){
            edgeLinesInMatlab[i][0] = edgeLines[i][0] + 1;  // matlab is 1-based index while cpp is 0-based index
            edgeLinesInMatlab[i][1] = edgeLines[i][1] + 1;
            edgeLinesInMatlab[i][2] = edgeLines[i][2] + 1;
            edgeLinesInMatlab[i][3] = edgeLines[i][3] + 1;
        }

        stream << "Finished!!!" << std::endl; displayOnMATLAB(stream);
        outputs[1] = std::move(edgeLinesInMatlab); 
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
        if (inputs.size() != 1) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Only one input required") }));
        }
        
        // inputs[0] is double grayscale image -> Matrix/Array
        if (inputs[0].getType() != ArrayType::UINT8 ||
            inputs[0].getType() == ArrayType::COMPLEX_UINT8) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be in type UINT8") }));
        }
        
        if (inputs[0].getDimensions().size() != 2) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Input[0] image must be m-by-n dimension") }));
        }
        
        
        // check outputs
        if (outputs.size() != 2) {
            matlabPtr->feval(u"error", 
                0, std::vector<Array>({ factory.createScalar("Two outputs required") }));
        }
        
    }
};