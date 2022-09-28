function result = post_process_output_data(output_data, corner_case, has_corner_case)
% has_corner_case is a logical value: [true, flase]
if ~has_corner_case
    output_data_with_corner_case = add_corner_case_label(output_data, corner_case);
    inds = (output_data_with_corner_case.is_corner_case == false);
    output_data = output_data_with_corner_case(inds, 1:end-1);  % don't need the field 'has_corner_case' any more.
end

groupvars = {'is_labeled', 'prior_excluded_middle_percent', 'scale', 'windowStepSize', 'angle_expect', 'angle_tolerance', 'windowWidth', 'decision_criter'};
methods = {'median', 'mean', 'std', 'min', 'max'};
datavars = {'metric_RMSE', 'runTime_cpp', 'runTime_matlab'};
result = groupsummary(output_data, groupvars, methods, datavars);

end

