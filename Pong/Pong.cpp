//
// Created by benjamin on 28.07.19.
//

#include "Pong.h"

Pong::Pong(){
    std::cout << "Pong is running: " << std::endl;

    width = 800;
    height = 600;
    ScoreA = 0;
    ScoreB = 0;

    std::cout << "Loading Music ... " << std::endl;

    if (!music.openFromFile("../Music/HK.wav")) {
        std::cout << "Problem with Music File!" << std::endl;
    }
    music.setLoop(true);
    music.play();

    std::cout << "Loading Sound ... " << std::endl;
    if (!wall.loadFromFile("../sounds/wall.wav")) {
        std::cout << "Problem with Sound File - Wall!" << std::endl;
    }

    if (!racket.loadFromFile("../sounds/racket.wav")) {
        std::cout << "Problem with Sound File - Racket!" << std::endl;
    }

    GameLoop();
}

void Pong::GameLoop() {

    sf::RenderWindow window(sf::VideoMode(width, height), "Pong!");
    sf::CircleShape PlayBall(10.f);
    sf::RectangleShape RacketA(sf::Vector2f(20, 80));
    sf::RectangleShape RacketB(sf::Vector2f(20, 80));
    PlayBall.setFillColor(sf::Color::Green);
    PlayBall.setPosition(ball.getXPos(), ball.getYPos());


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(PlayBall);
        window.draw(RacketA);
        window.draw(RacketB);
        window.display();
        ball.CalcVelo();
        ball.PosCalc();
        PlayBall.setPosition(ball.getXPos(), ball.getYPos());
        racketA.calcPosition();
        racketB.calcPosition();
        RacketA.setPosition(10, racketA.getPosition());
        RacketB.setPosition(width - 30, racketB.getPosition());
        ball.setHitType(DetectHit(ball.getXPos(), ball.getYPos(), racketA.getPosition(), racketB.getPosition()));

        for (int i = 0; i < 2000000 - ball.gethits(); i++ ){}
    }
}

int Pong::DetectHit(int X, int Y, int YPosA, int YPosB) {

    if (X <= 0){
        ScoreA++;
        std::cout << "Player A: " << ScoreA << " Player B: " << ScoreB << std::endl;
        return 2;
    }else if((X > 10) && (X < 30) && (Y > YPosA) && Y < (YPosA+10)) {
        sound.setBuffer(racket);
        sound.play();
        return 3;
    }else if(X > width - 50 && X < width - 30 && Y > YPosB && Y < YPosB+10){
        sound.setBuffer(racket);
        sound.play();
        return 3;
    }else if(X > 10 && X < 30 && Y >= YPosA + 10 && Y < YPosA + 20) {
        sound.setBuffer(racket);
        sound.play();
        return 4;
    }else if(X > width - 50 && X < width - 30 && Y >= YPosB + 10 && Y < YPosB + 20){
        sound.setBuffer(racket);
        sound.play();
        return 4;
    }else if(X > 10 && X < 30 && Y >= YPosA + 20 && Y < YPosA + 50) {
        sound.setBuffer(racket);
        sound.play();
        return 5;
    }else if(X > width - 50 && X < width - 30 && Y >= YPosB + 20 && Y < YPosB + 50){
        sound.setBuffer(racket);
        sound.play();
        return 5;
    }else if(X > 10 && X < 30 && Y >= YPosA + 50 && Y < YPosA + 60) {
        sound.setBuffer(racket);
        sound.play();
        return 4;
    }else if(X > width - 50 && X < width - 30 && Y >= YPosB + 50 && Y < YPosB + 60){
        sound.setBuffer(racket);
        sound.play();
        return 4;
    }else if(X > 10 && X < 30 && Y >= YPosA + 60 && Y < YPosA + 70) {
        sound.setBuffer(racket);
        sound.play();
        return 3;
    }else if(X > width - 50 && X < width - 30 && Y >= YPosB + 60 && Y < YPosB + 70){
        sound.setBuffer(racket);
        sound.play();
        return 3;
    }else if (X >= width - 20){
        ScoreB++;
        std::cout << "Player A: " << ScoreA << " Player B: " << ScoreB << std::endl;
        return 2;
    }else if (Y <= 0 || Y >= height - 20) {
        sound.setBuffer(wall);
        sound.play();
        return 1;
    }else{
        return 0;
    }
}