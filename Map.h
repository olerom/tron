#ifndef TRON_MAP_H
#define TRON_MAP_H

#include "stdafx.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"

class Map {
public:
    Map(int height, int width);

    void draw(Player firstPlayer, Player secondPlayer);

    int width;
    int height;
};


#endif