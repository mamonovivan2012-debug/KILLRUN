#include "Player.h"

Player::Player()
    : x(0), y(0), health(100) {
}

void Player::move(int dx, int dy) {
    int newX = x + dx;
    int newY = y + dy;

    if (newX >= 0 && newX < 10 &&
        newY >= 0 && newY < 5) {
        x = newX;
        y = newY;
    }
}

void Player::reset() {
    x = 0;
    y = 0;
    health = 100;
}

void Player::takeDamage(int amount) {
    health -= amount;

    if (health < 0) {
        health = 0;
    }
}

int Player::getX() const { return x; }
int Player::getY() const { return y; }
int Player::getHealth() const { return health; }

bool Player::isAlive() const {
    return health > 0;
}
