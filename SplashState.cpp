//
// Created by minau on 2/29/2024.
//
#include <iostream>
#include "SplashState.h"
#include "Textures.h"
#include "DEFINITIONS.h"
#include "MainMenuState.h"

SplashState::SplashState(GameDataRef data) :_data(data)
{

}

void SplashState::Init()
{
    Textures::setTexture(_splash,SPLASH);
    _splash.setScale(1.5,1.12);
}

void SplashState::InputHandler()
{
    sf::Event event;
    while(_data->window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            _data->window.close();
        }
    }
}

void SplashState::Update(float dt)
{
    if(this->_clock.getElapsedTime().asSeconds() > SPLASH_TIME)
    {
        this->_data->machine.AddState(new MainMenuState(_data),true);
    }
}

void SplashState::Draw(float dt)
{
    this->_data->window.clear(sf::Color::Red);
    this->_data->window.draw(_splash);
    _data->window.display();
}
