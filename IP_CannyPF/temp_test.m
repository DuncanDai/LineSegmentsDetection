addpath('./helperFuncs');
edgeLines = lines;
scale = 4;
resizeImageWidth = size(img_origin, 2) / scale;

windowWidth = 10;
windowStepSize = 5;
angle_expect = pi/2;
angle_tolerance = 5/180*pi;
decision_criterion = 'length/number';  % length/number
prior_mandrel_percent = 1/3;

[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent);
                                                                                                        
addpath('./helperPlots');
imshow(img);
hold on
draw_lines(full_edges_filter_by_angle);
draw_borders(left_border_pos, right_border_pos, 516);

%% for CannyPF edgeChains -> Lines
addpath('./helperFuncs');
edgeLines = lines;
scale = 1;
resizeImageWidth = size(img, 2) / scale;
resizeImageHeight = size(img, 1) / scale;

windowWidth = 10;
windowStepSize = 5;
angle_expect = pi/2;
angle_tolerance = 5/180*pi;
decision_criterion = 'number';  % length/number
prior_mandrel_percent = 1/3;

[left_border_pos, left_maxVal, right_border_pos, right_maxVal, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent);
                                                                                                        
addpath('./helperPlots');
img = im2uint8(img);
imshow(img);
hold on
draw_lines(full_edges_filter_by_angle);
% draw_borders(left_border_pos, right_border_pos, resizeImageHeight);
