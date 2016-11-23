cmake_minimum_required(VERSION 3.6)
project(tron)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES sources/main.cpp sources/stdafx.h sources/Game.cpp sources/Game.h sources/Map.cpp sources/Map.h sources/Player.cpp sources/Player.h sources/Computer.cpp sources/Computer.h sources/User.cpp sources/User.h)
add_executable(tron ${SOURCE_FILES})

add_subdirectory(sources)