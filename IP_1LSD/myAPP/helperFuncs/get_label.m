function [left_border_label, right_border_label] = get_label(label_data, folderName, imageNameWithPng)
% test
% data.x2022_04_28_13_09_34.x38169360000 -> no label
%   [label_left_border, label_right_border] = get_label(label_data, 'x2022_04_28_13_09_34', 'x38169360000')
% data.x2022_04_28_13_09_34.x35424000 -> label: [683, 2132]
%   [label_left_border, label_right_border] = get_label(label_data, 'x2022_04_28_13_09_34', 'x35424000')
%
% The results for label data
% 1) image is not in the label data: use "try-catch-end" (invalid field of struct)
% 2) img: null -> use "if ~isempty else"
% 3) img: not null & label: [null, null] -> not noticed that at first!!!
% 4) label: [left_value, right_value] -> use "if ~isempty else"

folderField = map_folderName2structField(folderName);
imageField = ['x', imageNameWithPng(1:end-4)];

if ~isempty(getfield(label_data, folderField, imageField))  % The outside function which calls get_label should deal with the exception of invalid imageField
    value = getfield(label_data, folderField, imageField, 'coords');
    left_border_label = value(1);
    right_border_label = value(2);
else  % This image is in the label.json file, but has no label 
    fprintf("(in get_label.m) Attention: this image has no label data!!!\n");
    fprintf("(in get_label.m) Additional notice: the input imageName should with suffix png!!!\n");
    left_border_label = 0;
    right_border_label = 0;
end

end


