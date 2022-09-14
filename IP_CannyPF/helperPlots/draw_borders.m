function draw_borders(left_border_pos, right_border_pos, img_height)
%DRAW_BORDERS Summary of this function goes here
%   Detailed explanation goes here

plot([left_border_pos, left_border_pos], [1, img_height], 'Color', 'r', 'LineWidth', 2);
plot([right_border_pos, right_border_pos], [1, img_height], 'Color', 'r', 'LineWidth', 2);
end

