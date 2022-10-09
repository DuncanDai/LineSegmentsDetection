edges = [0, 20, 50, 200, 500, 2000, 2500];
% me choose: metric_RMSE_vertical  or  metric_RMSE_polyfit

hist = histogram(output_data.metric_RMSE, edges);  % , edges
xticks(edges(1:end)); %xtickangle(90);
xticklabels({'0','20','50','200', '500', '2000', '2500'})

set(gca, 'Ygrid','on'); 
xtips = (edges(1:end-1) + edges(2:end))/2; %double(hist.BinEdges(1:end-1));  
ytips = hist.Values; 
labels = string(hist.Values); 
text(xtips, ytips, labels,'HorizontalAlignment','center',...  %left, center, right
    'VerticalAlignment','bottom')


%%% bar
% x = 2012:1:2020;
% y = [1, 4, 2, 8, 49, 122, 358, 859, 1477];
% b = bar(x, y, 0.6) 
% xlabel('Year')
% ylabel('Number')
% set(gca,'ylim',[0,1600],'ytick',[0:200:1600]); 
% set(gca, 'Ygrid','on'); 
% xtips1 = b.XEndPoints;
% ytips1 = b.YEndPoints; 
% labels1 = string(b.YData); 
% text(xtips1,ytips1,labels1,'HorizontalAlignment','center',...
%     'VerticalAlignment','bottom')