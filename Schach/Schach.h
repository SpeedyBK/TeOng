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

    void timeDisplay();

    void clockFunction(bool Player, int time);

    void loadPosition();

    std::string toChessNotation(int OldPosX, int OldPoxY, int newPosX, int newPosY);

    void takeFigure(sf::Vector2f Posi);

private:

    bool onMove = false;
    float dx = 0;
    float dy = 0;

    int oldPosX;
    int oldPosY;

    int m =0;

    int size = (int) 80;

    int ChessBoard[8][8] = {{-1, -2, -3, -4, -5, -3, -2, -1},
                            {-6, -6, -6, -6, -6, -6, -6, -6},
                            { 0,  0,  0,  0,  0,  0,  0,  0},
                            { 0,  0,  0,  0,  0,  0,  0,  0},
                            { 0,  0,  0,  0,  0,  0,  0,  0},
                            { 0,  0,  0,  0,  0,  0,  0,  0},
                            { 6,  6,  6,  6,  6,  6,  6,  6},
                            { 1,  2,  3,  4,  5,  3,  2,  1}};;

    int width;
    int height;

    int NumberOfPlayers;
    int StoneColor;

    sf::Texture Board;
    sf::Texture Figures;

    sf::Sprite sBoard;
    sf::Sprite sFigure[32];

    sf::Text PlayerA;
    sf::Text PlayerB;
    std::string NameA;
    std::string NameB;

    sf::Font MyFont;

    sf::Clock clock;
    float time;
    float delay = 1.0f;
    int secA = 00;
    int secB = 00;
    sf::Text PlayerAClock;
    sf::Text PlayerBClock;

    int whiteTakes = 0;
    int blackTakes = 0;


};


#endif //TEONG_SCHACH_H
