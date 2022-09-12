INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/lib ${PROJECT_BINARY_DIR})

# output bin files
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

AUX_SOURCE_DIRECTORY(./ DIR_SRCS)    # `DIR_SRCS`: compile all the .cpp files

ADD_EXECUTABLE(${PROJECT_NAME}  ${DIR_SRCS})

# link to Mylib (static library) from ${PROJECT_BINARY_DIR}
TARGET_LINK_LIBRARIES( ${PROJECT_NAME}   Mylib ${OpenCV_LIBS}) 














###############################################################################origin： with issue
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
