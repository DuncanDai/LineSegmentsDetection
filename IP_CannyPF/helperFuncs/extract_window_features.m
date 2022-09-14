function [edges_number, edges_length, window_pos] = extract_window_features(full_edges_filter_by_angle, windowStart, windowEnd)
% Description: From the detected edges, use moving window to count the
% edges number in the window (the edges should have a angle
% within the angle tolerance) and to calculate the edges length in the window
%
% Inputs:
%   - full_edges_filter_by_angle: elements in one row -> (x1, y1, x2, y2, ..., length, angle)
%   - scale (default is 4): the scale/resize size in x axis
%   - windowStart (in pixels): the start position of window in the original image
%   - windowEnd (in pixels): the end position of window in the original image
%
% Outputs: the features in one single window
%   - count
%   - length
%   - window_pos
%
% Preconditions: none
%
% Author: Dinggen DAI (daidinggen@hotmail.com)
% Date: 2022.09.13

valid_inds = filter_by_window(full_edges_filter_by_angle, windowStart, windowEnd);
valid_edges_full = full_edges_filter_by_angle(valid_inds, :);

[edges_number, edges_length] = calc_edges_number_and_length(valid_edges_full);
window_pos = (windowStart + windowEnd)./2;
end

