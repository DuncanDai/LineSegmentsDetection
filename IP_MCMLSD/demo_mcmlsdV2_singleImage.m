clear
clc
close all

% attention: filesep in linux is '/', in windows is '\' -> matlab will
% recognize it
addpath(genpath('code/'));
addpath('Resources/');
addpath(genpath('edges-master/'));
addpath('mcmlsdV2/');

%%% dinggen test
% img = imread(['Imgs', filesep, 'P1040823hr.jpg']);
% 'U:\my_projs\LineSegmentsDetection\LSM\Imgs\cboard.png'
img_path = 'U:\my_projs\imgSamples\2022-04-28_16-21-50\22529664000.png';
img_origin = imread(img_path);

% 1/16 size to the original image
% dinggen 08.26 test: full size
img = imresize(img_origin, [round(size(img_origin,1)/4), round(size(img_origin,2)/4)]);

%compute the kernel for the image size
%you only need to compute the kernal once for one an image size
% dinggen 2022.08.26 you only need to compute the kernal once for one type image size
[kernels, kernels_flip, kernel_params] =kernelInitialization(img);

%the lines variable contains the detected line segmentations it arranged as
%[x1 y1 x2 y2 probability]
%The fullLines are the detected lines. It is arranged as [rho theta probability]
ticId = tic;
[lines, fullLines] =lineSegmentation_HighRes(img, kernels, kernels_flip, kernel_params);
display('Total time');
toc(ticId)

fig = figure;
imshow(img);
hold on
%Order lines by probability
lines = sortrows(lines, -5);

linesNum = size(lines,1);
plotLineNum = min(50, linesNum);
for i = 1:plotLineNum
    %plot the top 90 lines
    line([lines(i,1) lines(i,3)], [lines(i,2) lines(i,4)],'Color','g', 'LineWidth', 1.5);  % ,  rand(1,3) 生成(1,3)矩阵  2.5宽度
end
%     imwrite(fig, ['..\g_output', filesep, imgSamples(k).name(1:end-4), filesep, '_1.png']);
%     saveas(fig, ['U:\my_projs\LineSegmentsDetection\g_output', filesep, imgSamples(k).name(1:end-4), '_1.png']);


%please use code in Evaluation code.zip to evaluate the performance of the line segmentation algorithm
[lines2] = mcmlsd2Algo(lines,img);
fig = figure;
imshow(img);
hold all
%Order lines by probability
lines2 = sortrows(lines2, -5);

linesNum = size(lines2,1);
plotLineNum = min(50, linesNum);
for i = 1:plotLineNum
    %plot the top 90 lines
    line([lines2(i,1) lines2(i,3)], [lines2(i,2) lines2(i,4)],'Color', 'g', 'LineWidth', 1.5);
end
%     imwrite(fig, ['..\g_output', filesep, imgSamples(k).name(1:end-4), filesep, '_2.png']);
%     saveas(fig, ['U:\my_projs\LineSegmentsDetection\g_output', filesep, imgSamples(k).name(1:end-4), '_2.png']);

