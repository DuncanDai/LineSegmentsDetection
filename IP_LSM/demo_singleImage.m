clear;
close all;
clc;

% addpath(genpath(pwd));
addpath('display\');
addpath('LSM\');
addpath('lsd_1.6\');


%% ****THRESHOLD AND PARAMETER SETTING***
xi_s=.05;   % spatial proximity threshold
tau_theta=pi/12; % angular proximity threshold

img_origin=imread('U:\my_projs\LineSegmentsDetection\LSM\Images\chainlink.png');
img=rgb2gray(img_origin);
img=double(img);

% version lsd_1.6
ticId = tic;
[out_lines, num_lines]=lsd_mexFunc(img/max(img(:))*255, 1.0);
toc(ticId)

% only the first 5 values needed
D = out_lines(:, 1:5);
[L]=mergeLines(D,tau_theta,xi_s);
toc(ticId)
display(strcat(int2str(size(L,1)),' merged line segments'));
imgD=display_image( D,img);
imgL=display_image( L,img);
img = [imgD imgL];

display('Total time');
imshow(img);

