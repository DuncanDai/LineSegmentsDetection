#include <stdio.h>
#include <fstream>

#include "opencv2/opencv.hpp"

// relative path to the lib directory -> pay attention to the directory change.
#include "../lib/CannyPF.h"
#include "../lib/ChainFromEdgeMap.h"
#include "../lib/run_edge_detecter.hpp"

using namespace cv;
using namespace std;

void run_edge_detecter(Mat &image, vector<Vec4f> &edgeLines) {
    // get edge map by using canny filter
    const unsigned int GaussSize = 3;
    const float VMGradient = 70;
    CannyPF cannyer;
    cv::Mat edgeMap;
    
    cannyer.cannyPF(image, GaussSize, VMGradient, edgeMap);
    
    // get edge chains
    ChainFromEdgeMap chainer;
    std::vector< std::vector<cv::Point> > edgeChains;
    
    chainer.run(image, edgeMap, edgeChains);
    
    // compose edgeLines from edgeChains
    // only takes 0.0001616s, the main program above takes 0.689525s （but in mexAPI takes 0.3s, when implemented there）
    size_t edgeChainsNumber = edgeChains.size();
    edgeLines.resize(edgeChainsNumber); // edgeLines will be declared in mex API
    for (unsigned int i=0; i<edgeChainsNumber; ++i){
        float start_x = edgeChains[i].front().x;  // Vec4f is float
        float start_y = edgeChains[i].front().y;
        float end_x = edgeChains[i].back().x;
        float end_y = edgeChains[i].back().y;
       
        edgeLines[i] = Vec4f(start_x, start_y, end_x, end_y);
    }
}
