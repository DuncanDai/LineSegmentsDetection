
R=35;
G = 8;
B=6;
R*0.299 + G*0.587 + B*0.114
%% only for test


edgeLines = lines;
scale = 4;
imageWidth = size(img_origin, 2);

windowWidth = 40;
windowStepSize = 20;
angle_expect = pi/2;
angle_tolerance = 5/180*pi;
decision_criterion = 'length';
prior_mandrel_percent = 1/3;

[left_border_index, right_border_index, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, scale, imageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent)




