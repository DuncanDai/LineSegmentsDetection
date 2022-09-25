function table_data_good_sets = select_sets_good(table_data)
% Criterion for "good": The RMSE should less than 20 pixels. (Some labels are not perfect)
inds = find(table_data.metric_RMSE <= 20);
table_data_good_sets = table_data(inds, :);
end

