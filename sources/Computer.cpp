#include "Computer.h"

Computer::Computer(int x, int y, Direction direction, int score, Map map) : Player(x, y, direction, score, map) {};

Computer::Computer(Player player) : Player(player) {};

void Computer::move(Player player, Map map) {
    this->tail[this->getX()][this->getY()] = true;

    Direction direction = this->checkDirection(player, map);

    this->choiceMove(direction);
}

//TODO перегрузить оператор присваивания || сделать нормальным checkover || Map c другими полями -- Спросить короче
//TODO добавить рандом на выбор направления

Direction Computer::checkDirection(Player player, Map map) {
    Direction direction = this->getDirection();

    Computer check(this->getX(), this->getY(), this->getDirection(), this->getScore(), map);
    check.choiceMove(direction);

    bool chaos = false;

    if (rand() % 40 == 5) {
        chaos = true;
    }

    if (Game::checkOver(check, map, player) || Game::checkOver(check, map, *this) || chaos) {
        switch (this->getDirection()) {
            case DOWN:
            case UP:
                if (rand() % 2 == 1) {
                    direction = this->findDirection(player, map, LEFT);
                } else {
                    direction = this->findDirection(player, map, RIGHT);
                }
                break;
            case LEFT:
            case RIGHT:
                if (rand() % 2 == 1) {
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
    Computer check(this->getX(), this->getY(), this->getDirection(), this->getScore(), map);
    check.choiceMove(direction);
    if (Game::checkOver(check, map, player) || Game::checkOver(check, map, *this)) {
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