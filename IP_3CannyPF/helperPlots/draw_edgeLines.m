function plt = draw_edgeLines(edgeLines)
%Summary of this function goes here
%   Detailed explanation goes here

num_lines = size(edgeLines, 1);
for i = 1:num_lines
    x1 = edgeLines(i, 1);
    y1 = edgeLines(i, 2);
    x2 = edgeLines(i, 3);
    y2 = edgeLines(i, 4);
    plt = line([x1 x2], [y1 y2],'Color','g', 'LineWidth', 1);   % only call the last line as `plt`
end
end

