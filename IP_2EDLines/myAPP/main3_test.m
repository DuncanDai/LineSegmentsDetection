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
    fprintf('(in main3_test.m): the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
end 

clear left_border_label  right_border_label;

%% TODO: optimized hyperparameters
scale = 1;
resizeImageHeight = size(img_rgb, 1) / scale;
resizeImageWidth = size(img_rgb, 2) / scale;

angle_expect = 90;
angle_tolerance = 5;

windowWidth = 40;
windowStepSize = 10;
decision_criter = 'number';
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