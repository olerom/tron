#include "Game.h"

void Game::run() {
    clearScreen();
    Map map(20, 60);
    Player first_player(5, 10, RIGHT);
    Player computer(55, 10, LEFT);

    while (true) {
        clearScreen();

        map.draw(first_player, computer);
        computer = computerLogic(computer, first_player, map);
        first_player = logic(first_player);

        usleep(60000);

        if (checkOver(first_player, map, computer)) {
            std::cout << "GAME OVER" << std::endl;
            break;
        } else if (checkOver(computer, map, first_player)) {
            std::cout << "YOU WON" << std::endl;
            break;
        }
    }
}

void Game::startMenu(int switcher) {

    bool running = true;
    while (running) {
        clearScreen();
        std::cout << " ─────────────────────────────────────────────────────────────────────────\n"
                " ─██████████████─████████████████───██████████████─██████──────────██████─\n"
                " ─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░██████████──██░░██─\n"
                " ─██████░░██████─██░░████████░░██───██░░██████░░██─██░░░░░░░░░░██──██░░██─\n"
                " ─────██░░██─────██░░██────██░░██───██░░██──██░░██─██░░██████░░██──██░░██─\n"
                " ─────██░░██─────██░░████████░░██───██░░██──██░░██─██░░██──██░░██──██░░██─\n"
                " ─────██░░██─────██░░░░░░░░░░░░██───██░░██──██░░██─██░░██──██░░██──██░░██─\n"
                " ─────██░░██─────██░░██████░░████───██░░██──██░░██─██░░██──██░░██──██░░██─\n"
                " ─────██░░██─────██░░██──██░░██─────██░░██──██░░██─██░░██──██░░██████░░██─\n"
                " ─────██░░██─────██░░██──██░░██████─██░░██████░░██─██░░██──██░░░░░░░░░░██─\n"
                " ─────██░░██─────██░░██──██░░░░░░██─██░░░░░░░░░░██─██░░██──██████████░░██─\n"
                " ─────██████─────██████──██████████─██████████████─██████──────────██████─\n"
                " ─────────────────────────────────────────────────────────────────────────\n"
                "\n";

        switch (switcher) {
            case 1:
                std::cout << "                          << Start new game >>\n";
                std::cout << "                              High scores\n";
                std::cout << "                                  Quit\n";
                break;
            case 2:
                std::cout << "                             Start new game \n";
                std::cout << "                           << High scores >>\n";
                std::cout << "                                  Quit\n";
                break;
            case 3:
                std::cout << "                             Start new game \n";
                std::cout << "                              High scores \n";
                std::cout << "                               << Quit >>\n";
                break;
        }

        int menu = myGetch();
        switch (menu) {
            case 'w':
                if (switcher != 1) {
                    this->startMenu(switcher - 1);
                } else {
                    this->startMenu(3);
                }
                break;
            case 's':
                if (switcher != 3) {
                    this->startMenu(switcher + 1);
                } else {
                    this->startMenu(1);
                }
                break;
            case ' ':
                if (switcher == 1) {
                    this->run();
                } else if (switcher == 2) {
                    //TODO highscore
                } else if (switcher == 3) {
                    _exit(0);
                }
                break;
        }
    }
}


void Game::clearScreen() {
    printf("\033[2J");
    printf("\033[0;0f");
}

Player Game::logic(Player player) {
    player.tail[player.getX()][player.getY()] = true;

    Direction direction = player.getDirection();

    if (myKbhit()) {
        int res = myGetch();
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

    player = choiceMove(player, direction);
    return player;
}

bool Game::checkOver(Player first_player, Map map, Player second_computer) {

    return first_player.getX() == 0 || first_player.getX() == map.width - 1
           || first_player.getY() == -1 || first_player.getY() == map.height
           || first_player.tail[first_player.getX()][first_player.getY()]
           || second_computer.tail[first_player.getX()][first_player.getY()]
           || (first_player.getX() == second_computer.getX() && first_player.getY() == second_computer.getY());

}

Player Game::computerLogic(Player computer, Player player, Map map) {

    computer.tail[computer.getX()][computer.getY()] = true;

    Direction direction = computer.getDirection();
    Player checkPlayer = choiceMove(computer, direction);

    if (checkOver(checkPlayer, map, player)) {
        if (computer.getDirection() == UP) {
            direction = RIGHT;
        } else if (computer.getDirection() == RIGHT) {
            direction = DOWN;
        } else if (computer.getDirection() == DOWN) {
            direction = LEFT;
        } else {
            direction = UP;
        }
    }

    computer = choiceMove(computer, direction);
    return computer;
}

Player Game::choiceMove(Player player, Direction direction) {

    switch (direction) {
        case LEFT:
            player.setX(player.getX() - 1);
            player.setDirection(LEFT);
            break;
        case RIGHT:
            player.setX(player.getX() + 1);
            player.setDirection(RIGHT);
            break;
        case UP:
            player.setY(player.getY() - 1);
            player.setDirection(UP);
            break;
        case DOWN:
            player.setY(player.getY() + 1);
            player.setDirection(DOWN);
            break;
    }

    return player;
}

//Unknown solution from internet, works somehow.
//TODO спросить про использование функций.

int Game::myGetch() {
    struct termios oldt,
            newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int Game::myKbhit() {
    static const int STDIN = 0;
    static bool initialized = false;

    if (!initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
