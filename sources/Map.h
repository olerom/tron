#ifndef TRON_MAP_H
#define TRON_MAP_H

#include "Colors.h"
#include "stdafx.h"
#include "Player.h"

class Map {
public:
    Map(int height, int width, int speed);

    void draw(Player firstPlayer, Player secondPlayer);

    int getWidth();

    int getHeight();

    int getSpeed();

private:
    int width;
    int height;
    int speed;
};


#endif