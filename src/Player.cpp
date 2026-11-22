#include "Player.h"
#include <iostream>

Player::Player()
    : position(0), health(100) {
}

void Player::move(int direction) {
    position += direction;

    if (position < 0) {
        position = 0;
    }

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
