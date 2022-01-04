#include <utility>
#include "headers/CONSTANTS.h"
#include "headers/Land.h"

namespace pokemania {

    Land::Land(GameDataRef data) : _data(std::move(data)) {
        sf::Sprite sprite(_data->assets.GetTexture("Land"));
        sf::Sprite sprite2(_data->assets.GetTexture("Land"));

        sprite.setPosition(0, (float) (_data->window.getSize().y) - sprite.getGlobalBounds().height);
        sprite2.setPosition(sprite.getGlobalBounds().width,
                            (float) (_data->window.getSize().y) - sprite.getGlobalBounds().height);

        _landSprites.push_back(sprite);
        _landSprites.push_back(sprite2);
    }

    void Land::MoveLand(float dt) {
        for (auto &_landSprite: _landSprites) {
            float movement = PIPE_MOVEMENT_SPEED * dt;
            _landSprite.move(-movement, 0.0f);

            if (_landSprite.getPosition().x < 0 - _landSprite.getGlobalBounds().width) {
                sf::Vector2f position((float) (_data->window.getSize().x), _landSprite.getPosition().y);
                _landSprite.setPosition(position);
            }
        }
    }

    void Land::DrawLand() {
        for (const auto &_landSprite: _landSprites) {
            this->_data->window.draw(_landSprite);
        }
    }

    const std::vector<sf::Sprite> &Land::GetSprites() const {
        return _landSprites;
    }
}
