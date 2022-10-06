function output_data = set_metric_RMSE(output_data, metric)
% metric:
%   - 'metric_RMSE_vertical'
%   - 'metric_RMSE_polyfit',

output_data.Properties.VariableNames{metric} = 'metric_RMSE';

end

