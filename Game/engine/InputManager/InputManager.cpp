#pragma once

#include "InputManager.h"

namespace pokemania {
    bool InputManager::IsSpriteClicked(const sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow &window) {
        if (sf::Mouse::isButtonPressed(button)) {
            sf::IntRect playButtonRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width,
                                       (int)object.getGlobalBounds().height);

            if (playButtonRect.contains(sf::Mouse::getPosition(window))) {
                return true;
            }
        }

        return false;
    }

    bool InputManager::IsButtonPressed(const sf::Sprite& object, sf::Keyboard::Key button, sf::RenderWindow &window) {
        if (sf::Keyboard::isKeyPressed(button)) {
            sf::IntRect playButtonRect((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width,
                                       (int)object.getGlobalBounds().height);

            if (playButtonRect.contains(sf::Mouse::getPosition(window))) {
                return true;
            }
        }

        return false;
    }
}