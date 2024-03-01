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
        case SPLASH: return 0;
        case BACKGROUND: return 0;
        case CIRCLE: return 0;
        case CROSS: return 0;
    }
}

sf::Texture &Textures::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}