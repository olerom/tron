#include "Map.h"


void Map::draw(Player firstPlayer, Player secondPlayer) {
    // Be careful here later:
    std::cout << "First player: " << firstPlayer.getScore();
    for (int i = 0; i < this->width - 31; i++) {
        std::cout << " ";
    }
    std::cout << "Second player: " << secondPlayer.getScore() << std::endl;
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
                    std::cout << CYAN << "O" << RESET;
                } else if (firstPlayer.tail[j][i]) {
                    std::cout << CYAN << "o" << RESET;
                } else if (secondPlayer.getY() == i && secondPlayer.getX() == j) {
                    std::cout << RED << "@" << RESET;
                } else if (secondPlayer.tail[j][i]) {
                    std::cout << RED << "o" << RESET;
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

Map::Map(int height, int width) {
    this->height = height;
    this->width = width;
}