function [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath) 
% 
% Inputs:
%   - img_rgb: output of imshow(imgFile)
%   - save_img_path
%   - varargin: a cell Array

% declare global variables in `trainHeader.m`
global scale;  % scale value: 0.8, 0.6, 0.5, 0.25
global angle_expect;
global angle_tolerance;

global resizeImageHeight; resizeImageHeight = size(img_rgb, 1) / scale;
global resizeImageWidth; resizeImageWidth = size(img_rgb, 2) / scale;
global windowWidth;
global windowStepSize;
global decision_criter;  decision_criterion = {'number'; 'length'; 'length/number'};
global prior_mandrel_percent;

global FLAG_VALID;

global label_data;
global output_data;  % in valid1_singleSample.m
global index;  % index of output_data
global flag_quit; index_limit = 100;  % should be divided by 100
%% run function
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb);  

% img: uint8_t format
[runTime_cpp, edgeLines] = mex_edgeDetecter(img_gray);

%% validation for single sample: only use when in validation
if FLAG_VALID == 1
    for windowStepSize = 1  % keep windowStepSize value 1
        for i = 1 : 3   % 3 values
            decision_criter = decision_criterion{i, 1};
            for scale = 1  % 5 values -> stepsize: 0.2
                resizeImageHeight = size(img_rgb, 1) / scale;
                resizeImageWidth = size(img_rgb, 2) / scale;
                for windowWidth = 6 : 2 : 80  % 35 values -> stepsize: 4 -> up to 80
                    for angle_tolerance = (0.1 : 1 : 30) * pi /180  % unit is rad   20 values -> stepsize: 0.5  -> up to 10
                        %%% IMPORTANT: here put the training/validation process
                        ticId = tic;
                        [left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                    edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                    angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
                        runTime_matlab = toc(ticId);
                        
                        %% calculate the output data
                        % 1 runTime_c, runTime_matlab  ->  ok!
                        % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
                        % 3 left_border_pos, right_border_pos ->  ok!

                        % left_border_label, right_border_label -> metric: MRSE
                        %%% DINGGEN excellent: this combines the training and validation processes together. 
                        % `try-catch-end` is only for my random data(the imageName is not a valid field, which creates error)
                        try
                            [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
                        catch ME
                            fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
                            left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
                            right_border_label = 0;
                        end 

                        metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
                        %%% TODO Adjustable: if left_border_pos == 1
                        
                        output_data(index, :) = {folderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect*180/pi, angle_tolerance*180/pi, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent};
                        
                        index = index + 1;
                        if ~mod(index, 100) 
                            fprintf('%d samples tested! Time is %s\n', index, datestr(now));
%                             if index == index_limit
%                                 fprintf('Manually terminated: index is %d \n', index);
%                                 flag_quit = 1;
%                                 return
%                             end
                        end

                    end
                end
            end
        end
    end
    
    
else
    ticId = tic;
    [left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                    edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                    angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
    runTime_matlab = toc(ticId);
    
    %% calculate the output data
    % 1 runTime_c, runTime_matlab  ->  ok!
    % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
    % 3 left_border_pos, right_border_pos ->  ok!
    % left_border_label, right_border_label -> metric: MRSE

    %%% DINGGEN excellent: this combines the training and validation processes together. 
    % `try-catch-end` is only for my random data(the imageName is not a valid field, which creates error)
    try
        [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
    catch ME
        fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
        left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
        right_border_label = 0;
    end 


    metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
    %%% Issue: if left_border_pos == 1, which means no window_feature
    %%% detected -> just record it in output_data for further analyse

    output_data(index, 1:end) = {folderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect*180/pi, angle_tolerance*180/pi, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent};
    
    index = index + 1;
    if ~mod(index, 100) 
        fprintf('%d samples tested! Time is %s\n', index, datestr(now));
%         if index == index_limit
%             fprintf('Manually terminated: index is %d \n', index);
%             flag_quit = 1;
%             return
%         end
    end

end


%% Plot and output: during analysing the output_data: stop to plot and save the image
%% Plot
figure;
imshow(img_gray, 'border', 'tight', 'initialmagnification', 100);  % image is uint8 grayscale
hold on
% issue: When there is no edgeLines after the angle fitering, the function
% will raise an error
draw_lines(full_edges_filter_by_angle);  legend('detected line segments');
plt2 = draw_borders(left_border_pos, right_border_pos, resizeImageHeight, ':b');  
plt3 = draw_borders(left_border_label, right_border_label, resizeImageHeight, '-or'); 
% legend([plt1 plt2 plt3], 'detected line segments', 'border predictions', 'border labels'); 
legend([plt2 plt3], 'border predictions', 'border labels'); 


%% Output
save_img_path = [imgOutputPath, filesep, folderName, filesep, imgName];
f = getframe(gcf);
imwrite(f.cdata, save_img_path);

close;
% % at last: record variables in debug modul
% fprintf("Here is a debug point: for check some variables\n");

end

