#include "Map.h"


void Map::draw(Player firstPlayer, Player secondPlayer) {
    for (int i = 0; i < this->width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (j == 0 || j == this->width - 1) {
                std::cout << "#";
            } else {
                if (firstPlayer.getY() == i && firstPlayer.getX() == j) {
                    std::cout << "O";
                } else if (firstPlayer.tail[j][i]) {
                    std::cout << "o";
                } else if (secondPlayer.getY() == i && secondPlayer.getX() == j) {
                    std::cout << "@";
                } else if (secondPlayer.tail[j][i]) {
                    std::cout << "o";
                } else {
                    std::cout << " ";
                }
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < this->width; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;
}

Map::Map(int height, int width) {
    this->height = height;
    this->width = width;
}