function folderName = map_structField2folderName(structField)
% Usage:
% Input:  
%   - structField is 'x2022_04_28_14_09_13'
% Output:
%   - folderName is '2022-04-28_14-09-13'
folderName = strrep(structField, '_', '-');
folderName = folderName(2:end);
folderName(11) = '_';
end
