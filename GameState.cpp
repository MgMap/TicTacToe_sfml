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

    Textures::setTexture(_grid,GRID);
    Textures::setTexture(_X_piece, CROSS);
    Textures::setTexture(_O_Piece, CIRCLE);
    Textures::setTexture(_pauseButton,PAUSE_BUTTON);
    Textures::setTexture(_background,BACKGROUND);

    _pauseButton.setPosition(_data->window.getSize().x - _pauseButton.getLocalBounds().width,_pauseButton.getPosition().y);
    _grid.setPosition(SCREEN_WIDTH/2 - (_grid.getGlobalBounds().width/2), SCREEN_HEIGHT/2 - (_grid.getGlobalBounds().height/2));

    InitGridPieces();

    for(int x= 0; x < 3; x++)
    {
        for (int y = 0; y< 3; y++)
        {
            gridArray[x][y] = EMPTY_PIECE;
        }
    }
}

void GameState::InitGridPieces()
{
    sf::Vector2u tempSprite = Textures::getTexture(CROSS).getSize();
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            Textures::setTexture(_gridPieces[x][y], CROSS);
            _gridPieces[x][y].setPosition(_grid.getPosition().x + (tempSprite.x * x) - 7,
                                          _grid.getPosition().y + (tempSprite.y * y) - 7);
            _gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));

        }
    }
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
            _data->machine.AddState(new PauseState(_data),false);
        }
        else if(MouseEvents::isClicked(_grid, _data->window))
        {
            CheckAndPlacePiece();
        }
    }
}

void GameState::CheckAndPlacePiece()
{
    sf::Vector2i touchPoint = sf::Mouse::getPosition(_data->window);
    sf::FloatRect gridSize = _grid.getGlobalBounds();
    sf::Vector2f gapOutSideOfGrid = sf::Vector2f (((SCREEN_WIDTH-gridSize.width)/2),(SCREEN_HEIGHT-gridSize.height)/2);
    sf::Vector2f gridLocalTouchPos = sf::Vector2f (touchPoint.x - gapOutSideOfGrid.x,touchPoint.y-gapOutSideOfGrid.y);

    sf::Vector2f  gridSectionSize = sf::Vector2f (gridSize.width/3,gridSize.height/3);
    int column, row;
    if(gridLocalTouchPos.x < gridSectionSize.x)
    {
        column = 1;
    }
    else if (gridLocalTouchPos.x < gridSectionSize.x*2)
    {
        column = 2;
    }
    else if (gridLocalTouchPos.x < gridSize.width)
    {
        column = 3;
    }

    if(gridLocalTouchPos.y < gridSectionSize.y)
    {
        row = 1;
    }
    else if (gridLocalTouchPos.y < gridSectionSize.y*2)
    {
        row = 2;
    }
    else if (gridLocalTouchPos.y < gridSize.height)
    {
        row = 3;
    }
    if (gridArray[column-1][row-1] == EMPTY_PIECE)
    {
        gridArray[column-1][row-1] = turn;
        if(PLAYER_PIECE == turn)
        {
            _gridPieces[column-1][row-1].setTexture(Textures::getTexture(CROSS));
            turn = AI_PIECE;

        }
        else  if(AI_PIECE == turn)
        {
            _gridPieces[column-1][row-1].setTexture(Textures::getTexture(CIRCLE));
            turn = PLAYER_PIECE;
        }
        _gridPieces[column-1][row-1].setColor(sf::Color(255,255,255,255));
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
    _data->window.draw(_grid);
    for(int x= 0; x < 3; x++)
    {
        for (int y = 0; y< 3; y++)
        {
            _data->window.draw(_gridPieces[x][y]);

        }
    }
    _data->window.display();

}