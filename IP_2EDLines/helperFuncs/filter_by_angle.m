function valid_inds = filter_by_angle(angles, angleExpect, angleTolerance)
% Based on the expected angle and angle tolerance, select the valid index
% of edges 
%
% Input:
%   - angles: the angles of the edges
%   - angleExpect (in degree): angle of inclination of the border (recomended: 90 degree )
%   - angleTolerance (in degree): tolerance of the angle (recomended: 5 degree)

low = angleExpect - angleTolerance;
high = angleExpect + angleTolerance;

valid_inds = find(angles >= low & angles < high);
end

