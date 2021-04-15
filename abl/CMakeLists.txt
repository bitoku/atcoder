cmake_minimum_required(VERSION 3.17)
project(abl)

set(CMAKE_CXX_STANDARD 14)

add_executable(ablc c.cpp)
add_executable(abld d.cpp)