#include "Map.h"
#include <iostream>

Map::Map()
    : width(10), height(5) {
}

void Map::display(int playerPosition, int targetPosition, bool targetActive) const {
    std::cout << "\nMap:\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (y == 0 && x == playerPosition) {
                std::cout << "P ";
            } else if (y == 0 && x == targetPosition && targetActive) {
                std::cout << "X ";
            } else {
                std::cout << ". ";
            }
        }

        std::cout << "\n";
    }
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}
