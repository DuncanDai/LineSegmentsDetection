%% for CannyPF edgeChains -> Lines
addpath('./helperFuncs');
addpath('./helperPlots');
addpath('./myAPP');

%%

train_single_sample(img_rgb, save_path);

[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent);
