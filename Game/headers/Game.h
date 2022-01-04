#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "../engine/StateMachine/StateMachine.h"
#include "../engine/AssetManager/AssetManager.h"
#include "../engine/InputManager/InputManager.h"

namespace pokemania {
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    public:
        Game(int width, int height, const std::string& title);

    private:
        GameDataRef _data = std::make_shared<GameData>();
        sf::Clock _clock;

        // Updates run at 60 per second.
        const float dt = 1.0f / 60.0f;
        void Run();
    };
}