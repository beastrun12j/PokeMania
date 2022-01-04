#include "headers/Pipe.h"
#include "headers/CONSTANTS.h"
#include <iostream>
#include <utility>

namespace pokemania {
    Pipe::Pipe(GameDataRef data) : _data(std::move(data)) {
        _pipeSpawnYOffset = 0;
        _landHeight = (int) _data->assets.GetTexture("Land").getSize().y;
    }

    void Pipe::DrawPipes() {
        for (const auto &pipeSprite: pipeSprites) {
            _data->window.draw(pipeSprite);
        }
    }

    void Pipe::SpawnBottomPipe() {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
        sprite.setPosition((float) (_data->window.getSize().x),
                           ((float) (_data->window.getSize().y) - sprite.getGlobalBounds().height) -
                           (float) _pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnTopPipe() {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Down"));
        sprite.setPosition((float) _data->window.getSize().x, (float) -_pipeSpawnYOffset);
        pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnInvisiblePipe() {
        sf::Sprite sprite(_data->assets.GetTexture("Pipe Up"));
        sprite.setPosition((float) _data->window.getSize().x,
                           (float) (_data->window.getSize().y) - sprite.getGlobalBounds().height);
        sprite.setColor(sf::Color(0, 0, 0, 0));
        pipeSprites.push_back(sprite);
    }

    void Pipe::SpawnScoringPipe() {
        sf::Sprite sprite(_data->assets.GetTexture("Scoring Pipe"));
        sprite.setPosition((float) _data->window.getSize().x, 0);
        scoringPipe.push_back(sprite);
    }

    void Pipe::MovePipes(float dt) {
        for (int i = 0; i < pipeSprites.size(); i++) {

            if (pipeSprites.at(i).getPosition().x < 0 - pipeSprites.at(i).getGlobalBounds().width) {
                pipeSprites.erase(pipeSprites.begin() + i);
            } else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                pipeSprites.at(i).move(-movement, 0);
            }
        }

        for (int i = 0; i < scoringPipe.size(); i++) {

            if (scoringPipe.at(i).getPosition().x < 0 - scoringPipe.at(i).getGlobalBounds().width) {
                scoringPipe.erase(pipeSprites.begin() + i);
            } else {
                float movement = PIPE_MOVEMENT_SPEED * dt;
                scoringPipe.at(i).move(-movement, 0);
            }
        }
    }

    void Pipe::RandomizePipeOffset() {
        _pipeSpawnYOffset = (int) (random()) % (_landHeight + 1);
    }

    const std::vector<sf::Sprite> &Pipe::GetSprites() const {
        return pipeSprites;
    }

    std::vector<sf::Sprite> &Pipe::GetScoringSprite() {
        return scoringPipe;
    }
}
