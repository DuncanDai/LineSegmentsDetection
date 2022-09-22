function valid_inds = filter_by_angle(angles, angleExpect, angleTolerance)
% Based on the expected angle and angle tolerance, select the valid index
% of edges 
%
% Input:
%   - angles: the angles of the edges
%   - angleExpect (in rad): angle of inclination of the border (recomended: (90 degree /180*pi) rad)
%   - angleTolerance (in rad): tolerance of the angle (recomended: (5 degree /180*pi) rad)

low = angleExpect - angleTolerance;
high = angleExpect + angleTolerance;

valid_inds = find(angles >= low & angles < high);
end

