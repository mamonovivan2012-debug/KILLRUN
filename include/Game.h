#pragma once

#include <array>
#include <string>
#include <utility>

#include "Player.h"
#include "Map.h"
#include "Target.h"

class Game {
public:
    Game();

    void initialize();
    void run();
    void shutdown();

private:
    void showMenu();
    void playGame();
    void showStatus() const;
    bool allTargetsCollected() const;

    bool isRunning;
    std::string gameName;

    Player player;
    Map map;

    std::array<Target, 3> targets;
    std::array<std::pair<int, int>, 2> hazards;
    std::array<bool, 2> hazardTriggered;

    int score;
};
