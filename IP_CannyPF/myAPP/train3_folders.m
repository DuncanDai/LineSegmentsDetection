function train3_folders(imgInputPath, imgOutputPath)
% imgInputPath = 'U:\my_projs\imgSamples';  % includes image folders 
% imgOutputPath = 'U:\my_projs\g_output';
folders = dir(imgInputPath);
foldersNumber = length(folders)-2;

for k = 3:foldersNumber+2
    folderName = folders(k).name;
    train2_singleFolder(folderName, imgInputPath, imgOutputPath);
end

end