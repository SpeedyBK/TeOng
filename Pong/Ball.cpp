//
// Created by benjamin on 28.07.19.
//

#include "Ball.h"

Ball::Ball() {

    hits = 0;
    HitType = 0;
    PosX = 380;
    PosY = 280;
    VelocityX = 1.f;
    VelocityY = 1.f;

}

int Ball::getXPos() { return PosX; }

int Ball::getYPos() { return PosY; }


void Ball::PosCalc(){

    PosX += (int)VelocityX;
    PosY += (int)VelocityY;

}

void Ball::CalcVelo() {

    switch(HitType) {
        case 1 : // Wall up or Down
            VelocityY = 0 - VelocityY;
            break;
        case 2 : // Left or Right OUT
            VelocityY = 1.f;
            VelocityX = 1.f;
            PosX = 380;
            PosY = 280;
            break;
        case 3 : // Hit Racket
            if (VelocityY <= 0){
                if (VelocityY >= -4) {
                    VelocityY -= 0.2f;
                }
            }else{
                if (VelocityY <= 4) {
                    VelocityY += 0.2f;
                }
            }
            VelocityX = 0 - VelocityX;
            hits+=1000;
            break;
        case 4 :
            if (VelocityY <= 0){
                VelocityY += 0.2f;
            }else{
                VelocityY -= 0.2f;
            }
            VelocityX = 0 - VelocityX;
            hits+=1000;
            break;
        case 5 :
            VelocityX = 0 - VelocityX;
            hits+=1000;
            break;
        default:
            VelocityY = VelocityY;
            VelocityX = VelocityX;
            break;
    }

    HitType = 0;
}

void Ball::setHitType(int hittype) {
    HitType = hittype;
}

int Ball::gethits() { return hits; }