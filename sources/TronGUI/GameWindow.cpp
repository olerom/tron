#include "GameWindow.h"
#include "MenuWindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron | Game"));

    QPixmap background(":/grid.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(qPalette);

    timer.start(0);
    initScene();


    computer = new Computer(this, 0);
    player = new User(this, 0);
    player->setEnemy(computer);
    computer->setEnemy(player);
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
//    Computer c(this, scoreEnemy);
//    Player p(this, scorePlayer);

    //
//    computer->setPos(SCREEN_SIZE.width() - 100, SCREEN_SIZE.height() >> 1);
//    computer->direction = LEFT;
//    computer->score = scoreEnemy;
//    computer->tail.clear();

//    player->setPos(100, SCREEN_SIZE.height() >> 1);
//    player->direction = RIGHT;
//    player->score = scorePlayer;
//    player->tail.clear();

    //
//
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
    scene->setSceneRect(0, 0, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    start(scorePlayer, scoreEnemy);
}

void GameWindow::initScene() {
    scene = new QGraphicsScene(0, 0, SCREEN_SIZE.width() - 50, SCREEN_SIZE.height() - 50);
    setScene(scene);
}
