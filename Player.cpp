#include "Player.h"

Player::Player(int x, int y, Direction direction) : head_x(x), head_y(y), direction(direction) {
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 60; j++){
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