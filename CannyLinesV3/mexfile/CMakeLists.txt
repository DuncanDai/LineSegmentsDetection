PROJECT(CannyLinesV3)
CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

FIND_PACKAGE( OpenCV REQUIRED )
message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")
message(STATUS "PROJECT_BINARY_DIR = ${PROJECT_BINARY_DIR}")

ADD_SUBDIRECTORY(./lib)
ADD_SUBDIRECTORY(./src)







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
