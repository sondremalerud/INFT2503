cmake_minimum_required(VERSION 3.26)
project(07)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(task1 fraction/fraction.hpp fraction/fraction.cpp fraction/main.cpp)
