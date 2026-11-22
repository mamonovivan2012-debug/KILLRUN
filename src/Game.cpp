#include "Game.h"
#include <iostream>

Game::Game()
    : isRunning(false), gameName("KILLRUN") {
}

void Game::initialize() {
    std::cout << "============================\n";
    std::cout << "          KILLRUN\n";
    std::cout << "============================\n";
    std::cout << "Game initialized!\n";

    isRunning = true;
}

void Game::run() {
    if (!isRunning) {
        std::cout << "Game is not initialized!\n";
        return;
    }

    std::cout << "\n";
    map.display(player.getPosition());

    std::cout << "\nControls:\n";
    std::cout << "A - move left\n";
    std::cout << "D - move right\n";
    std::cout << "S - show player status\n";
    std::cout << "Q - quit\n\n";

    char command;

    while (isRunning) {
        std::cout << "> ";
        std::cin >> command;

        switch (command) {
            case 'a':
            case 'A':
                player.move(-1);
                break;

            case 'd':
            case 'D':
                player.move(1);
                break;

            case 's':
            case 'S':
                player.showStatus();
                break;

            case 'q':
            case 'Q':
                isRunning = false;
                break;

            default:
                std::cout << "Unknown command.\n";
                break;
        }
    }
}

void Game::shutdown() {
    isRunning = false;
    std::cout << "\nKILLRUN shutdown.\n";
}
