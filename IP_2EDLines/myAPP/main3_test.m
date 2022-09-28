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
% Things you need to modify for testing
%   1 set the optimized hyperparameters (in line 25)
%   2 index limit: set the limitation for index of output_data (in 'train1_singleSample.m': line 25)
%   3 plot and analyzing (in 'train1_singleSample.m': line 118)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% run script: 
clear; clc; close;
main0_header;

FLAG_VALID = 0;  % only for valid process: flag is 1
index = 1;


%% TODO: optimized hyperparameters
scale = 1;
resizeImageHeight = size(img_rgb, 1) / scale;
resizeImageWidth = size(img_rgb, 2) / scale;

angle_expect = 90;
angle_tolerance = 5;

windowWidth = 40;
windowStepSize = 10;
decision_criter = 'num';
prior_mandrel_percent = 1/3;

%% test all folders
% TODO: imgInputPath (imgOutputPath is determained according to the platform: Pool or PC)
imgInputPath = 'E:\dataset_test'; % portable HDD or network driver


t1 = datestr(now);
train3_folders(imgInputPath, imgOutputPath);
t2 = datestr(now);


%% save data
t = clock; % Get current time
% example: out_test_0922_1347.mat
fname = ['out_test_', ...
              num2str(t(2:3), '%02d'), '_', ...   % -month-day_
              num2str(t(4:5), '%02d'), '.mat']; % hour min


save_data_path = [imgOutputPath, filesep, folderName, filesep, fname];
save(save_data_path, 'output_data');
clear PC_path  Pool_path  t  fname  save_data_path;