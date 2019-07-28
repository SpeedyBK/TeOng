//
// Created by benjamin on 28.07.19.
//

#include "Racket.h"

Racket::Racket() {
    pos = 260;
}

int Racket::getPosition(){ return pos;}

void Racket::setPosition(int Position){
    pos = Position;
}