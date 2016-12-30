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
    switch (choice) {
        case 0:
            return UP;
        case 1:
            return RIGHT;
        case 2:
            return DOWN;
        case 3:
            return LEFT;
    }
    return direction;
}


QPainterPath Computer::shape() const {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
            foreach (QPointF p, tail) {
            QPointF itemp = mapFromScene(p);
            path.addRect(QRectF(itemp.x(), itemp.y(), 5, 5));
        }
    return path;
}


void Computer::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->save();
    painter->fillPath(this->shape(), Qt::red);
    painter->restore();
}

void Computer::changeWay() {
    int choice = rand() % 2;
    switch (direction) {
        case UP:
        case DOWN:
            if (choice == 0) {
                direction = RIGHT;
            } else {
                direction = LEFT;
            }
            break;
        case LEFT:
        case RIGHT:
            if (choice == 0) {
                direction = DOWN;
            } else {
                direction = UP;
            }
    }
}

void Computer::checkMovement() {
    if (!tail.isEmpty()) {
        Computer check(board, 0, anotherPlayer);
        for (int i = 0; i < tail.size(); i++) {
            check.tail << tail.at(i);
        }
        check.direction = direction;
        check.head = head;
        check.setPos(head);
        check.makeMove();
        if (check.isOver(anotherPlayer)) {
            changeWay();
        }
    }
}
