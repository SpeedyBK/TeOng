//
// Created by benjamin on 20.09.19.
//

#include "Knight.h"
#include <iostream>

Knight::Knight(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Springer Lanzelott!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}