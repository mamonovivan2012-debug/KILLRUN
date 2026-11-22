#include "Target.h"

Target::Target()
    : position(5), active(true) {
}

int Target::getPosition() const {
    return position;
}

bool Target::isActive() const {
    return active;
}

void Target::collect() {
    active = false;
}
