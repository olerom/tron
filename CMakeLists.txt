cmake_minimum_required(VERSION 3.6)
project(tron)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_subdirectory(sources)

#add_executable(tron ${SOURCE_FILES})