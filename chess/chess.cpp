//
// Created by benjamin on 20.09.19.
//

#include "chess.h"

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

        PlayingField[0] = { 2,  3,  4,  5,  6,  4,  3,  2};
        PlayingField[1] = { 1,  1,  1,  1,  1,  1,  1,  1};
        PlayingField[2] = { 0,  0,  0,  0,  0,  0,  0,  0};
        PlayingField[3] = { 0,  0,  0,  0,  0,  0,  0,  0};
        PlayingField[4] = { 0,  0,  0,  0,  0,  0,  0,  0};
        PlayingField[5] = { 0,  0,  0,  0,  0,  0,  0,  0};
        PlayingField[6] = {-1, -1, -1, -1, -1, -1, -1, -1};
        PlayingField[7] = {-2, -3, -4, -5, -6, -4, -3, -2};



    }catch (int error){
        if (error == 1){
            std::cout << "Chess Constructor: Error while loading Boardtexture" << std::endl;
            stopProgram();
        }
    }

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
