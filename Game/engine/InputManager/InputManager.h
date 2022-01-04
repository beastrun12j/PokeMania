#pragma once

#include "SFML/Graphics.hpp"

namespace pokemania {
    class InputManager {
    public:
        static bool IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window);

        static bool IsButtonPressed(const sf::Sprite& object, sf::Keyboard::Key button, sf::RenderWindow &window);
    };
}