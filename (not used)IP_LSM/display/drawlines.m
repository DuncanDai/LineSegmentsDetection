% This file is part of LSM.
% 
% LSM is free software: you can redistribute it and/or modify
% it under the terms of the GNU v3.0 General Public License as published by
% the Free Software Foundation.
% 
% LSM is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU General Public License for more details
% <http://www.gnu.org/licenses/>.

function drawlines(lines)
lines=sort_line_points_y( lines );
[~,sorted_inds]=sort(lines(:,1));  % first order: x1
lines=lines(sorted_inds,:);
[~,sorted_inds]=sort(lines(:,2)); % second order: y1
lines=lines(sorted_inds,:);
m=(lines(:,1:2)+lines(:,3:4))/2;
a=1;
for j=1:size(lines,1)
    if mod(j,size(cmap,1))+1==0
        keyboard
    end
%     line((lines(j,[1,3]))',(lines(j,[2,4])'),'Color',cmap(mod(a,size(cmap,1))+1,:),'LineWidth',1);
%     text(m(j,1),m(j,2),num2str(j),'Color',cmap(mod(a,size(cmap,1))+1,:),'FontSize',8);
    % 并没有对输出的double坐标进行处理
    line((lines(j,[1,3]))',(lines(j,[2,4])'),'Color','green','LineWidth',1);
    text(m(j,1),m(j,2),num2str(j),'Color','blue','FontSize',8);
    a=a+2;
end