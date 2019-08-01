//
// Created by benjamin on 30.07.19.
//

#include "Stones.h"

Stones::Stones() = default;

Stones::Stones(int Stonetype){
    for (int i = 0; i < 4; i++){
        StoneArray[i] = appearance[Stonetype][i];
    }
}