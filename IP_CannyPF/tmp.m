
fig = figure(1);
tmp_img = imread('./_origin_rgb.png'); 
% tmp_gray = rgb2gray(tmp_img);
imshow(tmp_img);


get(fig)

img_tmp = img_gray;

tmp = img_gray(:;213);

%% only for tesst
tmp = imread("U:/my_projs/_test/data/cboard.png");
tmp_gray = rgb2gray(tmp);  

figure(1), image(tmp_1);
figure(2), image(tmp_2);
figure(3), image(tmp_3);




R=35;
G = 8;
B=6;
R*0.299 + G*0.587 + B*0.114
