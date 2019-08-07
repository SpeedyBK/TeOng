//
// Created by benjamin on 28.07.19.
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Stones.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef TEONG_TETRIS_H
#define TEONG_TETRIS_H


class Tetris {

public:

    Tetris();

    bool CheckBottom();

    void CreateNewStone();

    void TetrisDebug();

    int RandomGen();

    void GameLoop();

    void CheckLines();

private:

    int width;
    int height;

    bool PlayingField [18][10];
    int offset = 40;
    bool check = false;

    Stones firstStone = Stones(1);
    std::vector<Stones> StonesVec;

    std::vector <int> RandVec;

    sf::Texture t;
    sf::Sprite s;

    sf::Music music;

    sf::Clock clock;
    float delay = 0.5f;
    float timer = 0.f;
    float timex;

};


#endif //TEONG_TETRIS_H
