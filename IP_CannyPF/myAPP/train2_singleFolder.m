function train2_singleFolder(imgInputPath, folderName, imgOutputPath)
% for test: 
% imgInputPath = ['U:\my_projs\imgSamples', filesep, imgFolder]; 
% imgOutputPath = ['U:\my_projs\g_output', filesep, imgFolder]; mkdir(imgOutputPath);

% 11 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_pos, left_label, right_pos, right_label, metric, hyperparameters)
% 15 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_pos, left_label, right_pos, right_label, metric, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent)
OUTPUT_ELEMENTS = 2 + 15;

imgFoldertPath = [imgInputPath, filesep, folderName]; 
imgOutputPath = [imgOutputPath, filesep, folderName]; mkdir(imgOutputPath);

imgSamples = dir(imgFoldertPath);
imgNumber = length(imgSamples)-2;  % the first two elements are `.` and `..`

%%% create cell array
% output_data = cell(imgNumber, OUTPUT_ELEMENTS); 
% output_data(:, 1) = {folderName};  % output_data is a cellArray.
% output_data{k-2, 2} = imgName;
% output_data(k-2, 3:end) = {...};

%%% create table
sz = [imgNumber OUTPUT_ELEMENTS];
varTypes = {'string', 'string', 'double', 'double', 'double', 'double', 'double', 'double', 'double', 'double', ...
    'double', 'double', 'double', 'uint16', 'uint16', 'string', 'double'};  % by using class()
varNames = {"folderName", "imgName", "runTime_cpp", "runTime_matlab", "windows_features", "left_border_pos", "left_border_label", "right_border_pos", "right_border_label", "metric_RMSE", ...
    "scale", "angle_expect", "angle_tolerance", "windowWidth", "windowStepSize", "decision_criter", "prior_mandrel_percent"};
output_data = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);
output_data(:, 1) = {folderName};


for k = 3:imgNumber+2
    imgName = imgSamples(k).name; output_data{k-2, 2} = imgName;
    save_img_path = [imgOutputPath, filesep, imgName(1:end-4), '.png'];
    
    try
        img_rgb = imread([imgFoldertPath, filesep, imgName]);
    catch ME
        fprintf('Reminder: there was a problem while reading the image in %s, whose name is "%s"\n', imgFoldertPath, imgName);
        continue
    end 
    
    %%% Adjustable: modify the outputs
%     [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters] = train1_singleSample(img_rgb, folderName, imgName, save_img_path) ;
%     output_data(k-2, 3:end) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters};
    [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path);
    output_data(k-2, 3:end) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent};
    
    %%% TODO Adjustable: if left_border_pos == 1
    
    
end

% save data
save_data_path = [imgOutputPath, filesep, 'output_data.mat'];
save(save_data_path, 'output_data');