%% version in use: in Pool  -> (up to date)
% run in `mexAPI` Workspace
mex -output mex_edgeDetecter ./mex_edgeDetecter.cpp ./src/run_edge_detecter.cpp ...
    -I"./lib"  -I"U:/my_apps/myOpencv/install/include" ...
    -L"U:/my_apps/myOpencv/install/x64/vc16/lib"  -lopencv_world460 -g 

%%
% %%
% mex cannyPF_mex.cpp CXXFLAGS="\$CXXFLAGS -fopenmp" LDFLAGS="\$LDFLAGS -fopenmp -lopencv_core -lopencv_imgproc" -I/usr/local/include -L/usr/local/lib 
% mexOpenCV
% 
% 
% %% 参考
% mex -g cannyPF_mex.cpp ../source/cannyPF.cpp ../source/ChainFromEdgeMap.cpp -I"D:\Program Files\opencv\build\include" -L"D:\Program Files\opencv\build\x64\vc15\lib" -lopencv_world343
% 
% % debug module
% mex -output cannyPF_mex cannyPF_mex.cpp ../source/cannyPF.cpp ../source/ChainFromEdgeMap.cpp ...
%     -I"../include" -I"U:/my_apps/opencv/build/include" ...
%     -L"U:/my_apps/opencv/build/x64/vc15/lib"  -lopencv_world460 -g -v
% 
% mex -output cannyPF_mex cannyPF_mex.cpp ../source/cannyPF.cpp ../source/ChainFromEdgeMap.cpp ...
%     COMPFLAGS="$COMPFLAGS /D_SECURE_SCL=0" ...
%     -I"../include" -I"U:/my_apps/opencv/build/include" ...
%     -L"U:/my_apps/opencv/build/x64/vc15/lib"  -lopencv_world460 -g -v
% 
% % 在不执行命令的情况下，使用 -n 选项可预览编译命令详细信息。输出包含特定于您的平台和编译器的信息
% -n
% 
% %% version in use: on my Thinkpad 
% mex -output mex_CannyPF ./mex_CannyPF.cpp ./src/cannyPF.cpp ./src/ChainFromEdgeMap.cpp ...
%     -I"./lib" -I"C:/My_APPs/2_Engineer/myOpencv/install/include" ...
%     -L"C:/My_APPs/2_Engineer/myOpencv/install/x64/vc16/lib"  -lopencv_world460 -g 




