% edges = [0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 100, 200, 250, 500, 1000, 2000, 2500];
hist = histogram(output_data.metric_RMSE);  % , edges

set(gca, 'Ygrid','on'); 
xtips = double(hist.BinEdges(1:end-1));  
ytips = hist.Values; 
labels = string(hist.Values); 
text(xtips, ytips, labels,'HorizontalAlignment','left',...
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