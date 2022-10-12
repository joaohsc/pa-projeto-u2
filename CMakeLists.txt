cmake_minimum_required(VERSION 3.5)

project(sculptor-3d-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(sculptor-3d-cpp main.cpp sculptor.cpp sculptor.h voxel.h)

install(TARGETS sculptor-3d-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

