#pragma once

#include <array>
#include <utility>
#include "Player.h"
#include "Target.h"

class Map {
public:
    void display(
        const Player& player,
        const std::array<Target, 3>& targets,
        const std::array<std::pair<int, int>, 2>& hazards,
        const std::array<bool, 2>& hazardTriggered
    ) const;
};
