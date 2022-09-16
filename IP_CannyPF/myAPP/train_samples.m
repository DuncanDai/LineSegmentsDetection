addpath('../helperFuncs');
addpath('../helperPlots');
addpath('../mexAPI');

parser_JSON_hyperParams;
global GaussSize;
global VMGradient;

global angle_expect;
global angle_tolerance;
global scale;
global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;
global prior_mandrel_percent;


%% test:  samples -> 3 folders   2022-04-28_14-02-34  2022-04-28_15-39-22    2022-04-28_16-21-50
for scale = scale_start : scale_step : scale_end
%     resizeImageHeight = size(img_rgb, 1) / scale;
%     resizeImageWidth = size(img_rgb, 2) / scale;
    for windowWidth = windowWidth_start : windowWidth_step : windowWidth_end
        for windowStepSize = windowStepSize_start : windowStepSize_step : windowStepSize_end
            for angle_tolerance = angle_tolerance_start : angle_tolerance_step : angle_tolerance_end
                for i = 1 : decision_criterion_size
                    decision_criter = decision_criterion{i, 1};
                end
            end
        end
    end
end

%% specific parameters
GaussSize = uint8(3);
VMGradient = 70.0;

angle_expect = pi/2;
angle_tolerance = 5/180*pi;
scale = 1;

windowWidth = 40;
windowStepSize = 10;
decision_criter = 'number';
prior_mandrel_percent = 1/3;

%%
output_data_sum = cell(3,1);  % 3 folders

imgFolder = '2022-04-28_16-21-50'; 
imgInputPath = ['U:\my_projs\imgSamples', filesep, imgFolder]; 
imgOutputPath = ['U:\my_projs\g_output', filesep, imgFolder]; mkdir(imgOutputPath);

imgSamples = dir(imgInputPath);
imgNumber = length(imgSamples)-2;  % the first two elements are `.` and `..`
output_data = cell(imgNumber, 9);

output_data(:, 1) = {imgFolder};
for k = 3:imgNumber+2
    imgName = imgSamples(k).name;
    try
        img_rgb = imread([imgInputPath, filesep, imgName]);
    catch ME
        fprintf('Reminder: there was a problem reading file #%d, "%s"\n', k, imgName);
        continue
    end 
    
    resizeImageHeight = size(img_rgb, 1) / scale;
    resizeImageWidth = size(img_rgb, 2) / scale;  
    
    output_data{k-2, 2} = imgName;
    save_path_img = [imgOutputPath, filesep, imgName(1:end-4), '.png'];
    [runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features] = train_single_sample(img_rgb, save_path_img);
%     output_data{k-2, 3:end} = [runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features];
    output_data(k-2, 3:end) = {runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features};
end

% save data
save_path_data = [imgOutputPath, filesep, 'outputData.mat'];
save(save_path_data, 'output_data');
