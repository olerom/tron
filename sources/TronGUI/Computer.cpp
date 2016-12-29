#include <iostream>
#include "Computer.h"
#include "GameWindow.h"

Computer::Computer(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent) : Player(gameBoard,
                                                                                                            score,
                                                                                                            anotherPlayer,
                                                                                                            parent) {
    direction = LEFT;
    setPos(gameBoard->SCREEN_SIZE.width() - 100, gameBoard->SCREEN_SIZE.height() >> 1);
}

void Computer::advance(int step) {

    if (!step || tickCounter++ % speed != 0) {
        return;
    }

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
    std::cout << x() << " " << y() << "\n";
//    if (isOver()) {
//        if (++score == 3) {
//            board->menu();
//        } else {
//            board->clean();
//        }
//    }
    tail << head;


}

Direction Computer::getChaos() {
    int choice = rand() % 4;
//    switch (choice) {
//        case 0:
//            return UP;
//        case 1:
//            return RIGHT;
//        case 2:
//            return DOWN;
//        case 3:
//            return LEFT;
//    }
    return direction;
}


QPainterPath Computer::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    path.addRect(QRectF(400, 400, 10, 10));
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 1, 1));
        }
    return path;
}


void Computer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(this->shape(), Qt::red);
    painter->restore();
}
