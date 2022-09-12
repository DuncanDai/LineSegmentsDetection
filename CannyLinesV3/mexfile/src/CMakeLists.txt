PROJECT(cannylines)
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

FIND_PACKAGE( OpenCV REQUIRED )
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")

ADD_SUBDIRECTORY(./lib)



INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib ${PROJECT_BINARY_DIR})
# 输出二进制文件到 指定目录 => 实际上是`demo4`文件
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)  # 创建`DIR_SRCS变量`：存储 当前目录的源文件
# me test?
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)
ADD_EXECUTABLE(cannylines ${DIR_SRCS})

# 链接库Mylib (该库是静态库) from lib directory
TARGET_LINK_LIBRARIES(cannylines Mylib ${OpenCV_LIBS}) 
###############################################################################
# # CMake settings
# CMAKE_MINIMUM_REQUIRED(VERSION 3.0.0)

# # this command finds OpenCV libraries and sets all required variables
# FIND_PACKAGE(OpenCV REQUIRED)

# FILE(GLOB_RECURSE HDRS_FILES *.h *.hpp)
# FILE(GLOB_RECURSE SRCS_FILES *.c *.cpp)

# #ADD_LIBRARY(${PROJECT_NAME}  ${HDRS_FILES} ${SRCS_FILES})
# #TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})

# ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS_FILES})
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})


###############################################################################
# # CMake settings
# CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

# # this command finds OpenCV libraries and sets all required variables
# FIND_PACKAGE(OpenCV REQUIRED)

# FILE(GLOB_RECURSE HDRS_FILES *.h *.hpp)
# FILE(GLOB_RECURSE SRCS_FILES *.c *.cpp)

# ADD_EXECUTABLE(${PROJECT_NAME} ${SRCS_FILES} ${HDRS_FILES})
# TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})
