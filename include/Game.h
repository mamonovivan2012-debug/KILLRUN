#pragma once

#include <string>

class Game {
public:
    Game();

    void initialize();
    void run();
    void shutdown();

private:
    bool isRunning;
    std::string gameName;
};
