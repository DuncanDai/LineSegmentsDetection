INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS} ${PROJECT_BINARY_DIR} )
# get all .cpps in lib directory, save in DIR_LIB_SRCS
AUX_SOURCE_DIRECTORY(. DIR_LIB_SRCS)

# set the output path of lib
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# create the .cpps in Mylib 
# attention: .cpp include .h
ADD_LIBRARY(Mylib STATIC ${DIR_LIB_SRCS}) 