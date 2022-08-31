PROJECT(cannylines)

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


ADD_SUBDIRECTORY(./lib)

ADD_SUBDIRECTORY(./src)

###############################################################################
# # set project's name
# PROJECT( CannyPF )
# # CMake settings
# CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

# # this command finds OpenCV libraries and sets all required variables
# FIND_PACKAGE(OpenCV REQUIRED)

# FILE(GLOB_RECURSE HDRS_FILES *.h *.hpp)
# FILE(GLOB_RECURSE SRCS_FILES *.c *.cpp)

# ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS_FILES} ${HDRS_FILES})
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
