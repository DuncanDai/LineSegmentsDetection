function train3_folders(imgInputPath, imgOutputPath)
% imgInputPath = 'U:\my_projs\imgSamples';  % for test 
% imgOutputPath = 'U:\my_projs\g_output';
folders = dir(imgInputPath);
foldersNumber = length(folders)-2;

for k = 3:foldersNumber+2
    imgFolder = folders(k).name;
    train2_singleFolder(imgFolder, imgInputPath, imgOutputPath);
end

end