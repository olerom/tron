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
    Game(int speed) : speed(speed) {};

    ~Game() {};

    void startMenu(int switcher);

    bool static checkOver(Player firstPlayer, Map map, Player secondPlayer);

    int static myGetch();

    int static myKbhit();

    void setSpeed(int speed);

    int getSpeed();

private:
    void run();

    void clearScreen();

    void winMenu(int switcher);

    void loseMenu(int switcher);

    int settings();

    int speed;
};

#endif //TRON_GAME_H
