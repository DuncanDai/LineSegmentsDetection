#include <stdio.h>
#include <fstream>

#include "opencv2/opencv.hpp"  // can't be omitted
//#include <opencv2/imgproc.hpp>  // can be omitted

using namespace std;
using namespace cv;

// `edge_detecter` works like main function: if not be called, no need to create .h file
// image: grayscale CV_8UC1
void run_edge_detecter(Mat &image, vector<Vec4f> &edgeLines) {
// 	Ptr< LineSegmentDetector >  lsd = createLineSegmentDetector(LSD_REFINE_ADV, 1.0);  // scale = 1.0; LSD_REFINE_ADV: 1s 2435 edgeLines vs LSD_REFINE_NONE: 0.56s 579 edgeLines
    Ptr< LineSegmentDetector >  lsd = createLineSegmentDetector(LSD_REFINE_STD, 1.0);  // LSD_REFINE_STD 0.96s  3668 edgeLines
	lsd->detect(image, edgeLines); // other parameters aren't needed
// 	lsd->drawSegments(image, edgeLines);
}

// int main() {
// 	string image_path = "test1.png";
// 	Mat image = imread(image_path, IMREAD_GRAYSCALE);
// 	if (image.empty()){
// 		printf("the image loads failed\n");
// 		return -1;
// 	}
// 	vector<Vec4f> edgeLines;
// 	run_edge_detecter(image, edgeLines);
// 
// 	//for (auto i : edgeLines) 
// 		//std::cout << i << ' ';
// 
// 	namedWindow("lsd result", WINDOW_NORMAL);
// 	imshow("lsd result", image);
// 	waitKey();
// 	return 0;
// }