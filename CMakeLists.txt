cmake_minimum_required(VERSION 3.6)
project(tron)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stdafx.h Game.cpp Game.h Map.cpp Map.h Player.cpp Player.h Computer.cpp Computer.h User.cpp User.h)
add_executable(tron ${SOURCE_FILES})