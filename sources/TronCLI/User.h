#ifndef TRON_USER_H
#define TRON_USER_H

#include "stdafx.h"
#include "Player.h"
#include "Game.h"

class User : public Player {
public:
    User(int x, int y, Direction direction, int score, Map map);

    ~User() {}

    void logic();

    void reset(Map &map);
};


#endif //TRON_USER_H
