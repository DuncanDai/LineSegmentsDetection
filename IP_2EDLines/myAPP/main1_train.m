%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Note: pay attention to the following things
%   1 the initial variables
%       - FLAG_VALID = 0: only for valid process: flag is 1
%       - index: initial index of output_data
%   2 the path  (in 'main0_header.m': line 43)
%       - imgInputPath
%       - imgInputPath
%       - imgName
%       - imgOutputPath
% 
% Things you need to modify for training
%   1 initial hyperparameters (in 'main0_header.m': line 11)
%   2 index limit: set the limitation for index of output_data (in 'train1_singleSample.m': line 25)
%   3 plot and analyzing (in 'train1_singleSample.m': line 118)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% run script: 
clear; clc; close;
main0_header;

global is_plot is_output;
is_plot = 0; is_output = 0;

FLAG_VALID = 0;  % only for valid process: flag is 1
index = 1;

%% train single sample
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);


%% train single folder
train2_singleFolder(imgInputPath, folderName, imgOutputPath);


%% train all folders
t1 = datestr(now);
train3_folders(imgInputPath, imgOutputPath);
t2 = datestr(now);


%% save data
t = clock; % Get current time
% example: out_train_0922_1347.mat
fname = ['out_train_', ...
              num2str(t(2:3), '%02d'), '_', ...   % -month-day_
              num2str(t(4:5), '%02d'), '.mat']; % hour min


save_data_path = [imgOutputPath, filesep, folderName, filesep, fname]; mkdir([imgOutputPath, filesep, folderName]);
save(save_data_path, 'output_data');
clear PC_path  Pool_path  t  fname  save_data_path;