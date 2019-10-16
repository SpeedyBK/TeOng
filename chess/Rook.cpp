//
// Created by benjamin on 20.09.19.
//

#include "Rook.h"
#include <iostream>

Rook::Rook(int posX, int posY, int color) : Piece(posX, posY) {

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
    sprite.setTextureRect(sf::IntRect(0*80, color*86, 87, 85));
    sprite.setPosition(posX*85 + 44, posY*86+44);

}