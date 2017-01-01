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

    int score;

    void makeMove();

    void setEnemy(Player *player);

    int getScore();

    int setScore(int score);

protected:
    QPointF head;
    QList<QPointF> tail;
    Direction direction;
    GameWindow *board;
    int speed;
    int tickCounter;
    Player *anotherPlayer;

    bool isOver(Player *player);

    void manageScores();

public slots:

    void advance(int step);
};


#endif //TRON_PLAYER_H
