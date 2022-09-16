%% Plot
fig = figure;
imshow(image,'border','tight','initialmagnification',100);

%% Output: imwrite
% imwrite: input is data, not fig
imwrite(image, image_path);

% by using `getframe` -> the same as saveas
f = getframe(gcf);
imwrite(f.cdata, save_path);
close;


% getimage: no label
% f = getimage(gcf);
% imwrite(f, image_path);

%% Output: saveas
% saveas：输入参数是fig 
% saveas(fig, image_path);
% saveas(gca, image_path, 'png');

%% Output: print -> 类似saveas
% I = gcf;
% print(I, '-dpng', image_path);



