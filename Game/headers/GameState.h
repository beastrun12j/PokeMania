#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../engine/StateMachine/State.h"
#include "Game.h"
#include "Pipe.h"
#include "Land.h"
#include "Bird.h"
#include "Collision.h"
#include "Flash.h"
#include "HUD.h"

namespace pokemania {
    class GameState : public State {
    public:
        explicit GameState(GameDataRef data);

        void Init() override;

        void HandleInput() override;

        void Update(float dt) override;

        void Draw(float dt) override;

    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Clock clock;
        Collision collision;
        Pipe *pipe;
        Land *land;
        Bird *bird;
        Flash *flash;
        HUD *hud;

        int _gameState;
        int _score;

        sf::Sound _hitSound;
        sf::Sound _wingSound;
        sf::Sound _pointSound;
        sf::Sound _backgroundSound;
    };
}