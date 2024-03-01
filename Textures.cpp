//
// Created by minau on 2/29/2024.
//

#include "Textures.h"
std::map<textureEnum, sf::Texture> Textures::map;

void Textures::load(textureEnum texture) {
    map[texture].loadFromFile(getPath(texture));
}

std::string Textures::getPath(textureEnum texture)
{
    switch(texture)
    {
        case SPLASH: return "Textures/SplashScreen Tictac.png";
        case BACKGROUND: return "Textures/Main Menu Background.png";
        case CIRCLE: return "Textures/O.png";
        case CROSS: return "Textures/X.png";
        case CIRCLE_WIN: return "Textures/O Win.png";
        case CROSS_WIN: return "Textures/X Win.png";
        case GAME_TITLE: return "Textures/Game Title.png";
        case GRID: return "Textures/Grid.png";
        case HOME: return "Textures/Home Button.png";
        case PAUSE_BACKGROUND: return "Textures/Pause Background.png";
        case PAUSE_BUTTON: return "Textures/Pause Button.png";
        case PAUSE_WINDOW: return "Textures/Pause Window.png";
        case PLAY_BUTTON: return "Textures/Play Button.png";
        case PLAY_BUTTON_OUTER: return "Textures/Play Button Outer.png";
        case RESUME_BUTTON: return "Textures/Resume Button.png";
        case RETRY_BUTTON: return "Textures/Retry Button.png";
        case SOUND_OFF: return "Textures/Sound Off.png";
        case SOUND_ON: return "Textures/Sound On.png";
    }
}

sf::Texture &Textures::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}

void Textures::setTexture(sf::Sprite &sprite,textureEnum textureEnum)
{
    sprite.setTexture(getTexture(textureEnum));
}
