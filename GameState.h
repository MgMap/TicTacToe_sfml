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

enum game
{
    winning_piece
};
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
    void CheckPlayerHasWon( int turn);
    void Check3PiecesForMatch(int x1, int y1,int x2, int y2,int x3, int y3, int pieceToCheck);

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
