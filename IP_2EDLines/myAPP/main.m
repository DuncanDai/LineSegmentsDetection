%% common header for differnet situations.
addpath('../helperFuncs');
addpath('../helperPlots');
addpath('../mexAPI');
addpath('./helperFuncs');

% Script: parser JSON to get the parameters.
% parser_JSON_hyperParams;  % '/myApp' need to be current workspace

% declare global variables in this `trainHeader.m` file
global scale;  % scale is not used in CannyPF -> keep it to 1 by hyperparameter tuning. 
global angle_expect;
global angle_tolerance;

global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;  % global only for single variable -> once declare: decision_criterion = 0 (decision_criterion is string cell array); 
global prior_mandrel_percent;

global FLAG_VALID; FLAG_VALID = 0;
global label_data
label_file = 'U:\my_projs\LineSegmentsDetection\dataset\mandrel_border_labels_manually.json';  % absolut path of label file
label_data = load_label(label_file);
%% valid folders
FLAG_VALID = 1;
valid3_folders;

%% valid single folder
FLAG_VALID = 1;
valid2_singleFolder;

%% valid single sample
FLAG_VALID = 1;
valid1_singleSample;

%% train folders
imgInputPath = 'U:\my_projs\imgSamplesSubTest';
imgOutputPath = 'U:\my_projs\g_output';
train3_folders(imgInputPath, imgOutputPath);

%% train single folder
imgInputPath = 'U:\my_projs\imgSamplesSubTest';  folderName = '2022-04-28_14-09-13';
imgOutputPath = 'U:\my_projs\g_output';

train2_singleFolder(imgInputPath, folderName, imgOutputPath);

%% train single sample
imgInputPath = 'U:\my_projs\imgSamplesSubTest'; folderName = '2022-04-28_14-09-13'; imgName = '0.png';
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
save_img_path = 'U:\my_projs\g_output\train_single.png';

% [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);
[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);