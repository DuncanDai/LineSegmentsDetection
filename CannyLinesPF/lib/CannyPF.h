#ifndef _CANNY_PY_H_
#define _CANNY_PY_H_
#pragma once

#include "opencv2/opencv.hpp"
#include <vector>

// test header
//#include "opencv2/core/types.hpp"
//#include "opencv2/core/mat.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include "opencv2/imgproc.hpp"
//#include "opencv2/opencv.hpp"
//#include "opencv2/highgui.hpp"

class CannyPF
{
public:
	CannyPF(void);
	~CannyPF(void);

	void cannyPF( cv::Mat &image, int gausHalfSize, float VMGradient, cv::Mat &edgeMap );

};
#endif //_CANNY_PY_H_
