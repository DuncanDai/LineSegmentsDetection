%% choose the data to output
config_path;
global is_plot is_save;

%%% NOTICE!!! optional settings
is_plot = 1; is_save = 1;  
FLAG_VALID = 0; 

%%% input the row you want to check
% sub_test_result_0_20 -> select 20 samples
% sub_test_result_20_50 -> select 20 samples

% sub_test_result_50_200 = select_data_through_RMSE(output_data, 50, 200);
% sub_test_result_200_500 = select_data_through_RMSE(output_data, 200, 500);
% sub_test_result_500_2000 = select_data_through_RMSE(output_data, 500, 2000);
% sub_test_result_over_2000 = select_data_through_RMSE(output_data, 2000, 3000);
output_buffer = sub_test_result_0_20; % output_data1 works like a buffer
output = output_buffer;  


%%% plot
t = clock; % Get current time
date_folder = ['check_result_', ...
          num2str(t(2:3), '%02d')];   % -month-day

%%% in PC valid
% imgInputPath = 'E:\dataset_valid';  imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';
% imgOutputPath = [imgOutputPath, filesep, date_folder];    % mkdir(imgOutputPath);

%%% in pool-206 valid
% imgInputPath = 'D:/dataset_valid';  imgOutputPath = 'D:/g_output';
% imgOutputPath = [imgOutputPath, filesep, date_folder];     mkdir(imgOutputPath);

%%% in pool-206 test
imgInputPath = 'D:/dataset_valid';  imgOutputPath = 'D:/g_output';
imgOutputPath = [imgOutputPath, filesep, date_folder];     mkdir(imgOutputPath);

%% Method 1: use the hyper-parameters in table
%%% change the "row" you want to check
sz = size(output, 1);
interval = 1;
if sz > 100
    interval = floor(sz/24);  % 25 samples includes the 1st one.
end

for row = 1:interval:sz
    folderName = output.folderName(row);  folderName = char(folderName);
    imgName = output.imgName(row);  imgName = char(imgName);
    if exist([imgOutputPath, filesep, folderName, 'sep', imgName],'file')
        fprintf("\nalready existed...\n")
        continue
    else
        scale = output.scale(row); 
        
        angle_expect = output.angle_expect(row) ;
        angle_tolerance = output.angle_tolerance(row);   %angle_tolerance = 9;
        windowWidth = output.windowWidth(row); windowWidth = double(windowWidth);
        windowStepSize = output.windowStepSize(row); windowStepSize = double(windowStepSize);
        decision_criter = output.decision_criter(row); decision_criter = char(decision_criter);   %decision_criter = 'length*number';
        prior_excluded_middle_percent = output.prior_excluded_middle_percent(row);   prior_excluded_middle_percent = 5/16;
        
        img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
%         resizeImageHeight = size(img_rgb, 1) / scale;  resizeImageWidth = size(img_rgb, 2) / scale;
        % Use default hyperparameter.
        % If you want to check it in the hyperparameter set in output_data -> parser the table like above
        train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);
    end
end

clear t row;
%% Method 2: use the single optimized hyper-parameters (in config_path.m)
%%% change the "row" you want to check
sz = size(output, 1);
% for row = 29
for row = 1:100:sz
    folderName = output.folderName(row);  folderName = char(folderName);
    imgName = output.imgName(row);  imgName = char(imgName);
    if exist([imgOutputPath, filesep, folderName, 'sep', imgName],'file')
        fprintf("\nalready existed...\n")
        continue
    else
%         angle_tolerance = 3;  % special case
%         windowWidth = 14;
        try
            img_rgb = imread(['D:/dataset_train', filesep, folderName, filesep, imgName]);
        catch
            try
                img_rgb = imread(['D:/dataset_test', filesep, folderName, filesep, imgName]);
            catch
                img_rgb = imread(['D:/dataset_valid', filesep, folderName, filesep, imgName]);
            end
        end
%         resizeImageHeight = size(img_rgb, 1) / scale;  resizeImageWidth = size(img_rgb, 2) / scale;
        % Use default hyperparameter.
        % If you want to check it in the hyperparameter set in output_data -> parser the table like above
        train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);
    end
end

clear t row;
