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

    timer.start(0);
    initScene();
}

void GameWindow::exit() {
    close();
}

void GameWindow::menu() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    MenuWindow *menu = new MenuWindow(0);
    menu->show();
    exit();
}

void GameWindow::start(int score) {
    this->player = new User(this, score, computer);
    this->computer = new Computer(this, score, player);
    player->setEnemy(computer);
    scene->addItem(this->player);
    scene->addItem(this->computer);
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}

void GameWindow::clean() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    scene->clear();
    int score = player->score;
    initScene();
    scene->setSceneRect(0, 0, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    start(score);
}

void GameWindow::initScene() {
    scene = new QGraphicsScene(0, 0, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    setScene(scene);
}
