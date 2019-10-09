//
// Created by benjamin on 20.09.19.
//

#include <iostream>
#include "King.h"


King::King(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Koenig Gustav!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}