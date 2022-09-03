mex cannyPF_mex.cpp CXXFLAGS="\$CXXFLAGS -fopenmp" LDFLAGS="\$LDFLAGS -fopenmp -lopencv_core -lopencv_imgproc" -I/usr/local/include -L/usr/local/lib


COMPFLAGS='$COMPFLAGS -std=c++17'

mex -output cannyPF_mex cannyPF_mex.cpp LDFLAGS="\$LDFLAGS -fopenmp -lopencv_core -lopencv_imgproc"


mex -output cannyPF_mex cannyPF_mex.cpp ../source/cannyPF.cpp ../source/ChainFromEdgeMap.cpp LDFLAGS="\$LDFLAGS -fopenmp -lopencv_core -lopencv_imgproc" -I../include -IU:/my_apps/opencv/build/include -LU:/my_apps/opencv/build/x64/vc15/lib