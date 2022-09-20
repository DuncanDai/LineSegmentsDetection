#include <stdio.h>
#include <fstream>

#include "opencv2/opencv.hpp"

// relative path to the lib directory -> pay attention to the directory change.
// #include "../lib/CannyPF.h"
// #include "../lib/ChainFromEdgeMap.h"
// #include "../lib/run_edge_detecter.hpp"

using namespace cv;
using namespace std;

void run_edge_detecter(Mat &image, vector<Vec4f> &edgeLines);