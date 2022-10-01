function table_data_with_label = select_data_with_label(table_data)

inds = find(table_data.is_labeled == true);
table_data_with_label = table_data(inds, :);
end

