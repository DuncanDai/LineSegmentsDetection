#include <stdio.h>
#include <fstream>
//#include "cv.h"
//#include "highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

#include "CannyPF.h"
#include "ChainFromEdgeMap.h"

using namespace cv;
using namespace std;

int main()
{
	string imgFile = "U:\\my_projs\\LineSegmentsDetection\\CannyLines_PF\\data\\_origin_rgb.png";
	cv::Mat img = imread(imgFile, 0);

	// get edge map
	CannyPF cannyer;
	cv::Mat edgeMap;
	float VMGradient = 70.0;
	cannyer.cannyPF( img, 3, VMGradient, edgeMap );

	// get edge chain
	ChainFromEdgeMap chainer;
	std::vector<std::vector<cv::Point> > edgeChains;
	chainer.run( img, edgeMap, edgeChains );

	// show
	cv::Mat imgShow( img.rows, img.cols, CV_8UC1, cv::Scalar( 0 ) );
	uchar* ptrS = (uchar*) imgShow.data;
	for ( int i=0; i<edgeChains.size(); ++i )
	{
		for ( int j=0; j<edgeChains[i].size(); ++j )
		{
			int loc = edgeChains[i][j].y * img.cols + edgeChains[i][j].x;
			ptrS[loc] = 255;
		}
	}
	imwrite("U:\\my_projs\\LineSegmentsDetection\\g_output\\cannyPF",imgShow);
}
