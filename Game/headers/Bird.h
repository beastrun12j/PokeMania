#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "CONSTANTS.h"
#include "Game.h"

namespace pokemania {
    class Bird {
    public:
        explicit Bird(GameDataRef data);

        void Draw();

        void Animate();

        void Update(float dt);

        void Tap();

        const sf::Sprite &GetSprite() const;

    private:
        GameDataRef _data;

        sf::Sprite _birdSprite;
        sf::Clock _clock;
        sf::Clock _movementClock;

        int _birdState;
        float _rotation;
        unsigned int _animationIterator;
        std::vector<sf::Texture> _animationFrames;
    };
}