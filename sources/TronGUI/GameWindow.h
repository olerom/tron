#ifndef TRON_GAMEWINDOW_H
#define TRON_GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Player.h"
#include "User.h"
#include "Computer.h"

class GameWindow : public QGraphicsView {
Q_OBJECT
public:
    GameWindow(QWidget *parent = NULL);

    void start(int scorePlayer = 0, int scoreEnemy = 0);

    const QSize SCREEN_SIZE{1000, 500};
    QTimer timer;
    QGraphicsScene *scene;
private:
    Computer *computer;
    User *player;

    void initScene();
public slots:

    void exit();

    void menu();

    void clean();
};

#endif