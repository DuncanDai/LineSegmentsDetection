function  windows_features = select_by_moving_windows(edges, scale, imageWidth, windowWidth, windowStepSize, angleExpect, angleTolerance) %, lenthThreshold, countThreshold)
% [left_border_index, right_border_index]


% Description: From the detected edges, use moving window to count the
% edges number in the window (the edges should have a angle within the angle tolerance) and
% calculate the edges length in the window to give a rank to the index in x
% axis, from which we select the left and right border index.
%
% Input:
%   - edges: different edge detecters produce different types of edges.
%       for LSD: two endpoints (OpenCV)
%       for EDLines: two endpoints (OpenCV)
%       for CannyPF: edgeChains -> use the start and end points in the chain as endpoints
%       for MCMLSD: two endpoints
%       The structure of edges is (x1, y1, x2, y2)
%   - scale = 4 (resize: one fourth in x axis)
%   - windowWidth (in pixels): the width of the border (recommended: 20 ~ 40 pixels)
%   - windowStepSize (in pixels): (recommended: one fourth of the width)
%   - angleExpect (in rad): angle of inclination of the border (recomended: (90 degree /180*pi) rad)
%   - angleTolerance: tolerance of the angle (recomended: (5 degree /180*pi) rad)
%   - lenthThreshold: to be decided
%   - countThreshold: to be decided
%
% Output:
%   - left_border_index
%   - right_border_index
%
% Preconditions: none
%
% Author: Dinggen DAI
% Date: 2022.09.12

windows_num = idivide(imageWidth, int32(windowStepSize), 'ceil');
windows_features = zeros(windows_num, 3);

for i = 1:windows_num
    windowStart = 1 + (windowStepSize * (i-1));
    windowsEnd = windowStart + windowWidth;
    [count, length, window_pos] = extract_window_features(edges, scale, windowStart, windowsEnd, angleExpect, angleTolerance);  % 里面有很多可以重复使用的数据 -> 后期修改
    windows_features(i, 1) = count;
    windows_features(i, 2) = length;
    windows_features(i, 3) = window_pos;
end