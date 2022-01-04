#pragma once

#include <SFML/Graphics.hpp>
#include "CONSTANTS.h"
#include "Game.h"

namespace pokemania {
    class HUD {
    public:
        explicit HUD(GameDataRef data);

        void Draw();

        void UpdateScore(int score);

    private:
        GameDataRef _data;
        sf::Text _scoreText;
    };
}