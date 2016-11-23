#include "Computer.h"

Computer::Computer(int x, int y, Direction direction) : Player(x, y, direction) {};

Computer::Computer(Player player) : Player(player) {};

void Computer::move(Player player, Map map) {
    this->tail[this->getX()][this->getY()] = true;

    Direction direction = this->checkDirection(player, map);

    this->choiceMove(direction);
}

//TODO перегрузить оператор присваивания || сделать нормальным checkover

Direction Computer::checkDirection(Player player, Map map) {
    Direction direction = this->getDirection();

    Computer check(this->getX(), this->getY(), this->getDirection());
    check.choiceMove(direction);
    if (Game::checkOver(check, map, player)) {
        switch (this->getDirection()) {
            case UP:
                direction = this->findDirection(player, map, RIGHT);
                break;
            case LEFT:
                direction = this->findDirection(player, map, UP);
                break;
            case DOWN:
                direction = this->findDirection(player, map, LEFT);
                break;
            case RIGHT:
                direction = this->findDirection(player, map, DOWN);
                break;
        }
    }
    return direction;
}

Direction Computer::findDirection(Player player, Map map, Direction direction) {
    Computer check(this->getX(), this->getY(), this->getDirection());
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
                direction = DOWN;
                break;
        }
    }
    return direction;
}