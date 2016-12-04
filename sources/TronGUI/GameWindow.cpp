#include <QtWidgets>
#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron"));

    QPixmap background(":/grid.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(qPalette);

    board = new GraphicFrame();


//    QGraphicsScene *scene = new QGraphicsScene();
//    QGraphicsRectItem *rect = new QGraphicsRectItem();
//    rect->setRect(0, 0, 100, 100);
//
//    scene->addItem(rect);
//
//    QGraphicsView *view = new QGraphicsView(scene);
//    view->show();

}

void GameWindow::exit() {
    close();
}

void GameWindow::menu() {
    MenuWindow *menu = new MenuWindow(0);
    menu->show();
    close();
}
