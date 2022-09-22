global scale;  % scale value: 0.8, 0.6, 0.5, 0.25
global angle_expect;
global angle_tolerance;

global resizeImageHeight; 
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter; 
global prior_mandrel_percent;

%% copy from table
row = 114;

folderName = output_data.folderName(row);  folderName = char(folderName);
imgName = output_data.imgName(row);  imgName = char(imgName);
scale = output_data.scale(row); resizeImageHeight = size(img_rgb, 1) / scale;  resizeImageWidth = size(img_rgb, 2) / scale;
angle_expect = output_data.angle_expect(row);
angle_tolerance = output_data.angle_tolerance(row);
windowWidth = output_data.windowWidth(row); windowWidth = double(windowWidth);
windowStepSize = output_data.windowStepSize(row); windowStepSize = double(windowStepSize);
decision_criter = output_data.decision_criter(row); decision_criter = char(decision_criter);
prior_mandrel_percent = output_data.prior_mandrel_percent(row);

%%
imgInputPath = 'E:\dataset_valid';  imgOutputPath = 'D:/My_Data/me_Projs/Proj_MA/g_output';
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
% Use default hyperparameter.
% If you want to check it in the hyperparameter set in output_data -> parser the table like above
[runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);

