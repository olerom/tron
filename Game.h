#ifndef TRON_GAME_H
#define TRON_GAME_H

#include "Player.h"
#include "Map.h"
#include "Computer.h"
#include "User.h"

#include "stdafx.h"
#include <termios.h>
#include <stropts.h>
#include <asm/ioctls.h>

class Game {
public:
    void run();

    void startMenu(int switcher);

    void clearScreen();

    bool static checkOver(Player first_player, Map map, Player second_computer);

    int static myGetch();

    int static myKbhit();
};

#endif //TRON_GAME_H
