%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% step 0: run main0_header.m
% step 1: choose one of the follow three -> there is the related instructions in the function
%   1 main1_train.m for training
%   2 main2_valid.m for validation
%   3 main3_test.m for test
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% common header for differnet situations.
addpath('../helperFuncs');
addpath('../helperPlots');
addpath('../mexAPI');
addpath('./helperFuncs');

% Script: parser JSON to get the parameters.
% parser_JSON_hyperParams;  % '/myApp' need to be current workspace

% declare global variables in this `trainHeader.m` file
global scale;  scale = 1; % scale is not used in CannyPF -> keep it to 1 by hyperparameter tuning. 
global angle_expect;  angle_expect = pi/2;
global angle_tolerance;  angle_tolerance = 5/180*pi;

global resizeImageHeight; 
global resizeImageWidth; 
global windowWidth;  windowWidth = 40;
global windowStepSize;  windowStepSize = 10;
global decision_criter;   decision_criter = 'number'; % global only for single variable -> once declare: decision_criterion = 0 (decision_criterion is string cell array); 
global prior_mandrel_percent;  prior_mandrel_percent = 1/4; % the middle prior_mandrel_percent part is not into consideration

global FLAG_VALID; FLAG_VALID = 0;
global label_data
label_file = './mandrel_border_labels_manually.json';  % absolut path of label file
label_data = load_label(label_file);

global output_data;
global index; index = 1;  % index of output_data
global flag_quit; flag_quit = 0;
%%% create table 
OUTPUT_ELEMENTS = 2 + 15;   % 2 + 15 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent)
sz = [50000 OUTPUT_ELEMENTS];
varTypes = {'string', 'string', 'double', 'double', 'cell', 'double', 'double', 'double', 'double', 'double', ...
    'double', 'double', 'double', 'uint16', 'uint16', 'string', 'double'};  % by using class()
varNames = {'folderName', 'imgName', 'runTime_cpp', 'runTime_matlab', 'windows_features', 'left_border_pos', 'left_border_label', 'right_border_pos', 'right_border_label', 'metric_RMSE', ...
    'scale', 'angle_expect', 'angle_tolerance', 'windowWidth', 'windowStepSize', 'decision_criter', 'prior_mandrel_percent'};

% angle's unit is degree
output_data = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);

clear label_file  OUTPUT_ELEMENTS  sz  varTypes  varNames;
