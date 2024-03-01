//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_GAMESTATE_H
#define SFML_PROJECT_GAMESTATE_H

#include "State.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

class GameState :public State
{
private:
    void initGird();

public:
    GameState(GameDataRef data);
    void init();
    void Update(float dt);
    void Draw(float dt);
};


#endif //SFML_PROJECT_GAMESTATE_H
