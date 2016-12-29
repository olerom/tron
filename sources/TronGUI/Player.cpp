#include <iostream>
#include "Player.h"
#include "MenuWindow.h"
#include "GameWindow.h"

Player::Player(GameWindow *gameBoard, QGraphicsItem *parent) {
    this->board = gameBoard;
    score = 0;
    speed = 50;
    tickCounter = 5;
    setRect(0, 0, 1, 1);
    direction = RIGHT;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}

void Player::advance(int step) {
    std::cout << "IN- ";
    if (!step || tickCounter++ % speed != 0) {
        return;
    }
//    || tickCounter++ % speed != 0
    std::cout << "IN+ \n";
    switch (direction) {
        case UP:
            head.setX(x());
            head.setY(y() - 1);
            break;
        case DOWN:
            head.setX(x());
            head.setY(y() + 1);
            break;
        case LEFT:
            head.setX(x() - 1);
            head.setY(y());
            break;
        case RIGHT:
            head.setX(x() + 1);
            head.setY(y());
            break;
    }
    setPos(head);
    if (isOver()) {
        if (++score == 3) {
            std::cout << "_over_\n";
            board->menu();
        } else {
            board->clean();
//            board->start();
        }
    }
    tail << head;

}

QPainterPath Player::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(QRectF(0, 0, 1, 1));
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 1, 1));
        }
    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}

bool Player::isOver() {
    return (tail.contains(head) || this->x() < -50 || this->y() < -50
            || this->x() > board->SCREEN_SIZE.width() - 50 || this->y() > board->SCREEN_SIZE.height() - 50);
}
