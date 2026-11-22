#pragma once

class Map {
public:
    Map();

    void display(int playerPosition) const;

    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
};
