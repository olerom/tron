//
// Created by oleg on 07.11.16.
//

#ifndef TRON_MAP_H
#define TRON_MAP_H

#include "stdafx.h"
#include "Player.h"
#include "User.h"
#include "Computer.h"

class Map {
public:
    int width;
    int height;

    Map(int height, int width);

    void draw(Player firstPlayer, Player secondPlayer);
};


#endif //TRON_MAP_H