#include "headers/HUD.h"
#include <string>
#include <utility>

namespace pokemania {
    HUD::HUD(GameDataRef data) : _data(std::move(data)) {
        _scoreText.setFont(_data->assets.GetFont("Poke Font"));
        _scoreText.setString("0");
        _scoreText.setCharacterSize(128);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2,
                             _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition((float) (_data->window.getSize().x) / 2,
                               (float) (_data->window.getSize().y) / 5);
    }

    void HUD::Draw() {
        _data->window.draw(_scoreText);
    }

    void HUD::UpdateScore(int score) {
        _scoreText.setString(std::to_string(score));
    }
}
