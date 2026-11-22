#pragma once

class Target {
public:
    Target(int x, int y);

    int getX() const;
    int getY() const;
    bool isActive() const;

    void collect();

private:
    int x;
    int y;
    bool active;
};
