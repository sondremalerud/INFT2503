cmake_minimum_required(VERSION 3.26)
project(03)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(circle
        circle/circle.cpp
        circle/circle.hpp
)
add_executable(commodity
        commodity/commodity.cpp
        commodity/commodity.hpp
)
add_executable(string_practice string/string_practice.cpp)
