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
clear; clc; close;
main0_header;

FLAG_VALID = 1; % only for valid process: flag is 1
index = 1;
%% configure: different paths
%%% general path in Pool
imgInputPath = 'U:/my_projs/imgSamplesSubTest';  folderName = '2022-04-28_14-09-13'; imgName = '0.png';
imgOutputPath = 'U:/my_projs/g_output';


%%% general path in PC
imgInputPath = 'D:/My_Data/me_Projs/Proj_MA/images';  folderName = '2022-04-28_14-09-13'; imgName = '0.png';
imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';


%%% path in portable HDD
imgInputPath = 'E:\dataset_valid'; folderName = '2022-04-28_13-30-38';  imgName = '21750336000.png';
imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';


%%% check: whether the image has labels
try
    [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);  % image name with .png
    fprintf('Result: the border labels are (%d, %d)\n', left_border_label, right_border_label);
catch ME
    fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
end 

clear left_border_label  right_border_label;

%% valid single sample
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);

t1 = datestr(now);
[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);
t2 = datestr(now);


%% valid single folder
t1 = datestr(now);
train2_singleFolder(imgInputPath, folderName, imgOutputPath);
t2 = datestr(now);


%% valid all folders
t1 = datestr(now);
valid3_folders;
t2 = datestr(now);


%% save data
t = clock; % Get current time
% example: output_data_20220922_1347.mat
fname = ['output_data_', ...
              num2str(t(1:1), '%04d'), ...  % Year
              num2str(t(2:3), '%02d'), '_', ...   % -month-day_
              num2str(t(4:5), '%02d'), '.mat']; % hour min


save_data_path = [imgOutputPath, filesep, folderName, filesep, fname];
save(save_data_path, 'output_data');
clear PC_path  Pool_path  t  fname  save_data_path;