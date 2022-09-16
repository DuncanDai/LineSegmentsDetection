function save_imshow(image, save_path)
% example image_path = ['U:\my_projs\g_output', filesep, imgSamples(k).name(1:end-4), '_label.png']
% example image_path = ['U:\my_projs\g_output', filesep, '_label.png'];

%% Plot
fig = figure;
imshow(image,'border','tight','initialmagnification',100);

%% Output
% imwrite: input is data, not fig
% by using `getframe` -> the same as saveas
f = getframe(gcf);
imwrite(f.cdata, save_path);

close;
% getimage: no label
% I = getimage(gcf);
% imwrite(I, image_path);

% saveas：输入参数是fig 
% saveas(fig, image_path);
% saveas(gca, image_path, 'png');

% print：类似saveas
% I = gcf;
% print(I, '-dpng', image_path);
end

