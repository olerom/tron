#include "Game.h"

//**
#include <termios.h>
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <stropts.h>
#include <asm/ioctls.h>

//**

using namespace std;

void Game::run() {
    clearScreen();
    Map map(15, 60);
    Player first_player(7, 7, RIGHT);
    Player computer(25, 8, LEFT);

    while (true) {
        clearScreen();
        map.draw(first_player, computer);
        computer = computerLogic(computer, first_player, map);
        first_player = logic(first_player);
        sleep(0.1);
        if (checkOver(first_player, map, computer)) {
            cout << "GAME OVER" << endl;
            break;
        } else if (checkOver(computer, map, first_player)) {
            cout << "YOU WON" << endl;
            break;
        }
    }

}

void Game::startMenu() {

    string menu;
    bool running = true;
    bool wrongCommand = false;
    while (running) {
        clearScreen();
        if (!wrongCommand) {
            cout << "TRON GAME" << endl;
        } else {
            cout << "Wrong command. Try again." << endl;
        }
        cout << endl;
        cout << "1. Start new game" << endl;
        cout << "2. Quit" << endl;
        cout << endl;

        cin >> menu;
        if (menu == "1") {
            run();
            running = false;
        } else if (menu == "2") {
            return;
        } else {
            wrongCommand = true;
        }
    }
}

void Game::clearScreen() {
    printf("\033[2J");
    printf("\033[0;0f");
}

Player Game::logic(Player player) {
    player.tail[player.getX()][player.getY()] = true;

    Direction direction;

//    if (myKbhit()) {
    int res = myGetch();
    if (res == 'a') {
        direction = LEFT;
    } else if (res == 'd') {
        direction = RIGHT;
    } else if (res == 'w') {
        direction = UP;
    } else if (res == 's') {
        direction = DOWN;
    } else {
        direction = player.getDirection();
    }
//    }

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