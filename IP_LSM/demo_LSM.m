% This file is part of LSM.
% 
% LSM is free software: you can redistribute it and/or modify
% it under the terms of the GNU v3.0 General Public License as published by
% the Free Software Foundation.
% 
% LSM is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details
% <http://www.gnu.org/licenses/>.

clear;
close all;
clc;

% addpath(genpath(pwd));
addpath('display\');
addpath('LSM\');
addpath('lsd_1.6\');


%****THRESHOLD AND PARAMETER SETTING***%
xi_s=.05;   % spatial proximity threshold
tau_theta=pi/12; % angular proximity threshold

I=imread('U:\my_projs\LineSegmentsDetection\LSM\Imgs\chainlink.png');
I=rgb2gray(I);
I=double(I);

%     % mrows = size(I,1);
%     % ncols = size(I,2);
% 
%     % version lsd_1.5
%     % D=lsd_mexFunc(I/max(I(:))*255, 1.0);
% 
%     % version lsd_1.6
%     [D, num_lines]=lsd_mexFunc(I/max(I(:))*255, 1.0);
% 
%     % only the first 5 values needed
%     D = D(:, 1:5);
%     [L]=mergeLines(D,tau_theta,xi_s);
%     display(strcat(int2str(size(L,1)),' merged line segments'));
%     imgD=display_image( D,I);
%     imgL=display_image( L,I);
% 
%     imwrite([imgD imgL],'U:\my_projs\LineSegmentsDetection\g_output\result_chainlink.png');

%% 2022-04-28_14-02-34  2022-04-28_15-39-22    2022-04-28_16-21-50
imgPath = ['U:\my_projs\LineSegmentsDetection\imgSamples', filesep, '2022-04-28_16-21-50'];

imgSamples = dir(imgPath);
for k = 3:length(imgSamples)
    try
        img = imread([imgPath, filesep, imgSamples(k).name]);
    catch ME
        fprintf('There was a problem reading file #%d, "%s"\n', k, imgSamples(k).name);
        continue
    end 
    
    img = rgb2gray(img);
    img = double(img);
    % 1/16 size to the original image
%     img = imresize(img, [round(size(img,1)/4), round(size(img,2)/4)]);
    
    ticId = tic;
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % mrows = size(I,1);
    % ncols = size(I,2);

    % version lsd_1.5
    % D=lsd_mexFunc(I/max(I(:))*255, 1.0);

    % version lsd_1.6
    [out_lines, num_lines]=lsd_mexFunc(img/max(img(:))*255, 1.0);
    toc(ticId)
    % only the first 5 values needed
    D = out_lines(:, 1:5);
    [L]=mergeLines(D,tau_theta,xi_s);
    toc(ticId)
    display(strcat(int2str(size(L,1)),' merged line segments'));
    imgD=display_image( D,img);
    imgL=display_image( L,img);

%     imwrite([imgD imgL],'U:\my_projs\LineSegmentsDetection\g_output\result_chainlink.png');
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    img = [imgD imgL];
    display('Total time');
    
    fig = figure;
    imshow(img);
    hold all

%     imwrite(fig, ['..\g_output', filesep, imgSamples(k).name(1:end-4), filesep, '_1.png']);
    saveas(fig, ['U:\my_projs\LineSegmentsDetection\g_output', filesep, imgSamples(k).name(1:end-4), '.png']);
end
