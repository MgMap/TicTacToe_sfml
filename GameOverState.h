//
// Created by minau on 3/2/2024.
//

#ifndef SFML_PROJECT_GAMEOVERSTATE_H
#define SFML_PROJECT_GAMEOVERSTATE_H


#include "Textures.h"
#include "DEFINITIONS.h"
#include "MouseEvent.h"
#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

class GameOverState :public State
{
private:
    GameDataRef _data;
    sf::Sprite _retryButton;
    sf::Sprite _homeButton;

    int gameState;

public:
    GameOverState(GameDataRef data);
    void Init();
    void InputHandler();
    void Update (float dt);
    void Draw(float dt);

};

#endif //SFML_PROJECT_GAMEOVERSTATE_H
