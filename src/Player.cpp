#include "Player.h"
#include <iostream>

Player::Player()
    : position(0), health(100) {
}

void Player::move(int direction) {
    int newPosition = position + direction;

    if (newPosition < 0) {
        std::cout << "You reached the left edge!\n";
        return;
    }

    if (newPosition >= 10) {
        std::cout << "You reached the right edge!\n";
        return;
    }

    position = newPosition;

    std::cout << "Player moved to position: "
              << position << "\n";
}

void Player::showStatus() const {
    std::cout << "Player position: " << position << "\n";
    std::cout << "Player health: " << health << "\n";
}

int Player::getPosition() const {
    return position;
}

int Player::getHealth() const {
    return health;
}
