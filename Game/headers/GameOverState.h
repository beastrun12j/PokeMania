#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/StateMachine/State.h"
#include "Game.h"

namespace pokemania {
    class GameOverState : public State {
    public:
        GameOverState(GameDataRef data, int score);

        void Init() override;

        void HandleInput() override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _gameOverTitle;
        sf::Sprite _gameOverContainer;
        sf::Sprite _retryButton;
        sf::Sprite _medal;
        sf::Text _scoreText;
        sf::Text _highScoreText;

        int _score;
        int _highScore;
    };
}