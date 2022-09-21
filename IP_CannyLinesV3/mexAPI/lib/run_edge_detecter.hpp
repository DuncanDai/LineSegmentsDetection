#ifndef _EDGE_DETECTER_
#define _EDGE_DETECTER_
#pragma once

#include "opencv2/opencv.hpp"
// test: do I need to add the #include "opencv2/ximgproc.hpp"  in .h file???

using namespace std;
using namespace cv;

void run_edge_detecter(Mat &image, vector<Vec4f> &edgeLines);


#endif // _PLINKAGE_SUPERPIXEL_
