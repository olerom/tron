#include "User.h"

void User::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && direction != RIGHT) {
        direction = LEFT;
    } else if (event->key() == Qt::Key_Right && direction != LEFT) {
        direction = RIGHT;
    } else if (event->key() == Qt::Key_Up && direction != DOWN) {
        direction = UP;
    } else if (event->key() == Qt::Key_Down && direction != UP) {
        direction = DOWN;
    }
}

User::User(GameWindow *gameBoard, QGraphicsItem *parent) : Player(gameBoard, parent) {
}
