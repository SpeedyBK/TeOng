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
            PlayingField[i][j] = 0;
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

    GameLoop();
}

void Tetris::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(width, height), "Tetris!");
    sf::RectangleShape line(sf::Vector2f(5, 800));
    line.setPosition(400, 0);
    line.setFillColor(sf::Color::Red);

    while (window.isOpen()) {

        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up){
                    Stone.rotate();
                }else if (event.key.code == sf::Keyboard::Left){
                    Stone.move(-1);
                }else if (event.key.code == sf::Keyboard::Right){
                    Stone.move(1);
                }
            }
        }
        window.clear(sf::Color::White);
        window.draw(line);
        for (int i = 0; i < 4; i++){
            s.setPosition(Stone.a[i].x * 40, Stone.a[i].y * 40);
            window.draw(s);
        }


        /*for (int i = 0; i < 18; i++){
            for (int j = 0; j < 10; j++){

            }
        }*/
        window.display();
    }
}