#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include <QtWidgets/QGraphicsRectItem>

#include <QKeyEvent>

class Player : public QGraphicsRectItem {
public:
    Player(QGraphicsItem *parent = NULL);

    void keyPressEvent(QKeyEvent *event);

    QPointF prevPos;
};


#endif //TRON_PLAYER_H
