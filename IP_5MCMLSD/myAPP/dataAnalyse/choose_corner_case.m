function corner_case_table = choose_corner_case(output_data, RMSE_low_threshold)

bad_data = select_data_through_RMSE(output_data, RMSE_low_threshold, 3000);  % 3000 is bigger than the max value of RMSE
bad_data.name = bad_data.folderName + 'sep' + bad_data.imgName;
unique_files = unique(bad_data.name);
unique_size = size(unique_files, 1);

OUTPUT_ELEMENTS = 2;   % 2 + 15 elements in one row (imgFolderName, imgName, runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, scale, angle_expect, angle_tolerance, windowWidth, windowStepSize, decision_criter, prior_mandrel_percent)
sz = [unique_size OUTPUT_ELEMENTS];
varTypes = {'string', 'string'};  % by using class() to check the type of variable
varNames = {'folderName', 'imgName'};

% Notice: angle's unit is degree
corner_case_table = table('Size',sz, 'VariableTypes',varTypes, 'VariableNames',varNames);


index = 1;
for i=1:unique_size
    file = unique_files(i);  file = char(file); % from string to char array
    folder = file(1:19); 
    img =  file(23:end);
    
    sub_data = output_data(output_data.folderName == folder & output_data.imgName == img, :);
    if all(sub_data.metric_RMSE >= RMSE_low_threshold)
        corner_case_table(index, :) = {folder, img};
        index = index + 1;
    end
end

fprintf('\n There are %d corner cases! \n',index-1);
corner_case_table = corner_case_table(1:index-1, :);
end