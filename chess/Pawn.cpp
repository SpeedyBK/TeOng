//
// Created by benjamin on 20.09.19.
//

#include <iostream>
#include "Pawn.h"

Pawn::Pawn(int posX, int posY, int color) : Piece(posX, posY) {

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
    sprite.setTextureRect(sf::IntRect(5*80, color*87, 87, 87));
    sprite.setPosition(posX*86 + 44, posY*86+44);

}
