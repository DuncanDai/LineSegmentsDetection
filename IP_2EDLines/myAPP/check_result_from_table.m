main0_header;


%% copy from table
global is_plot is_save;

%%% NOTICE!!! optional settings
is_plot = 1; is_save = 0;  
FLAG_VALID = 0; 

%%% input the row you want to check
% output_buffer = test_data; % output_data1 works like a buffer
output = output_buffer;  


%%% plot
t = clock; % Get current time
date_folder = ['check_', ...
          num2str(t(2:3), '%02d')];   % -month-day


imgInputPath = 'E:\dataset_valid';  imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';
imgOutputPath = [imgOutputPath, filesep, date_folder];    % mkdir(imgOutputPath);

%%% change the "row" you want to check
for row = 31
% for row = 1: size(output, 1)
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
        resizeImageHeight = size(img_rgb, 1) / scale;  resizeImageWidth = size(img_rgb, 2) / scale;
        % Use default hyperparameter.
        % If you want to check it in the hyperparameter set in output_data -> parser the table like above
        [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_excluded_middle_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);
    end
end

clear t row;
