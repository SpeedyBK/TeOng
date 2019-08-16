//
// Created by benjamin on 28.07.19.
//

#include "Tetris.h"


Tetris::Tetris(){
    std::cout << "Tetris is running... " << std::endl;

    width = 640;
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
    sf::RectangleShape lineHor(sf::Vector2f(640, 5));
    line.setPosition(400, 0);
    lineHor.setPosition(0, 720);
    line.setFillColor(sf::Color::Red);
    lineHor.setFillColor(sf::Color::Red);

    StonesVec.push_back(firstStone);
    StonesVec.push_back(secondStone);
    StonesVec[0].setPosition(-8, -3);
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
                    StonesVec[element-2].rotate();
                }else if (event.key.code == sf::Keyboard::Left){
                    StonesVec[element-2].move(-1);
                }else if (event.key.code == sf::Keyboard::Right){
                    StonesVec[element-2].move(1);
                }else if (event.key.code == sf::Keyboard::P){
                    delay = 10000000.f;
                }else if (event.key.code == sf::Keyboard::U){
                    delay = 0.5f;
                }else if (event.key.code == sf::Keyboard::Down){
                    delay = 0.05f;
                }
            }
        }

        CreateNewStone();

        window.clear(sf::Color::White);
        window.draw(line);
        window.draw(lineHor);
        for (int j = 0; j < StonesVec.size(); j++) {
            for (int i = 0; i < 4; i++) {
                if (StonesVec[j].a[i].y <= 17) {
                    s.setPosition(StonesVec[j].a[i].x * 40, StonesVec[j].a[i].y * 40);
                    s.setTextureRect(sf::IntRect((RandVec[j] % 5) * 40, 0, 40, 40));
                    window.draw(s);
                }
            }
        }
        window.display();
    }
}

bool Tetris::CheckBottom() {
    int Collision = 0;

    for (int i = 0; i < 4; i++){
        if (StonesVec[StonesVec.size()-2].a[i].y >= 17){
            Collision++;
        }else {
            for (int i = 0; i < 4; i++){
                if (PlayingField[StonesVec[StonesVec.size()-2].a[i].y+1][StonesVec[StonesVec.size()-2].a[i].x]){
                    Collision++;
                }
            }
        }
    }
    if (Collision != 0){
        check = true;
        delay = 0.5f;
    }else {
        check = false;
    }

    return check;
}

void Tetris::CreateNewStone() {

    if (!CheckBottom()) {
        timer = StonesVec[StonesVec.size()-2].down(timer, delay);
    }else {
        for (int i = 0; i < 4; i++){
            PlayingField[StonesVec[StonesVec.size()-2].a[i].y][StonesVec[StonesVec.size()-2].a[i].x] = true;
        }
        check = false;
        //TetrisDebug();
        int Random = RandomGen();
        Stones NewStone = Stones(Random);
        StonesVec.push_back(NewStone);
        StonesVec[StonesVec.size()-2].setPosition(-8, -3);
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
    std::cout << std::endl;
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

            for (int f = i; f > 0; f--) {
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

            i=18;
        }
        checksum = 0;
    }
    std::cout << StonesVec.size() << " Stone Objects.." << std::endl;
}