cmake_minimum_required(VERSION 3.26)
project(06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_executable(task1 chess/main.cpp
        chess/ChessBoard.hpp
        chess/ChessBoardPrint.hpp
)
add_executable(task2 web-server/main.cpp )
target_link_libraries(task2 ${Boost_LIBRARIES})