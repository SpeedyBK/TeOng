//
// Created by benjamin on 26.08.19.
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#ifndef TEONG_SCHACH_H
#define TEONG_SCHACH_H


class Schach {

public:

    Schach();

    void GameLoop();

private:

    int width;
    int height;

};


#endif //TEONG_SCHACH_H
