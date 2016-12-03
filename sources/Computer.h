#ifndef TRON_COMPUTER_H
#define TRON_COMPUTER_H

#include "stdafx.h"
#include "Map.h"
#include "Game.h"

class Computer : public Player {
public:
    Computer(int x, int y, Direction direction, int score, Map map);

    Computer(int x, int y, Direction direction, int score, Map &map, Computer computer);

    void move(Player player, Map map);

    void reset(Map &map);

    Direction checkDirection(Player player, Map map);

    Direction findDirection(Player player, Map map, Direction direction);

    bool getChaos();

    bool getRandomChoice();
};


#endif //TRON_COMPUTER_H