//
// Created by minau on 2/29/2024.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(GameDataRef data) :_data(data)
{
    Init();
}

void MainMenuState::Init()
{
    //setting textures in the main menu screen
    Textures::setTexture(_menu_background, BACKGROUND);
    Textures::setTexture(_playButton,PLAY_BUTTON);
    Textures::setTexture(_playButtonOuter,PLAY_BUTTON_OUTER);
    Textures::setTexture(_title,GAME_TITLE);

    //setting positions of the elements
    _playButton.setPosition((SCREEN_WIDTH/2)-(_playButton.getGlobalBounds().width/2),
                            (SCREEN_HEIGHT/2)-(_playButton.getGlobalBounds().height/2));
    _playButtonOuter.setPosition((SCREEN_WIDTH/2)-(_playButtonOuter.getGlobalBounds().width/2),
                                 (SCREEN_HEIGHT/2)-(_playButtonOuter.getGlobalBounds().height/2));
    _playButton.setPosition((SCREEN_WIDTH/2)-(_playButton.getGlobalBounds().width/2),
                            (SCREEN_HEIGHT/2)-(_playButton.getGlobalBounds().height/2));
    _title.setPosition((SCREEN_WIDTH/2)-(_title.getGlobalBounds().width/2),
                       (SCREEN_HEIGHT/7));
}

void MainMenuState::InputHandler()
{
    sf::Event event;
    while(_data->window.pollEvent(event))
    {
        if(sf::Event::Closed == event.type)
        {
            _data->window.close();
        }
        if(MouseEvents::isClicked(_playButton, _data->window))
        {
            this->_data->machine.AddState((new GameState(_data)),true);

        }

        /*
         * will do another state for the PvP mode
        if(MouseEvents::isClicked(_playButton, _data->window))
        {
            this->_data->machine.AddState((new GameState(_data)),true);
        }
        */
    }
}

void MainMenuState::Update(float dt)
{

}

void MainMenuState::Draw(float dt)
{
    _data->window.clear();
    _data->window.draw(_menu_background);
    _data->window.draw(_playButton);
    _data->window.draw(_playButtonOuter);
    _data->window.draw(_title);

    _data->window.display();


}
