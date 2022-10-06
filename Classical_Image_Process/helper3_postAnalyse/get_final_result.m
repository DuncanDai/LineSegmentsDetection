function final_result = get_final_result(test_result)
% (min mean max std)
%     - runtime in C++
%     - runtime in Matlab
%     - RMSE: select one of metric_RMSE_vertical, metric_RMSE_polyfit as metric_RMSE

final_result = varfun(@min, test_result, 'InputVariables', {'runTime_cpp', 'runTime_matlab', 'metric_RMSE'});
final_result = [final_result, varfun(@mean, test_result, 'InputVariables', {'runTime_cpp', 'runTime_matlab', 'metric_RMSE'})];
final_result = [final_result, varfun(@max, test_result, 'InputVariables', {'runTime_cpp', 'runTime_matlab', 'metric_RMSE'})];
final_result = [final_result, varfun(@std, test_result, 'InputVariables', {'runTime_cpp', 'runTime_matlab', 'metric_RMSE'})];
end