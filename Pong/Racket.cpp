//
// Created by benjamin on 28.07.19.
//

#include "Racket.h"

Racket::Racket(char player) {
    Player = player;
    pos = 260;
}

int Racket::getPosition(){ return pos;}

void Racket::setPosition(int Position){
    pos = Position;
}

void Racket::calcPosition(){
    if (Player == 'A') {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            if (pos > 0) {
                pos -= 2;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            if (pos < 520) {
                pos += 2;
            }
        }
    }else if (Player == 'B'){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8)) {
            if (pos > 0) {
                pos -= 2;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2)) {
            if (pos < 520) {
                pos += 2;
            }
        }
    }
}