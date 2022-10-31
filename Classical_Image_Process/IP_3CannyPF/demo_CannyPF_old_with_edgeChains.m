addpath('./mexAPI');
% addpath('./include');
% addpath('./source');
% addpath('U:/my_apps/opencv/build/x64/vc15/lib');
% addpath('U:/my_apps/opencv/build/include')

%% test: demo for only one image
imgPath = '../../g_dataset/test.png';
img_rgb = imread(imgPath);
img_rgb = im2double(img_rgb);
GaussSize = uint8(3);
VMGradient = 70.0;
img_gray = rgb2gray(img_rgb);  

[runTime, edgeMap, edgeChains] = mex_CannyPF_old(img_gray, GaussSize, VMGradient);

h = figure;
h.WindowState = 'minimized'; % don't show in the front  

imshow(img_gray, 'border', 'tight', 'initialmagnification', 100);   % img_gray is uint8 grayscale
ax = gca;
ax.Toolbar.Visible = 'off';

hold on

% [m,n] =find(edgeMap==255); -> too much noise
n = edgeChains(:,1);
m = edgeChains(:,2);
% plot(n,m, 'g')
scatter(n,m,2, 'filled','MarkerEdgeColor','g','MarkerFaceColor','g','LineWidth',0.01)


% plot(edgeChains(:,1), edgeChains(:, 2), 'g') -> plot is useless
% % sz = size(n,1);
% for i=1:20
%     plot(n(i), m(i), 'g')
% end

save_img_path = 'U:/my_projs/g_output_PPT/cannyPF_edgeChains.png';
f = getframe(gcf);

imwrite(f.cdata, save_img_path);

close;