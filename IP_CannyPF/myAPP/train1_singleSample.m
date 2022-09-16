function [runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features] = train1_singleSample(img_rgb, save_img_path) %varargin
% 
% Inputs:
%   - img_rgb: color image
%   - varargin: a cell Array

% declare global variables in `trainHeader.m`
global GaussSize;
global VMGradient;

global angle_expect;
global angle_tolerance;
global scale;
global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;
global prior_mandrel_percent;

%% test: specific parameters
GaussSize = uint8(3);
VMGradient = 70.0;

angle_expect = pi/2;
angle_tolerance = 5/180*pi;
scale = 1;

windowWidth = 40;
windowStepSize = 10;
decision_criter = 'number';
prior_mandrel_percent = 1/3;

%%
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

resizeImageHeight = size(img_rgb, 1) / scale;
resizeImageWidth = size(img_rgb, 2) / scale;

[runTime, edgeMap, edgeChains] = mex_CannyPF(img, GaussSize, VMGradient);
edgeLines = compose_line_from_edgeChains(edgeChains);

ticId = tic;
[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
runTime_matlab = toc(ticId);

% Plot
img = uint8(img);
imshow(img, 'border', 'tight', 'initialmagnification', 100);
hold on
draw_lines(full_edges_filter_by_angle);
draw_borders(left_border_pos, right_border_pos, resizeImageHeight);   

% Output
f = getframe(gcf);
imwrite(f.cdata, save_img_path);

close;
end

