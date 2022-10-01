function output_corner_case = select_img_from_corner_case(output_data, corner_case)

sz = size(corner_case, 1);
output_corner_case = [];

for i=1:sz
    inds = find(output_data.folderName==corner_case{i, 1} & output_data.imgName==corner_case{i, 2});
    sub_data = output_data(inds, :);
    output_corner_case = [output_corner_case; sub_data];
end

