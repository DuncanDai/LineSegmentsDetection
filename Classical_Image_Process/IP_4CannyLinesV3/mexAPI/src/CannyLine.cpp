#include "../lib/CannyLine.h"
#include "../lib/MetaLine.h"

CannyLine::CannyLine(void)
{
}

CannyLine::~CannyLine(void)
{
}

void CannyLine::cannyLine(cv::Mat &image,std::vector<std::vector<float> > &lines)
{
	MetaLine detector;
	float gausSigma=1.0;
	int gausHalfSize=1;
	detector.MetaLineDetection(image,gausSigma,gausHalfSize,lines);
}