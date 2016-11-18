#ifndef TRON_GAME_H
#define TRON_GAME_H

#include "Player.h"
#include "Map.h"

#include "stdafx.h"
#include <termios.h>
#include <stropts.h>
#include <asm/ioctls.h>

class Game {
public:
    void run();

    void startMenu(int switcher);

    void clearScreen();

    bool checkOver(Player first_player, Map map, Player second_computer);

    Player logic(Player);

    Player computerLogic(Player player, Player computer, Map map);

    Player choiceMove(Player player, Direction direction);

    int myGetch();

    int myKbhit();
};

#endif //TRON_GAME_H
