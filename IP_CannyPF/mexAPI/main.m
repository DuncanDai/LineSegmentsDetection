img_rgb = imread('test1.png');
img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

[runTime_cpp, edgeLines] = mex_edgeDetecter(img);

