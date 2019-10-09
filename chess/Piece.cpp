//
// Created by benjamin on 20.09.19.
//

#include <iostream>
#include "Piece.h"

Piece::Piece() {

}

void Piece::printOutDebug() {

    std::cout << "Debugging Output:" << std::endl;
    std::cout << "Position X: " << this -> posX << " / Position Y: " << this -> posY << std::endl;
    if (this -> color){
        std::cout << "Ich bin Weiss" << std::endl;
    }else {
        std::cout << "Ich bin Schwarz" << std::endl;
    }

    std::cout << std::endl;

}
