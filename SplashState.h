//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_SPLASHSTATE_H
#define SFML_PROJECT_SPLASHSTATE_H

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"


class SplashState : public State
{
private:
    GameDataRef _data;
    sf::Clock _clock;
    sf::Sprite _splash;
public:
    SplashState(GameDataRef data);
    void Init();
    void InputHandler();
    void Update(float dt);
    void Draw(float dt);
};


#endif //SFML_PROJECT_SPLASHSTATE_H
