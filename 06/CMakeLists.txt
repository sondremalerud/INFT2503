cmake_minimum_required(VERSION 3.26)
project(06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(task1 chess/main.cpp
        chess/ChessBoard.hpp
        chess/ChessBoardPrint.hpp
)
