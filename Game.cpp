#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "User.h"


using namespace std;

void Game::run() {
    clearScreen();
    Map map(15, 60);
    Player first_player(7, 7, RIGHT);
    Player computer(25, 7, LEFT);

    while (true) {
        clearScreen();
        map.draw(first_player, computer);
        computer = computerLogic(computer, first_player, map);
        first_player = logic(first_player);
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
    while (running) {
        clearScreen();
        cout << "TRON GAME" << endl;
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
            cout << "Wrong command. Try again." << endl;
        }
    }
}

//TODO clearScreen, спросить про TERM variable not set -- atm $TERM=xterm, important!
void Game::clearScreen() {
    printf("\033[2J");
    printf("\033[0;0f");
}

Player Game::logic(Player player) {
    player.tail[player.getX()][player.getY()] = true;

    Direction direction;

//    int res = getchar();
//    if (res == 'a') {
//        direction = LEFT;
//    } else if (res == 'd') {
//        direction = RIGHT;
//    } else if (res == 'w') {
//        direction = UP;
//    } else if (res == 's') {
//        direction = DOWN;
//    } else {
//        direction = player.getDirection();
//    }

    char choice;
    cin >> choice;
    switch (choice) {
        case 'a':
            direction = LEFT;
            break;
        case 'd':
            direction = RIGHT;
            break;
        case 'w':
            direction = UP;
            break;
        case 's':
            direction = DOWN;
            break;
        default:
            direction = player.getDirection();
            break;
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