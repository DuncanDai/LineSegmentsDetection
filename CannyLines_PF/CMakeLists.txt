PROJECT(cannylines)

CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

FIND_PACKAGE( OpenCV REQUIRED )
INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

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
