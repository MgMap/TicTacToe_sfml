//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_GAMESTATE_H
#define SFML_PROJECT_GAMESTATE_H

#include "State.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.h"
#include "Textures.h"
#include <iostream>

class GameState :public State
{
private:
    GameDataRef  _data;
    sf::Sprite _background;
    sf::Sprite _pauseButton;
    int turn;
    int gameState;

public:
    GameState(GameDataRef data);
    void Init();
    void InputHandler();
    void Update(float dt);
    void Draw(float dt);
};


#endif //SFML_PROJECT_GAMESTATE_H
