//
// Created by benjamin on 20.09.19.
//

#ifndef TEONG_PIECE_H
#define TEONG_PIECE_H

#include "SFML/Graphics.hpp"


class Piece {

public:

    Piece();
    Piece(int PosiX, int PosiY);
    ~Piece() = default;

    void printOutDebug();

    sf::Sprite getSprite(){ return sprite; };

    std::pair <int, int> getPosition();

    std::pair <int, int> convertMousePosition(sf::Vector2i MPos);

protected:

    int posX;
    int posY;

    int color;

    sf::Texture texture;
    sf::Sprite sprite;

private:


};


#endif //TEONG_PIECE_H
