function [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, save_img_path) 
% 
% Inputs:
%   - img_rgb: output of imshow(imgFile)
%   - save_img_path
%   - varargin: a cell Array

% declare global variables in `trainHeader.m`
global scale;
global angle_expect;
global angle_tolerance;

global resizeImageHeight;
global resizeImageWidth;
global windowWidth;
global windowStepSize;
global decision_criter;  
decision_criterion = {'number'; 'length'; 'length/number'};
global prior_mandrel_percent;

global FLAG_VALID;
global label_data;

global output_data;  % in valid1_singleSample.m

%% run function
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

resizeImageHeight = size(img_rgb, 1) / scale;
resizeImageWidth = size(img_rgb, 2) / scale;

[runTime_cpp, edgeLines] = mex_edgeDetecter(img);

%% validation for single sample: only use when in validation
if FLAG_VALID == 1
    k = 1;
    for scale = 1  % 5 values -> stepsize: 0.2
        for windowWidth = 2 : 2 : 120  % 20 values -> stepsize: 4 -> up to 80
            for windowStepSize = 1 : 3 : 40  % 5 values -> stepsize: 3  -> up to 15
                for angle_tolerance = (0 : .2 : 30) * pi /180  % unit is rad   20 values -> stepsize: 0.5  -> up to 10
                    for i = 1 : 3   % 3 values
                        decision_criter = decision_criterion{i, 1};  
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
                        % for training(there is no label) -> but still get the wanted output data
                        try
                            [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
                        catch ME
                            fprintf('Reminder: the image "%s" in folder  %s has no label data!!!\n', imgName, folderName);
                            left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
                            right_border_label = 0;
                        end 

                        metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
                        % 4 Hyperparameters: use a struct Array
                        % hyper_parameters = struct('scale', scale, 'angle_expect', angle_expect, 'angle_tolerance', angle_tolerance, ...
                        %                             'windowWidth', windowWidth, 'windowStepSize', windowStepSize, 'decision_criter', decision_criter, ...
                        %                             'prior_mandrel_percent', prior_mandrel_percent);
                        
                        output_data(k, 3:end) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent};
                        k = k + 1;
                        if ~mod(k, 1000)
                            fprintf('Now: %d sets of hyperparameter have been tested... \n', k);

%                             save_data_path = ['U:\my_projs\g_output', filesep, 'output_data_validSingleSample.mat'];
%                             save(save_data_path, 'output_data');
%                             t2 = datestr(now)
%                             return
                        end
                    end
                end
            end
        end
    end
    
    
else
    %% test: specific parameters -> only use when train single sample.
%     GaussSize = uint8(3);
%     VMGradient = 70.0;
    
    scale = 1;
    angle_expect = pi/2;
    angle_tolerance = 5/180*pi;
    
    windowWidth = 40;
    windowStepSize = 10;
    decision_criter = 'number';
    prior_mandrel_percent = 1/3;
    
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
    % for training(there is no label) -> but still get the wanted output data
    try
        [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
    catch ME
        fprintf('Reminder: the image "%s" in folder  %s has no label data!!!\n', imgName, folderName);
        left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
        right_border_label = 0;
    end 

    metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
    % 4 Hyperparameters: use a struct Array
    % hyper_parameters = struct('scale', scale, 'angle_expect', angle_expect, 'angle_tolerance', angle_tolerance, ...
    %                             'windowWidth', windowWidth, 'windowStepSize', windowStepSize, 'decision_criter', decision_criter, ...
    %                             'prior_mandrel_percent', prior_mandrel_percent);
end



%% plot and output
% during analying the output_data: stop to plot and save the image
% Plot

% img = uint8(img);
% imshow(img, 'border', 'tight', 'initialmagnification', 100);
% hold on
% draw_lines(full_edges_filter_by_angle);
% draw_borders(left_border_pos, right_border_pos, resizeImageHeight);   

% Output

% f = getframe(gcf);
% imwrite(f.cdata, save_img_path);

% close;
end

