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
        }
    }

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

        Piece Albert(300, 300);

        window.draw(sBoard);
        window.draw(Albert.getSprite());

        window.display();
    }
}