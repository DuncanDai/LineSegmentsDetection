function plt = draw_borders(left_border_pos, right_border_pos, img_height, color, lineStyle, lineWidth, marker)
%DRAW_BORDERS Summary of this function goes here
%   Detailed explanation goes here

plot([left_border_pos, left_border_pos], [1, img_height], 'Color', color, 'LineStyle', lineStyle, 'LineWidth', lineWidth, 'Marker', marker);
plt = plot([right_border_pos, right_border_pos], [1, img_height], 'Color', color, 'LineStyle', lineStyle, 'LineWidth', lineWidth, 'Marker', marker);

end

