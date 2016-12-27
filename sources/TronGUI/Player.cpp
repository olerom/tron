#include "Player.h"

Player::Player(QGraphicsItem *parent) {
    setRect(20, 20, 25, 25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(keepMove()));
    timer->start(50);
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right) {
        setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Up) {
        setPos(x(), y() - 10);
    } else if (event->key() == Qt::Key_Down) {
        setPos(x(), y() + 10);
    }
}

void Player::keepMove() {
    setPos(x() + 1, y());
}