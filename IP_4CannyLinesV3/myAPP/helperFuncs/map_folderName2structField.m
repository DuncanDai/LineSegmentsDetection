function structField = map_folderName2structField(folderName)
% Usage:
% Input:  
%   - folderName is '2022-04-28_14-09-13'
% Output:
%   - structField is 'x2022_04_28_14_09_13'
structField = strrep(folderName, '-', '_');
structField = ['x', structField];
end

