//
// Created by benjamin on 20.09.19.
//

#include "chess.h"
#include "Pieces/Pawn.h"
#include "Pieces/Rook.h"
#include "Pieces/King.h"
#include "Pieces/Knight.h"
#include "Pieces/Bishop.h"
#include "Pieces/Queen.h"
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

    startPosition();

    std::cout << "Entering Gameloop" << std::endl;
    GameLoop();
}


void chess::GameLoop() {

    int t = 0;
    sf::RenderWindow window(sf::VideoMode(width, height), "Chess!");
    while(window.isOpen()){

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(sBoard);
        for (auto &it : figures) {
            if (t == 0) {
                std::cout << "X: " << it->getPosition().first << " Y: " << it->getPosition().second << std::endl;
            }
            window.draw(it->getSprite());
        }
        window.display();
        t = 1;
    }
}

void chess::startPosition(){

    int i = 0;
    int j = 0;

    for (auto &rIt : PlayingField){
        for (auto &cIt : rIt){
            if (abs(cIt) == 1){
                if (cIt < 0) {
                    auto pawn = new Pawn(j, i, 1);
                    figures.push_back(pawn);
                }else{
                    auto pawn = new Pawn(j, i, 0);
                    figures.push_back(pawn);
                }
            }else if (abs(cIt) == 2){
                if (cIt < 0) {
                    auto rook = new Rook(j, i, 1);
                    figures.push_back(rook);
                }else{
                    auto rook = new Rook(j, i, 0);
                    figures.push_back(rook);
                }
            }else if (abs(cIt) == 3){
                if (cIt < 0) {
                    auto knight = new Knight(j, i, 1);
                    figures.push_back(knight);
                }else{
                    auto knight = new Knight(j, i, 0);
                    figures.push_back(knight);
                }
            }else if (abs(cIt) == 4){
                if (cIt < 0) {
                    auto bishop = new Bishop(j, i, 1);
                    figures.push_back(bishop);
                }else{
                    auto bishop = new Bishop(j, i, 0);
                    figures.push_back(bishop);
                }
            }else if (abs(cIt) == 5){
                if (cIt < 0) {
                    auto queen = new Queen(j, i, 1);
                    figures.push_back(queen);
                }else{
                    auto queen = new Queen(j, i, 0);
                    figures.push_back(queen);
                }
            }else if (abs(cIt) == 6){
                if (cIt < 0) {
                    auto king = new King(j, i, 1);
                    figures.push_back(king);
                }else{
                    auto king = new King(j, i, 0);
                    figures.push_back(king);
                }
            }
            j++;
        }
        j = 0;
        i++;
    }

}