#include "User.h"

User::User(int x, int y, Direction direction, int score) : Player(x, y, direction, score) {
}

User::User(Player player) : Player(player) {}

void User::logic() {
    this->tail[this->getX()][this->getY()] = true;

    Direction direction = this->getDirection();

    if (Game::myKbhit()) {
        int res = Game::myGetch();
        if (res == 'a' && direction != RIGHT) {
            direction = LEFT;
        } else if (res == 'd' && direction != LEFT) {
            direction = RIGHT;
        } else if (res == 'w' && direction != DOWN) {
            direction = UP;
        } else if (res == 's' && direction != UP) {
            direction = DOWN;
        }
    }

    this->choiceMove(direction);
}

