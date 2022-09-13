function valid_inds = filter_by_angle(angles, angleExpect, angleTolerance)
%Summary of this function goes here
%   Detailed explanation goes here
low = angleExpect - angleTolerance;
high = angleExpect + angleTolerance;

valid_inds = find(angles >= low & angles <= high);
end

