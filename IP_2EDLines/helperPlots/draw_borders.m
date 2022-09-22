function plt = draw_borders(left_border_pos, right_border_pos, img_height, lineSpec)
%DRAW_BORDERS Summary of this function goes here
%   Detailed explanation goes here

plot([left_border_pos, left_border_pos], [1, img_height], lineSpec, 'LineWidth', 1.2);
plt = plot([right_border_pos, right_border_pos], [1, img_height], lineSpec, 'LineWidth', 1.2);

end

