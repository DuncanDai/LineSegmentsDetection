function label_data = load_label(fname)
%% only load once -> to get the label value
label_data = load_JSON(fname);
end