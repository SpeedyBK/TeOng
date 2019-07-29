//
// Created by benjamin on 28.07.19.
//

#include <SFML/Window.hpp>

#ifndef TEONG_RACKET_H
#define TEONG_RACKET_H


class Racket {

public:

    explicit Racket(char player);

    int getPosition();
    void setPosition(int Position);
    void calcPosition();

private:

    int pos;
    char Player;

};


#endif //TEONG_RACKET_H
