//
// Created by benjamin on 28.07.19.
//

#include "Tetris.h"

Tetris::Tetris(){
    std::cout << "Tetris is running: " << std::endl;

    std::cout << "Loading Music ... " << std::endl;

    if (!music.openFromFile("../Music/tetris.wav")) {
        std::cout << "Problem with Music File!" << std::endl;
    }
    music.setLoop(true);
    music.play();

    GameLoop();
}

void Tetris::GameLoop() {
    int i = 0;

    std::cin >> i;

}