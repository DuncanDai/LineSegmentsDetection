addpath('./mexAPI');
% addpath('./include');
% addpath('./source');
% addpath('U:/my_apps/opencv/build/x64/vc15/lib');
% addpath('U:/my_apps/opencv/build/include')

%% test: demo for only one image
imgPath = './Resources/_origin_gray.png';
img = imread(imgPath);
img = im2double(img);
GaussSize = uint8(3);
VMGradient = 70.0;

[edgeMap, edgeChains] = mex_CannyPF(img, GaussSize, VMGradient);

figure('name','demo of CannyPF');
subplot(1,2,1); imshow(img); title('original');
subplot(1,2,2); imshow(edgeMap); title('CannyPF edge detecter');