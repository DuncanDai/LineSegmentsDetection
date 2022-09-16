%% common header for differnet situations.
addpath('../helperFuncs');
addpath('../helperPlots');
addpath('../mexAPI');

% Script: parser JSON to get the parameters.
parser_JSON_hyperParams;

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
%% test
imgInputPath = 'U:\my_projs\_imgTest';
imgOutputPath = 'U:\my_projs\g_output';
train3_folders(imgInputPath, imgOutputPath);