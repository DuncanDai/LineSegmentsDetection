#include <stdio.h>
// #include <fstream>  // not neccessary

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void run_edge_detecter(cv::Mat &image, std::vector<Vec4f> &edgeLines);