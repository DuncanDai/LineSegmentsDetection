function [train_path, validate_path, test_path] =  parser_JSON_dataset(filename)
data = load_JSON(filename);

%% train dataset -> cell array
trainFolders = fieldnames(data.train);
folderNumber = size(trainFolders, 1);
row = 1;
train_path = {};
for i = 1:folderNumber
    folderName = trainFolders{i, 1}(2:end);
    imagesName = data.train.(trainFolders{i, 1});
    imagesNumber = size(imagesName, 1);
    for j = 1:imagesNumber
        train_path(row, 1) = {folderName};
        train_path(row, 2) = {imagesName{j, 1}};
        row = row + 1;
    end
end


%% validation dataset -> cell array
validateFolders = fieldnames(data.val);
folderNumber = size(validateFolders, 1);
row = 1;
validate_path = {};
for i = 1:folderNumber
    folderName = validateFolders{i, 1}(2:end);
    imagesName = data.val.(validateFolders{i, 1});
    imagesNumber = size(imagesName, 1);
    for j = 1:imagesNumber
        validate_path(row, 1) = {folderName};
        validate_path(row, 2) = {imagesName{j, 1}};
        row = row + 1;
    end
end

%% test dataset -> cell array
testFolders = fieldnames(data.test);
folderNumber = size(testFolders, 1);
row = 1;
test_path = {};
for i = 1:folderNumber
    folderName = testFolders{i, 1}(2:end);
    imagesName = data.test.(testFolders{i, 1});
    imagesNumber = size(imagesName, 1);
    for j = 1:imagesNumber
        test_path(row, 1) = {folderName};
        test_path(row, 2) = {imagesName{j, 1}};
        row = row + 1;
    end
end
