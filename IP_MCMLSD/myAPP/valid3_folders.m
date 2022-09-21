imgInputPath = 'U:\my_projs\imgSamplesSubTest';
imgOutputPath = 'U:\my_projs\g_output';

%% hyperparameters gridSerach
for scale = 1
    for windowWidth = windowWidth_start : windowWidth_step : windowWidth_end
        for windowStepSize = windowStepSize_start : windowStepSize_step : windowStepSize_end
            for angle_tolerance = angle_tolerance_start : angle_tolerance_step : angle_tolerance_end
                for i = 1 : decision_criterion_size
                    decision_criter = decision_criterion{i, 1};
                    %%% IMPORTANT: here put the training/validation process
                    % TODO: folders' parent directory in valid dataset
                    
                    train3_folders(imgInputPath, imgOutputPath);
                end
            end
        end
    end
end