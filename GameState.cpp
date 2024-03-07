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
            if (STATE_PLAYING == gameState)
            {
                this->CheckAndPlacePiece();
            }
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
            this->CheckPlayerHasWon(turn);
            turn = AI_PIECE;

        }
        else  if(AI_PIECE == turn)
        {
            _gridPieces[column-1][row-1].setTexture(Textures::getTexture(CIRCLE));
            this->CheckPlayerHasWon(turn);
            turn = PLAYER_PIECE;
        }
        _gridPieces[column-1][row-1].setColor(sf::Color(255,255,255,255));
    }
}

void GameState::CheckPlayerHasWon(int player)
{
    Check3PiecesForMatch(0, 0, 1, 0, 2, 0, player);
    Check3PiecesForMatch(0, 1, 1, 1, 2, 1, player);
    Check3PiecesForMatch(0, 2, 1, 2, 2, 2, player);
    Check3PiecesForMatch(0, 0, 0, 1, 0, 2, player);
    Check3PiecesForMatch(1, 0, 1, 1, 1, 2, player);
    Check3PiecesForMatch(2, 0, 2, 1, 2, 2, player);
    Check3PiecesForMatch(0, 0, 1, 1, 2, 2, player);
    Check3PiecesForMatch(0, 2, 1, 1, 2, 0, player);

    int emptyNum = 9;

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (EMPTY_PIECE != gridArray[x][y])
            {
                emptyNum--;
            }
        }
    }

    // check if the game is a draw
    if (0 == emptyNum && (STATE_WON != gameState) && (STATE_LOSE != gameState))
    {
        gameState = STATE_DRAW;
    }

    // check if the game is over
    if (STATE_DRAW == gameState || STATE_LOSE == gameState || STATE_WON == gameState)
    {
        // show game over
    }

    std::cout << gameState << std::endl;
}

void GameState::Check3PiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
{
    if (pieceToCheck == gridArray[x1][y1] && pieceToCheck == gridArray[x2][y2] && pieceToCheck == gridArray[x3][y3])
    {
        std::string winningPieceStr;

        if (O_PIECE == pieceToCheck)
        {
            _gridPieces[x1][y1].setTexture(Textures::getTexture(CIRCLE_WIN));
            _gridPieces[x2][y2].setTexture(Textures::getTexture(CIRCLE_WIN));
            _gridPieces[x3][y3].setTexture(Textures::getTexture(CIRCLE_WIN));
        }
        else
        {
            _gridPieces[x1][y1].setTexture(Textures::getTexture(CROSS_WIN));
            _gridPieces[x2][y2].setTexture(Textures::getTexture(CROSS_WIN));
            _gridPieces[x3][y3].setTexture(Textures::getTexture(CROSS_WIN));
        }

        if (PLAYER_PIECE == pieceToCheck)
        {
            gameState = STATE_WON;
        }
        else
        {
            gameState = STATE_LOSE;
        }
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