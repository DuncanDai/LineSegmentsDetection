function train1_singleSample(img_rgb, folderName, imgName, imgOutputPath) 
% 
% Inputs:
%   - img_rgb: output of imshow(imgFile)
%   - folderName
%   - imgName
%   - imgOutputPath
% 
% Record: [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_excluded_middle_percent] = 
% declare global variables in main0_header.m`
global scale; 
global angle_expect;
global angle_tolerance;

global resizeImageHeight;  
global resizeImageWidth; 
global windowWidth;
global windowStepSize; 
global decision_criter;  decision_criterion = {'num'; 'len'; 'len*num';'len/num'};
global prior_excluded_middle_percent;

global FLAG_VALID;

global label_data;
global is_labeled;

global output_data;  % in valid1_singleSample.m
global index;  % index of output_data
global flag_quit; index_limit = 500;  % should be divided by 100

%% Check the label
%%% Excellent!!! This combines the training and validation processes together. 
% `try-catch-end` is only for my random data(the imageName is not a valid field, which creates error)
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


%% run function
% pay attention to the input format of image
img_gray = rgb2gray(img_rgb); 
imageHeight = size(img_rgb,1);
imageWidth = size(img_rgb,2);

%% validation for single sample: only use when in validation -> maximal 840 samples in one set of hyper-params
config_hyperParams;

if FLAG_VALID == 1
    for scale = scale_range 
        % resize
        resizeImageHeight = round( imageHeight*scale ); 
        resizeImageWidth  = round( imageWidth*scale );
        img_scale = imresize(img_gray, [resizeImageHeight, resizeImageWidth]);
        % img_gray: uint8_t format
        [runTime_cpp, edgeLines] = mex_edgeDetecter(img_scale);
        for windowStepSize = 1  % keep windowStepSize value 1
            for i = criterion_range   % select values of {'num'; 'len'; 'len*num'; 'len/num'}
                decision_criter = decision_criterion{i, 1};
                for windowWidth = width_range  % 16 values (stepsize: 4 )
                    for angle_tolerance = angle_toler_range   % 28 values  (unit is degree)
                        %%% here put the training/validation process
                        ticId = tic;
                        [left_window_start, left_pos1, left_pos2, right_window_start, right_pos1, right_pos2, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                                    edgeLines, resizeImageHeight, resizeImageWidth, windowWidth, windowStepSize, ...
                                                    angle_expect, angle_tolerance, decision_criter, prior_excluded_middle_percent);
                        
                        left_window_start  = round( left_window_start/scale ); right_window_start  = round( right_window_start/scale );
                        left_pos1  = round( left_pos1/scale ); left_pos2  = round( left_pos2/scale );
                        right_pos1  = round( right_pos1/scale ); right_pos2  = round( right_pos2/scale );
                        runTime_matlab = toc(ticId);
                        %% calculate the output data
                        % 1 runTime_c, runTime_matlab  ->  ok!
                        % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
                        % 3 left_border_pos, right_border_pos ->  ok!

                        % left_border_label, right_border_label -> metric: MRSE
                        [metric_RMSE_vertical, metric_RMSE_polyfit] = calc_RMSE(left_pos1, left_pos2, left_border_label, right_pos1, right_pos2, right_border_label);

                        output_data(index, 1:end) = {folderName, imgName, runTime_cpp, runTime_matlab, left_window_start, left_pos1, left_pos2, left_border_label, right_window_start, right_pos1, right_pos2, right_border_label, metric_RMSE_vertical, metric_RMSE_polyfit, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_excluded_middle_percent, is_labeled};

                        index = index + 1;
                        if ~mod(index, 500) 
                            fprintf('Now(valid): image "%s" in the folder "%s"\n', imgName, folderName);
                            fprintf('Now(valid): %d samples tested! Time is %s\n', index, datestr(now));
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
    % resize
    resizeImageHeight = round( size(img_rgb,1)*scale ); 
    resizeImageWidth  = round( size(img_rgb,2)*scale );
    img_scale = imresize(img_gray, [resizeImageHeight, resizeImageWidth]);
    % img_gray: uint8_t format
    [runTime_cpp, edgeLines] = mex_edgeDetecter(img_scale);
    
    ticId = tic;
    [left_window_start, left_pos1, left_pos2, right_window_start, right_pos1, right_pos2, windows_features, full_edges_filter_by_angle] = extract_borders(...
                                edgeLines, resizeImageHeight, resizeImageWidth, windowWidth, windowStepSize, ...
                                angle_expect, angle_tolerance, decision_criter, prior_excluded_middle_percent);
    
    left_window_start  = round( left_window_start/scale ); right_window_start  = round( right_window_start/scale );
    left_pos1  = round( left_pos1/scale ); left_pos2  = round( left_pos2/scale );
    right_pos1  = round( right_pos1/scale ); right_pos2  = round( right_pos2/scale );
    runTime_matlab = toc(ticId);
    %% calculate the output data
    % 1 runTime_c, runTime_matlab  ->  ok!
    % 2 windows_features: elements in one row (pos, number, length, length/number)  ->  ok!
    % 3 left_border_pos, right_border_pos ->  ok!

    % left_border_label, right_border_label -> metric: MRSE
    [metric_RMSE_vertical, metric_RMSE_polyfit] = calc_RMSE(left_pos1, left_pos2, left_border_label, right_pos1, right_pos2, right_border_label);

    output_data(index, 1:end) = {folderName, imgName, runTime_cpp, runTime_matlab, left_window_start, left_pos1, left_pos2, left_border_label, right_window_start, right_pos1, right_pos2, right_border_label, metric_RMSE_vertical, metric_RMSE_polyfit, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_excluded_middle_percent, is_labeled};

    index = index + 1;
    if ~mod(index, 500) 
        fprintf('Now(test): this is the image "%s" in the folder "%s"\n', imgName, folderName);
        fprintf('Now(test): %d samples tested! Time is %s\n', index, datestr(now));
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
    plt1 = draw_two_borders(left_border_label, left_border_label, right_border_label, right_border_label, imageHeight, 'r', '-', 1, 'o');
    full_edges_filter_by_angle(:, 1:4) = full_edges_filter_by_angle(:, 1:4)./scale;
    plt2 = draw_edgeLines(full_edges_filter_by_angle); 
    plt3 = draw_two_borders(left_pos1, left_pos2, right_pos1, right_pos2, imageHeight, 'c', '--', 1.5, 'none');  

    % draw the line in the center of image in x-axis.
    plt4 = line([imageWidth/2 imageWidth/2], [1 imageHeight],'Color','k', 'LineStyle', ':', 'LineWidth', 1);
    % set prior_mandrel_percent = 5/16 of middle part (initial in main0_header.m)
    plt5 = draw_two_borders(imageWidth .* (1/2 - 1/8 - 1/32), imageWidth .* (1/2 - 1/8 - 1/32), imageWidth .* (1/2 + 1/8 + 1/32), imageWidth .* (1/2 + 1/8 + 1/32), imageHeight, 'k', '-', 1, 'none');
    
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

