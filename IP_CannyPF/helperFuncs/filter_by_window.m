function valid_inds = filter_by_window(edges_filtered_by_angle, windowStart, windowEnd)
% Calculate the total number and total length of the valid edges in a window 
%
% Input:
%   - edges_filtered_by_angle: elements in one row -> (x1, y1, x2, y2, ...)
%   - windowStart (in pixels): the start position of window in the original image
%   - windowEnd (in pixels): the end position of window in the original image
%
% Output:
%   - valid_inds: valid indexes in the image after resizing -> need to be
%   recovered to the indexes in the original image at the end.

min_x_val = min(edges_filtered_by_angle(:, 1), edges_filtered_by_angle(:, 3));
max_x_val = max(edges_filtered_by_angle(:, 1), edges_filtered_by_angle(:, 3));

invalid_inds = find(min_x_val >= windowEnd | max_x_val <= windowStart);
valid_inds = setdiff(1:size(edges_filtered_by_angle,1), invalid_inds);
end

