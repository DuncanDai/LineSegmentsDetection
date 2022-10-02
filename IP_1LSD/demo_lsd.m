img_rgb = imread('./Resources/test.png');
img_gray = rgb2gray(img_rgb);  

[runTime_cpp, edgeLines] = mex_edgeDetecter(img_gray);

%%
addpath('./helperPlots');

imshow(img_gray);
hold on;
draw_edgeLines(edgeLines);