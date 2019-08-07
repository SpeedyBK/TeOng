//
// Created by benjamin on 30.07.19.
//

#ifndef TEONG_STONES_H
#define TEONG_STONES_H

class Stones {

public:

    Stones();
    ~Stones();
    explicit Stones(int Stonetype);
    void rotate ();
    void move(int lr);
    float down(float timer, float delay);
    void AddIncrement();
    int GetIncrement();


    struct Stone {
        int x;
        int y;
    } a[4], b[4];

private:

    int appearance[7][4] = { {1, 3, 5, 7}, // I
                             {2, 4, 5, 7}, // Z
                             {3, 5, 4, 6}, // S
                             {3, 4, 5, 7}, // T
                             {2, 3, 5, 7}, // L
                             {3, 7, 5, 6}, // J
                             {2, 3, 4, 5}, // O
                            };

    int start;

    int increment = 0;

};

/*
 * 0 1
 * 2 3
 * 4 5
 * 6 7
 */


#endif //TEONG_STONES_H
