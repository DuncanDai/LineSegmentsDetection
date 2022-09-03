%% load an image
img = imread('/Users/bschauer/Desktop/9gag/aLRxOb6_460s.jpg');
img = im2double(img);

figure('name','demo image');
subplot(1,2,1); imshow(img); title('original');

%% invoke C++.mex-code
ksize = 9;
sigma = 9;
out = opencv_matlab_mex(rgb2gray(img),ksize,sigma);

subplot(1,2,2); imshow(out); title('OpenCV blurred');