% folderName: not entire path -> Just the name of folder: as a field name
% imgName: with the suffix .png 
imgInputPath = 'U:\my_projs\imgSamplesSubTest'; folderName = '2022-04-28_14-09-13'; imgName = '0.png';
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
save_img_path  = 'U:\my_projs\g_output\test_valid_singleSample.png';

%% hyperparameters gridSerach
OUTPUT_ELEMENTS = 2 + 15;  % see train2_singleFolder.m

%%% create table
sz = [3000 OUTPUT_ELEMENTS];
varTypes = {'string', 'string', 'double', 'double', 'cell', 'double', 'double', 'double', 'double', 'double', ...
    'double', 'double', 'double', 'uint16', 'uint16', 'string', 'double'};  % by using class()
varNames = {'folderName', 'imgName', 'runTime_cpp', 'runTime_matlab', 'windows_features', 'left_border_pos', 'left_border_label', 'right_border_pos', 'right_border_label', 'metric_RMSE', ...
    'scale', 'angle_expect', 'angle_tolerance', 'windowWidth', 'windowStepSize', 'decision_criter', 'prior_mandrel_percent'};
output_data = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);

output_data(:, 1) = {folderName};
output_data(:, 2) = {imgName};

t1 = datestr(now);

k = 1;
for scale = 1  % 5 values -> stepsize: 0.2
    for windowWidth = 2 : 4 : 100  % 20 values -> stepsize: 4 -> up to 80
        for windowStepSize = 1 : 3 : 20  % 5 values -> stepsize: 3  -> up to 15
            for angle_tolerance = (.1 : .5 : 10) * pi /180  % unit is rad   20 values -> stepsize: 0.5  -> up to 10
                for i = 1 : decision_criterion_size   % 3 values
                    decision_criter = decision_criterion{i, 1};  
                    %%% IMPORTANT: here put the training/validation process
%                     [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters] = ...
%                         train1_singleSample(img_rgb, folderName, imgName, save_img_path); 
%                     output_data(k, :) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters};
                    [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);
                    output_data(k, 3:end) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent};
                    k = k + 1;
%                     if k == 600
%                         save_data_path = ['U:\my_projs\g_output', filesep, 'output_data_validSingleSample.mat'];
%                         save(save_data_path, 'output_data');
%                         t2 = datestr(now)
%                         return
%                     end
                end
            end
        end
    end
end

% save data
save_data_path = ['U:\my_projs\g_output', filesep, 'output_data_validSingleSample.mat'];
save(save_data_path, 'output_data');
t2 = datestr(now)