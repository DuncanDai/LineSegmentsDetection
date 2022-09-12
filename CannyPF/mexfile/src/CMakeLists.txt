# Suggetion: only use MSVC compiler(multi-config) instead of MinGW(single-configuration)
#################################
PROJECT(cannylines) # LANGUAGES CXX
CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

# Packages
FIND_PACKAGE( OpenCV REQUIRED )  # in OpenCV/../v15/bin
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")
message(STATUS "PROJECT_SOURCE_DIR = ${PROJECT_SOURCE_DIR}")
# -- OpenCV_INCLUDE_DIRS = U:/my_apps/opencv/build/include
# -- OpenCV_LIBS = opencv_calib3d;opencv_core;opencv_dnn;opencv_features2d;opencv_flann;opencv_gapi;opencv_highgui;opencv_imgcodecs;opencv_imgproc;opencv_ml;opencv_objdetect;opencv_photo;opencv_stitching;opencv_video;opencv_videoio;opencv_world
# -- PROJECT_BINARY_DIR = U:/my_projs/LineSegmentsDetection/CannyLines_PF/build
# -- PROJECT_SOURCE_DIR = U:/my_projs/LineSegmentsDetection/CannyLines_PF

### output bin files
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

ADD_SUBDIRECTORY(./lib)

### include: to add Mylib (static library)  -> not necessary
#INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/lib  ${OpenCV_INCLUDE_DIRS})   

AUX_SOURCE_DIRECTORY(./src  DIR_SRCS)  # `DIR_SRCS`: compile all the .cpp files
AUX_SOURCE_DIRECTORY(./  DIR_SRCS_MAIN)  # main.cpp -> need to be tested 2022.09.12
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS} ${DIR_SRCS_MAIN})

### include: static lib (manuall build)  -> not necessary
# find_library(opencv_dll NAMES opencv_world460 PATHS ${OpenCV_INCLUDE_DIRS}/../x64/vc15/lib)
### include: dynamical lib  -> not necessary
# LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib  ${OpenCV_INCLUDE_DIRS}/../x64/vc15/lib)


### link to Mylib (static library) from ${PROJECT_BINARY_DIR}
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Mylib ${OpenCV_LIBS} )   # ${opencv_dll} -> not necessary

