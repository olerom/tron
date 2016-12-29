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

//    timer.setInterval(5);
    timer.start();
//    timer.start(0);
}

void GameWindow::exit() {
    close();
}

void GameWindow::menu() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    std::cout << "in menu\n";
    MenuWindow *menu = new MenuWindow(0);
    menu->show();
    this->close();
}

void GameWindow::start() {
    scene->clear();
    player = new User(this);
    scene->addItem(player);
//    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}


void GameWindow::clean() {
//    this->scene->clear();
//    player->tail.clear();
//    start();
}
