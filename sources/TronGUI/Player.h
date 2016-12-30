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
    Player(GameWindow *gameBoard, int score, Player *anotherPlayer = NULL, QGraphicsItem *parent = NULL);

    QPointF head;
    QList<QPointF> tail;
    int score;

    void makeMove();

    void setEnemy(Player *player);

    Player &operator=(const Player &player);
    Direction direction;
    GameWindow *board;
    int speed;
    int tickCounter;
    Player *anotherPlayer;

protected:

    bool isOver(Player *player);

    void manageScores();

public slots:

    void advance(int step);
};


#endif //TRON_PLAYER_H
