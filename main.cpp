#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pong/Pong.h"
#include "Tetris/Tetris.h"
#include "Schach/Schach.h"

void GameSelect(int selector);

int main()
{
    int selector = 0;

    std::cout << "Game Menu: " << std::endl;
    std::cout << "Type 1 for Pong, type 2 for Tetris or type 3 for Chess" << std::endl;

    std::cin >> selector;

    GameSelect(selector);

    return 0;
}

void GameSelect(int selector){

    std::cout << selector << std::endl;


    if (selector == 1) {
        std::cout << "Running Pong!" << std::endl;
        Pong pong;
    }else if (selector == 2) {
        std::cout << "Running Tetris!" << std::endl;
        Tetris tetris;
    }else if (selector == 3){
        std::cout << "Running Chess!" << std::endl;
        Schach schach;
    }else{
        std::cout << "Error: Type 1 for Pong, type 2 for Tetris or type 3 for Chess" << std::endl;
        std::cin >> selector;
        GameSelect(selector);
    }

}