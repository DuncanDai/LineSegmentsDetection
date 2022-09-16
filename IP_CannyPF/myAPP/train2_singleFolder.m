function train2_singleFolder(imgFolder, imgInputPath, imgOutputPath)
% for test: 
% imgInputPath = ['U:\my_projs\imgSamples', filesep, imgFolder]; 
% imgOutputPath = ['U:\my_projs\g_output', filesep, imgFolder]; mkdir(imgOutputPath);

imgInputPath = [imgInputPath, filesep, imgFolder]; 
imgOutputPath = [imgOutputPath, filesep, imgFolder]; mkdir(imgOutputPath);

imgSamples = dir(imgInputPath);
imgNumber = length(imgSamples)-2;  % the first two elements are `.` and `..`

output_data = cell(imgNumber, 9);
output_data(:, 1) = {imgFolder};

for k = 3:imgNumber+2
    imgName = imgSamples(k).name;
    output_data{k-2, 2} = imgName;
    save_img_path = [imgOutputPath, filesep, imgName(1:end-4), '.png'];
    
    try
        img_rgb = imread([imgInputPath, filesep, imgName]);
    catch ME
        fprintf('Reminder: there was a problem while reading the #%d image, whose name is "%s"\n', k-2, imgName);
        continue
    end 
    
    
    [runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features] = train1_singleSample(img_rgb, save_img_path);
    output_data(k-2, 3:end) = {runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features};
end

% save data
save_data_path = [imgOutputPath, filesep, 'outputData.mat'];
save(save_data_path, 'output_data');
