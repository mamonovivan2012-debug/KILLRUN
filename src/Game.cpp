#include "Game.h"
#include <iostream>

Game::Game()
    : isRunning(false),
      gameName("KILLRUN"),
      targets{
          Target(3, 0),
          Target(6, 2),
          Target(9, 4)
      },
      hazards{{
          {4, 1},
          {7, 3}
      }},
      hazardTriggered{false, false},
      score(0) {
}

void Game::initialize() {
    isRunning = true;

    std::cout << "KILLRUN v0.2 initialized!\n";
}

void Game::showMenu() {
    std::cout << "\n========================\n";
    std::cout << "       KILLRUN\n";
    std::cout << "========================\n";
    std::cout << "1 - Start game\n";
    std::cout << "Q - Quit\n";
    std::cout << "> ";
}

void Game::run() {
    while (isRunning) {
        showMenu();

        char command;
        std::cin >> command;

        switch (command) {
            case '1':
                playGame();
                break;

            case 'q':
            case 'Q':
                isRunning = false;
                break;

            default:
                std::cout << "Unknown command!\n";
                break;
        }
    }
}

void Game::playGame() {
    player.reset();
    score = 0;

    targets = {
        Target(3, 0),
        Target(6, 2),
        Target(9, 4)
    };

    hazardTriggered.fill(false);

    bool quitToMenu = false;

    std::cout << "\nCollect all 3 targets!\n";
    std::cout << "Avoid the hazards!\n";
    std::cout << "WASD - Move | I - Status | Q - Menu\n";

    while (player.isAlive() &&
           !allTargetsCollected() &&
           !quitToMenu) {

        map.display(
            player,
            targets,
            hazards,
            hazardTriggered
        );

        std::cout << "\n> ";

        char command;
        std::cin >> command;

        switch (command) {
            case 'w':
            case 'W':
                player.move(0, -1);
                break;

            case 's':
            case 'S':
                player.move(0, 1);
                break;

            case 'a':
            case 'A':
                player.move(-1, 0);
                break;

            case 'd':
            case 'D':
                player.move(1, 0);
                break;

            case 'i':
            case 'I':
                showStatus();
                continue;

            case 'q':
            case 'Q':
                quitToMenu = true;
                continue;

            default:
                std::cout << "Unknown command!\n";
                continue;
        }

        for (int i = 0; i < 2; ++i) {
            if (!hazardTriggered[i] &&
                player.getX() == hazards[i].first &&
                player.getY() == hazards[i].second) {

                hazardTriggered[i] = true;
                player.takeDamage(50);

                std::cout << "Hazard triggered! -50 health\n";
            }
        }

        for (auto& target : targets) {
            if (target.isActive() &&
                player.getX() == target.getX() &&
                player.getY() == target.getY()) {

                target.collect();
                score += 10;

                std::cout << "Target collected! +10 points\n";
            }
        }
    }

    if (allTargetsCollected()) {
        std::cout << "\n*** YOU WIN! ***\n";
    } else if (!player.isAlive()) {
        std::cout << "\n*** GAME OVER ***\n";
    }

    if (!quitToMenu) {
        showStatus();
    }
}

void Game::showStatus() const {
    std::cout << "\n----- STATUS -----\n";
    std::cout << "Health: " << player.getHealth() << '\n';
    std::cout << "Score: " << score << '\n';
    std::cout << "Position: "
              << player.getX() << ", "
              << player.getY() << '\n';
    std::cout << "------------------\n";
}

bool Game::allTargetsCollected() const {
    for (const auto& target : targets) {
        if (target.isActive()) {
            return false;
        }
    }

    return true;
}

void Game::shutdown() {
    isRunning = false;
    std::cout << "KILLRUN closed.\n";
}
