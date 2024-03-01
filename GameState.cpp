//
// Created by minau on 2/29/2024.
//

//GameState can be considered as Bot vs player gameState
#include "GameState.h"

GameState::GameState(GameDataRef data) : _data(data)
{

}

void GameState::Init()
{
    gameState = STATE_PLAYING;
    turn = PLAYER_PIECE;

    Textures::setTexture(_pauseButton,PAUSE_BUTTON);
    Textures::setTexture(_background,BACKGROUND);

    _pauseButton.setPosition(_data->window.getSize().x - _pauseButton.getLocalBounds().width,_pauseButton.getPosition().y);
}

void GameState::InputHandler()
{
    sf::Event event;
    while(_data->window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            _data->window.close();
        }
        if(MouseEvents::isClicked(_pauseButton, _data->window))
        {
            std::cout << "Pause The Game";
        }
    }
}

void GameState::Update(float dt)
{

}

void GameState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_background);
    _data->window.draw(_pauseButton);

    _data->window.display();

}