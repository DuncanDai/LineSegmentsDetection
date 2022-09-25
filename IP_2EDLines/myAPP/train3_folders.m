function train3_folders(imgInputPath, imgOutputPath)

% if we want to stop the train/valid/test process, use flag_quit
global flag_quit;

folders = dir(imgInputPath);
foldersNumber = length(folders)-2;

for n = 3:foldersNumber+2
    folderName = folders(n).name;
    train2_singleFolder(imgInputPath, folderName, imgOutputPath);
    if flag_quit  % This is set in 'main1_train.m' line 72
        return
    end
end

end