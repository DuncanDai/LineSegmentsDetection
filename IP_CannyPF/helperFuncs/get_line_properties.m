function [lengths,angles]=get_line_properties(lines)
% caculated in matrix/vector form.
% lengths (in pixels)
% angles (in rad)  -> range is (0,pi]
%
% Input:
%   - lines: the structure of lines is (x1, y1, x2, y2)
x1 = lines(:,1); x2=lines(:,3);
y1 = lines(:,2); y2=lines(:,4);
dx = x2-x1;
dy = y2-y1;

lengths = sqrt(dx.^2+dy.^2);
angles  = atan2(dy, dx);
angles(angles<=0) = angles(angles<=0) + pi; %convert from (-pi,pi] to (0,pi]
end


