#include <stdio.h>
#include <fstream>

// #include "cv.h"
// #include "highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"

#include "CannyLine.h"

using namespace cv;
using namespace std;


void main()
{	
	// use absolute path
	string imgFile="C:\\Users\\dinggen\\Downloads\\cannylinesV3\\data\\_origin_rgb.png";
	cv::Mat img = imread( imgFile, 0 );

	CannyLine detector;
	std::vector<std::vector<float> > lines;
	detector.cannyLine( img, lines );

	// show
	cv::Mat imgShow( img.rows, img.cols, CV_8UC3, cv::Scalar( 255, 255, 255 ) );
	for ( int m=0; m<lines.size(); ++m )
	{
		cv::line( imgShow, cv::Point( lines[m][0], lines[m][1] ), cv::Point( lines[m][2], lines[m][3] ), cv::Scalar(0,0,0), 1, CV_AA );
	}
	namedWindow("cannylinesV3", WINDOW_NORMAL);
	imshow("cannylinesV3", imgShow);
	imwrite("C:\\Users\\dinggen\\Downloads\\cannylinesV3\\data\\test.jpg",imgShow);
	cv::waitKey(0);
}