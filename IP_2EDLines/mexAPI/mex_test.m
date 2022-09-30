img_rgb = imread('../Resources/test.png');
img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

[runTime_cpp, edgeLines] = mex_edgeDetecter(img);

%%
addpath('../helperPlots');

imshow(img_gray);
hold on;
draw_lines(edgeLines);