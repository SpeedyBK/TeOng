//
// Created by benjamin on 20.09.19.
//

#ifndef TEONG_CHESS_H
#define TEONG_CHESS_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Piece.h"
#include <list>
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
     * Initialises the startposition for both Players.
     */
    void startPosition();

    /*!
     * Backgound Texture;
     */
    sf::Texture BoardTexture;

    /*!
     * Sprite from the BordTexture;
     */
    sf::Sprite sBoard;

    /*!
     * Used for the Mouse as Input
     */
    sf::Mouse mouse;

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

    /*!
     * List of all the figures.
     */
    std::list <Piece*> figures;

};


#endif //TEONG_CHESS_H
