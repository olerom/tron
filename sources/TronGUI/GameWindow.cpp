#include "GameWindow.h"
#include "MenuWindow.h"
#include "Player.h"
//TODO пофиксить переходы
//TODO пофиксить смещение фона
//TODO продумать кор, не наследоваться от кьютишных классов? Хз вообще
//TODO сделать движение без аи

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron"));

//    QPixmap background(":/grid.png");
//    QPalette qPalette;
//    qPalette.setBrush(this->backgroundRole(), QBrush(background));
//    this->setPalette(qPalette);

    scene = new QGraphicsScene(0, 0, SCREEN_SIZE.width(), SCREEN_SIZE.height());
    setScene(scene);
}

void GameWindow::exit() {
    close();
}

void GameWindow::menu() {
    MenuWindow *menu = new MenuWindow(0);
    menu->show();
    close();
}

void GameWindow::start() {
    Player *test = new Player();
    scene->addItem(test);
}
