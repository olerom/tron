#include "Game.h"

void Game::run(int firstScore, int secondScore, int speed) {

    Map map(20, 80, speed);
    User player(map.width >> 2, map.height >> 1, RIGHT, firstScore);
    Computer computer(3 * (map.width >> 2), map.height >> 1, LEFT, secondScore);

    while (true) {
        clearScreen();

        map.draw(player, computer);
        player.logic();
        computer.move(player, map);

        if (checkOver(player, map, computer)) {
            usleep(1000000);
            computer.upScore();
            run(player.getScore(), computer.getScore(), map.speed);
        } else if (checkOver(computer, map, player)) {
            usleep(1000000);
            player.upScore();
            run(player.getScore(), computer.getScore(), map.speed);
        }

        if (player.getScore() == 3) {
            this->winMenu(1);
            break;
        } else if (computer.getScore() == 3) {
            this->loseMenu(1);
            break;
        }

        usleep((__useconds_t) (map.speed * 10000));
    }
    _exit(0);
}

void Game::startMenu(int switcher) {

    bool running = true;
    static int speed = 6;
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
                          << "                                Settings" << std::endl
                          << "                                  Quit" << std::endl;
                break;
            case 2:
                std::cout << "                             Start new game" << std::endl
                          << "                             << Settings >>" << std::endl
                          << "                                  Quit" << std::endl;
                break;
            case 3:
                std::cout << "                             Start new game" << std::endl
                          << "                                Settings" << std::endl
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
                    this->run(0, 0, speed);
                } else if (switcher == 2) {
                    speed = this->settings();
                } else if (switcher == 3) {
                    _exit(0);
                }
                break;
        }
    }
}


int Game::settings() {
    clearScreen();
    std::cout << "Choose speed: from 1 to 9" << std::endl;
    bool running = true;
    while (running) {
        int choice = myGetch();
        if (choice >= 49 && choice <= 57) {
            return 60 - choice;
        } else {
            std::cout << "Wrong input. Try again." << std::endl;
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

void Game::winMenu(int switcher) {
    while (true) {
        clearScreen();
        std::cout << " ____   ____  _____   ______  _________    ___   _______   ____  ____  " << std::endl
                  << "|_  _| |_  _||_   _|.' ___  ||  _   _  | .'   `.|_   __ \\ |_  _||_  _| " << std::endl
                  << "  \\ \\   / /    | | / .'   \\_||_/ | | \\_|/  .-.  \\ | |__) |  \\ \\  / /   " << std::endl
                  << "   \\ \\ / /     | | | |           | |    | |   | | |  __ /    \\ \\/ /    " << std::endl
                  << "    \\ ' /     _| |_\\ `.___.'\\   _| |_   \\  `-'  /_| |  \\ \\_  _|  |_    " << std::endl
                  << "     \\_/     |_____|`.____ .'  |_____|   `.___.'|____| |___||______|   " << std::endl
                  << "                                                                       " << std::endl;
        switch (switcher) {
            case 1:
                std::cout << "                          << Main menu >>" << std::endl
                          << "                               Quit" << std::endl;
                break;
            case 2:
                std::cout << "                             Main menu" << std::endl
                          << "                            << Quit >>" << std::endl;
                break;
        }
        int menu = myGetch();
        switch (menu) {
            case 'w':
            case 's':
                if (switcher != 1) {
                    this->winMenu(1);
                } else {
                    this->winMenu(2);
                }
                break;
            case ' ':
                if (switcher == 1) {
                    this->startMenu(1);
                } else if (switcher == 2) {
                    _exit(0);
                }
                break;
        }
    }

}

void Game::loseMenu(int switcher) {
    while (true) {
        clearScreen();
        std::cout << "     ______   ________  ________  ________       _     _________  " << std::endl
                  << "    |_   _ `.|_   __  ||_   __  ||_   __  |     / \\   |  _   _  | " << std::endl
                  << "      | | `. \\ | |_ \\_|  | |_ \\_|  | |_ \\_|    / _ \\  |_/ | | \\_| " << std::endl
                  << "      | |  | | |  _| _   |  _|     |  _| _    / ___ \\     | |     " << std::endl
                  << "     _| |_.' /_| |__/ | _| |_     _| |__/ | _/ /   \\ \\_  _| |_    " << std::endl
                  << "    |______.'|________||_____|   |________||____| |____||_____|   " << std::endl
                  << "                                                              " << std::endl;
        switch (switcher) {
            case 1:
                std::cout << "                          << Main menu >>" << std::endl
                          << "                               Quit" << std::endl;
                break;
            case 2:
                std::cout << "                             Main menu" << std::endl
                          << "                            << Quit >>" << std::endl;
                break;
        }
        int menu = myGetch();
        switch (menu) {
            case 'w':
            case 's':
                if (switcher != 1) {
                    this->loseMenu(1);
                } else {
                    this->loseMenu(2);
                }
                break;
            case ' ':
                if (switcher == 1) {
                    this->startMenu(1);
                } else if (switcher == 2) {
                    _exit(0);
                }
                break;
        }
    }

}