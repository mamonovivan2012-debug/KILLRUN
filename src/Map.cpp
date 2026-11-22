#include "Map.h"
#include <iostream>

Map::Map()
    : width(10), height(5) {
}

void Map::display() const {
    std::cout << "\nMap:\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            std::cout << ". ";
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
