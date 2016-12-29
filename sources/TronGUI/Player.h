#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include <QtWidgets/QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include <QtGui>

class GameWindow;

enum Direction {
    UP, RIGHT, DOWN, LEFT
};

class Player : public QObject, public QGraphicsRectItem {
Q_OBJECT
public:

    Player(GameWindow *gameBoard, QGraphicsItem *parent = NULL);

    Direction direction;

    QPointF head;
    QList<QPointF> tail;

    QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

private:
    GameWindow *board;
    int score;
    int speed;
    int tickCounter;

    bool isOver();

public slots:

    void advance(int step);
};


#endif //TRON_PLAYER_H
