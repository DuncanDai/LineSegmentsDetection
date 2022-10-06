%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% step 0: run config_path.m
% step 1: choose one of the follow three -> there is the related instructions in the function
%   1 run_1train.m for training
%   2 run_2valid.m for validation
%   3 run_3test.m for test
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all; clc;

%% common header for differnet situations.
addpath('./');

addpath('../mexAPI');

addpath('../../helper0_train');
addpath('../../helper1_extractFeature');
addpath('../../helper2_calcRMSE');
addpath('../../helper3_postAnalyse');
addpath('../../helperPlots');

label_file = '../../g_dataset/mandrel_border_labels_manually.json';  % absolut path of label.json file

% Script: parser JSON to get the parameters.
% parser_JSON_hyperParams;  % '/myApp' need to be current workspace

% declare global variables in this main0_header.m` file
% Other scripts using follow global variables: 
%   - train1_singleSample.m
%   - helperFuncs/check_result.m
global scale; scale = 1.0; % scale is not used in CannyPF -> keep it to 1 by hyperparameter tuning. 
global angle_expect;  angle_expect = 90;
global angle_tolerance;  angle_tolerance = 25;

global resizeImageHeight; 
global resizeImageWidth; 
global windowWidth;  windowWidth = 34;
global windowStepSize;  windowStepSize = 1;
global decision_criter;   decision_criter = 'len*num'; % global only for single variable -> once declare: decision_criterion = 0 (decision_criterion is string cell array); 
global prior_excluded_middle_percent;  prior_excluded_middle_percent = 5/16; % the middle prior_mandrel_percent part is not into consideration

global FLAG_VALID; FLAG_VALID = 0;
global label_data;  label_data = load_label(label_file);
global is_labeled;  % whether the image is labeled or not, or even not exists in the label.json file

global output_data;
global index; index = 1;  % index of output_data
global flag_quit; flag_quit = 0;

%%% create table 
OUTPUT_ELEMENTS = 4 + 8 + 2 +8;   % 22 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent)
sz = [1000000 OUTPUT_ELEMENTS];
varTypes = {'string', 'string', 'single', 'single', ...
    'single', 'single', 'single', 'single', 'single', 'single', 'single', 'single', ...
    'single', 'single', ...
    'single', 'single', 'single', 'uint8', 'uint8', 'string', 'single', 'logical'};  % by using class() to check the type of variable
varNames = {'folderName', 'imgName', 'runTime_cpp', 'runTime_matlab', ...
    'left_window_start', 'left_pos1', 'left_pos2', 'left_border_label', 'right_window_start', 'right_pos1', 'right_pos2', 'right_border_label', ...
    'metric_RMSE_vertical', 'metric_RMSE_polyfit', ...
    'scale', 'angle_expect', 'angle_tolerance', 'windowWidth', 'windowStepSize', 'decision_criter', 'prior_excluded_middle_percent', 'is_labeled'};

% Notice: angle's unit is degree
output_data = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);

clear label_file  OUTPUT_ELEMENTS  sz  varTypes  varNames;

%% configure: different paths

%%% general path in PC
imgInputPath = 'D:/My_Data/me_Projs/Proj_MA/images';  folderName = '2022-04-28_14-09-13'; imgName = '0.png';
imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';


%%% path in portable HDD of pool 
% Notice: DHH in disk D:\
imgInputPath = 'D:/dataset_valid'; folderName = '2022-04-28_13-30-38';  imgName = '21750336000.png';
imgOutputPath = 'D:/g_output';

%% path in portable HDD of PC
imgInputPath = 'E:/dataset_valid'; folderName = '2022-04-28_13-30-38';  imgName = '21750336000.png';
imgOutputPath = 'E:/g_output';


%% check: whether the image has labels
try
    [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);  % image name with .png
    fprintf('Result: the border labels of the image "%s" in folder "%s" are (%d, %d)\n', imgName, folderName, left_border_label, right_border_label);
catch ME
    fprintf('(in main1_train.m): the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
end 

clear left_border_label  right_border_label;
