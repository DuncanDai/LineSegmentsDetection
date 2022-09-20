% folderName: not entire path -> Just the name of folder: as a field name
% imgName: with the suffix .png 
imgInputPath = 'U:\my_projs\imgSamplesSubTest'; folderName = '2022-04-28_14-09-13'; imgName = '0.png';
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
save_img_path  = 'U:\my_projs\g_output\test_valid_singleSample.png';

%% hyperparameters gridSerach
global output_data;
OUTPUT_ELEMENTS = 2 + 15;  % see train2_singleFolder.m

%%% create table
sz = [500000 OUTPUT_ELEMENTS];
varTypes = {'string', 'string', 'double', 'double', 'cell', 'double', 'double', 'double', 'double', 'double', ...
    'double', 'double', 'double', 'uint16', 'uint16', 'string', 'double'};  % by using class()
varNames = {'folderName', 'imgName', 'runTime_cpp', 'runTime_matlab', 'windows_features', 'left_border_pos', 'left_border_label', 'right_border_pos', 'right_border_label', 'metric_RMSE', ...
    'scale', 'angle_expect', 'angle_tolerance', 'windowWidth', 'windowStepSize', 'decision_criter', 'prior_mandrel_percent'};
output_data = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);

output_data(:, 1) = {folderName};
output_data(:, 2) = {imgName};


t1 = datestr(now);

[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);


% save data
save_data_path = ['U:\my_projs\g_output', filesep, 'output_data_validSingleSample.mat'];
save(save_data_path, 'output_data');
t2 = datestr(now)