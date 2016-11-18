//
// Created by oleg on 07.11.16.
//

#ifndef TRON_GAME_H
#define TRON_GAME_H


#include "stdafx.h"
#include "Player.h"
#include "Map.h"

class Game {
public:
    void run();

    void startMenu();

    void clearScreen();

    bool checkOver(Player first_player, Map map, Player second_computer);

    Player logic(Player);

    Player computerLogic(Player player, Player computer, Map map);

    Player choiceMove(Player player, Direction direction);
};

#endif //TRON_GAME_H
