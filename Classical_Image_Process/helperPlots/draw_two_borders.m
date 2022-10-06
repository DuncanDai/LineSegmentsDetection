function plt = draw_two_borders(left_pos1, left_pos2, right_pos1, right_pos2, img_height, color, lineStyle, lineWidth, marker)
%DRAW_BORDERS Summary of this function goes here
%   Detailed explanation goes here

plot([left_pos1, left_pos2], [1, img_height], 'Color', color, 'LineStyle', lineStyle, 'LineWidth', lineWidth, 'Marker', marker);
plt = plot([right_pos1, right_pos2], [1, img_height], 'Color', color, 'LineStyle', lineStyle, 'LineWidth', lineWidth, 'Marker', marker);

end

