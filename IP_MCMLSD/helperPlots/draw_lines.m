function draw_lines(lines)
%Summary of this function goes here
%   Detailed explanation goes here

num_lines = size(lines, 1);
for i = 1:num_lines
    x1 = lines(i, 1);
    y1 = lines(i, 2);
    x2 = lines(i, 3);
    y2 = lines(i, 4);
    line([x1 x2], [y1 y2],'Color','g', 'LineWidth', 1.2); 
end
end

