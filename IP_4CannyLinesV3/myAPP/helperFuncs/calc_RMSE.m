function metric_RMSE = calc_RMSE(left_border_pos,left_border_label,right_border_pos,right_border_label)
%CALC_METRIC Summary of this function goes here
%   Detailed explanation goes here
d_left = left_border_pos - left_border_label;
d_right = right_border_pos - right_border_label;
metric_RMSE = hypot(d_left, d_right);
end

