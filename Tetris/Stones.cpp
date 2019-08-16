//
// Created by benjamin on 30.07.19.
//

#include "Stones.h"
#include <iostream>

Stones::Stones() = default;

Stones::~Stones() = default;

Stones::Stones(int Stonetype){
    startx = 12;
    starty = 3;


    for (int i = 0; i < 4; i++){
        a[i].x = appearance[Stonetype][i] % 2 + startx;
        a[i].y = appearance[Stonetype][i] / 2 + starty;
    }
}

void Stones::rotate() {
    Stone CG = a[1];
    for (int i = 0; i < 4; i++){
        int x = a[i].y-CG.y;
        int y = a[i].x-CG.x;
        a[i].x = CG.x - x;
        a[i].y = CG.y + y;
    }

    //ToDo Out of Bounds abfangen.
}

void Stones::move(int lr) {
    bool possible;
    for (int i = 0; i < 4; i++){
        if ((a[i].x <= 0 && lr == -1) || (a[i].x >= 9 && lr == 1)){
            possible = false;
            break;
        } else {
            possible = true;
        }
    }

    if (possible) {
        for (int i = 0; i < 4; i++) {
            a[i].x += lr;
        }
    }
}

float Stones::down(float timer, float delay) {
    if (timer > delay){
        for (int i = 0; i < 4; i++){
            a[i].y += 1;
            timer = 0;
        }
    }
    return timer;
}

void Stones::AddIncrement() { increment++; }

int Stones::GetIncrement() { return increment; }

void Stones::setPosition(int X, int Y) {

    for (int i = 0; i < 4; i++){
        a[i].x += X;
        a[i].y += Y;
    }
}
