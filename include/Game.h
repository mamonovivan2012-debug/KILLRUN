#pragma once

#include <string>
#include "Player.h"
#include "Map.h"

class Game {
public:
    Game();

    void initialize();
    void run();
    void shutdown();

private:
    bool isRunning;
    std::string gameName;
    Player player;
    Map map;
};
