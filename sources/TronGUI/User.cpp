#include "User.h"

void User::keyPressEvent(QKeyEvent *event) {
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

User::User(GameWindow *gameBoard, int score, QGraphicsItem *parent) : Player(gameBoard, score, parent) {
//    speed = 100;
//    tickCounter = 0;
//    setRect(0, 0, 1, 1);
    direction = RIGHT;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
}


QPainterPath User::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(QRectF(0, 0, 1, 1));
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 1, 1));
        }
    return path;
}

void User::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}