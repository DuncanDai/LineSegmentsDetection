img_uint  = uint8(img);
imshow(img_uint);
hold on

for i = 1:num_lines
    x1 = output_lines(i, 1);
    y1 = output_lines(i, 2);
    x2 = output_lines(i, 3);
    y2 = output_lines(i, 4);
    line([x1 x2], [y1 y2],'Color','g', 'LineWidth', 1.5); 
end


addpath('./helperFuncs');
edges = lines;
scale = 4;
imageWidth = size(img, 2) * scale;
windowWidth = 30;
windowStepSize = 10;
% windowStart = 10;
% windowsEnd = 1600;
angleExpect = pi/2;
angleTolerance = 5/180*pi;

[windows_features, edges_full_filtered_by_angle] = select_by_moving_windows(edges, scale, imageWidth, windowWidth, windowStepSize, angleExpect, angleTolerance);



close;
% img_path = 'U:\my_projs\imgSamples\2022-04-28_16-21-50\22529664000.png';
% img = imread(img_path);
img_gray = rgb2gray(img);
imshow(img_gray);
hold on
draw_lines(edges_full_filtered_by_angle)
plot(windows_features(:, 3)./4, windows_features(:, 2));
