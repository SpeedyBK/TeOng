//
// Created by benjamin on 26.08.19.
//

#include <iostream>
#include "Schach.h"

Schach::Schach() {

    std::cout << "Chess startet..." << std::endl;
    width = 1100;
    height = 800;

    std::cout << "Loading textures..." << std::endl;

    if (!Board.loadFromFile("../Textures/board.png")){
        std::cout << "Problem loading textures!" << std::endl;
    }

    sf::Sprite sTemp(Board);
    sBoard = sTemp;

    sf::Font MyFont;

    if (!MyFont.loadFromFile("../Fonts/arial.ttf"))
    {
        throw std::exception();
    }

    getInfos();

    PlayerA = sf::Text(NameA , MyFont);
    PlayerB = sf::Text(NameB , MyFont);
    PlayerA.setPosition(875.f, 600.f);
    PlayerB.setPosition(875.f, 100.f);
    PlayerA.setFillColor(sf::Color::White);
    PlayerB.setFillColor(sf::Color::White);

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
        window.draw(sBoard);
        window.draw(PlayerA);
        window.draw(PlayerB);
        window.display();
    }


}

void Schach::getInfos() {

    std::cout << "Geben sie die Anzahl der Spieler ein..." << std::endl;
    std::cin >> NumberOfPlayers;

    if (NumberOfPlayers > 2){
        std::cout << "Geben Sie 0 für KI vs. KI ein." << std::endl;
        std::cout << "Geben Sie 1 für Spieler vs. KI ein." << std::endl;
        std::cout << "Geben Sie 2 für Spieler vs. Spieler ein." << std::endl;
        getInfos();
    } else if(NumberOfPlayers == 1){
        std::cout << "Waehlen Sie ihre Steine... 1 > Weiss, 0 > Schwarz" << std::endl;
        std::cin >> StoneColor;
        while (StoneColor > 1 || StoneColor < 0){
            std::cin >> StoneColor;
        }
        std::cout << "Geben Sie den Namen des Spielers ein..." << std::endl;
        if (StoneColor == 0) {
            std::cin >> NameA;
            NameB = "Stockfish";
        }else {
            std::cin >> NameB;
            NameA = "Stockfish";
        }

    }

}
