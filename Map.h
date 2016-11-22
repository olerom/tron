#ifndef TRON_MAP_H
#define TRON_MAP_H

#include "stdafx.h"
#include "Player.h"

class Map {
public:
    Map(int height, int width);

    void draw(Player firstPlayer, Player secondPlayer);

    int width;
    int height;
};


#endif