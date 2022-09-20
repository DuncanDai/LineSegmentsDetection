#include <stdio.h>
#include <fstream>

#include "opencv2/opencv.hpp"  // can't be omitted
//#include <opencv2/imgproc.hpp>  // can be omitted

using namespace cv;
using namespace std;

// `edge_detecter` works like main function: if not be called, no need to create .h file
// image: grayscale CV_8UC1
void edge_detecter(Mat &image, vector<Vec4f> &lines) {
	Ptr< LineSegmentDetector >  lsd = createLineSegmentDetector(LSD_REFINE_ADV, 1.0);  // scale = 1.0
	lsd->detect(image, lines); // other parameters aren't needed
	lsd->drawSegments(image, lines);
}

int main() {
	string image_path = "test1.png";
	Mat image = imread(image_path, IMREAD_GRAYSCALE);
	if (image.empty()){
		printf("the image loads failed\n");
		return -1;
	}
	vector<Vec4f> lines;
	edge_detecter(image, lines);

	//for (auto i : lines) 
		//std::cout << i << ' ';

	namedWindow("lsd result", WINDOW_NORMAL);
	imshow("lsd result", image);
	waitKey();
	return 0;
}