//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_MAINMENUSTATE_H
#define SFML_PROJECT_MAINMENUSTATE_H
#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"
#include "Textures.h"
#include "DEFINITIONS.h"
#include "MouseEvent.h"
#include <iostream>
#include "GameState.h"

class MainMenuState :public State
{
private:
    GameDataRef _data;
    sf::Sprite _menu_background;
    sf::Sprite _playButton;
    sf::Sprite _playButtonOuter;
    sf::Sprite _title;
public:
    MainMenuState(GameDataRef data);
    void Init();
    void InputHandler();
    void Update (float dt);
    void Draw(float dt);

};


#endif //SFML_PROJECT_MAINMENUSTATE_H
