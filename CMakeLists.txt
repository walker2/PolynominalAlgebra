cmake_minimum_required(VERSION 3.8)
project(poly)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Polynom.cpp Polynom.h Mod.h Task.cpp Task.h)
add_executable(poly ${SOURCE_FILES})