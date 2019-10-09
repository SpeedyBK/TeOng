//
// Created by benjamin on 20.09.19.
//

#include "Rook.h"
#include <iostream>

Rook::Rook(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Turm Tom!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}