#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include "stdafx.h"

class Map;

class Player {
public:

    Player(int x, int y, Direction direction, int score, Map &map);

    virtual ~Player() {};

    int getX();

    int getY();

    int getScore();

    void upScore();

    virtual void reset(Map &map);

    void setX(int);

    void setY(int);

    Direction getDirection();

    void setDirection(Direction);

    bool getTail(int x, int y);

    void setTail(int x, int y);

    void choiceMove(Direction direction);

protected:
    int score;
    int head_x;
    int head_y;
    std::vector<std::vector<bool> > tail;
    Direction direction;
};

#endif //TRON_PLAYER_H