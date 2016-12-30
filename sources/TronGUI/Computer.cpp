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
    checkMovement();

    makeMove();
    setPos(head);

    manageScores();
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
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 2, 2));
        }
    return path;
}


void Computer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(this->shape(), Qt::red);
    painter->restore();
}

void Computer::changeWay() {
    if (direction == UP) {
        direction = RIGHT;
    } else if (direction == RIGHT) {
        direction = DOWN;
    } else if (direction == DOWN) {
        direction = LEFT;
    } else if (direction == LEFT) {
        direction = UP;
    }
}

void Computer::checkMovement() {
    if (!tail.isEmpty()) {
        Computer check(this->board, 0, anotherPlayer);
        for (int i = 0; i < tail.size(); i++) {
            check.tail << tail[i];
        }
        check.setPos(head);
        check.direction = direction;
        check.makeMove();
        if (check.isOver(anotherPlayer)) {
            changeWay();
        }
    }
}
