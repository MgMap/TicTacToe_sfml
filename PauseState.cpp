//
// Created by minau on 3/1/2024.
//

#include "PauseState.h"

PauseState::PauseState(GameDataRef data) : _data(data)
{

}

void PauseState::Init()
{
    gameState = STATE_PAUSED;
    Textures::setTexture(_background,PAUSE_BACKGROUND);
    Textures::setTexture(_homeButton,HOME);
    Textures::setTexture(_resumeButton,RESUME_BUTTON);

    _homeButton.setPosition(10,_homeButton.getPosition().y);
    _resumeButton.setPosition(_data->window.getSize().x-_resumeButton.getLocalBounds().width,_resumeButton.getPosition().y);

}

void PauseState::InputHandler()
{
    sf::Event event;
    if(sf::Event::Closed == event.type)
    {
        _data->window.close();
    }
    if(MouseEvents::isClicked(_resumeButton,_data->window))
    {
        //going back to the playing state by poping the pause state
        _data->machine.RemoveState();
    }
    if(MouseEvents::isClicked(_homeButton,_data->window))
    {
        _data->machine.RemoveState();
        _data->machine.AddState(new MainMenuState(_data),true);
    }
}

void PauseState::Update(float dt)
{

}

void PauseState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_resumeButton);
    _data->window.draw(_homeButton);
    _data->window.display();

}
