%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Note: pay attention to the following things
%   1 the initial variables
%       - FLAG_VALID = 1: only for valid process: flag is 1
%       - index: initial index of output_data
%   2 the path  (in 'main0_header.m': line 43)
%       - imgInputPath
%       - imgInputPath
%       - imgName
%       - imgOutputPath
% 
% Things you need to modify for validation
%   1 index limit: set the limitation for index of output_data (in 'train1_singleSample.m': line 25) 
%   2 hyperparameters optimization (in 'train1_singleSample.m': line 33)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% run script:
clear;
main0_header;

global is_plot is_save;
is_plot = 0; is_save = 0;

FLAG_VALID = 1; % only for valid process: flag is 1
index = 1;


%% valid single sample
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);

t1 = datestr(now);
[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);
t2 = datestr(now);


%% valid single folder
t1 = datestr(now);
train2_singleFolder(imgInputPath, folderName, imgOutputPath);
t2 = datestr(now);

load handel
sound(y,Fs)

%% valid all folders
t1 = datestr(now);
train3_folders(imgInputPath, imgOutputPath);
t2 = datestr(now);

load handel
sound(y,Fs)

%%% save data
addpath('./dataAnalyse');
output_data = select_data_with_label(output_data);

t = clock; % Get current time
%%% 1 original output_data (all records are with labels)
% example: out_valid_0922_1347.mat
fname = ['out_valid_', ...
              num2str(t(2:3), '%02d'), '_', ...   % -month-day_
              num2str(t(4:5), '%02d'), '.mat']; % hour min

save_data_path = [imgOutputPath, filesep, fname];  
save(save_data_path, 'output_data');

% %%% 2 select_sets_good
% fname = ['out_valid_', ...
%               num2str(t(2:3), '%02d'), '_', ...   % -month-day_
%               num2str(t(4:5), '%02d'), '_good.mat']; % hour min
% 
% output_data_good = select_sets_good(output_data);
% save_data_path = [imgOutputPath, filesep, folderName, filesep, fname];
% save(save_data_path, 'output_data_good');
% 
% 
% %%% 3 select_sets_bad
% fname = ['out_valid_', ...
%               num2str(t(2:3), '%02d'), '_', ...   % -month-day_
%               num2str(t(4:5), '%02d'), '_bad.mat']; % hour min
% 
% output_data_bad = select_sets_bad(output_data);
% save_data_path = [imgOutputPath, filesep, folderName, filesep, fname];
% save(save_data_path, 'output_data_bad');

clear PC_path  Pool_path  t  fname  save_data_path;