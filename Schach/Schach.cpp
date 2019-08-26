//
// Created by benjamin on 26.08.19.
//

#include <iostream>
#include "Schach.h"

Schach::Schach() {

    std::cout << "Chess startet..." << std::endl;
    width = 800;
    height = 800;

    GameLoop();
}

void Schach::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(width, height), "Chess!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }


}
