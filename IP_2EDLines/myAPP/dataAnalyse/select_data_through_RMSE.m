function table_data_good_sets = select_data_through_RMSE(table_data, low_thres, high_thres)
% Default criterion for "good": The RMSE should less than 20 pixels. (Some labels are not perfect)
% Default criterion for "bad": The RMSE should more than 100 pixels. (Some labels are not perfect)
inds = find(table_data.metric_RMSE >= low_thres  & table_data.metric_RMSE <= high_thres);
table_data_good_sets = table_data(inds, :);
end

