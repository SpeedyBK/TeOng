//
// Created by benjamin on 27.03.21.
//

#include <iostream>
#include "PongAI.h"

PongAI::PongAI() : T(1), tau(1), dTerm(0), iTerm(0), pTerm(0), SetPoint(300), maxLim(600), minLim(-600),
                   prevError(0), prevMessument(0), Kd(0.1), Ki(0.015), Kp(0.8)
{
    std::cout << "Initializing AI ... Done!" << std::endl;
}

PongAI::PongAI(float SP, float KP, float KI, float KD, float T, float tau) : SetPoint(SP), Kp(KP), Ki(KI), Kd(KD),
                                                                             T(T), tau(tau)
{
    this->dTerm = 0;
    this->pTerm = 0;
    this->iTerm = 0;
    this->prevMessument = 0;
    this->prevError= 0;
    this->minLim = -240;
    this->maxLim = 240;

    std::cout << "Initializing AI (with values) ... Done!" << std::endl;

}

void PongAI::setSP(float SP) {
    this->SetPoint = SP;
}

float PongAI::updatePID(float ballPosition) {

    //Calculate Error:
    float error = this->SetPoint - (ballPosition + 30);
    //cout << this->setpoint << " : " << actValue << " : " << this->err << endl;

    //Calculate P-Term:
    this->pTerm = this->Kp * error;

    //Calculate I-Term:
    this->iTerm = this->iTerm + this->Ki * this->T * (error + this->prevError);

    //Integrator Clamping:
    if (this->iTerm > this->maxLim){
        this->iTerm = this->maxLim;
    }else if (this->iTerm < this->minLim){
        this->iTerm = this->minLim;
    }

    //Calculate D-Term:
    this->dTerm = (2 * this->Kd * (ballPosition - this->prevMessument)
                  + (2 * this->T - this->tau) * this->dTerm) / (2 * this->tau + this->T);

    //Saving the Error and Value for next iteration:
    this->prevError = error;
    this->prevMessument = ballPosition;

    std::cout << "P-Term = " << this->pTerm << " - I-Term = " << this->iTerm << " - D-Term = " << this->dTerm;
    std::cout << " - Output = " << this->pTerm + this->iTerm + this->dTerm << std::endl;

    return this->pTerm + this->iTerm + this->dTerm;
}

void PongAI::setDifficulty(int level) {

    if (level == 3) {
        this->Kd = 0.1;
        this->Ki = 0.015;
        this->Kp = 0.8;
    }else if (level == 2) {
        this->Kd = 0.01;
        this->Ki = 0.011;
        this->Kp = 1;
    }else if (level == 4) {
        this->Kd = 0.01;
        this->Ki = 0.022;
        this->Kp = 1;
    }else if (level == 1) {
        this->Kd = 0.01;
        this->Ki = 0.011;
        this->Kp = 0.99;
    }else if (level == 5) {
        this->Kd = 0.2;
        this->Ki = 0.03;
        this->Kp = 1;
    }else if (level == 6) {
        this->Kd = 0.2;
        this->Ki = 0.035;
        this->Kp = 0.2;
    }else if (level == 7) {
        this->Kd = 0.8;
        this->Ki = 0.04;
        this->Kp = 0.2;
    }else if (level == 8){
        this->Kd = 0.8;
        this->Ki = 0.035;
        this->Kp = 0.6;
    } else if (level == 9){
        this->Kd = 0.2;
        this->Ki = 0.05;
        this->Kp = 0.2;
    } else{
        this->Kd = 0.8;
        this->Ki = 0.5;
        this->Kp = 0.8;
    }

}


