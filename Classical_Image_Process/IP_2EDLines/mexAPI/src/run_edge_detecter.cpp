#include <stdio.h>
#include <fstream>

#include "opencv2/opencv.hpp" 
#include "opencv2/ximgproc.hpp"  // here need dependency: opencv-contrib 

//#include "opencv2/imgproc.hpp"
//#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;
using namespace cv::ximgproc; 

// `edge_detecter` works like main function: if not be called, there is no need to create .h file
// input argument - image: grayscale CV_8UC1
void run_edge_detecter(Mat& image, vector<Vec4f>& edgeLines) {   
    Ptr<EdgeDrawing> ed = createEdgeDrawing();
    ed->params.EdgeDetectionOperator = EdgeDrawing::SOBEL;
    ed->params.GradientThresholdValue = 38;
    ed->params.AnchorThresholdValue = 8;

    // Detect edges
    //you should call this before detectLines() and detectEllipses()
    ed->detectEdges(image);
    // Detect lines
    ed->detectLines(edgeLines);   
}

//int main() {
//	string image_path = "test1.png";
//	Mat image = imread(image_path, IMREAD_GRAYSCALE);
//	if (image.empty()) {
//		printf("the image loads failed\n");
//		return -1;
//	}
//	vector<Vec4f> lines;
//	edge_detecter(image, lines);
//
//	//for (auto i : lines) 
//		//std::cout << i << ' ';
//
//	namedWindow("3 ed result", WINDOW_NORMAL);
//	imshow("3 ed result", image);
//	waitKey();
//	return 0;
//}