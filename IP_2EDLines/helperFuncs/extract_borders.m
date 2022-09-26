function  [left_border_pos, right_border_pos, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, resizeImageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent) %, prior_mandrel_diameter, lenth_threshold, number_threshold)
% Description: From the detected edge lines, use moving window to count the
% number of edge lines in the window (the edge lines should have a angle within the angle tolerance) and
% calculate the length of edge line in the window to give a rank to the index in x
% axis, from which we select the left and right border index.
%
% Inputs:
%   - edges: different edge detecters produce different types of edges.
%       for LSD: two endpoints (OpenCV)
%       for EDLines: two endpoints (OpenCV)
%       for CannyPF: edgeChains -> use the start and end points in the chain as endpoints
%       for MCMLSD: two endpoints
%       The elements in one row of `edges` is (x1, y1, x2, y2)
%   - resizeImageWidth (in pixels): the width of the original image (before resizing)
%   - windowWidth (in pixels): the width of the border (recommended: 10 ~ 40 pixels / scale )
%   - windowStepSize (in pixels): (recommended: 1/4 of the window width)
%   - angle_expect (in degree): angle of inclination of the border (recomended: 90 degree)
%   - angle_tolerance: tolerance of the angle (recomended: 5 degree)
%   - decision_criterion: choose 'length' or 'number' or 'length/number'
%   - prior_mandrel_percent:  the middle part to be ignored (recommended: 1/4 of the original image 
%                           -> it's better use a small number, to avoid borders being ignored)
%
%   %% Optional for improving the information extraction step
%   - prior_mandrel_diameter: to deal with corner case, when the left border is hard to be detected
%   - lenth_threshold: to be determined after calculating in train dataset...
%   - number_threshold: to be determined after calculating in train dataset...
%
% Outputs:
%   - left_border_index: left border in the image after resizing
%   - right_border_index： right border in the image after resizing
%   - windows_features: the total number and length of valid edges in all
%   moving windows
%   - full_edges_filter_by_angle: elements in one row -> (x1, y1, x2, y2, ..., length, angle)
%   
% Preconditions: none
%
% Author: Dinggen DAI (daidinggen@hotmail.com)
% Date: 2022.09.12

[lengths, angles] = get_line_properties(edgeLines);
full_edges = [edgeLines, lengths, angles];

valid_inds = filter_by_angle(angles, angle_expect, angle_tolerance);
full_edges_filter_by_angle = full_edges(valid_inds, :);

windows_num = idivide(resizeImageWidth, int16(windowStepSize), 'ceil');
windows_features = zeros(windows_num, 3);   % original 3 elements in a row -> (window_pos, number, length)
for i = 1:(windows_num-1)
    windowStart = 1 + (windowStepSize * (i-1));
    windowEnd = windowStart + windowWidth - 1;
    [window_pos, edges_number, edges_length] = get_window_features(full_edges_filter_by_angle, ...
                                                                  windowStart, windowEnd);
    windows_features(i, :) = [window_pos, edges_number, edges_length];
end

%% feature engineering
feature_length_multiple_number = windows_features(:, 3) .* windows_features(:, 2);
feature_length_divide_number = windows_features(:, 3) ./ windows_features(:, 2);
windows_features = [windows_features, feature_length_multiple_number, feature_length_divide_number];  % add an extra feature

%% find the border index: left peak, right peak
% 1 prior knowledge: the percentage of mandrel in image ->  (1/4 ~ 1/3) -> 
% this middle part will be ignored, and then divide the image into 2 sides: 
% left valid side & right valid side (valid for detecting the borders in each side)
valid_side_range = resizeImageWidth*( (1-prior_mandrel_percent)/2 );
valid_left_boundary = valid_side_range;
valid_right_boundary = resizeImageWidth - valid_side_range + 1;

% find left peak in the left and right valid range
left_valid_windows_features = windows_features( windows_features(:, 1) <= valid_left_boundary, : );
right_valid_windows_features = windows_features( windows_features(:, 1) >= valid_right_boundary, : );

if strcmp(decision_criterion, 'number')
    idx = 2;
    [left_maxVal, ~] = max(left_valid_windows_features(:, idx));
    [right_maxVal, ~] = max(right_valid_windows_features(:, idx));
elseif strcmp(decision_criterion, 'length')
    idx = 3;
    [left_maxVal, ~] = max(left_valid_windows_features(:, idx));
    [right_maxVal, ~] = max(right_valid_windows_features(:, idx));
elseif strcmp(decision_criterion, 'length*number')
    idx = 4;
    [left_maxVal, ~] = max(left_valid_windows_features(:, idx));
    [right_maxVal, ~] = max(right_valid_windows_features(:, idx));
elseif strcmp(decision_criterion, 'length/number')
    idx = 5;
    [left_maxVal, ~] = max(left_valid_windows_features(:, idx));
    [right_maxVal, ~] = max(right_valid_windows_features(:, idx));
else
    error('the decision_criterion should be "number" or "length" ');
end

% valid region of moving window: in the left side of mandrel ->  (1/2 - prior_mandrel_percent/2)
left_maxIndex = find(left_valid_windows_features(:, idx)==left_maxVal);
left_border_index = left_maxIndex(1);
if left_valid_windows_features(left_border_index, 2) == 0  % the number of edge lines is 0
    left_border_pos = 0;
else
    left_border_pos = left_valid_windows_features(left_border_index, 1) - windowWidth/2;  
end

% valid region of moving window: in the right side of mandrel -> (1/2 + prior_mandrel_percent/2)
right_maxIndex = find(right_valid_windows_features(:, idx)==right_maxVal); 
right_border_index = right_maxIndex(end);
if right_valid_windows_features(right_border_index, 2) == 0  % the number of edge lines is 0
    right_border_pos = 0;
else
    right_border_pos = right_valid_windows_features(right_border_index, 1) + windowWidth/2;  
end

% 2 Optional - corner case: using prior_mandrel_diameter
% lenth_threshold, number_threshold help to determine whether it's a corner
% case or not


end