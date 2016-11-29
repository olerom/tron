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
    void run(int &speed);

    void winMenu(int switcher);

    void loseMenu(int switcher);

    int settings();

    void startMenu(int switcher);

    void clearScreen();

    bool static checkOver(Player firstPlayer, Map map, Player secondPlayer);

    int static myGetch();

    int static myKbhit();
};

#endif //TRON_GAME_H
