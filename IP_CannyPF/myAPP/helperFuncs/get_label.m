function [label_left_border, label_right_border] = get_label(label_data, folderName, imageName)
% test
% data.x2022_04_28_13_09_34.x38169360000 -> no label
%   [label_left_border, label_right_border] = get_label(label_data, 'x2022_04_28_13_09_34', 'x38169360000')
% data.x2022_04_28_13_09_34.x35424000 -> label: [683, 2132]
%   [label_left_border, label_right_border] = get_label(label_data, 'x2022_04_28_13_09_34', 'x35424000')

field = map_folderName2structField(folderName);
imageName = ['x', imageName(1:end-4)];

if ~isempty(getfield(label_data, field, imageName))
    value = getfield(label_data, field, imageName, 'coords');
    label_left_border = value(1);
    label_right_border = value(2);
else
    fprintf("Attention: this image has no label data!!!");
    label_left_border = [];
    label_right_border = [];
end

end


