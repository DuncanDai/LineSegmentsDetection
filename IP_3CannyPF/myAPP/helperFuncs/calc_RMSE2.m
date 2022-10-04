function output_data = calc_RMSE2(output_data)

left_deviation = min(output_data.left_pos1, output_data.left_pos2) - output_data.left_border_label;
right_deviation = max(output_data.right_pos1, output_data.right_pos2) - output_data.right_border_label;

output_data.metric_RMSE_polyfit = output_data.metric_RMSE;
output_data.metric_RMSE = hypot(left_deviation, right_deviation);
end

