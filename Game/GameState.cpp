#include <sstream>
#include <utility>
#include "headers/GameState.h"
#include "headers/CONSTANTS.h"
#include "headers/GameOverState.h"

namespace pokemania {
    GameState::GameState(GameDataRef data) : _data(std::move(data)) {}

    void GameState::Init() {
        _data->assets.LoadSoundBuffer("Hit Sound", HIT_SOUND_FILEPATH);
        _data->assets.LoadSoundBuffer("Wing Sound", WING_SOUND_FILEPATH);
        _data->assets.LoadSoundBuffer("Point Sound", POINT_SOUND_FILEPATH);
        _data->assets.LoadSoundBuffer("Background Sound", BACKGROUND_SOUND_FILEPATH);

        _hitSound.setBuffer(this->_data->assets.GetSoundBuffer("Hit Sound"));
        _wingSound.setBuffer(this->_data->assets.GetSoundBuffer("Wing Sound"));
        _pointSound.setBuffer(this->_data->assets.GetSoundBuffer("Point Sound"));
        _backgroundSound.setBuffer(this->_data->assets.GetSoundBuffer("Background Sound"));

        _data->assets.LoadTexture("Game Background", GAME_BACKGROUND_FILEPATH);
        _data->assets.LoadTexture("Pipe Up", PIPE_UP_FILEPATH);
        _data->assets.LoadTexture("Pipe Down", PIPE_DOWN_FILEPATH);
        _data->assets.LoadTexture("Land", LAND_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 1", BIRD_FRAME_1_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 2", BIRD_FRAME_2_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 3", BIRD_FRAME_3_FILEPATH);
        _data->assets.LoadTexture("Bird Frame 4", BIRD_FRAME_4_FILEPATH);
        _data->assets.LoadTexture("Scoring Pipe", SCORING_PIPE_FILEPATH);
        _data->assets.LoadFont("Poke Font", POKE_FONT_FILEPATH);

        pipe = new Pipe(_data);
        land = new Land(_data);
        bird = new Bird(_data);
        flash = new Flash(_data);
        hud = new HUD(_data);

        _background.setTexture(this->_data->assets.GetTexture("Game Background"));
        _score = 0;
        hud->UpdateScore(_score);

        _gameState = GameStates::eReady;

        _backgroundSound.setLoop(true);
        _backgroundSound.play();
        _backgroundSound.setVolume(20.0);
    }

    void GameState::HandleInput() {
        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }
            if (_data->input.IsButtonPressed(this->_background, sf::Keyboard::Space, this->_data->window)) {
                if (GameStates::eGameOver != _gameState) {
                    _gameState = GameStates::ePlaying;
                    bird->Tap();
                    _wingSound.play();
                }
            }
        }
    }

    void GameState::Update(float dt) {
        if (GameStates::eGameOver != _gameState) {
            bird->Animate();
            land->MoveLand(dt);
        }

        if (GameStates::ePlaying == _gameState) {
            pipe->MovePipes(dt);

            if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY) {
                pipe->RandomizePipeOffset();
                pipe->SpawnInvisiblePipe();
                pipe->SpawnBottomPipe();
                pipe->SpawnTopPipe();
                pipe->SpawnScoringPipe();

                clock.restart();
            }

            bird->Update(dt);

            std::vector<sf::Sprite> landSprites = land->GetSprites();

            for (auto &landSprite: landSprites) {
                if (pokemania::Collision::CheckSpriteCollision(bird->GetSprite(), 0.7f, landSprite, 1.0f)) {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();

                    _backgroundSound.stop();
                    _backgroundSound.resetBuffer();
                }
            }

            std::vector<sf::Sprite> pipeSprites = pipe->GetSprites();

            for (auto &pipeSprite: pipeSprites) {
                if (pokemania::Collision::CheckSpriteCollision(
                        bird->GetSprite(), 0.625f,
                        pipeSprite, 1.0f)) {
                    _gameState = GameStates::eGameOver;
                    clock.restart();
                    _hitSound.play();
                    _backgroundSound.stop();
                    _backgroundSound.resetBuffer();
                }
            }

            if (GameStates::ePlaying == _gameState) {
                std::vector<sf::Sprite> &scoringSprites = pipe->GetScoringSprite();

                for (int i = 0; i < scoringSprites.size(); i++) {
                    if (pokemania::Collision::CheckSpriteCollision(
                            bird->GetSprite(), 0.625f,
                            scoringSprites.at(i), 1.0f)) {
                        _score++;
                        hud->UpdateScore(_score);
                        scoringSprites.erase(scoringSprites.begin() + i);
                        _pointSound.play();
                    }
                }
            }
        }

        if (GameStates::eGameOver == _gameState) {
            flash->Show(dt);
            if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER_APPEARS) {
                _backgroundSound.stop();
                _backgroundSound.resetBuffer();
                _data->machine.AddState(StateRef(new GameOverState(_data, _score)), true);
            }
        }
    }

    void GameState::Draw(float dt) {
        _data->window.clear(sf::Color::Black);
        _data->window.draw(this->_background);
        pipe->DrawPipes();
        land->DrawLand();
        bird->Draw();
        flash->Draw();
        hud->Draw();
        _data->window.display();
    }
}
