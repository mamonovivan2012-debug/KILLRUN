#pragma once

class Map {
public:
    Map();

    void display() const;

    int getWidth() const;
    int getHeight() const;

private:
    int width;
    int height;
};
