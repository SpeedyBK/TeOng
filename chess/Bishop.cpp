//
// Created by benjamin on 20.09.19.
//

#include "Bishop.h"
#include <iostream>

Bishop::Bishop(int posX, int posY, int color) : Piece(posX, posY) {

    this -> posX = posX;
    this -> posY = posY;

    try {
        if (!texture.loadFromFile("../Textures/figures.png")) {
            throw 1;
        }
    }catch (int error){
        if (error == 1){
            std::cout << "Chess Constructor: Error while loading textures" << std::endl;
        }
    }

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(2*80, color*84, 80, 83));
    sprite.setPosition(posX*85 + 44, posY*86+42);

}
