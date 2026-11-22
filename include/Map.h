#pragma once

class Map {
public:
    Map();

    void display(int playerPosition, int targetPosition, bool targetActive) const;

    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
};
