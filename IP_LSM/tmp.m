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

