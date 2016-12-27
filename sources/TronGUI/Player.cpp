#include "Player.h"

Player::Player(QGraphicsItem *parent) {
    setRect(0, 0, 5, 5);
    direction = RIGHT;
//    QBrush brush;
//    brush.setStyle(Qt::SolidPattern);
//    brush.setColor(Qt::darkRed);
//    setBrush(brush);

    setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

    QTimer *timer = new QTimer();

    connect(timer, SIGNAL(timeout()), this, SLOT(keepMove()));

    timer->start(40);
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && direction != RIGHT) {
        direction = LEFT;
    } else if (event->key() == Qt::Key_Right && direction != LEFT) {
        direction = RIGHT;
    } else if (event->key() == Qt::Key_Up && direction != DOWN) {
        direction = UP;
    } else if (event->key() == Qt::Key_Down && direction != UP) {
        direction = DOWN;
    }
}

void Player::keepMove() {
    switch (direction) {
        case UP:
            head.setX(x());
            head.setY(y() - 5);
            break;
        case DOWN:
            head.setX(x());
            head.setY(y() + 5);
            break;
        case LEFT:
            head.setX(x() - 5);
            head.setY(y());
            break;
        case RIGHT:
            head.setX(x() + 5);
            head.setY(y());
            break;
    }

    setPos(head);
    tail << head;
}

QPainterPath Player::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);

    path.addRect(QRectF(0, 0, 5, 5));

            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 5, 5));
        }

    return path;
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}