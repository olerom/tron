#include <QtWidgets/QMessageBox>
#include "GameWindow.h"
#include "MenuWindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron | Game"));

//    QPixmap background(":/grid.png");
//    QPalette qPalette;
//    qPalette.setBrush(this->backgroundRole(), QBrush(background));
//    this->setPalette(qPalette);

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

void GameWindow::start(int scorePlayer, int scoreEnemy) {
    player = new User(this, scorePlayer);
    computer = new Computer(this, scoreEnemy);
    computer->setEnemy(player);
    player->setEnemy(computer);
    scene->addItem(player);
    scene->addItem(computer);
    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}

void GameWindow::clean() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    int scorePlayer = player->score;
    int scoreEnemy = computer->score;
    scene->clear();
    initScene();
    scene->setSceneRect(0, 100, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    start(scorePlayer, scoreEnemy);
}

void GameWindow::initScene() {
    scene = new QGraphicsScene(0, 100, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 250);
    QPixmap background(":/grid.png");
    scene->setBackgroundBrush(QBrush(background));
    setScene(scene);
}

void GameWindow::manageWin() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QMessageBox msgBox;
    msgBox.tr("Tron | Game result");
    msgBox.setText(player->score < 3 ? "Victory!" : "Defeat!");
    QAbstractButton *noButton = msgBox.addButton(trUtf8("Main menu"), QMessageBox::NoRole);
    QAbstractButton *yesButton = msgBox.addButton(trUtf8("Play again"), QMessageBox::YesRole);
    msgBox.exec();
    if (msgBox.clickedButton() == yesButton) {
        player->score = 0;
        computer->score = 0;
        clean();
    } else if (msgBox.clickedButton() == noButton) {
        menu();
    }
}
