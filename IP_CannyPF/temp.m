R=35; G = 8; B=6;
R*0.299 + G*0.587 + B*0.114
%% only for test

figure(2);
imshow(img);
hold on
for i = 1:1604
    edge_1 = edgeChains(edgeChains(:, 3) == i, :);
    plot(edge_1(:, 1), edge_1(:, 2), 'color', 'green')  
end


%%
