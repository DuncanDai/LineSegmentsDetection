function train2_singleFolder(folderName, imgInputPath, imgOutputPath)
% for test: 
% imgInputPath = ['U:\my_projs\imgSamples', filesep, imgFolder]; 
% imgOutputPath = ['U:\my_projs\g_output', filesep, imgFolder]; mkdir(imgOutputPath);

imgFoldertPath = [imgInputPath, filesep, folderName]; 
imgOutputPath = [imgOutputPath, filesep, folderName]; mkdir(imgOutputPath);

imgSamples = dir(imgFoldertPath);
imgNumber = length(imgSamples)-2;  % the first two elements are `.` and `..`

output_data = cell(imgNumber, 11); % 11 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_pos, left_label, right_pos, right_label, metric, hyperparameters)
output_data(:, 1) = {folderName};  % output_data is a cellArray.

for k = 3:imgNumber+2
    imgName = imgSamples(k).name; output_data{k-2, 2} = imgName;
    img_save_path = [imgOutputPath, filesep, imgName(1:end-4), '.png'];
    
    try
        img_rgb = imread([imgFoldertPath, filesep, imgName]);
    catch ME
        fprintf('Reminder: there was a problem while reading the image in %s, whose name is "%s"\n', imgFoldertPath, imgName);
        continue
    end 
    
    %%% Adjustable: modify the outputs
    [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters] = train1_singleSample(img_rgb, folderName, imgName, img_save_path) ;
    %%% TODO Adjustable: if left_border_pos == 1
    output_data(k-2, 3:end) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters};
end

% save data
data_save_path = [imgOutputPath, filesep, 'output_data.mat'];
save(data_save_path, 'output_data');
