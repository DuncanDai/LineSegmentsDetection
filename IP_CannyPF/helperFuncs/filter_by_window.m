function valid_inds = filter_by_window(edges_filtered_by_angle, scale, windowStart, windowsEnd)
%FILTER_BY_WINDOW Summary of this function goes here
%   Detailed explanation goes here
%Input: 
%   - edges_filtered_by_angle: x1, y1, x2, y2, ...
%   - scale=4

min_x_val = min(edges_filtered_by_angle(:, 1), edges_filtered_by_angle(:, 3)) * scale;
max_x_val = max(edges_filtered_by_angle(:, 1), edges_filtered_by_angle(:, 3)) * scale;

invalid_inds = find(min_x_val >= windowsEnd | max_x_val <= windowStart);
valid_inds = setdiff(1:size(edges_filtered_by_angle,1), invalid_inds);
end

