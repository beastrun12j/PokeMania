#include "headers/Flash.h"
#include <utility>

namespace pokemania {
    Flash::Flash(GameDataRef data) : _data(std::move(data)) {
        _shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
        _shape.setFillColor(sf::Color(255, 255, 255, 0));

        _flashOn = true;
    }

    void Flash::Show(float dt) {
        if (_flashOn) {
            int alpha = (int) ((float) (_shape.getFillColor().a) + (FLASH_SPEED * dt));

            if (alpha >= 255) {
                alpha = 255;
                _flashOn = false;
            }

            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        } else {
            int alpha = (int) ((float) (_shape.getFillColor().a) - (FLASH_SPEED * dt));

            if (alpha <= 0) {
                alpha = 0;
                _flashOn = false;
            }

            _shape.setFillColor(sf::Color(255, 255, 255, alpha));
        }
    }

    void Flash::Draw() {
        _data->window.draw(_shape);
    }
}
