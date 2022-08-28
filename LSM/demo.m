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

clear;
close all;
clc;

% addpath(genpath(pwd));
addpath('display\');
addpath('LSM-Dec16\');
addpath('lsd_1.6\');


%****THRESHOLD AND PARAMETER SETTING***%
xi_s=.05;   % spatial proximity threshold
tau_theta=pi/12; % angular proximity threshold

I=imread('U:\my_projs\LineSegmentsDetection\LSM\Imgs\cboard.png');
%I=imread('chainlink.png');
I=rgb2gray(I);
I=double(I);

%%
n_out = 0;
mrows = size(I,1);
ncols = size(I,2);

D=lsd(n_out, I/max(I(:))*255, ncols, mrows, 1.0);
[L]=mergeLines(D,tau_theta,xi_s);
display(strcat(int2str(size(L,1)),' merged line segments'));
imgD=display_image( D,I);
imgL=display_image( L,I);

imwrite([imgD imgL],'U:\my_projs\LineSegmentsDetection\g_output\result.png');