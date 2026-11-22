#pragma once

class Target {
public:
    Target();

    int getPosition() const;
    bool isActive() const;

    void collect();

private:
    int position;
    bool active;
};
