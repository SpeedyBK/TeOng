//
// Created by benjamin on 26.08.19.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>

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

};


#endif //TEONG_SCHACH_H
