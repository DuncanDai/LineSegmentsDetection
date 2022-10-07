####################################################
#### init: daidinggen@hotmail.com   2022.09    ####
####################################################
# Usage
step1: Check the path (in "config_hyperParams.m")
- in Pool or on PC

step2: Choose the modul (in "Classical_Image_Process/helper0_myAPP/" folder) 
- train, valid, test

step3: Notice the global variables


optional: choose to select in "helper3_postAnalyse/" folder   
optional: choose to check the result  
- "check_result_from_table.m"


###############################################
// Core functions ready.  
1 modify: use one set of hyperparameters to valid all the images (all folders)  -> create a new script

// need to adjust between Pool and my own PC  
1 input path -> main0_header.m  
- train: local disk
- valid: portable HDD
- test: portable HDD

2 output path -> "check_result_from_table.m"  


##########################################################
######    vaild: daidinggen@hotmail.com   2022.10    #####
##########################################################
[Analyse of the validation output] original data name: "output_data" from validation
### preprare work
(already finished!) output_data = set_metric_RMSE(output_data, metric) -> metric: metric_RMSE_vertical, metric_RMSE_polyfit
config_path;  % in the "<IP method>/main" folder
load output_data.mat; % saved in the "<IP method>/main" folder

(Note: don't need anymore!) ### Commands 1: choose_corner_case.m -> corner_case (RMSE threshold = ...)
corner_case1_30 = choose_corner_case(output_data, 30);
corner_case2_40 = choose_corner_case(output_data, 40);
corner_case3_50 = choose_corner_case(output_data, 50);
corner_case4_100 = choose_corner_case(output_data, 100);
corner_case5_200 = choose_corner_case(output_data, 200);
corner_case6_300 = choose_corner_case(output_data, 300);
corner_case7_400 = choose_corner_case(output_data, 400);
corner_case8_500 = choose_corner_case(output_data, 500);
corner_case91_600 = choose_corner_case(output_data, 600);
corner_case92_700 = choose_corner_case(output_data, 700);
corner_case93_800 = choose_corner_case(output_data, 800);
corner_case94_900 = choose_corner_case(output_data, 900);
corner_case95_1000 = choose_corner_case(output_data, 1000);
corner_case96_1500 = choose_corner_case(output_data, 1500);
corner_case97_2000 = choose_corner_case(output_data, 2000);
save(, 'corner_case*');  %'corner_case_1001_0950.mat'


(Note: don't need anymore!) ### Commands 2: choose a corner_case -> manually
corner_case = corner_case2_40; % me: check the result in "test" -> LSD: corner_case2_40
output_data = add_corner_case_label(output_data, corner_case);

(Note: don't need anymore!) ### Commands 3: has_corner_case = false
     - groupby hyper-parameters -> "result"
     - choose the best set of hyper-parameters
    % result = groupby_hyperparams_from_output(output_data, corner_case, false);


### Commands: has_corner_case = true
    - groupby hyper-parameters -> "result"
    - choose the best set of hyper-parameters
% in "helper3_postAnalyse" folder
result = groupby_hyperparams_from_output(output_data, [], true);  
save('result.mat', 'result');

##########################################################
######    test: daidinggen@hotmail.com   2022.10    #####
##########################################################
Only for MCMLSD: notice the "scale" -> calculate related kernel params!
    - scale = 0.25 -> kernel size: 927
    - scale = 0.5 -> kernel size: 1857
###############   Now: run test!!!   ##########################


############### After test process##########################
[ Analyse of the test output (only one set of optimized hyper-parameters) ]
% metric: metric_RMSE_vertical, metric_RMSE_polyfit
metric = "metric_RMSE_vertical";
output_data = set_metric_RMSE(output_data, metric); 

mean(output_data.metric_RMSE);

1 Distribution of RMSE
    - histogramm:  with texts
    - ordered plot: in ascending order

2 analyse the result of histogramm -> select_data_through_RMSE.m + check_result_from_table.m
    - choose at least 3 range based on histogramm -> check_result for analyzing the effect of algorithms.
    ### for LSD

sub_test_result_30_90 = select_data_through_RMSE(output_data, 30, 90);
sub_test_result_90_500 = select_data_through_RMSE(output_data, 90, 500);
sub_test_result_500_1000 = select_data_through_RMSE(output_data, 500, 1000);
sub_test_result_over_1000 = select_data_through_RMSE(output_data, 1000, 3000);
save('sub_test_result().mat', 'sub_test_result_*');

2' USER_check_result_from_table.m  - plot & save the corner_case result



3 get_final_result.m (min mean max std) -> get_final_result.m
    - runtime in C++
    - runtime in Matlab
    - RMSE
    
    1) single method: three-line table
        - column: min mean max std
        - row: c++, matlab, RMSE
    2) all methods: boxplot
        - runtime
        - RMSE

    plus: corner_case -> save figures

