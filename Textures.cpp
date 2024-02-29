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

    }
}

sf::Texture &Textures::getTexture(textureEnum texture) {
    load(texture);
    return map[texture];
}