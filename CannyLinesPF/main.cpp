#include <stdio.h>
#include <fstream>
//#include "cv.h"
//#include "highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

// debug testing: add header according to the error info.
//#include <opencv2/imgcodecs.hpp>
//#include <opencv2/core/mat.hpp>
//#include <opencv2/imgcodecs.hpp>

//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/core/mat.hpp"
//#include "opencv2/imgcodecs.hpp"

// test header
//#include "opencv2/core/types.hpp"
//#include "opencv2/core/mat.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/opencv.hpp"
//#include "opencv2/highgui.hpp"

// relative path
#include "lib/CannyPF.h"
#include "lib/ChainFromEdgeMap.h"

using namespace cv;
using namespace std;

int main()
{
	string imgFile = "D:\\My_Data\\me_Projs\\Proj_MA\\CannyLines_PF4_CMake+cmake-gui\\data\\_origin.png";
	
	cv::Mat img = cv::imread(imgFile, 0);
	printf("size of imaga %zu", sizeof(img));

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
	cv::imwrite("D:\\My_Data\\me_Projs\\Proj_MA\\CannyLines_PF4_CMake+cmake-gui\\data\\cannyPF test1-simple.png",imgShow);
}
