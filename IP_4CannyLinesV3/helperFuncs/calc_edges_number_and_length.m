function [number, length] = calc_edges_number_and_length(valid_edges)
% Calculate the total number and total length of the valid edges in a window 
%
% Input:
%   - valid_edges: elements in one row -> (..., length, angle)

rows = size(valid_edges, 1);
cols = size(valid_edges, 2);

number = rows;
length = sum(valid_edges(:, cols-1));
end

