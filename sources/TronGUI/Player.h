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

    enum Direction {
        UP, RIGHT, DOWN, LEFT
    };

    Player(QGraphicsItem *parent = NULL);

    void keyPressEvent(QKeyEvent *event);

    Direction direction;

    QPointF head;
    QList<QPointF> tail;

    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

public slots:

    void keepMove();
};


#endif //TRON_PLAYER_H
