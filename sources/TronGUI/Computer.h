#ifndef TRON_COMPUTER_H
#define TRON_COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
    Computer(GameWindow *gameBoard, QGraphicsItem *parent = NULL);

};


#endif
