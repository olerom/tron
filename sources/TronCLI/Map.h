#ifndef TRON_MAP_H
#define TRON_MAP_H

#include "Colors.h"
#include "stdafx.h"
#include "Player.h"

class Map {
public:
    Map(int height, int width);

    ~Map() {};

    void draw(Player firstPlayer, Player secondPlayer);

    int getWidth();

    int getHeight();

private:
    int width;
    int height;
};


#endif