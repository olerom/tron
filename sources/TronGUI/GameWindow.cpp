#include <iostream>
#include "GameWindow.h"
#include "MenuWindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron"));

    QPixmap background(":/grid.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(qPalette);

    scene = new QGraphicsScene(0, 0, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    setScene(scene);
//    setFocus(Qt::OtherFocusReason);
    setFocus();
}

void GameWindow::exit() {
    close();
}

void GameWindow::menu() {
    std::cout << "in menu\n";
    MenuWindow *menu = new MenuWindow(0);
    menu->show();
    close();
}

void GameWindow::start() {
    player = new User(this);

    scene->addItem(player);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), player, SLOT(keepMove()));
    timer->start(10);
}


void GameWindow::clean() {
//    this->scene->clear();
//    player->tail.clear();
//    start();
}
