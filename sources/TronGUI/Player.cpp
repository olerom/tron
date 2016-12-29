#include <iostream>
#include "Player.h"
#include "GameWindow.h"

Player::Player(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent) : board(gameBoard),
                                                                                                 score(score),
                                                                                                 anotherPlayer(
                                                                                                         anotherPlayer) {
    speed = 100;
    tickCounter = 0;
//    setRect(0, 0, 1, 1);
//    direction = RIGHT;
//    this->setFlag(QGraphicsItem::ItemIsFocusable);
//    this->setFocus();
}

void Player::advance(int step) {
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
    if (isOver(anotherPlayer)) {
        if (++anotherPlayer->score == 3) {
            board->menu();
        } else {
            board->clean();
        }
    }
    tail << head;

}

bool Player::isOver(Player *player) {
    return (tail.contains(head) || this->x() < -50 || this->y() < -50
            || this->x() > board->SCREEN_SIZE.width() - 50 || this->y() > board->SCREEN_SIZE.height() - 50
            || player->tail.contains(head));
}
