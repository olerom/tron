#ifndef TRON_USER_H
#define TRON_USER_H

#include "stdafx.h"
#include "Player.h"
#include "Game.h"

class User : public Player {
public:
    User(int x, int y, Direction direction);

    User(Player player);

    void logic();
};


#endif //TRON_USER_H
