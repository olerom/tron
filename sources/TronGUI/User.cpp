#include "User.h"
#include "GameWindow.h"

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

User::User(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent) : Player(gameBoard, score,
                                                                                                    anotherPlayer,
                                                                                                    parent) {
    direction = RIGHT;
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();
    setPos(100, gameBoard->SCREEN_SIZE.height() >> 1);
}


QPainterPath User::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), board->RIDER_SIZE.width(), board->RIDER_SIZE.height()));
        }
    return path;
}

void User::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(shape(), Qt::yellow);
    painter->restore();
}