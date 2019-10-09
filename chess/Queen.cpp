//
// Created by benjamin on 20.09.19.
//

#include "Queen.h"
#include <iostream>

Queen::Queen(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Dame Diana!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}