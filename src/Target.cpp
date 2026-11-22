#include "Target.h"

Target::Target(int startX, int startY)
    : x(startX), y(startY), active(true) {
}

int Target::getX() const { return x; }
int Target::getY() const { return y; }

bool Target::isActive() const {
    return active;
}

void Target::collect() {
    active = false;
}
