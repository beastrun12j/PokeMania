#include <sstream>
#include "headers/GameOverState.h"
#include "headers/CONSTANTS.h"
#include "headers/GameState.h"
#include <fstream>
#include <utility>

namespace pokemania {
    GameOverState::GameOverState(GameDataRef data, int score) : _data(std::move(data)), _score(score) {}

    void GameOverState::Init() {

        std::ifstream readFile;
        readFile.open(HIGHSCORE_FILEPATH);
        if (readFile.is_open()) {
            while (!readFile.eof()) {
                readFile >> _highScore;
            }
        }
        readFile.close();

        std::ofstream writeFile(HIGHSCORE_FILEPATH);
        if (writeFile.is_open()) {
            if (_score > _highScore) {
                _highScore = _score;
            }
            writeFile << _highScore;
        }
        writeFile.close();

        this->_data->assets.LoadTexture("Game Over Background", GAME_OVER_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Title", GAME_OVER_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Game Over Body", GAME_OVER_BODY_FILEPATH);
        this->_data->assets.LoadTexture("Bronze Medal", BRONZE_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Silver Medal", SILVER_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Gold Medal", GOLD_MEDAL_FILEPATH);
        this->_data->assets.LoadTexture("Retry Button", GAME_OVER_RETRY_BUTTON_FILEPATH);


        _background.setTexture(this->_data->assets.GetTexture("Game Over Background"));
        _gameOverTitle.setTexture(this->_data->assets.GetTexture("Game Over Title"));
        _gameOverContainer.setTexture(this->_data->assets.GetTexture("Game Over Body"));
        _retryButton.setTexture(this->_data->assets.GetTexture("Retry Button"));

        _gameOverContainer.setPosition(
                (float) ((float) (_data->window.getSize().x) / 2) - ((_gameOverContainer.getGlobalBounds().width) / 2),
                (float) (_data->window.getSize().y) / 2 -
                (_gameOverContainer.getGlobalBounds().height / 2));
        _gameOverTitle.setPosition(
                sf::Vector2f(((float) (_data->window.getSize().x) / 2) -
                             ((float) (_gameOverTitle.getGlobalBounds().width) / 2),
                             (float) ((_gameOverContainer.getPosition().y) -
                                      (_gameOverTitle.getGlobalBounds().height * 1.2))));
        _retryButton.setPosition(480, 550);

        _scoreText.setFont(_data->assets.GetFont("Poke Font"));
        _scoreText.setString(std::to_string(_score));
        _scoreText.setCharacterSize(56);
        _scoreText.setFillColor(sf::Color::White);
        _scoreText.setOrigin(
                _scoreText.getGlobalBounds().width / 2,
                _scoreText.getGlobalBounds().height / 2);
        _scoreText.setPosition(
                (float) ((float) ((float) (_data->window.getSize().x) / 10) * 6.30),
                (float) ((float) (_data->window.getSize().y) / 2.22));

        _highScoreText.setFont(_data->assets.GetFont("Poke Font"));
        _highScoreText.setString(std::to_string(_highScore));
        _highScoreText.setCharacterSize(56);
        _highScoreText.setFillColor(sf::Color::White);
        _highScoreText.setOrigin(_highScoreText.getGlobalBounds().width / 2,
                                 _highScoreText.getGlobalBounds().height / 2);
        _highScoreText.setPosition((float) ((float) ((float) (_data->window.getSize().x) / 10) * 6.30),
                                   (float) ((float) (_data->window.getSize().y) / 1.72));

        if (_score >= GOLD_MEDAL_SCORE) {
            _medal.setTexture(_data->assets.GetTexture("Gold Medal"));
        } else if (_score >= SILVER_MEDAL_SCORE) {
            _medal.setTexture(_data->assets.GetTexture("Silver Medal"));
        } else if (_score >= BRONZE_MEDAL_SCORE) {
            _medal.setTexture(_data->assets.GetTexture("Bronze Medal"));
        }
        _medal.setPosition(430, 355);
    }

    void GameOverState::HandleInput() {
        sf::Event event{};
        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }
            if (_data->input.IsSpriteClicked(_retryButton, sf::Mouse::Left, _data->window)) {
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void GameOverState::Update(float dt) {}

    void GameOverState::Draw(float dt) {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_background);
        this->_data->window.draw(_gameOverTitle);
        this->_data->window.draw(_gameOverContainer);
        this->_data->window.draw(_retryButton);
        this->_data->window.draw(_scoreText);
        this->_data->window.draw(_highScoreText);
        this->_data->window.draw(_medal);
        this->_data->window.display();
    }
}
