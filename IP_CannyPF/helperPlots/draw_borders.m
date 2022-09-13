function draw_borders(left_border_index, right_border_idnex, img_height)
%DRAW_BORDERS Summary of this function goes here
%   Detailed explanation goes here

plot([left_border_index, left_border_index], [1, img_height], 'Color', 'r', 'LineWidth', 2);
plot([right_border_idnex, right_border_idnex], [1, img_height], 'Color', 'r', 'LineWidth', 2);
end

