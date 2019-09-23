//
// Created by benjamin on 20.09.19.
//

#ifndef TEONG_CHESS_H
#define TEONG_CHESS_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include <iostream>


class chess {

public:
    chess();

private:

    /*!
     * Main Loop for the game, will be called in Constructor.
     */
    void GameLoop();

    /*!
     * Just a convertion from the chess notation to screencoordinates.
     * @param ChessCoordinates like E5 are used in the game.
     * @return A sf::Vector2i with the screen coordinates.
     */
    sf::Vector2f to_ScreenCoordinates(std::pair <char, int> ChessCoordinates);

    /*!
     * Converts A = 1, B = 2, ..., H = 8.
     * @param chessChar
     * @return the corresponding integer Value.
     */
    int chessCharToInt (char chessChar);

    /*!
     * stopProgram runs an endless loop, until an 'E' is put in, then it breaks the loop and continues the
     * programm.
     */
    void stopProgram();

    /*!
     * Multiplying the BoardMatrix with -1 to invert colors of the players.
     */
    void BoardRotate();

    /*!
     * Backgound Texture;
     */
    sf::Texture BoardTexture;

    /*!
     * Sprite from the BordTexture;
     */
    sf::Sprite sBoard;

    /*!
     * Height of the boardtexture.
     */
    int height;

    /*!
     * Width of the boardtexture.
     */
    int width;

    /*!
     * Playing Field
     */
    std::vector <std::vector <int>> PlayingField;

};


#endif //TEONG_CHESS_H
