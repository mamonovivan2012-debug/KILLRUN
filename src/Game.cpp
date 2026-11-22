#include "Game.h"
#include <iostream>

Game::Game()
    : isRunning(false), gameName("KILLRUN") {
}

void Game::initialize() {
    std::cout << "============================\n";
    std::cout << "       " << gameName << "\n";
    std::cout << "============================\n";
    std::cout << "Game initialized!\n";

    isRunning = true;
}

void Game::run() {
    if (!isRunning) {
        std::cout << "Game is not initialized!\n";
        return;
    }

    std::cout << "Welcome to KILLRUN!\n";
    std::cout << "Game loop started.\n";
}

void Game::shutdown() {
    isRunning = false;
    std::cout << "KILLRUN shutdown.\n";
}
