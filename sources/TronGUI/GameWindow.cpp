#include "GameWindow.h"
#include "MenuWindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron"));

    QPixmap background(":/grid.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(qPalette);

    scene = new QGraphicsScene(0, 0, 800, 600);
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

}
