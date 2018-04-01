cmake_minimum_required(VERSION 3.0)
project(iR_dev)

set_property(GLOBAL PROPERTY USER_FOLDER ON)
set (CMAKE_VERBOSE_MAKEFILE 1)

find_package(OpenCV REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})
message(STATUS "openc = ${OpenCV_VERSION}")

# libraries declaration
add_library(exampleLibrary ./src/example/example.cc)

# main
add_executable(iR_dev ./src/main.cc)


# library linking
target_link_libraries(iR_dev exampleLibrary ${OpenCV_LIBS})

# Add flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

#cmake_minimum_required(VERSION 2.8)
#project( DisplayImage )
#find_package( OpenCV REQUIRED )
#include_directories( ${OpenCV_INCLUDE_DIRS} )
#add_executable( DisplayImage DisplayImage.cpp )
#target_link_libraries( DisplayImage ${OpenCV_LIBS} )
