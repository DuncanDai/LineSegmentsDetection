R=35; G = 8; B=6;
R*0.299 + G*0.587 + B*0.114
%% only for test

figure(2);
imshow(img);
hold on
for i = 1:1604
    edge_1 = edgeChains(edgeChains(:, 3) == i, :);
    plot(edge_1(:, 1), edge_1(:, 2), 'color', 'green')  
end


%%
%% for CannyPF edgeChains -> Lines
addpath('./helperFuncs');
addpath('./helperPlots');
addpath('./myAPP');

%%
img_rgb = imread('../Resources/_origin_rgb.png');
save_img_path = ('.');
[runTime, runTime_matlab, left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features] = train1_singleSample(img_rgb, save_img_path) %varargin


[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent);