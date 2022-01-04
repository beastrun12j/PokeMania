#include "headers/MainMenuState.h"
#include "headers/GameState.h"
#include "headers/CONSTANTS.h"
#include <utility>

namespace pokemania {
    MainMenuState::MainMenuState(GameDataRef data) : _data(std::move(data)) {}

    void MainMenuState::Init() {

        this->_data->assets.LoadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
        this->_data->assets.LoadTexture("Game Title", GAME_TITLE_FILEPATH);
        this->_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

        _background.setTexture(this->_data->assets.GetTexture("Main Menu Background"));

        _title.setTexture(this->_data->assets.GetTexture("Game Title"));
        _title.setPosition((int) (SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2),
                           _title.getGlobalBounds().height / 2);

        _playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
        _playButton.setScale(0.4, 0.4);
        _playButton.setPosition((int) (SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
                                (int) (SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));

    }

    void MainMenuState::HandleInput() {
        sf::Event event{};

        while (this->_data->window.pollEvent(event)) {
            if (sf::Event::Closed == event.type) {
                this->_data->window.close();
            }
            if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window)) {
                _data->machine.AddState(StateRef(new GameState(_data)), true);
            }
        }
    }

    void MainMenuState::Update(float dt) {}

    void MainMenuState::Draw(float dt) {
        this->_data->window.clear(sf::Color::Black);
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_title);
        this->_data->window.draw(this->_playButton);
        this->_data->window.display();
    }
}
