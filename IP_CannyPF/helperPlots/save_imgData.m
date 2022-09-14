function save_imgData(image, image_path)
% image_path example: ['U:\my_projs\g_output', filesep, imgSamples(k).name(1:end-4), '_label.png']

%% Output
% imwrite: input is data, not fig
imwrite(image, image_path);
end

