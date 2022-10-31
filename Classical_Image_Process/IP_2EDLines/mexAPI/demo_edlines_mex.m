img_rgb = imread('../../../g_dataset/test.png');
img_gray = rgb2gray(img_rgb);  

[runTime_cpp, edgeLines] = mex_edgeDetecter(img_gray);

%%
addpath('../../helperPlots');

h = figure;
h.WindowState = 'minimized'; % don't show in the front  

imshow(img_gray, 'border', 'tight', 'initialmagnification', 100);   % img_gray is uint8 grayscale
ax = gca;
ax.Toolbar.Visible = 'off';

hold on
draw_edgeLines(edgeLines, 4);  % linewidth = 4

save_img_path = 'U:/my_projs/g_output_PPT/edlines.png';
f = getframe(gcf);

imwrite(f.cdata, save_img_path);

close;