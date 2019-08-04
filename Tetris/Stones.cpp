//
// Created by benjamin on 30.07.19.
//

#include "Stones.h"
#include <iostream>

Stones::Stones() = default;

Stones::Stones(int Stonetype){
    start = 4;

    for (int i = 0; i < 4; i++){
        a[i].x = appearance[Stonetype][i] % 2 + start;
        a[i].y = appearance[Stonetype][i] / 2;
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