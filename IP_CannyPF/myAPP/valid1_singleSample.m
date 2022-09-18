% folderName: not entire path -> Just the name of folder: as a field name
% imgName: with the suffix .png 
imgInputPath = 'U:\my_projs\imgSamplesSubTest'; folderName = '2022-04-28_14-09-13'; imgName = '0.png';
img_rgb = imread([imgInputPath, filesep, folderName, filesep, imgName]);
save_img_path  = 'U:\my_projs\g_output\test_valid_singleSample.png';

%% hyperparameters gridSerach
output_data = cell(2000, 9); 
k = 1;
for scale = 1
    for windowWidth = 1 : 5 : 100
        for windowStepSize = 1 : 3 : 10
            for angle_tolerance = (0 : 1 : 10) * pi /180  % attention: unit is rad 
                for i = 1 : decision_criterion_size
                    decision_criter = decision_criterion{i, 1};
                    %%% IMPORTANT: here put the training/validation process
                    [runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters] = ...
                        train1_singleSample(img_rgb, folderName, imgName, save_img_path); 
                    output_data(k, :) = {runTime_cpp, runTime_matlab, windows_features, left_border_pos, left_border_label, right_border_pos, right_border_label, metric_RMSE, hyper_parameters};
                    k = k + 1;
                end
            end
        end
    end
end

% save data
save_data_path = ['U:\my_projs\g_output', filesep, 'output_data_validSingleSample.mat'];
save(save_data_path, 'output_data');
