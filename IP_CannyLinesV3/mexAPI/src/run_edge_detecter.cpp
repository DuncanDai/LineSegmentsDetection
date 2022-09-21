#include <stdio.h>
#include <fstream>

// #include "cv.h"
// #include "highgui.h"
#include "opencv2/opencv.hpp"
// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc/imgproc_c.h"

#include "../lib/CannyLine.h"

using namespace std;
using namespace cv;

void run_edge_detecter(Mat& image, vector<Vec4f>& edgeLines) {
	CannyLine detector;
	detector.cannyLine(image, edgeLines);
}