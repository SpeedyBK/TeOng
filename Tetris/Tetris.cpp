//
// Created by benjamin on 28.07.19.
//

#include "Tetris.h"


Tetris::Tetris(){
    std::cout << "Tetris is running... " << std::endl;

    width = 600;
    height = 800;

    std::cout << "Creating Playing Field... " << std::endl;
    for (int i = 0; i < 18; i++ ){
        for (int j = 0; j < 10; j++){
            PlayingField[i][j] = false;
        }
    }

    std::cout << "Loading Textures... " << std::endl;

    if (! t.loadFromFile("../Textures/TetrisTexture.png")){
        std::cout << "Error loading Texture" << std:: endl;
    }

    sf::Sprite sTemp(t);
    s = sTemp;
    s.setTextureRect(sf::IntRect(0,0,40,40));

    std::cout << "Loading Music ... " << std::endl;

    if (!music.openFromFile("../Music/tetris.wav")) {
        std::cout << "Problem with Music File!" << std::endl;
    }
    music.setLoop(true);
    music.play();

    srand(time(nullptr));

    GameLoop();
}

void Tetris::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris!");
    sf::RectangleShape line(sf::Vector2f(5, 800));
    line.setPosition(400, 0);
    line.setFillColor(sf::Color::Red);

    StonesVec.push_back(firstStone);
    RandVec.push_back(4);

    while (window.isOpen()) {

        timex = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=timex;

        int element = StonesVec.size();

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up){
                    StonesVec[element-1].rotate();
                }else if (event.key.code == sf::Keyboard::Left){
                    StonesVec[element-1].move(-1);
                }else if (event.key.code == sf::Keyboard::Right){
                    StonesVec[element-1].move(1);
                }
            }
        }

        CreateNewStone();

        window.clear(sf::Color::White);
        window.draw(line);
        for (int j = 0; j < StonesVec.size(); j++) {
            for (int i = 0; i < 4; i++) {
                s.setPosition(StonesVec[j].a[i].x * 40, StonesVec[j].a[i].y * 40);
                s.setTextureRect(sf::IntRect((RandVec[j]%5)*40,0,40,40));
                window.draw(s);
            }
        }
        window.display();
    }
}

bool Tetris::CheckBottom() {
    int Collision = 0;

    for (int i = 0; i < 4; i++){
        if (StonesVec[StonesVec.size()-1].a[i].y >= 17){
            Collision++;
        }else {
            for (int i = 0; i < 4; i++){
                if (PlayingField[StonesVec[StonesVec.size()-1].a[i].y+1][StonesVec[StonesVec.size()-1].a[i].x]){
                    Collision++;
                }
            }
        }
    }
    if (Collision != 0){
        check = true;
    }else {
        check = false;
    }

    return check;
}

void Tetris::CreateNewStone() {

    if (!CheckBottom()) {
        timer = StonesVec[StonesVec.size()-1].down(timer, delay);
    }else {
        for (int i = 0; i < 4; i++){
            PlayingField[StonesVec[StonesVec.size()-1].a[i].y][StonesVec[StonesVec.size()-1].a[i].x] = true;
        }
        check = false;
        //TetrisDebug();
        int Random = RandomGen();
        Stones NewStone = Stones(Random);
        StonesVec.push_back(NewStone);
        RandVec.push_back(Random);
        CheckLines();
        TetrisDebug();
    }
}

void Tetris::TetrisDebug(){
    for (int i = 0; i < 18; i++){
        for (int j = 0; j < 10; j++){
            std::cout << PlayingField[i][j];
        }
        std::cout << std::endl;
    }
    int t = 1;
    while (t != 0){
        t++;
    }
}

int Tetris::RandomGen() {
    int RandomNumber;

    RandomNumber = rand() % 7;

    return RandomNumber;
}

void Tetris::CheckLines() {

    int checksum = 0;

    for(int i = 18; i >= 0; --i){
        for (int j = 0; j < 10; j++){
            if (PlayingField[i][j]){
                checksum++;
            }
        }
        if (checksum == 10){
            // Zeile Löschen
            // Alles oberhalb der Zeile eins nach unten;

            for (int f = i; f >= 0; f--) {
                for (int j = 0; j < 10; j++) {
                    PlayingField[f][j] = PlayingField[f - 1][j];
                }
            }
            for (int g = 0; g < StonesVec.size(); g++){
                for (int h = 0; h < 4; h++){
                    if (StonesVec[g].a[h].y <= i){
                        StonesVec[g].a[h].y++;
                    }
                }
            }

            i++;
        }
        checksum = 0;
    }
}