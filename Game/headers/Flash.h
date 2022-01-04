#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "CONSTANTS.h"

namespace pokemania {
    class Flash {
    public:
        explicit Flash(GameDataRef data);

        void Show(float dt);

        void Draw();

    private:
        GameDataRef _data;
        sf::RectangleShape _shape;

        bool _flashOn;
    };
}