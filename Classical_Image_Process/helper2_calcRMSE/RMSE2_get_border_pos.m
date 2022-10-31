function [pos1, pos2] = RMSE2_get_border_pos(edgePoints_row, edgePoints_col, resizeImageHeight)
% fit to a line from edgePoints
% p(1)*x + p(2) = y
% y-axis is the horizontal axis
y = edgePoints_col;
x = edgePoints_row;


p = polyfit(x, y, 1);

pos1 = polyval(p, 1);
pos2 = polyval(p, resizeImageHeight);
end

