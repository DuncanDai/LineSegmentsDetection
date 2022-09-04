addpath('./mexfile');
addpath('./include');
addpath('./source');
addpath('U:/my_apps/opencv/build/x64/vc15/lib');
addpath('U:/my_apps/opencv/build/include')

%% load an image
img = imread('./data/_origin.png');
% subplot(1,2,1); imshow(img); title('original');
% img = im2double(img);
GaussSize = 3;
VMGradient = 70.0;
[edgeMap, edgeChains] = cannyPF_mex(img, GaussSize, VMGradient);

figure('name','demo image');
subplot(1,2,1); imshow(img); title('original');
subplot(1,2,2); imshow(edgeMap); title('OpenCV blurred');