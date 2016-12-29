#ifndef TRON_COMPUTER_H
#define TRON_COMPUTER_H

#include "Player.h"

class Computer : public Player {
public:
    Computer(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent = NULL);

    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
    Direction getChaos();

public slots:

    void advance(int step);
};


#endif
