#pragma once

#include <SFML/Graphics.hpp>

namespace pokemania {
    class Collision {
    public:
        static bool CheckSpriteCollision(sf::Sprite sprite1, float scale1, sf::Sprite sprite2, float scale2);
    };
}