#pragma once

#include <SFML/Graphics.hpp>
#include "../engine/StateMachine/State.h"
#include "Game.h"

namespace pokemania {
    class MainMenuState : public State {
    public:
        explicit MainMenuState(GameDataRef data);

        void Init() override;

        void HandleInput() override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        GameDataRef _data;

        sf::Sprite _background;
        sf::Sprite _title;
        sf::Sprite _playButton;
    };
}