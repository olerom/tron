#include "User.h"

User::User(int x, int y, Direction direction, int score, Map map) : Player(x, y, direction, score, map) {
}

void User::logic() {
    this->setTail(this->getX(), this->getY());

    Direction direction = this->getDirection();

    if (Game::myKbhit()) {
        int res = Game::myGetch();
        if (res == 97 && direction != RIGHT) {
            direction = LEFT;
        } else if (res == 100 && direction != LEFT) {
            direction = RIGHT;
        } else if (res == 119 && direction != DOWN) {
            direction = UP;
        } else if (res == 115 && direction != UP) {
            direction = DOWN;
        }
    }

    this->choiceMove(direction);
}

void User::reset(Map &map) {
    Player::reset(map);
    this->direction = RIGHT;
    this->head_x = map.getWidth() >> 2;
    this->head_y = map.getHeight() >> 1;
}

