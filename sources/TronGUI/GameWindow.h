#ifndef TRON_GAMEWINDOW_H
#define TRON_GAMEWINDOW_H


#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "MenuWindow.h"
#include "GraphicFrame.h"

class GameWindow : public QWidget {
Q_OBJECT


public:
    explicit GameWindow(QWidget *parent);

    virtual ~GameWindow() {}

private:

    const QSize SCREEN_SIZE{1000, 500};

    GraphicFrame *board;


private slots:

    void exit();

    void menu();

};

#endif //TRON_GAMEWINDOW_H
