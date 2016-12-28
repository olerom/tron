#ifndef TRON_USER_H
#define TRON_USER_H

#include <QtGui/QKeyEvent>
#include "Player.h"

class User : public Player {

public:
    User(GameWindow *gameBoard, QGraphicsItem *parent = NULL);

private:
    void keyPressEvent(QKeyEvent *event);

};


#endif
