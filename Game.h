//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_GAME_H
#define SFML_PROJECT_GAME_H
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "Textures.h"
#include "Fonts.h"
#include "MouseEvent.h"



struct GameData
        {
    StateMachine machine;
    sf::RenderWindow window;
    };
    typedef std::shared_ptr<GameData> GameDataRef;

    class Game
            {
            private:
                GameDataRef _data = std::make_shared<GameData>();
                sf::Clock _clock;
                const float dt = 1.0f / 60.0f;
                void run();
            public:
                Game(int width, int height, std::string title);
    };


#endif //SFML_PROJECT_GAME_H
