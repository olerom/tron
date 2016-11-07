#include "Map.h"

using namespace std;

void Map::draw(Player firstPlayer, Player secondPlayer) {
    for (int i = 0; i < width; i++) {
        cout << ".";
    }
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1) {
                cout << ".";
            } else {
                if (firstPlayer.getY() == i && firstPlayer.getX() == j) {
                    cout << "O";
                } else if (firstPlayer.tail[j][i]) {
                    cout << "o";
                } else if (secondPlayer.getY() == i && secondPlayer.getX() == j) {
                    cout << "@";
                } else if (secondPlayer.tail[j][i]) {
                    cout << "o";
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++) {
        cout << ".";
    }
    cout << endl;
}

Map::Map(int height, int width) {
    this->height = height;
    this->width = width;
}