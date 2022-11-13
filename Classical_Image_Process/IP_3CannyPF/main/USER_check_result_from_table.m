config_path;  % initial output_data

% need to load output_data again.
% choose the data to output
global is_plot is_save;

%%% NOTICE!!! optional settings
is_plot = 1; is_save = 1;  
FLAG_VALID = 0; 


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
imgInputPath = 'D:/dataset_test';  imgOutputPath = 'D:/g_output';
imgOutputPath = [imgOutputPath, filesep, date_folder];     mkdir(imgOutputPath);

%% Method 1: use the hyper-parameters in table
%%% input the row you want to check
% sub_test_result_0_20 -> select 20 samples
% sub_test_result_20_50 -> select 20 samples

% sub_test_result_50_200 = select_data_through_RMSE(output_data, 50, 200);
% sub_test_result_200_500 = select_data_through_RMSE(output_data, 200, 500);
% sub_test_result_500_2000 = select_data_through_RMSE(output_data, 500, 2000);
% sub_test_result_over_2000 = select_data_through_RMSE(output_data, 2000, 3000);
output_buffer = sub_test_result_20_50; % output_data1 works like a buffer
output = output_buffer;  



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
for row = 29
    folderName = output.folderName(row);  folderName = char(folderName);
    imgName = output.imgName(row);  imgName = char(imgName);
    if exist([imgOutputPath, filesep, folderName, 'sep', imgName],'file')
        fprintf("\nalready existed...\n")
        continue
    else
%         angle_tolerance = 3;  % special case
%         windowWidth = 14;
        img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
%         resizeImageHeight = size(img_rgb, 1) / scale;  resizeImageWidth = size(img_rgb, 2) / scale;
        % Use default hyperparameter.
        % If you want to check it in the hyperparameter set in output_data -> parser the table like above
        train1_singleSample(img_rgb, folderName, imgName, imgOutputPath);
    end
end

clear t row;
%% Method 3: use the single optimized hyper-parameters (in config_path.m) -> check single image
%%% in pool-206 plot single sample
config_path;
global is_plot is_save;

%%% NOTICE!!! optional settings
is_plot = 1; is_save = 1;  
FLAG_VALID = 0; 

imgPath = 'U:/my_projs/LineSegmentsDetection/g_dataset/test.png';  
imgInputPath = '\\os.lsdf.kit.edu\itiv-projects\Stents4Tomorrow\Data\2022-04-28\Data\Images';
imgOutputPath = 'U:/my_projs/g_output_PPT';
% LSD-bad case 1: 2022-04-28_14-07-03   336528027.png
% LSD-bad case 2: 2022-04-28_15-47-20   5402160000.png
folderName = '2022-04-28_13-30-38'; %'2022-04-28_15-47-20';
imgName = '26957664000.png'; %'5402160000.png';
%CannyPF noise: %2022-04-28_13-30-38sep26957664000

% sep
try
%     img_rgb = imread(imgPath);
    img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
catch
    fprintf("error: image can't be read!!!")
end

%%% Check the label
%%% Excellent!!! This combines the training and validation processes together. 
try
    [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
    if left_border_label ==0 & right_border_label ==0   % This image is in the label.json file, but has no label -> img: null
        is_labeled = false;
        return  % if not labeled
    else
        is_labeled = true;
    end
catch ME  % This image is not in the label.json file
    fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
%         left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
%         right_border_label = 0;
    is_labeled = false;
    return % if not labeled
end 

img_gray = rgb2gray(img_rgb); 
imageHeight = size(img_rgb,1);
imageWidth = size(img_rgb,2);

resizeImageHeight = round( size(img_rgb,1)*scale ); 
resizeImageWidth  = round( size(img_rgb,2)*scale );
img_scale = imresize(img_gray, [resizeImageHeight, resizeImageWidth]);  % for MCMLSD is color image!!!
% img_gray: uint8_t format
[runTime_cpp, edgeLines] = mex_edgeDetecter(img_scale);

ticId = tic;
[left_window_start, left_pos1, left_pos2, left_num, left_len, right_window_start, right_pos1, right_pos2, right_num, right_len, windows_features, full_edges_filter_by_angle] = extract_borders(...
                            edgeLines, resizeImageHeight, resizeImageWidth, windowWidth, windowStepSize, ...
                            angle_expect, angle_tolerance, decision_criter, prior_excluded_middle_percent);

left_window_start  = round( left_window_start/scale ); right_window_start  = round( right_window_start/scale );
left_pos1  = round( left_pos1/scale ); left_pos2  = round( left_pos2/scale );
right_pos1  = round( right_pos1/scale ); right_pos2  = round( right_pos2/scale );
left_len = round( left_len/scale ); right_len  = round( right_len/scale );
runTime_matlab = toc(ticId);
%%% calculate the output data
% 1 runTime_c, runTime_matlab  ->  ok!
% 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
% 3 left_border_pos, right_border_pos ->  ok!

% left_border_label, right_border_label -> metric: MRSE
[metric_RMSE_vertical, metric_RMSE_polyfit] = calc_RMSE(left_pos1, left_pos2, left_border_label, right_pos1, right_pos2, right_border_label);


%%% Plot and output: during analysing the output_data: stop to plot and save the image
if is_plot
    linewidth = 3;
    
    h = figure;
%     h.WindowState = 'minimized'; % don't show in the front  

    imshow(img_gray) %, 'border', 'tight', 'initialmagnification', 100);   % img_gray is uint8 grayscale
    title_num2str = sprintf('%.2f', metric_RMSE_vertical);
    title(['RSE: ', title_num2str, ' pixels'], 'FontSize', 14);
    ax = gca;
    ax.Toolbar.Visible = 'off';
    
    hold on
    
%     title_num2str = sprintf('%.2f', metric_RMSE_vertical);
%     title(ax, ['RSE: ', title_num2str, 'pixels']);
    
    %%% Type I: without label
%     full_edges_filter_by_angle(:, 1:4) = full_edges_filter_by_angle(:, 1:4)./scale;
%     plt = draw_edgeLines(full_edges_filter_by_angle); 
%     plt2 = draw_two_borders(left_pos1, left_pos2, right_pos1, right_pos2, imageHeight, 'c', '--', linewidth, 'none');  

    %%% Type II: without label
    % issue: When there is no edgeLines after the angle fitering, the function
    % will raise an error
    plt1 = draw_two_borders(left_border_label, left_border_label, right_border_label, right_border_label, imageHeight, 'r', '-', linewidth, 'o');
    full_edges_filter_by_angle(:, 1:4) = full_edges_filter_by_angle(:, 1:4)./scale;
    plt2 = draw_edgeLines(full_edges_filter_by_angle, linewidth-1); 
    plt3 = draw_two_borders(left_pos1, left_pos2, right_pos1, right_pos2, imageHeight, 'b', '--', linewidth, 'none');  

    % draw the line in the center of image in x-axis.
    plt4 = line([imageWidth/2 imageWidth/2], [1 imageHeight],'Color','k', 'LineStyle', ':', 'LineWidth', linewidth);
    % set prior_mandrel_percent = 5/16 of middle part (initial in main0_header.m)
    plt5 = draw_two_borders(imageWidth .* (1/2 - 1/8 - 1/32), imageWidth .* (1/2 - 1/8 - 1/32), imageWidth .* (1/2 + 1/8 + 1/32), imageWidth .* (1/2 + 1/8 + 1/32), imageHeight, 'k', '-', linewidth, 'none');
    
    % first legend
    axOrigin = axes('position',[-0.06, 0.19, 1, 1],'visible','off');
    legend(axOrigin, plt1, 'border labels', 'Location', 'southeast');
    
    % the rest legends
    % create new axes: use `get` to create the same axes but set visible=off
    % ax_position = get(gca,'position');
    % axNew_position = [axes_position(1)]
    axDetect = axes('position',[-0.06, 0.14, 1, 1],'visible','off');  % [left. bottom, width, height]: normalized to [0, 1] for width, height
    legend(axDetect,[plt2, plt3],{'detected line segments', 'border predictions'}, 'Location', 'southeast');

    axFixed = axes('position',[-0.06, 0.09, 1, 1],'visible','off');  % [left. bottom, width, height]: normalized to [0, 1] for width, height
    legend(axFixed,[plt4, plt5],{'center of x-axis', 'prior: permissible mandrel percentage'}, 'Location', 'southeast');


    if is_save
        %%% Output
        save_img_path = [imgOutputPath, filesep, folderName,'sep',imgName];
        f = getframe(gcf);
        
%         imwrite(f.cdata, save_img_path);
        saveas(gcf, save_img_path);
        
%         close;
    end
end