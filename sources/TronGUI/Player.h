#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include <QtWidgets/QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QtGui>

class Player : public QObject, public QGraphicsRectItem {
Q_OBJECT
public:

    Player(QGraphicsItem *parent = NULL);

    void keyPressEvent(QKeyEvent *event);

    QPointF prevPos;


public slots:

    void keepMove();
};


#endif //TRON_PLAYER_H
