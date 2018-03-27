cmake_minimum_required(VERSION 3.0)
project(iR_dev)


# libraries declaration
add_library(exampleLibrary ./src/example/example.cc)

# main
add_executable(iR_dev ./src/main.cc)



# library linking
target_link_libraries(iR_dev exampleLibrary)

# Add flags.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")