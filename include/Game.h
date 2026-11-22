#pragma once

#include <string>
#include "Player.h"

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
};
