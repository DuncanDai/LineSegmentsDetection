function [count, length] = calc_edges_number_and_length(valid_edges)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
% valid_edges_with_length: (..., length, angle)
rows = size(valid_edges, 1);
cols = size(valid_edges, 2);

count = rows;
length = sum(valid_edges(:, cols-1));
end

