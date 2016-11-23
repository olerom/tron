#include "Game.h"

void Game::run() {

    Map map(20, 60);
    User player(map.width >> 2, map.height >> 1, RIGHT);
    Computer computer(3 * (map.width >> 2), map.height >> 1, LEFT);

    while (true) {
        clearScreen();

        map.draw(player, computer);
        player.logic();
        computer.move(player, map);


        if (checkOver(player, map, computer)) {
            std::cout << "YOU LOSE" << std::endl;
            break;
        } else if (checkOver(computer, map, player)) {
            std::cout << "YOU WON" << std::endl;
            break;
        }

        usleep(150000);
    }

    _exit(0);
}

void Game::startMenu(int switcher) {

    bool running = true;
    while (running) {
        clearScreen();
        std::cout << " ─────────────────────────────────────────────────────────────────────────" << std::endl
                  << " ─██████████████─████████████████───██████████████─██████──────────██████─" << std::endl
                  << " ─██░░░░░░░░░░██─██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░██████████──██░░██─" << std::endl
                  << " ─██████░░██████─██░░████████░░██───██░░██████░░██─██░░░░░░░░░░██──██░░██─" << std::endl
                  << " ─────██░░██─────██░░██────██░░██───██░░██──██░░██─██░░██████░░██──██░░██─" << std::endl
                  << " ─────██░░██─────██░░████████░░██───██░░██──██░░██─██░░██──██░░██──██░░██─" << std::endl
                  << " ─────██░░██─────██░░░░░░░░░░░░██───██░░██──██░░██─██░░██──██░░██──██░░██─" << std::endl
                  << " ─────██░░██─────██░░██████░░████───██░░██──██░░██─██░░██──██░░██──██░░██─" << std::endl
                  << " ─────██░░██─────██░░██──██░░██─────██░░██──██░░██─██░░██──██░░██████░░██─" << std::endl
                  << " ─────██░░██─────██░░██──██░░██████─██░░██████░░██─██░░██──██░░░░░░░░░░██─" << std::endl
                  << " ─────██░░██─────██░░██──██░░░░░░██─██░░░░░░░░░░██─██░░██──██████████░░██─" << std::endl
                  << " ─────██████─────██████──██████████─██████████████─██████──────────██████─" << std::endl
                  << " ─────────────────────────────────────────────────────────────────────────" << std::endl;

        switch (switcher) {
            case 1:
                std::cout << "                          << Start new game >>" << std::endl
                          << "                              High scores" << std::endl
                          << "                                  Quit" << std::endl;
                break;
            case 2:
                std::cout << "                             Start new game" << std::endl
                          << "                           << High scores >>" << std::endl
                          << "                                  Quit" << std::endl;
                break;
            case 3:
                std::cout << "                             Start new game" << std::endl
                          << "                              High scores" << std::endl
                          << "                               << Quit >>" << std::endl;
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

bool Game::checkOver(Player firstPlayer, Map map, Player secondPlayer) {

    return firstPlayer.getX() == 0 || firstPlayer.getX() == map.width - 1
           || firstPlayer.getY() == -1 || firstPlayer.getY() == map.height
           || firstPlayer.tail[firstPlayer.getX()][firstPlayer.getY()]
           || secondPlayer.tail[firstPlayer.getX()][firstPlayer.getY()]
           || (firstPlayer.getX() == secondPlayer.getX() && firstPlayer.getY() == secondPlayer.getY());

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
