//
// Created by minau on 2/29/2024.
//

#include "Game.h"
#include "SplashState.h"

Game::Game(int width, int height, std::string title)
{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    _data->machine.AddState((new SplashState(_data)));
    this->run();
}

void Game::run()
{
    float newTime, frameTime, Interpolation;
    float currentTime = this->_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    while(_data->window.isOpen())
    {
        _data->machine.ProcessStateChanges();
        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;

        if(frameTime > 0.25f)
        {
            frameTime = 0.25f;
        }

        currentTime = newTime;
        accumulator += frameTime;

        if(accumulator > frameTime)
        {
            _data->machine.GetActiveState()->InputHandler();
            _data->machine.GetActiveState()->Update(dt);
            accumulator -= frameTime;
        }

        Interpolation = accumulator/dt;
        _data->machine.GetActiveState()->Draw(dt);
    }
}