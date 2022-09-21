clear
clc
close all

addpath(genpath('Toolkit/code/'));
addpath(genpath('Toolkit/edges-master/'));
addpath('Toolkit/mcmlsdV2/');


img = imread(['Resources', filesep, 'test.png']);  % P1040823hr.JPG

img = imread('U:\my_projs\test4.png');
img = imresize(img, [round(size(img,1)/4), round(size(img,2)/4)]);

%compute the kernel for the image size
%you only need to compute the kernal once for one type of image size
[kernels, kernels_flip, kernel_params] =kernelInitialization(img);

%%
MIN_LINE_NUMBER = 15; % used as hyperparameter to select the edgeLine

ticId1 = tic;
% The lines variable contains the detected line segmentations it arranged as [x1 y1 x2 y2 probability]
% The fullLines are the detected lines. It is arranged as [rho theta probability]
[lines, fullLines] = lineSegmentation_HighRes(img, kernels, kernels_flip, kernel_params);
t1 = toc(ticId1);
disp(['Running time in PHT/LSD = ', num2str(t1), ' second(s)']);

figure(1);
imshow(img);
hold all

%Order lines by probability
sorted_lines = sortrows(lines, -5);  % descending
linesNumber = size(sorted_lines,1);
plotLineNumber = min(MIN_LINE_NUMBER, linesNumber);
for i = 1:plotLineNumber
    %plot the lines
    line([sorted_lines(i,1) sorted_lines(i,3)], [sorted_lines(i,2) sorted_lines(i,4)], 'Color', 'g', 'LineWidth', 1.5);
end

%%
%please use code in Evaluation code.zip to evaluate the performance of the line segmentation algorithm
ticId2 = tic;
% The lines2 is arranged as [x1 y1 x2 y2 probability score], see mcmlsd2Algo() to know what score is
[lines2] = mcmlsd2Algo(lines, img);
t2 = toc(ticId2);
disp(['Running time in MCM = ', num2str(t2), ' second(s)']);

figure(2);
imshow(img);
hold all

%Order lines by probability
sorted_lines2 = sortrows(lines2, -6);
linesNumber = size(sorted_lines2, 1);
plotLineNumber = min(MIN_LINE_NUMBER, linesNumber);
for i = 1:plotLineNumber
    %plot the lines
    line([sorted_lines2(i,1) sorted_lines2(i,3)], [sorted_lines2(i,2) sorted_lines2(i,4)], 'Color', 'g', 'LineWidth', 1.5);
end
