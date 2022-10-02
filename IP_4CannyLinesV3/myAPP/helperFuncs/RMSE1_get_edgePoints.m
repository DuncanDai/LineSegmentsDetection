function [edgePoints_row, edgePoints_col] = RMSE1_get_edgePoints(max_window_with_edgeLines)
% max_window_with_edgeLines: 4 elements in one row -> (x1, y1, x2, y2)
edgePoints_col = [max_window_with_edgeLines(:, 1); max_window_with_edgeLines(:, 3)];
edgePoints_row = [max_window_with_edgeLines(:, 2); max_window_with_edgeLines(:, 4)];
end

