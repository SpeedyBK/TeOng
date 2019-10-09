//
// Created by benjamin on 20.09.19.
//

#ifndef TEONG_PIECE_H
#define TEONG_PIECE_H

#include "SFML/Graphics.hpp"


class Piece {

public:

    Piece();

    void printOutDebug();



protected:

    int posX;
    int posY;

    bool color;

    sf::Texture texture;
    sf::Sprite sprite;

private:


};


#endif //TEONG_PIECE_H
