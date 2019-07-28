//
// Created by benjamin on 28.07.19.
//

#include <iostream>
#include <SFML/Audio.hpp>

#ifndef TEONG_TETRIS_H
#define TEONG_TETRIS_H


class Tetris {

public:

    Tetris();

    void GameLoop();

private:

    sf::Music music;

};


#endif //TEONG_TETRIS_H
