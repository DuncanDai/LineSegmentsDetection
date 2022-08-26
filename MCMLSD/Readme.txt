【Source Code Files Overview】 2022.08.26 win10
root/main: demo_start_v2.m
dir v2: the main MCMLSD 
dir code: the main supporting code
	- dir ElderZuckerEdgeDetector: API
	- dir mexfiles: the main supporting code
	- dir parameters
	- dir utils 
dir edges-master: API package (entire project)
dir Imgs: data


================================================================================
### source code file types
.m -> Matlab Coder -> .mex
	- .prj file: the config file to output .mex file for .m file
.c -> mex: 3 platform
	- Linux: .mexa64
	- Mac: .mexmaci64
	- Windows: .mexw64


================================================================================
【step1: .c code -> mex file】by using compiler & matlab command: mex
many function in the line segmentation algorithm were mex file, if you are using
windows or linux system, please recompile following c code into mex file.
 mexRemoveVotes_v3_scale.c
 mexVoteEdges_v3_scale.c
the c code can be compiled by command
 mex xxxxxxxxx.c

【step2: .m code -> mex file】by using Matlab Coder
Please use matlab coder to compile following .m file into mex file:
 hmmParameters.m
 returnLines.m
 sampleLine.m


the matlab coder is an app in matlab to automatically compile .m code into mex file,
The entry point for the code is demo_start_v2.m. 
	- Page `Select`: Entry-Point Functions: current file name （there could be more than one Entry-Point Functions）
	- Page `Define Input Types`: 
		- Matlab prompt calls: demo_start_v2
		- input types (as below)
	- Page `Generate Code`: Select MEX as output format also remove the _mex ending in the output file name section
     		for example if you are compiling sampleLine.m, output the file name as sampleLine instead of sampleLine_mex


The instruction is in following
    select No for "Does this code use global variables?"

The input variable type should be configurated in following
    1 sampleLine.m
    rho    double(1x1)
    theta  double(1x1)
    m      double(1x1)
    n      double(1x1)
    pp     double(1x2)

    2 returnLines.m
    points_proj     double(:infx2)
    final_labels    double(1x:inf)

    3 hmmParameters.m
    exist_edge_on   double(1x40)
    exist_edge_off  double(1x40)
    ang_dev_on      double(1x181)
    ang_dev_off     double(1x181)
    node_idx        double(:infx1)
    Psi_t           double(2x2)
    pi_var          double(2x1)
    y_h             double(:infx1)
    distances       double(:infx1)
    range_dis       double(1x40)
    nexist_edge_on  double(1x40)
    nexist_edge_off double(1x40)
    prob_on         double(1x1)
    prob_off        double(1x1)
    prob_stay_on    double(1x1)
    prob_leave_off  double(1x1)
    prob_leave_on   double(1x1)
    prob_stay_off   double(1x1)
    ang_dev         double(:infx1)
    range_ang       double(1x181)


【step3: run demo】
issue 1: dir v2 ist not in the path
	- addpath('v2/');
	- code line 42: lines2 = sortrows(lines2, -5);
bug 1： opts = getPrmDflt(varargin,dfs,1); -> Unrecognized function or variable 'getPrmDflt'
	- me： addpath(genpath('edges-master/'));
	
================================================================================
the line segment detector has two steps
1. compute the kernel for the image size
 you only need to compute the kernal once for one an image size
 [kernels, kernels_flip, kernel_params] =kernelInitialization(img);
 the kernels, kernels_flip, kernel_params are the kernel parameter for the line segment algorithm below

2. line segment detection
 [lines, fullLines] =lineSegmentation_HighRes(img,kernels, kernels_flip, kernel_params);

the lines variable contains the detected line segmentations it arranged as
 [x1 y1 x2 y2 probability]
The fullLines are the detected lines. It is arranged as 
 [rho theta probability]

 please run the demo_start_v2.m for demonstration

the code in Evaluation Code.zip are line evaluation algorithms
 run_create_contours_MCMLSD.m is the algorithm to get line segment statistics for
 MCMLSD, you can modify it to process other line segment detection algorithms

 run_eval_PR_4Methods.m and run_eval_PR.m process the statistical information from
 the run_create_contours_MCMLSD.m result and perform evaluations

 run_plot_PR.m and run_plot_PR4Methods.m plot the results in a graph
