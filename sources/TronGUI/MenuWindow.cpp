#include "MenuWindow.h"

MenuWindow::MenuWindow(QWidget *parent) : QGraphicsView(parent) {
    this->setFixedSize(SCREEN_SIZE);

    QPixmap background(":/grid.png");
    QPalette qPalette;
    qPalette.setBrush(this->backgroundRole(), QBrush(background));
    this->setPalette(qPalette);

    QWidget *frame = new QWidget(this);
    frame->setGeometry(100, 0, 800, 310);
    frame->setStyleSheet("background-image: url(:/tron_logo.png)");

    startButton = new QPushButton(this);
    startButton->setStyleSheet(QPushButtonStyle);
    startButton->setText(tr("Start new game"));
    startButton->resize(BUTTON_SIZE);
    startButton->move((SCREEN_SIZE.width() >> 1) - BUTTON_SIZE.width() - 10,
                      (SCREEN_SIZE.height() >> 1) + BUTTON_SIZE.height());

    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));

    exitButton = new QPushButton(this);

    exitButton->setStyleSheet(QPushButtonStyle);
    exitButton->setText(tr("Exit"));
    exitButton->resize(BUTTON_SIZE);
    exitButton->move((SCREEN_SIZE.width() >> 1) + 10,
                     (SCREEN_SIZE.height() >> 1) + BUTTON_SIZE.height());

    connect(exitButton, SIGNAL(clicked()), this, SLOT(exit()));

    setWindowTitle(tr("Tron | Main menu"));
}

void MenuWindow::exit() {
    this->close();
}

void MenuWindow::startGame() {
    GameWindow *game = new GameWindow();
    game->show();
    game->start();
    exit();
}
