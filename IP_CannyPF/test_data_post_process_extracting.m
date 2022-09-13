%% 1 show the image after filtered by CannyPF
img_origin = im2uint8 (img);
img_cannyPF = edgeMap;
img_edges = zeros(size(img_origin), 'like', img_origin);


% figure(1);
% imshow([img_origin, img_cannyPF]);

%% 2 show the image after edge chain judgment criteria
imageWidth = size(img_origin, 2);

edge_count = zeros(imageWidth,1);
edge_number = size(edgeChains, 1);  

% me: 如何把edgeChains -> 变成lines: x1, y1, x2, y2
for edgeIdx = 1:edge_number  %读取edgeChains中的结构体 -> chain对应edge的数量
    one_edge_chain = edgeChains{edgeIdx};
    point_number = size(one_edge_chain, 1);
    for point_idx = 1:point_number
        x_coord = one_edge_chain(point_idx, 1) + 1;  % in C/C++ index/coordinate 0-based
        y_coord = one_edge_chain(point_idx, 2) + 1;
        
        img_edges(y_coord, x_coord) = 255;
        edge_count(x_coord) = edge_count(x_coord) + 1;
    end
end

figure;
imshow([img_origin, img_cannyPF, img_edges]);

%% calculate the distribution of edgeChains
edge_range = size(edge_count,1);
edge_half_range = idivide(edge_range, uint16(2));
edge_count(1:edge_half_range, :)
edge_count(edge_half_range+1:end, :)

[max_val_one, max_idx_one] = max(edge_count(1:edge_half_range, :));
[max_val_two, max_idx_two] = max(edge_count(edge_half_range+1:end, :));
max_idx_two = max_idx_two + edge_half_range;

figure(3);
imshow(img);
hold on;
plot([max_idx_one, max_idx_one], [1,2064], 'Color', 'r', 'LineWidth', 2);
hold on;
plot([max_idx_two, max_idx_two], [1,2064], 'Color', 'r', 'LineWidth', 2);

%%
% figure; imshow(img);
% [cx,cy,c] = improfile;
% hold on; plot(cx, cy, 'r-', 'LineWidth', 2)
% figure; plot(c);