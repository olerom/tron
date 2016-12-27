#include "Map.h"

void Map::draw(Player firstPlayer, Player secondPlayer) {
    // Be careful here later:
    std::cout << CYAN << "First player: " << firstPlayer.getScore() << RESET;
    for (int i = 0; i < this->getWidth() - 31; i++) {
        std::cout << " ";
    }
    std::cout << RED << "Second player: " << secondPlayer.getScore() << RESET << std::endl;
    // To here


    for (int i = 0; i < this->getWidth(); i++) {
        std::cout << "▄";
    }
    std::cout << std::endl;
    for (int j = 0; j < this->getHeight(); j++) {
        for (int i = 0; i < this->getWidth(); i++) {
            if (i == 0 || i == this->getWidth() - 1) {
                std::cout << "█";
            } else {
                if (firstPlayer.getY() == j && firstPlayer.getX() == i) {
                    std::cout << CYAN << "°" << RESET;
                } else if (firstPlayer.getTail(i, j)) {
                    std::cout << CYAN << "°" << RESET;
                } else if (secondPlayer.getY() == j && secondPlayer.getX() == i) {
                    std::cout << RED << "°" << RESET;
                } else if (secondPlayer.getTail(i, j)) {
                    std::cout << RED << "°" << RESET;
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < this->getWidth(); i++) {
        std::cout << "▀";
    }
    std::cout << std::endl;
}

Map::Map(int height, int widthd) {
    this->height = height;
    this->width = width;
}

int Map::getHeight() {
    return this->height;
}

int Map::getWidth() {
    return this->width;
}