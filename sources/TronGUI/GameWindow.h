#ifndef TRON_GAMEWINDOW_H
#define TRON_GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "Player.h"
//#include <GL\freeglut.h>

class GameWindow : public QGraphicsView {
Q_OBJECT
public:
    GameWindow(QWidget *parent = NULL);

    void start();

private:

    QGraphicsScene *scene;

    Player *player;

    const QSize SCREEN_SIZE{1000, 500};

public slots:

    void exit();

    void menu();

};

#endif //TRON_GAMEWINDOW_H
