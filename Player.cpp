#include "Player.h"

Player::Player(int x, int y, Direction direction) : head_x(x), head_y(y), direction(direction) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 60; j++) {
            tail[j][i] = false;
        }
    }
}

int Player::getX() {
    return this->head_x;
}

int Player::getY() {
    return this->head_y;
}

void Player::setX(int x) {
    this->head_x = x;
}

void Player::setY(int y) {
    this->head_y = y;
}

void Player::setDirection(Direction direction) {
    this->direction = direction;
}

Direction Player::getDirection() {
    return this->direction;
}

Player::Player() : head_x(10), head_y(10), direction(RIGHT) {
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 60; j++) {
            tail[j][i] = false;
        }
    }
}

void Player::choiceMove(Direction direction) {

    switch (direction) {
        case LEFT:
            this->setX(this->getX() - 1);
            this->setDirection(LEFT);
            break;
        case RIGHT:
            this->setX(this->getX() + 1);
            this->setDirection(RIGHT);
            break;
        case UP:
            this->setY(this->getY() - 1);
            this->setDirection(UP);
            break;
        case DOWN:
            this->setY(this->getY() + 1);
            this->setDirection(DOWN);
            break;
    }

}

