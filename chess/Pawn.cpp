//
// Created by benjamin on 20.09.19.
//

#include <iostream>
#include "Pawn.h"

Pawn::Pawn(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Bauer Johann!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}
