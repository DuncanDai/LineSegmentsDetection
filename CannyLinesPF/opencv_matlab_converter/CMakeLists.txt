cmake_minimum_required(VERSION 2.8)

PROJECT( opencv_matlab_standalone )
FIND_PACKAGE( OpenCV REQUIRED )
ADD_EXECUTABLE( opencv_matlab_standalone opencv_matlab_standalone)  # execytable obj: .cpp
TARGET_LINK_LIBRARIES( opencv_matlab_standalone ${OpenCV_LIBS} )