//
// Created by benjamin on 20.09.19.
//

#include "chess.h"
#include "Pawn.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include <cmath>

chess::chess() {
    this -> height = 760;
    this -> width = 760;

    try {
        std::cout << "Loading Board ..." << std::endl;
        if (!BoardTexture.loadFromFile("../Textures/board.png")) {
            throw 1;
        }
        sf::Sprite sBoardTemp(BoardTexture);
        sBoard = sBoardTemp;

        PlayingField.push_back({ 2,  3,  4,  5,  6,  4,  3,  2});
        PlayingField.push_back({ 1,  1,  1,  1,  1,  1,  1,  1});
        PlayingField.push_back({ 0,  0,  0,  0,  0,  0,  0,  0});
        PlayingField.push_back({ 0,  0,  0,  0,  0,  0,  0,  0});
        PlayingField.push_back({ 0,  0,  0,  0,  0,  0,  0,  0});
        PlayingField.push_back({ 0,  0,  0,  0,  0,  0,  0,  0});
        PlayingField.push_back({-1, -1, -1, -1, -1, -1, -1, -1});
        PlayingField.push_back({-2, -3, -4, -5, -6, -4, -3, -2});


    }catch (int error){
        if (error == 1){
            std::cout << "Chess Constructor: Error while loading Boardtexture" << std::endl;
            stopProgram();
        }
    }

    BoardSetup();

    std::cout << "Entering Gameloop" << std::endl;
    GameLoop();
}


void chess::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(width, height), "Chess!");
    while(window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(sBoard);
        window.display();
    }

}

sf::Vector2f chess::to_ScreenCoordinates(std::pair<char, int> ChessCoordinates) {

    int offset = 40;
    try {
        if (ChessCoordinates.second >= 0 && ChessCoordinates.second < 8) {
            int xValue = chessCharToInt(ChessCoordinates.first);
            int yValue = ChessCoordinates.second;
            sf::Vector2f ScreenVector(xValue * 87 + offset, yValue * 87 + offset);
            return ScreenVector;
        }else {
            throw 2;
        }
    }catch (int error){
        if (error == 1) {
            std::cout << "to_ScreenCoordinates X-Value out of Range" << std::endl;
            stopProgram();
        }else if (error == 2){
            std::cout << "to_ScreenCoordinates Y-Value out of Range" << std::endl;
            stopProgram();
        }
    }
    sf::Vector2f errValue(0,0);
    return errValue;
}

int chess::chessCharToInt(char chessChar) {

    if ((int) chessChar - 65 < 8 && (int) chessChar >= 0) {
        return (int) chessChar - 65;
    }else {
        throw 1;
    }

}

void chess::stopProgram() {

    while (true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            break;
        }
    }
}

void chess::BoardRotate() {

    for (auto &it : PlayingField){
        for (auto &zIt : it){
            zIt *= -1;
        }
    }
}

void chess::BoardSetup() {

    int indexX = 0;
    int indexY = 0;
    bool color = false;

    for (auto &rIt : PlayingField){
        for (auto &cIt : rIt){
            if (cIt > 0){
                color = true;
            }else{
                color = false;
            }
            if (abs(cIt) == 1){
                auto Bauer = new Pawn(indexX, indexY, color);
                figures.push_back(Bauer);
                delete Bauer;
            }else if (abs(cIt) == 2){
                auto Turm = new Rook(indexX, indexY, color);
                figures.push_back(Turm);
                delete Turm;
            }else if (abs(cIt) == 3){
                auto Springer = new Knight(indexX, indexY, color);
                figures.push_back(Springer);
                delete Springer;
            }else if (abs(cIt) == 4){
                auto Laufer = new Bishop(indexX, indexY, color);
                figures.push_back(Laufer);
                delete Laufer;
            }else if (abs(cIt) == 5){
                auto Dame = new Queen(indexX, indexY, color);
                figures.push_back(Dame);
                delete Dame;
            }else if (abs(cIt) == 6){
                auto Koenig = new King(indexX, indexY, color);
                figures.push_back(Koenig);
                delete Koenig;
            }
            indexX++;
        }
        indexX = 0;
        indexY++;
    }

}
