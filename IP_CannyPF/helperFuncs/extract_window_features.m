function [count, length, window_pos] = extract_window_features(edges, scale, windowStart, windowsEnd, angleExpect, angleTolerance)
% Description: From the detected edges, use moving window to count the
% edges number in the window (the edges should have a angle within the angle tolerance) and
% calculate the edges length in the window to give a rank to the index in x
% axis, from which we select the left and right border index.
%
% Input:
%   - edges: different edge detecters produce different types of edges.
%       for LSD: two endpoints (OpenCV)
%       for EDLines: two endpoints (OpenCV)
%       for CannyPF: edgeChains -> use the start and end points in the chain as endpoints
%       for MCMLSD: two endpoints
%       The structure of edges is (x1, y1, x2, y2)
%   - scale = 4 (resize: one fourth in x axis)
%   - windowStart (in pixels): the start position of window in the original image
%   - windowsEnd (in pixels): the end position of window in the original image
%   - angleExpect (in rad): angle of inclination of the border (recomended: (90 degree /180*pi) rad)
%   - angleTolerance: tolerance of the angle (recomended: (5 degree /180*pi) rad)
%
% Output: the features of one single window
%   - count
%   - length
%   - window_pos
%
% Preconditions: none
%
% Author: Dinggen DAI
% Date: 2022.09.12

[lengths,angles]=get_line_properties(edges);
edges_full = [edges, lengths, angles];

valid_inds = filter_by_angle(angles, angleExpect, angleTolerance);
edges_full_filtered_by_angle = edges_full(valid_inds, :);

valid_inds = filter_by_window(edges_full_filtered_by_angle, scale, windowStart, windowsEnd);
valid_edges_full = edges_full_filtered_by_angle(valid_inds, :);

[count, length] = calc_edges_number_and_length(valid_edges_full);
window_pos = (windowStart + windowsEnd)./2;
end

