#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Pong/Pong.h"
#include "Tetris/Tetris.h"
#include "chess/chess.h"

void GameSelect(int selector);
void printPiInBinary(float* pi);

int main()
{
    using namespace std;
    int selector = 0;

    auto pi = (float) M_PI;
    printPiInBinary(&pi);

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
    }else if (selector == 3) {
        std::cout << "Running Chess!" << std::endl;
        chess Chess;
    }else{
        std::cout << "Error: Type 1 for Pong, type 2 for Tetris or type 3 for Chess" << std::endl;
        std::cin >> selector;
        GameSelect(selector);
    }
}

void printPiInBinary(float* pi){
    auto lptr = (int*) pi;
    std::array<int, 32> pi_bin = {};

    for (int i = pi_bin.size()-1; i >= 0; i--){
        pi_bin.at(i) = *lptr & 1;
        *lptr = *lptr >> 1;
    }

    std::cout << "This is Pi: " << std::endl;
    for (auto &it : pi_bin){
        std::cout << it;
    }
    std::cout << std::endl;
}