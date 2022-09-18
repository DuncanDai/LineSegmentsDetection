%% common header for differnet situations.
addpath('../helperFuncs');
addpath('../helperPlots');
addpath('../mexAPI');

% Script: parser JSON to get the parameters.
parser_JSON_hyperParams;  % '/myApp' need to be current workspace

% declare global variables in this `trainHeader.m` file
global GaussSize;
global VMGradient;

global angle_expect;
global angle_tolerance;
global scale;  % scale is not used in CannyPF -> keep it to 1 by hyperparameter tuning. 
global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;
global prior_mandrel_percent;
%% test folders
imgInputPath = 'U:\my_projs\_imgTest';
imgOutputPath = 'U:\my_projs\g_output';
train3_folders(imgInputPath, imgOutputPath);

%% test single folder
folderName = '2022-04-28_14-09-13';
imgInputPath = 'U:\my_projs\_imgTest';
imgOutputPath = 'U:\my_projs\g_output';
train2_singleFolder(folderName, imgInputPath, imgOutputPath);

%% test single image
img_rgb = imread('../Resources/_origin_rgb.png');
save_img_path = 'U:\my_projs\g_output\09-18.png';
[runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features] = train1_singleSample(img_rgb, save_img_path);