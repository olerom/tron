#ifndef TRON_GAMEWINDOW_H
#define TRON_GAMEWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
//#include <GL\freeglut.h>

class GameWindow : public QGraphicsView {
Q_OBJECT
public:
    GameWindow(QWidget *parent = NULL);

    void start();

    QGraphicsScene *scene;

private:

    const QSize SCREEN_SIZE{1000, 500};


private slots:

    void exit();

    void menu();

};

#endif //TRON_GAMEWINDOW_H
