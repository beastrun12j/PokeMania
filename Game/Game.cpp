#include "headers/Game.h"
#include "headers/SplashState.h"

namespace pokemania {
    Game::Game(int width, int height, const std::string& title) {

        _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        _data->machine.AddState(StateRef(new SplashState(this->_data)));

        this->Run();
    }

    void Game::Run() {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen()) {
            this->_data->machine.ProcessStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f) {
                frameTime = 0.25f;
            }

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt) {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(dt);
                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}