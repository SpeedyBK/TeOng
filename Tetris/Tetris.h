//
// Created by benjamin on 28.07.19.
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Stones.h"

#ifndef TEONG_TETRIS_H
#define TEONG_TETRIS_H


class Tetris {

public:

    Tetris();

    void GameLoop();

private:

    int width;
    int height;

    int PlayingField [18][10];
    int offset = 40;

    Stones Stone = Stones(2);

    sf::Texture t;
    sf::Sprite s;

    sf::Music music;

};


#endif //TEONG_TETRIS_H
