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

#include <stdio.h>
#include <fstream>

// #include "cv.h"
// #include "highgui.h"
#include "opencv2/opencv.hpp"
// #include "opencv2/highgui.hpp"
// #include "opencv2/imgproc/imgproc_c.h"

//#include "../lib/CannyLine.h"
#include "../lib/CannyLine.h"

using namespace std;
using namespace cv;

void run_edge_detecter(Mat& image, vector<Vec4f>& edgeLines) {
	CannyLine detector;
	vector< vector<float> > lines;
	detector.cannyLine(image, lines);

	// change std::vector< std::vector<float> > to vector<Vec4f> : 2D to 1D
	for (auto ele : lines) {
		edgeLines.push_back(Vec4f(ele[0], ele[1], ele[2], ele[3]));
	}
}