function output_data = add_corner_case_label(output_data, corner_case)

size_corner_cases = size(corner_case, 1);
for i = 1:size_corner_cases
    inds = find(output_data.folderName==corner_case{i, 1} & output_data.imgName==corner_case{i, 2});
    output_data.is_corner_case(inds) = true;
end

end

