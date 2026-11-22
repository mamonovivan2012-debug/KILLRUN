#pragma once

class Player {
public:
    Player();

    void move(int dx, int dy);
    void reset();
    void takeDamage(int amount);

    int getX() const;
    int getY() const;
    int getHealth() const;
    bool isAlive() const;

private:
    int x;
    int y;
    int health;
};
