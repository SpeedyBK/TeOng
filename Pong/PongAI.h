//
// Created by benjamin on 27.03.21.
//

#ifndef TEONG_PONGAI_H
#define TEONG_PONGAI_H

/*!
 * To implement a Pong AI, we use basicly a pretty bad PID-Conteroller. The Controller gets the Ball-Y-Position
 * and should try to bring its racket somewhere close to this position. We can use the Kp, Ki, Kd constants to make
 * this PID-Controller better or worse, depending on the level of difficulty we want to play against.
 */
class PongAI {

public:

    PongAI();
    PongAI(float SP, float KP, float KI, float KD, float T, float tau);
    ~PongAI() = default;

    /*!
     * Methode to adjust the Setpoint.
     * @param SP Setpoint.
     */
    void setSP(float SP);

    /*!
     * Resets the the Controller to some standard values.
     */
    void resetPID();

    /*!
     * Methode to update the internal Value of our PID-Controller.
     * @param ballPosition
     * @return A correction Signal to change the position of AIs Racket.
     */
    float updatePID(float ballPosition);

    void setDifficulty(int level);

private:

    /*!
     * This is the Value, where the Internal-Error is 0.
     */
    float SetPoint;

    /*!
     * Sampletime and Timeconstant.
     */
    float T;
    float tau;

    /*!
     * Messurment- and Error-Values stored for next itteration.
     */
    float prevError;
    float prevMessument;

    /*!
     * Propotional-, Integral- and Derivative-Values.
     */
    float pTerm;
    float iTerm;
    float dTerm;

    /*!
     * Controller Constants.
     */
    float Kp;
    float Ki;
    float Kd;

    /*!
     * Limits for the Integral-Term to prevent wind-ups.
     */
    float minLim;
    float maxLim;

};


#endif //TEONG_PONGAI_H
