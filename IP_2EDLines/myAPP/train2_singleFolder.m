function train2_singleFolder(imgInputPath, folderName, imgOutputFolder)

% if we want to stop the train/valid/test process, use flag_quit
global flag_quit;

imgFoldertPath = [imgInputPath, filesep, folderName]; 
imgOutputFolder = [imgOutputFolder, filesep, folderName]; mkdir(imgOutputFolder);

imgSamples = dir(imgFoldertPath);
imgNumber = length(imgSamples)-2;  % the first two elements are `.` and `..`

%%% (outdated version: can be deleted): create cell array
% output_data = cell(imgNumber, OUTPUT_ELEMENTS); 
% output_data(:, 1) = {folderName};  % output_data is a cellArray.
% output_data{k-2, 2} = imgName;
% output_data(k-2, 3:end) = {...};


for n = 3:imgNumber+2
    imgName = imgSamples(n).name; 
    
    try
        img_rgb = imread([imgFoldertPath, filesep, imgName]);
    catch ME
        fprintf('(in train2_singleFolder.m): there was a problem while reading the image in %s, whose name is "%s"\n', imgFoldertPath, imgName);
        continue
    end 
    
    % keep the output name here: use it in debug modul to check the output values
    [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputFolder);
    if flag_quit  % set in 'main1_train.m' line 72
        return
    end
end
