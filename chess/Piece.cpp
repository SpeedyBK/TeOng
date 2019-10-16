//
// Created by benjamin on 20.09.19.
//

#include <iostream>
#include "Piece.h"

Piece::Piece() {

    std::cout << "Placeing Piece!" << std::endl;

    try {
        if (!texture.loadFromFile("../Textures/figures.png")) {
            throw 1;
        }
    }catch (int error){
        if (error == 1){
            std::cout << "Chess Constructor: Error while loading textures" << std::endl;
        }
    }
}

void Piece::printOutDebug() {

}

Piece::Piece(int PosiX, int PosiY) {

    posX = PosiX;
    posY = PosiY;

    color = 0;

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
    sprite.setTextureRect(sf::IntRect(0, 0, 87, 87));
    sprite.setPosition(posX, posY);

}

std::pair<int, int> Piece::getPosition() {
    return std::make_pair(posX, posY);
}
