// 
// 
// 
int main()
{
	string imgFile = "D:\\My_Data\\me_Projs\\Proj_MA\\CannyLines_PF4_CMake+cmake-gui\\data\\_origin.png";
	
    // 单通道
	cv::Mat img = cv::imread(imgFile, cv::IMREAD_GRAYSCALE);
	printf("size of imaga %zu", sizeof(img));

	// get edge Map by using canny filter
	CannyPF cannyer;
	cv::Mat edgeMap;
	float VMGradient = 70.0;
	cannyer.cannyPF( img, 3, VMGradient, edgeMap );

	// get edge chain
    // class object: chaniner
	ChainFromEdgeMap chainer;
	std::vector<std::vector<cv::Point> > edgeChains;
	chainer.run( img, edgeMap, edgeChains );

	// show  8bit single channel -> grayscale
    // imgShow is a cv::Mat data (not a function)
	cv::Mat imgShow( img.rows, img.cols, CV_8UC1, cv::Scalar( 0 ) );

    // 注意ptrS是一维向量：根据行优先的存储方式，调取边界点
	uchar* ptrS = (uchar*) imgShow.data;
	for ( int i=0; i<edgeChains.size(); ++i )
	{
		for ( int j=0; j<edgeChains[i].size(); ++j )
		{
			int loc = edgeChains[i][j].y * img.cols + edgeChains[i][j].x;
			ptrS[loc] = 255;  // choose white to show the edge
		}
	}
	cv::imwrite("D:\\My_Data\\me_Projs\\Proj_MA\\CannyLines_PF4_CMake+cmake-gui\\data\\cannyPF test1-simple.png",imgShow);
}


%% only for tesst
tmp = imread("U:/my_projs/_test/data/cboard.png");
tmp_gray = rgb2gray(tmp);  

figure(1), image(tmp_1);
figure(2), image(tmp_2);
figure(3), image(tmp_3);


R=35;
G = 8;
B=6;
R*0.299 + G*0.587 + B*0.114
