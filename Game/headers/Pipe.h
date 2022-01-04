#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"
#include <vector>

namespace pokemania {
    class Pipe {
    public:
        explicit Pipe(GameDataRef data);

        void SpawnBottomPipe();

        void SpawnTopPipe();

        void SpawnInvisiblePipe();

        void SpawnScoringPipe();

        void MovePipes(float dt);

        void DrawPipes();

        void RandomizePipeOffset();

        const std::vector<sf::Sprite> &GetSprites() const;

        std::vector<sf::Sprite> &GetScoringSprite();

    private:
        GameDataRef _data;
        std::vector<sf::Sprite> pipeSprites;
        std::vector<sf::Sprite> scoringPipe;

        int _landHeight;
        int _pipeSpawnYOffset;
    };
}