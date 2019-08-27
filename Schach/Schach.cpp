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

    if (!Figures.loadFromFile("../Textures/figures.png")){
        std::cout << "Problem loading Figures!" << std::endl;
    }

    sf::Sprite fTemp(Figures);

    sf::Sprite sTemp(Board);
    sBoard = sTemp;

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

    timeDisplay();

    for (int i = 0; i < 32; i++){
        sFigure[i].setTexture(Figures);
    }

    loadPosition();

    GameLoop();
}

void Schach::GameLoop() {

    std::cout << "Entering Game Loop" << std::endl;

    sf::RenderWindow window(sf::VideoMode(width, height), "Chess!");


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float timer = clock.getElapsedTime().asSeconds();
        clock.restart();
        time += timer;
        if (time > delay){
            clockFunction(true, 1);
            timeDisplay();
            time = 0;
        }

        window.clear();
        window.draw(sBoard);
        for (auto &it : sFigure){
            window.draw(it);
        }
        window.draw(PlayerA);
        window.draw(PlayerB);
        window.draw(PlayerAClock);
        window.draw(PlayerBClock);
        window.display();
        usleep(10000);
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
    }else if (NumberOfPlayers == 0){
        NameB = "Stockfish";
        NameA = "Stockfish";
    }

    std::cout << "Waehlen sie die Spielzeit in Minuten:" << std::endl;
    std::cin >> secA;
    secA *= 60;
    secB = secA;

}

void Schach::timeDisplay() {

    int MinutesA = (int) secA / 60;
    int MinutesB = (int) secB / 60;

    int SecondsA = secA % 60;
    int SecondsB = secB % 60;

    SecondsA < 10 ? PlayerAClock = sf::Text(std::to_string(MinutesA) + ":0" + std::to_string(SecondsA), MyFont) : PlayerAClock = sf::Text(std::to_string(MinutesA) + ":" + std::to_string(SecondsA), MyFont);
    SecondsB < 10 ? PlayerBClock = sf::Text(std::to_string(MinutesB) + ":0" + std::to_string(SecondsB), MyFont) : PlayerAClock = sf::Text(std::to_string(MinutesB) + ":" + std::to_string(SecondsB), MyFont);

    PlayerAClock.setPosition(875.f, 650.f);
    PlayerBClock.setPosition(875.f, 150.f);

}

void Schach::clockFunction(bool Player, int time) {

    if (Player){
        secA -= time;
    }else{
        secB -= time;
    }
}

void Schach::loadPosition() {

    int k = 0;
    int n = 0;
    int x;
    int y;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            n = ChessBoard[j][i];
            if (n == 0){
                continue;
            }
            x = abs(n)-1;
            n > 0 ? y = 1 : y = 0;
            sFigure[k].setTextureRect(sf::IntRect(size*x, size*y, size, size));
            sFigure[k].setPosition(size*i + i*9 + 53, size*j + j*9 + 48);
            k++;
        }
    }

}
