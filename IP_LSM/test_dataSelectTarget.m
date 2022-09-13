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
addpath('lsm\');
addpath('mexAPI\lsd_1.6\');


%****THRESHOLD AND PARAMETER SETTING***%
xi_s=.05;   % spatial proximity threshold
tau_theta=pi/12; % angular proximity threshold

I=imread('U:\my_projs\LineSegmentsDetection\IP_LSM\Resources\chainlink.png');
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
imgPath = ['U:\my_projs\imgSamples', filesep, '2022-04-28_14-02-34'];

imgSamples = dir(imgPath);
for k = 3:length(imgSamples)
    try
        img_origin = imread([imgPath, filesep, imgSamples(k).name]);
    catch ME
        fprintf('There was a problem reading file #%d, "%s"\n', k, imgSamples(k).name);
        continue
    end 
    
    img_gray = rgb2gray(img_origin);
    img_gray = double(img_gray);
    % 1/16 size to the original image
%     img = imresize(img, [round(size(img,1)/4), round(size(img,2)/4)]);
    
    ticId = tic;
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % mrows = size(I,1);
    % ncols = size(I,2);

    % version lsd_1.5
    % D=lsd_mexFunc(I/max(I(:))*255, 1.0);

    % version lsd_1.6
    % Arguments: (image, scale)
    [output_lines, num_lines]=mex_lsd(img_gray/max(img_gray(:))*255, 1.0);  % standard to [0, 1]
    toc(ticId)
    % only the first 5 values needed
    D = output_lines(:, 1:5);
    [L]=mergeLines(D,tau_theta,xi_s);
    toc(ticId)
    display(strcat(int2str(size(L,1)),' merged line segments'));
    
    img_uint  = uint8(img_gray);
    figD = figure(1); 
    imshow(img_uint);
    hold on; axis normal;
    
    for i = 1:num_lines
        x1 = D(i, 1);
        y1 = D(i, 2);
        x2 = D(i, 3);
        y2 = D(i, 4);
        line([x1 x2], [y1 y2],'Color','g', 'LineWidth', 1.5); 
    end
    imgD = frame2im(getframe(figD));
    hold off;close;
    
    
    figL = figure(2); 
    imshow(img_uint);
    hold on; axis normal;
    
    num_merged_lines = size(L, 1);
    for i = 1:num_merged_lines
        x1 = L(i, 1);
        y1 = L(i, 2);
        x2 = L(i, 3);
        y2 = L(i, 4);
        line([x1 x2], [y1 y2],'Color','g', 'LineWidth', 1.5); 
    end
    imgL = frame2im(getframe(figL));
    hold off;close;
    
%     imgD = display_image(D, img);
%     imgL = display_image(L, img);

%     imwrite([imgD imgL],'U:\my_projs\LineSegmentsDetection\g_output\result_chainlink.png');
    % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    img = [imgD imgL];
    display('Total time');
    
    fig = figure(3);
    imshow(img);
    imwrite(img, ['U:\my_projs\g_output', filesep, imgSamples(k).name(1:end-4), '.png']);
%     saveas(fig, ['U:\my_projs\LineSegmentsDetection\g_output', filesep, imgSamples(k).name(1:end-4), '.png']);
    close;
end
