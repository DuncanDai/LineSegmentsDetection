function copy_img_from_table(dataTable)
t = clock; % Get current time
%%% 1 original output_data (all records are with labels)
fname = ['check_', ...
              num2str(t(2:3), '%02d')];  % month-day

%%% Attention: in PC, the disk is "E:\"
imgInputPath = 'E:/dataset_valid';
imgOutputPath = ['D:/My_Data/me_Projs/Proj_MA/g_output', filesep, fname];

sz = size(dataTable, 1);
for i = 1:sz
    folderName = dataTable.folderName(i); folderName = char(folderName);
    imgName = dataTable.imgName(i); imgName = char(imgName);
    
    src = [imgInputPath, filesep, folderName, filesep, imgName];
    dst = [imgOutputPath, filesep, folderName,'sep',imgName];
    copyfile(src, dst);
end

