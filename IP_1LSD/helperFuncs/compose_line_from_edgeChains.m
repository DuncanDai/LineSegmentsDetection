function lines = compose_line_from_edgeChains(edgeChains)
% take the start and end points of one edgeChain to compose a line
edgeChain_number = edgeChains(end, 3);

lines = zeros(edgeChain_number, 4);
for i = 1:edgeChain_number
    edgeChain = edgeChains(edgeChains(:, 3) == i, :);
    x1 = edgeChain(1, 1);
    y1 = edgeChain(1, 2);
    x2 = edgeChain(end, 1);
    y2 = edgeChain(end, 2);
    lines(i, :) = [x1+1, y1+1, x2+1, y2+1];  % C++ is 0-based index, matlab is 1-based index
end
end


%% BEFORE: the edgeChains are CellArray -> just keep a BackUp here
% 2 show the image after edge chain judgment criteria
% x_range = size(img_gray, 2);
% edge_count = zeros(x_range,1);
% edge_number = size(edgeChains, 1);  
% 
% % me: 如何把edgeChains -> 变成lines: x1, y1, x2, y2
% for edgeIdx = 1:edge_number  %读取edgeChains中的结构体 -> chain对应edge的数量
%     one_edge_chain = edgeChains{edgeIdx};
%     point_number = size(one_edge_chain, 1);
%     for point_idx = 1:point_number
%         x_coord = one_edge_chain(point_idx, 1) + 1;  % in C/C++ index/coordinate 0-based
%         y_coord = one_edge_chain(point_idx, 2) + 1;
% 
%         img_edges(y_coord, x_coord) = 255;
%         edge_count(x_coord) = edge_count(x_coord) + 1;
%     end
% end