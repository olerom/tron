#ifndef TRON_USER_H
#define TRON_USER_H

#include <QtGui/QKeyEvent>
#include "Player.h"
#include "GameWindow.h"

class User : public Player {

public:
    User(GameWindow *gameBoard, int score, Player *anotherPlayer = NULL, QGraphicsItem *parent = NULL);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QPainterPath shape() const;

private:
    void keyPressEvent(QKeyEvent *event);

};


#endif
