# Suggetion: only use MSVC compiler(multi-config) instead of MinGW(single-configuration)
#################################
PROJECT(cannylines ) # LANGUAGES CXX

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



### include: to add Mylib (static library)  -> not necessary
#INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})     # ${PROJECT_SOURCE_DIR}/lib  ${OpenCV_INCLUDE_DIRS}

### output bin files
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)  # `DIR_SRCS`: compile all the .cpp files
ADD_EXECUTABLE(${PROJECT_NAME} ${DIR_SRCS})

### include: static lib (manuall build)  -> not necessary
# find_library(opencv_dll NAMES opencv_world460 PATHS ${OpenCV_INCLUDE_DIRS}/../x64/vc15/lib)
### include: dynamical lib  -> not necessary
# LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib  ${OpenCV_INCLUDE_DIRS}/../x64/vc15/lib)


### link to Mylib (static library) from ${PROJECT_BINARY_DIR}
TARGET_LINK_LIBRARIES(${PROJECT_NAME} Mylib ${OpenCV_LIBS} )   # ${opencv_dll} -> not necessary



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
