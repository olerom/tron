#include "Player.h"
#include "Map.h"

Player::Player(int x, int y, Direction direction, int score, Map &map) : head_x(x), head_y(y), direction(direction),
                                                                         score(score) {
    for (int i = 0; i < map.getWidth(); i++) {
        std::vector<bool> tailHelp;
        for (int j = 0; j < map.getHeight(); j++) {
            tailHelp.push_back(false);
        }
        tail.push_back(tailHelp);
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

int Player::getScore() {
    return this->score;
}

void Player::upScore() {
    this->score++;
}

void Player::reset(Map &map) {
    for (int i = 0; i < map.getWidth(); i++) {
        for (int j = 0; j < map.getHeight(); j++) {
            tail[i][j] = false;
        }
    }
}
