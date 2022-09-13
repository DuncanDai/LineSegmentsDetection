function  [left_border_index, right_border_index, windows_features, full_edges_filter_by_angle] = extract_borders(edgeLines, scale, imageWidth, windowWidth, windowStepSize, ...
                                                                                                            angle_expect, angle_tolerance, decision_criterion, prior_mandrel_percent) %, prior_mandrel_diameter, lenth_threshold, number_threshold)
% Description: From the detected edges, use moving window to count the
% edges number in the window (the edges should have a angle within the angle tolerance) and
% calculate the edges length in the window to give a rank to the index in x
% axis, from which we select the left and right border index.
%
% Inputs:
%   - edges: different edge detecters produce different types of edges.
%       for LSD: two endpoints (OpenCV)
%       for EDLines: two endpoints (OpenCV)
%       for CannyPF: edgeChains -> use the start and end points in the chain as endpoints
%       for MCMLSD: two endpoints
%       The elements in one row of `edges` is (x1, y1, x2, y2)
%   - scale (default is 4): the scale/resize size in x axis
%   - imageWidth (in pixels): the width of the original image (before resizing)
%   - windowWidth (in pixels): the width of the border (recommended: 10 ~ 40 pixels)
%   - windowStepSize (in pixels): (recommended: 1/4 of the window width)
%   - angle_expect (in rad): angle of inclination of the border (recomended: (90 degree /180*pi) rad)
%   - angle_tolerance: tolerance of the angle (recomended: (5 degree /180*pi) rad)
%   - decision_criterion: choose 'length' or 'number'
%   - prior_mandrel_percent:  the middle part to be ignored (recommended: 1/4 of the original image 
%                           -> it's better use a small number, to avoid borders being ignored)
%   - prior_mandrel_diameter: to deal with corner case, when the left border is hard to be detected
%   - lenth_threshold: to be determined after calculating in train dataset...
%   - number_threshold: to be determined after calculating in train dataset...
%
% Outputs:
%   - left_border_index: left border in the original image
%   - right_border_index： right border in the original image
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

windows_num = idivide(imageWidth, int32(windowStepSize), 'ceil');
windows_features = zeros(windows_num, 3);   % the 3 elements in a row -> (number, length, window_pos)
for i = 1:(windows_num-1)
    windowStart = 1 + (windowStepSize * (i-1));
    windowEnd = windowStart + windowWidth - 1;
    windows_features(i) = extract_window_features(full_edges_filter_by_angle, scale, ...
                                                                  windowStart, windowEnd);
end

%% find the border index: left peak, right peak
% 1 prior knowledge: the percentage of mandrel in image ->  (1/4 ~ 1/3) -> 
% this middle part will be ignored, and then divide the image into 2 sides: 
% left valid side & right valid side (valid for detecting the borders in each side)
valid_side_range = imageWidth*( (1-prior_mandrel_percent)/2 );
valid_left_boundary = valid_side_range;
valid_right_boundary = imageWidth - valid_side_range + 1;

% 1) find left peak in `valid_left_side_range`
left_valid_windows = windows_features(windows_features(:, 3) <= valid_left_boundary);

if strcmp(decision_criterion, 'number')
    left_max_index = find(left_valid_windows(:, 1));
elseif strcmp(decision_criterion, 'length')
    left_max_index = find(left_valid_windows(:, 2));
else
    error('the decision_criterion should be "number" or "length" ');
end
left_border_index = left_max_index(1);
    

% 2) find right peak in `valid_left_side_range`
right_valid_windows = windows_features(windows_features(:, 3) >= valid_right_boundary);

if strcmp(decision_criterion, 'number')
    right_max_index = find(right_valid_windows(:, 1));
elseif strcmp(decision_criterion, 'length')
    right_max_index = find(right_valid_windows(:, 2));
else
    error('the decision_criterion should be "number" or "length" ');
end
right_border_index = right_max_index(end);

% 2 corner case: using prior_mandrel_diameter
% lenth_threshold, number_threshold help to determine whether it's a corner
% case or not


end