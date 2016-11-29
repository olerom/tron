#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include "stdafx.h"

class Player {
public:
    Player(int, int, Direction, int);

    Player();

    int getX();

    int getY();

    int getScore();

    void upScore();

    void setX(int);

    void setY(int);

    Direction getDirection();

    void setDirection(Direction);

    bool tail[80][20];

    void choiceMove(Direction direction);

protected:
    int score;
    int head_x;
    int head_y;
    Direction direction;
};

#endif //TRON_PLAYER_H