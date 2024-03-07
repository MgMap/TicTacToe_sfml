//
// Created by minau on 3/2/2024.
//

#include "GameOverState.h"

GameOverState::GameOverState(GameDataRef data) : _data(data)
{

}

void GameOverState::Init()
{
    Textures::setTexture(_retryButton,RETRY_BUTTON);
    Textures::setTexture(_homeButton,HOME);

    _homeButton.setPosition(10,_homeButton.getPosition().y);
    _retryButton.setPosition(_data->window.getSize().x-_retryButton.getLocalBounds().width,
                             _data->window.getSize().y-_retryButton.getLocalBounds().height);
}

void GameOverState::InputHandler()
{
    sf::Event event;
    if(sf::Event::Closed == event.type)
    {
        _data->window.close();
    }
    if(MouseEvents::isClicked(_retryButton,_data->window))
    {
        //going back to the playing state by poping the pause state
        _data->machine.AddState(new GameState(_data),true);

    }
    if(MouseEvents::isClicked(_homeButton,_data->window))
    {
        _data->machine.AddState(new MainMenuState(_data),true);
    }
}

void GameOverState::Update(float dt)
{

}

void GameOverState::Draw(float dt)
{
    _data->window.clear(sf::Color::Red);
    _data->window.draw(_retryButton);
    _data->window.draw(_homeButton);
    _data->window.display();
}
