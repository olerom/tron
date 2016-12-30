#include <iostream>
#include "Player.h"
#include "GameWindow.h"

Player::Player(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent) : board(gameBoard),
                                                                                                 score(score),
                                                                                                 anotherPlayer(
                                                                                                         anotherPlayer) {
    speed = 100;
    tickCounter = 0;
}

void Player::advance(int step) {
    if (!step || tickCounter++ % speed != 0) {
        return;
    }
    makeMove();
    setPos(head);
    manageScores();
    tail << head;

}

bool Player::isOver(Player *player) {
    return (tail.contains(head) || this->x() < -50 || this->y() < -50
            || this->x() > board->SCREEN_SIZE.width() - 50 || this->y() > board->SCREEN_SIZE.height() - 50
            || player->tail.contains(head)) || player->head == head;
}

void Player::makeMove() {
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
}

void Player::manageScores() {
    if (isOver(anotherPlayer)) {
        if (++anotherPlayer->score == 3) {
            QTimer::singleShot(0, board, SLOT(menu()));
        } else {
            QTimer::singleShot(0, board, SLOT(clean()));
        }
    }
}


void Player::setEnemy(Player *player) {
    anotherPlayer = player;
}

Player &Player::operator=(const Player &player) {
    score = player.score;
    board = player.board;
    direction = player.direction;
    anotherPlayer = player.anotherPlayer;
    head = player.head;
    speed = player.speed;
    tickCounter = player.tickCounter;
    tail = player.tail;
    setPos(player.x(), player.y());
}
