#ifndef TRON_COMPUTER_H
#define TRON_COMPUTER_H

#include "stdafx.h"
#include "Map.h"
#include "Game.h"

class Computer : public Player {

public:
    Computer(int x, int y, Direction direction);

    Computer(Player player);

    void move(Player player, Map map);

    Direction checkDirection(Player player, Map map);

    Direction findDirection(Player player, Map map, Direction direction);
};


#endif //TRON_COMPUTER_H