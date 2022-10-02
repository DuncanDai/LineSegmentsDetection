function metric_RMSE = calc_RMSE(left_pos1, left_pos2, left_border_label,right_pos1, right_pos2, right_border_label)

left_deviation1 = left_pos1 - left_border_label;
left_deviation2 = left_pos2 - left_border_label;
d_left = hypot(left_deviation1, left_deviation2);

right_deviation1 = right_pos1 - right_border_label;
right_deviation2 = right_pos2 - right_border_label;
d_right = hypot(right_deviation1, right_deviation2);

metric_RMSE = d_left + d_right;
end

