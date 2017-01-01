#include "Player.h"
#include "GameWindow.h"

Player::Player(GameWindow *gameBoard, int score, Player *anotherPlayer, QGraphicsItem *parent) : board(gameBoard),
                                                                                                 score(score),
                                                                                                 anotherPlayer(
                                                                                                         anotherPlayer) {
    speed = 2000;
    tickCounter = 0;
    QRectF qRectF = QRectF(0, 0, board->RIDER_SIZE.width(), board->RIDER_SIZE.height());
    setRect(qRectF);
}

void Player::advance(int step) {
    if (!step) {
        return;
    }
    if (tickCounter++ % speed != 0) {
        return;
    }
    makeMove();
    setPos(head);
    manageScores();
    tail << head;

}

bool Player::isOver(Player *player) {
    return (tail.contains(head) || head.x() < 0 || head.y() < 0
            || head.x() > board->GRAPHIC_ZONE_SIZE.width() || head.y() > board->GRAPHIC_ZONE_SIZE.height()
            || player->tail.contains(head)) || player->head == head;
}

void Player::makeMove() {
    switch (direction) {
        case UP:
            head.setX(x());
            head.setY(y() - board->RIDER_SIZE.height());
            break;
        case DOWN:
            head.setX(x());
            head.setY(y() + board->RIDER_SIZE.height());
            break;
        case LEFT:
            head.setX(x() - board->RIDER_SIZE.width());
            head.setY(y());
            break;
        case RIGHT:
            head.setX(x() + board->RIDER_SIZE.width());
            head.setY(y());
            break;
    }
}

void Player::manageScores() {
    if (isOver(anotherPlayer)) {
        if (++anotherPlayer->score == 3) {
            QTimer::singleShot(0, board, SLOT(manageWin()));
        } else {
            QTimer::singleShot(0, board, SLOT(battleSection()));
        }
    }
}


void Player::setEnemy(Player *player) {
    anotherPlayer = player;
}

int Player::setScore(int score) {
    this->score = score;
}

int Player::getScore() {
    return this->score;
}