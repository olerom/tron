#ifndef TRON_USER_H
#define TRON_USER_H

#include <QtGui/QKeyEvent>
#include "Player.h"

class User : public Player {

public:
    User(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent = NULL);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    void setEnemy(Player *player);

    QPainterPath shape() const;

private:
    void keyPressEvent(QKeyEvent *event);

};


#endif
