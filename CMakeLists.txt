cmake_minimum_required(VERSION 3.14)
project(TeOng)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/benjamin/Dependencies/sfml/include")
set(SFML_LIBRARY_DIR "/home/benjamin/Dependencies/sfml/lib")
set(SFML_DIR "/home/benjamin/Dependencies/sfml/lib/cmake/SFML")

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
        Pong/PongAI.cpp
        Pong/PongAI.h
        Tetris/Tetris.cpp
        Tetris/Tetris.h
        Pong/Ball.cpp
        Pong/Ball.h
        Pong/Racket.cpp
        Pong/Racket.h
        Tetris/Stones.cpp
        Tetris/Stones.h
        chess/Pieces/King.cpp
        chess/Pieces/King.h
        chess/Piece.cpp
        chess/Piece.h
        chess/Pieces/Queen.cpp
        chess/Pieces/Queen.h
        chess/Pieces/Bishop.cpp
        chess/Pieces/Bishop.h
        chess/Pieces/Knight.cpp
        chess/Pieces/Knight.h
        chess/Pieces/Rook.cpp
        chess/Pieces/Rook.h
        chess/Pieces/Pawn.cpp
        chess/Pieces/Pawn.h
        chess/chess.cpp
        chess/chess.h)

target_link_libraries (TeOng sfml-graphics sfml-audio sfml-window sfml-system)