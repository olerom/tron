#include "User.h"

User::User(int x, int y, Direction direction, int score, Map map) : Player(x, y, direction, score, map) {
}

void User::logic() {
    this->setTail(this->getX(), this->getY());

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

void User::reset(Map &map) {
    Player::reset(map);
    this->direction = RIGHT;
    this->head_x = map.getWidth() >> 2;
    this->head_y = map.getHeight() >> 1;
}

