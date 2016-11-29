#include "Map.h"


void Map::draw(Player firstPlayer, Player secondPlayer) {
    // Be careful here later:
    std::cout << CYAN << "First player: " << firstPlayer.getScore() << RESET;
    for (int i = 0; i < this->width - 31; i++) {
        std::cout << " ";
    }
    std::cout << RED << "Second player: " << secondPlayer.getScore() << RESET << std::endl;
    // To here


    for (int i = 0; i < this->width; i++) {
        std::cout << "▄";
    }
    std::cout << std::endl;
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (j == 0 || j == this->width - 1) {
                std::cout << "█";
            } else {
                if (firstPlayer.getY() == i && firstPlayer.getX() == j) {
                    std::cout << CYAN << "°" << RESET;
                } else if (firstPlayer.tail[j][i]) {
                    std::cout << CYAN << "°" << RESET;
                } else if (secondPlayer.getY() == i && secondPlayer.getX() == j) {
                    std::cout << RED << "°" << RESET;
                } else if (secondPlayer.tail[j][i]) {
                    std::cout << RED << "°" << RESET;
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < this->width; i++) {
        std::cout << "▀";
    }
    std::cout << std::endl;
}

Map::Map(int height, int width, int speed) {
    this->height = height;
    this->width = width;
    this->speed = speed;
}