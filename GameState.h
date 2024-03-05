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
#include "PauseState.h"
#include "GameOverState.h"

class GameState :public State
{
private:
    GameDataRef  _data;
    sf::Sprite _background;
    sf::Sprite _pauseButton;

    void InitGridPieces();
    sf::Sprite _grid;
    sf::Sprite _gridPieces[3][3];
    sf::Sprite _X_piece;
    sf::Sprite _O_Piece;
    int gridArray[3][3];

    void CheckAndPlacePiece();

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
