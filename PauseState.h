//
// Created by minau on 3/1/2024.
//

#ifndef SFML_PROJECT_PAUSESTATE_H
#define SFML_PROJECT_PAUSESTATE_H

#include "Textures.h"
#include "DEFINITIONS.h"
#include "MouseEvent.h"
#include <iostream>
#include "GameState.h"
#include "MainMenuState.h"

class PauseState :public State
{
private:
    GameDataRef _data;
    sf::Sprite _background;
    sf::Sprite _resumeButton;
    sf::Sprite _homeButton;

    int gameState;

public:
    PauseState(GameDataRef data);
    void Init();
    void InputHandler();
    void Update (float dt);
    void Draw(float dt);

};


#endif //SFML_PROJECT_PAUSESTATE_H
