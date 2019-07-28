//
// Created by benjamin on 28.07.19.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Ball.h"
#include "Racket.h"

#ifndef TEONG_PONG_H
#define TEONG_PONG_H


class Pong {

public:

    Pong();

    void GameLoop();

    int DetectHit(int X, int Y, int YPosA, int YPosB);

private:

    Ball ball;
    Racket racketA;
    Racket racketB;
    sf::Music music;
    sf::SoundBuffer wall;
    sf::SoundBuffer racket;
    sf::Sound sound;
    int width;
    int height;
    int ScoreA;
    int ScoreB;

};


#endif //TEONG_PONG_H
