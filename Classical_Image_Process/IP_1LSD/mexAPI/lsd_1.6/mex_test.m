img_gray = rgb2gray(img_rgb);  
img = double(img_gray); 

[output_img, num_lines] = mex_lsd(img, 0.8);