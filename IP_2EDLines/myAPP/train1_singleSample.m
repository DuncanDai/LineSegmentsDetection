function [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent] = train1_singleSample(img_rgb, folderName, imgName, imgOutputPath) 
% 
% Inputs:
%   - img_rgb: output of imshow(imgFile)
%   - folderName
%   - imgName
%   - imgOutputPath


% declare global variables in main0_header.m`
global scale; 
global angle_expect;
global angle_tolerance;

global resizeImageHeight; resizeImageHeight = size(img_rgb, 1) / scale;  % for the "else" part in the follow if-statement
global resizeImageWidth; resizeImageWidth = size(img_rgb, 2) / scale;
global windowWidth;
global windowStepSize; 
global decision_criter;  decision_criterion = {'number'; 'length'; 'length*number';'length/number'};
global prior_mandrel_percent;

global FLAG_VALID;

global label_data;
global is_labeled;

global output_data;  % in valid1_singleSample.m
global index;  % index of output_data
global flag_quit; index_limit = 100;  % should be divided by 100
%% run function
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb);  

% img_gray: uint8_t format
[runTime_cpp, edgeLines] = mex_edgeDetecter(img_gray);

%% validation for single sample: only use when in validation
if FLAG_VALID == 1
    for windowStepSize = 1  % keep windowStepSize value 1
        for i = 1 : 3   % the front 3 values of {'number'; 'length'; 'length*number'; 'length/number'}
            decision_criter = decision_criterion{i, 1};
            for scale = 1  % (5 values -> stepsize: 0.2)
                resizeImageHeight = size(img_rgb, 1) / scale;
                resizeImageWidth = size(img_rgb, 2) / scale;
                for windowWidth = 6 : 2 : 50  % (35 values -> stepsize: 4 -> up to 80)
                    for angle_tolerance = (1 : 0.5 : 15)   % unit is degree   (20 values -> stepsize: 0.5  -> up to 10)
                        %%% here put the training/validation process
                        ticId = tic;
                        [left_border_pos, right_border_pos, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                    edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                    angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
                        runTime_matlab = toc(ticId);
                        
                        %% calculate the output data
                        % 1 runTime_c, runTime_matlab  ->  ok!
                        % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
                        % 3 left_border_pos, right_border_pos ->  ok!

                        % left_border_label, right_border_label -> metric: MRSE
                        %%% Excellent!!! This combines the training and validation processes together. 
                        % `try-catch-end` is only for my random data(the imageName is not a valid field, which creates error)
                        try
                            [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
                            if left_border_label ==0 & right_border_label ==0   % This image is in the label.json file, but has no label 
                                is_labeled = 'not labeled';
                                metric_RMSE = Inf; %  call function in train2_singleFolder.m need the output of metric_RMSE, however, not recorded in output_data
                                return  % if not labeled
                            else
                                is_labeled = 'labeled';
                            end
                        catch ME  % This image is not in the label.json file
                            fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
                            left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
                            right_border_label = 0;
                            is_labeled = 'not in the label.json';
                            metric_RMSE = Inf; % just for output consistence of train2_singleFolder.m, not recorded in output_date
                            return % if not labeled
                        end 

                        metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
                        
                        output_data(index, 1:end) = {folderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent, is_labeled};
                        
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
    
    
else  % check & test (for classical IP there is no train process)
    ticId = tic;
    [left_border_pos, right_border_pos, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                    edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                    angle_expect, angle_tolerance, decision_criter, prior_mandrel_percent);
    runTime_matlab = toc(ticId);
    
    %% calculate the output data
    % 1 runTime_c, runTime_matlab  ->  ok!
    % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
    % 3 left_border_pos, right_border_pos ->  ok!
    % left_border_label, right_border_label -> metric: MRSE

    %%% Excellent!!! This combines the training and validation processes together. 
    % `try-catch-end` is only for my random data(the imageName is not a valid field, which creates error)
    try
        [left_border_label, right_border_label] = get_label(label_data, folderName, imgName);
        if left_border_label ==0 & right_border_label ==0   % This image is in the label.json file, but has no label 
            is_labeled = 'not labeled';
        else
            is_labeled = 'labeled';
        end
    catch ME  % This image is not in the label.json file
        fprintf('Reminder: the image "%s" in folder  %s is not existed in the label.json file, that means a invalid field of struct array in matlab!!!\n', imgName, folderName);
        left_border_label = 0;  % if assign the value `[]`, the following calc_RMSE() function couldn't work 
        right_border_label = 0;
        is_labeled = 'not in the label.json';
    end 


    metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label);
    %%% Issue: if left_border_pos == 0, which means no window_feature -> just record it in output_data for further analyse

    output_data(index, 1:end) = {folderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent, is_labeled};
    
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
global is_plot is_save;

if is_plot
    %% Plot
    h = figure;
    h.WindowState = 'minimized'; % don't show in the front  
%     h.Visible = 'off';  % nothing
%     set(groot, 'CurrentFigure', []);


    
    imshow(img_gray, 'border', 'tight', 'initialmagnification', 100);   % img_gray is uint8 grayscale
    ax = gca;
    ax.Toolbar.Visible = 'off';
    
    hold on
    % issue: When there is no edgeLines after the angle fitering, the function
    % will raise an error
    plt1 = draw_borders(left_border_label, right_border_label, resizeImageHeight, 'r', '-', 1, 'o');    
    plt2 = draw_lines(full_edges_filter_by_angle); 
    plt3 = draw_borders(left_border_pos, right_border_pos, resizeImageHeight, 'c', '--', 1.5, 'none');  

    % draw the line in the center of image in x-axis.
    plt4 = line([resizeImageWidth/2 resizeImageWidth/2], [1 resizeImageHeight],'Color','k', 'LineStyle', ':', 'LineWidth', 1);
    % set prior_mandrel_percent = 5/16 of middle part (initial in main0_header.m)
    plt5 = draw_borders(resizeImageWidth .* (1/2 - 1/8 - 1/32), resizeImageWidth .* (1/2 + 1/8 + 1/32), resizeImageHeight, 'k', '-', 1, 'none');
    
    % first legend
    legend(plt1, 'border labels', 'Location', 'northwest');
    
    % the rest legends
    % create new axes: use `get` to create the same axes but set visible=off
    % ax_position = get(gca,'position');
    % axNew_position = [axes_position(1)]
    axDetect = axes('position',[0, -0.03, 1, 1],'visible','off');  % [left. bottom, width, height]: normalized to [0, 1] for width, height
    legend(axDetect,[plt2, plt3],{'detected line segments', 'border predictions'}, 'Location', 'northwest');

    axFixed = axes('position',[0, -0.08, 1, 1],'visible','off');  % [left. bottom, width, height]: normalized to [0, 1] for width, height
    legend(axFixed,[plt4, plt5],{'center of x-axis', 'prior: permissible mandrel percentage'}, 'Location', 'northwest');


    if is_save
        %% Output
        save_img_path = [imgOutputPath, filesep, folderName,'sep',imgName];
        f = getframe(gcf);
        
        imwrite(f.cdata, save_img_path);
        
        close;
    end
end

end
