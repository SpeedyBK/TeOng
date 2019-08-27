//
// Created by benjamin on 26.08.19.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <unistd.h>


#ifndef TEONG_SCHACH_H
#define TEONG_SCHACH_H


class Schach {

public:

    Schach();

    void getInfos();

    void GameLoop();

private:

    int width;
    int height;

    int NumberOfPlayers;
    int StoneColor;

    sf::Texture Board;
    sf::Texture Figures;

    sf::Sprite sBoard;

    sf::Text PlayerA;
    sf::Text PlayerB;
    std::string NameA;
    std::string NameB;

    sf::Clock clockA;
    sf::Clock clockB;
    int minA;
    int minB;
    int secA = 00;
    int secB = 00;
    sf::Text PlayerAClock;
    sf::Text PlayerBClock;


};


#endif //TEONG_SCHACH_H
