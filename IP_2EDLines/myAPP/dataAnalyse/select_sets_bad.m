function table_data_bad_sets = select_sets_bad(table_data)
% Criterion for "bad": The RMSE should more than 100 pixels.
inds = find(table_data.metric_RMSE >= 100);
table_data_bad_sets = table_data(inds, :);
end
