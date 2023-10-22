cmake_minimum_required(VERSION 3.26)
project(08)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(task1 task1/main.cpp)
add_executable(task2 task2/Pair.hpp task2/Pair.cpp task2/main.cpp)