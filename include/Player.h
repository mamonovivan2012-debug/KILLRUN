#pragma once

class Player {
public:
    Player();

    void move(int direction);
    void showStatus() const;

    int getPosition() const;
    int getHealth() const;

private:
    int position;
    int health;
};
