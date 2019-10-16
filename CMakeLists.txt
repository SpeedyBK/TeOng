cmake_minimum_required(VERSION 3.14)
project(TeOng)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/benjamin/sfml/include")
set(SFML_LIBRARY_DIR "/home/benjamin/sfml/lib")
set(SFML_DIR "/home/benjamin/sfml/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(TeOng main.cpp
        Pong/Pong.cpp
        Pong/Pong.h
        Tetris/Tetris.cpp
        Tetris/Tetris.h
        Pong/Ball.cpp
        Pong/Ball.h
        Pong/Racket.cpp
        Pong/Racket.h
        Tetris/Stones.cpp
        Tetris/Stones.h
        chess/King.cpp
        chess/King.h
        chess/Piece.cpp
        chess/Piece.h
        chess/Queen.cpp
        chess/Queen.h
        chess/Bishop.cpp
        chess/Bishop.h
        chess/Knight.cpp
        chess/Knight.h
        chess/Rook.cpp
        chess/Rook.h
        chess/Pawn.cpp
        chess/Pawn.h
        chess/chess.cpp
        chess/chess.h)

target_link_libraries (TeOng sfml-graphics sfml-audio sfml-window sfml-system)