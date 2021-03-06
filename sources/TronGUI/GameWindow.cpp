#include "GameWindow.h"

GameWindow::GameWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);
    setWindowTitle(tr("Tron | Game"));
    initScene();
    timer.start(0);
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
    scene->addItem(computer);
    scene->addItem(player);

    connect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
}

void GameWindow::clean() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    int scorePlayer = player->score;
    int scoreEnemy = computer->score;
    scene->clear();
    initScene();
    start(scorePlayer, scoreEnemy);
}

void GameWindow::initScene() {
    scene = new QGraphicsScene(0,
                               0,
                               GRAPHIC_ZONE_SIZE.width(),
                               GRAPHIC_ZONE_SIZE.height());
    QPixmap background(":/grid.png");
    scene->setBackgroundBrush(QBrush(background));
    setScene(scene);
}

void GameWindow::manageWin() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QMessageBox msgBox;
    msgBox.setFixedSize(400, 200);
    msgBox.setWindowTitle("Tron | Game result");
    msgBox.setText(player->getScore() == 3 ? "Victory!" : "Defeat!");
    QAbstractButton *noButton = msgBox.addButton(trUtf8("Main menu"), QMessageBox::YesRole);
    QAbstractButton *yesButton = msgBox.addButton(trUtf8("Play again"), QMessageBox::NoRole);
    msgBox.exec();
    if (msgBox.clickedButton() == yesButton) {
        player->setScore(0);
        computer->setScore(0);
        clean();
    } else if (msgBox.clickedButton() == noButton) {
        menu();
    }
}

void GameWindow::battleSection() {
    disconnect(&timer, SIGNAL(timeout()), scene, SLOT(advance()));
    QMessageBox msgBox;
    msgBox.setFixedSize(400, 200);
    msgBox.setWindowTitle("Tron | Round result");
    QString qString("Your score: " + QString::number(player->getScore()) +
                    "\n Enemy score: " + QString::number(computer->getScore()));
    msgBox.setText(qString);
    QAbstractButton *button = msgBox.addButton(trUtf8("Next round"), QMessageBox::YesRole);
    msgBox.exec();
    if (msgBox.clickedButton() == button) {
        clean();
    }
}
