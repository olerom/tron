#include "Computer.h"

Computer::Computer(int x, int y, Direction direction, int score, Map map) : Player(x, y, direction, score, map) {};

void Computer::move(Player player, Map map) {
    this->setTail(this->getX(), this->getY());

    Direction direction = this->checkDirection(player, map);

    this->choiceMove(direction);
}

Direction Computer::checkDirection(Player player, Map map) {
    Direction direction = this->getDirection();

    Computer check(this->getX(), this->getY(), this->getDirection(), this->getScore(), map, *this);
    check.choiceMove(direction);

    if (Game::checkOver(check, map, player) || this->getChaos()) {
        switch (this->getDirection()) {
            case DOWN:
            case UP:
                if (this->getRandomChoice()) {
                    direction = this->findDirection(player, map, LEFT);
                } else {
                    direction = this->findDirection(player, map, RIGHT);
                }
                break;
            case LEFT:
            case RIGHT:
                if (this->getRandomChoice()) {
                    direction = this->findDirection(player, map, DOWN);
                } else {
                    direction = this->findDirection(player, map, UP);
                }
                break;
        }
    }
    return direction;
}

Direction Computer::findDirection(Player player, Map map, Direction direction) {
    Computer check(this->getX(), this->getY(), this->getDirection(), this->getScore(), map, *this);
    check.choiceMove(direction);
    if (Game::checkOver(check, map, player)) {
        switch (direction) {
            case UP:
                direction = DOWN;
                break;
            case LEFT:
                direction = RIGHT;
                break;
            case DOWN:
                direction = UP;
                break;
            case RIGHT:
                direction = LEFT;
                break;
        }
    }
    return direction;
}

void Computer::reset(Map &map) {
    Player::reset(map);
    this->direction = LEFT;
    this->head_x = 3 * (map.getWidth() >> 2);
    this->head_y = map.getHeight() >> 1;
}

Computer::Computer(int x, int y, Direction direction, int score, Map &map, Computer computer) : Player(x, y, direction,
                                                                                                       score, map) {
    this->tail.reserve(computer.tail.size());
    for (int i = 0; i < this->tail.size(); i++) {
        this->tail[i].reserve(computer.tail[i].size());
    }
    for (int i = 0; i < computer.tail.size(); i++) {
        for (int j = 0; j < computer.tail[i].size(); j++) {
            this->tail[i][j] = computer.tail[i][j];
        }
    }
}

bool Computer::getRandomChoice() {
    return rand() % 2 == 0;
}

bool Computer::getChaos() {
    return rand() % 10 == 0;
}
