#include "Map.h"
#include <iostream>

void Map::display(
    const Player& player,
    const std::array<Target, 3>& targets,
    const std::array<std::pair<int, int>, 2>& hazards,
    const std::array<bool, 2>& hazardTriggered
) const {

    std::cout << "\n========== MAP ==========\n";

    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x < 10; ++x) {
            char symbol = '.';

            if (player.getX() == x && player.getY() == y) {
                symbol = 'P';
            } else {
                for (const auto& target : targets) {
                    if (target.isActive() &&
                        target.getX() == x &&
                        target.getY() == y) {
                        symbol = 'X';
                    }
                }

                for (int i = 0; i < 2; ++i) {
                    if (!hazardTriggered[i] &&
                        hazards[i].first == x &&
                        hazards[i].second == y) {
                        symbol = 'H';
                    }
                }
            }

            std::cout << symbol << ' ';
        }

        std::cout << '\n';
    }

    std::cout << "=========================\n";
    std::cout << "P = Player | X = Target | H = Hazard\n";
}
