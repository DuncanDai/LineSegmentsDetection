function [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path) 
% 
% Inputs:
%   - img_rgb: output of imshow(imgFile)
%   - save_img_path
%   - varargin: a cell Array

% declare global variables in `trainHeader.m`
global GaussSize;
global VMGradient;

global scale;
global angle_expect;
global angle_tolerance;

global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;
global prior_mandrel_percent;

global label_data
%% test: specific parameters
% GaussSize = uint8(3);
% VMGradient = 70.0;
% 
% scale = 1;
% angle_expect = pi/2;
% angle_tolerance = 5/180*pi;
% 
% windowWidth = 40;
% windowStepSize = 10;
% decision_criter = 'number';
% prior_mandrel_percent = 1/3;

%% run function
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

resizeImageHeight = size(img_rgb, 1) / scale;
resizeImageWidth = size(img_rgb, 2) / scale;

[runTime_cpp, edgeMap, edgeChains] = mex_CannyPF(img, GaussSize, VMGradient);
edgeLines = compose_line_from_edgeChains(edgeChains);

ticId = tic;
[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
runTime_matlab = toc(ticId);

%% calculate the output data
% 1 runTime_c, runTime_matlab  ->  ok!
% 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
% 3 left_border_pos, right_border_pos ->  ok!
% left_border_label, right_border_label -> metric: MRSE

%%% DINGGEN excellent: this combines the training and validation processes together. 
% for training(there is no label) -> but still get the wanted output data
try
    [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
catch ME
    fprintf('Reminder: the image "%s" in folder  %s has no label data!!!\n', imgName, folderName);
    left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
    right_border_label = 0;
end 

metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
% 4 Hyperparameters: use a struct Array
% hyper_parameters = struct('scale', scale, 'angle_expect', angle_expect, 'angle_tolerance', angle_tolerance, ...
%                             'windowWidth', windowWidth, 'windowStepSize', windowStepSize, 'decision_criter', decision_criter, ...
%                             'prior_mandrel_percent', prior_mandrel_percent);

%% plot and output
% during analying the output_data: stop to plot and save the image
% Plot

% img = uint8(img);
% imshow(img, 'border', 'tight', 'initialmagnification', 100);
% hold on
% draw_lines(full_edges_filter_by_angle);
% draw_borders(left_border_pos, right_border_pos, resizeImageHeight);   

% Output

% f = getframe(gcf);
% imwrite(f.cdata, save_img_path);

close;
end

