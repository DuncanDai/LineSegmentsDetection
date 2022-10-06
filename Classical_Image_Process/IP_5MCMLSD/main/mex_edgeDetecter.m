function [runTime_cpp, edgeLines] = mex_edgeDetecter(img)
% Note: This is not mex function, but just in consistent to the train,
% valid and futher test scripts
%
% Input(s):
%   - img: can be either rgb(original rgb image) or grayscale image(uint8), but double image (in matlab) is not allowed
%           in function `main_edge` (line 13-16: the input image will be double image)
%
%   - selectedLineNumber: hyperparameter
%
%
% Output(s):
%   - runTime_cpp = runTime_PHT + runTime_MCM
%   - edgeLines: arranged in one row (x1, x2, x3, x4)

global kernels kernels_flip kernel_params;
%% step1: PHT -> LSD
% The lines variable contains the detected line segmentations it arranged as [x1 y1 x2 y2 probability]
% The fullLines are the detected lines. It is arranged as [rho theta probability]
ticId1 = tic;
[lines, fullLines] = lineSegmentation_HighRes(img, kernels, kernels_flip, kernel_params);
runTime_PHT = toc(ticId1);
fprintf('Running time in PHT/LSD = %f second(s)\n', runTime_PHT);

%% step2: MCM -> get high score lines
ticId2 = tic;
% The lines2 is arranged as [x1 y1 x2 y2 probability score], see mcmlsd2Algo() to know what score is
[lines2] = mcmlsd2Algo(lines, img);
runTime_MCM = toc(ticId2);
fprintf('Running time in MCM = %f second(s)\n\n', runTime_MCM);
runTime_cpp = runTime_PHT + runTime_MCM;

edgeLines = sortrows(lines2, -6);

%% Choose the number of output lines
MIN_LINE_NUMBER = 25;  % more than 15 in  "demo"
line_number = size(edgeLines, 1);
selected_line_number = min(MIN_LINE_NUMBER, line_number);
edgeLines = edgeLines(1:selected_line_number, 1:4);

end




