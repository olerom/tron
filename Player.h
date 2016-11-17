#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include "stdafx.h"

class Player {
public:
    Player(int, int, Direction);

    Player();

    int getX();

    int getY();

    void setX(int);

    void setY(int);

    Direction getDirection();

    void setDirection(Direction);

    bool tail[60][15];

protected:
    int head_x;
    int head_y;
    Direction direction;
};


#endif //TRON_PLAYER_H