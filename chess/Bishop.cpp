//
// Created by benjamin on 20.09.19.
//

#include "Bishop.h"
#include <iostream>

Bishop::Bishop(int positionX, int positionY, bool col) {

    std::cout << "Ich bin Laufer Franz!" << std::endl;

    posX = positionX;
    posY = positionY;

    color = col;

    printOutDebug();

}
