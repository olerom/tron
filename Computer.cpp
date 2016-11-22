#include "Computer.h"

Computer::Computer(int x, int y, Direction direction) : Player(x, y, direction) {};

Computer::Computer(Player player) : Player(player) {};

void Computer::move(Player player, Map map) {

    this->tail[this->getX()][this->getY()] = true;

    Direction direction = this->getDirection();

    Computer check(this->getX(), this->getY(), this->getDirection());
    check.choiceMove(direction);

    if (Game::checkOver(check, map, player)) {
        if (this->getDirection() == UP) {
            direction = RIGHT;
        } else if (this->getDirection() == RIGHT) {
            direction = DOWN;
        } else if (this->getDirection() == DOWN) {
            direction = LEFT;
        } else {
            direction = UP;
        }
    }

    this->choiceMove(direction);
}
