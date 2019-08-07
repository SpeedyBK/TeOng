//
// Created by benjamin on 28.07.19.
//

#include <iostream>

#ifndef TEONG_BALL_H
#define TEONG_BALL_H


class Ball {

public:

    Ball();

    int getXPos();
    int getYPos();

    void PosCalc();
    void CalcVelo();

    void setHitType(int hittype);
    int gethits();

private:

    bool HitFlag;
    int hits;
    int HitType;
    int PosX;
    int PosY;
    float VelocityX;
    float VelocityY;

};


#endif //TEONG_BALL_H
