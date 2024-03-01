//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_TEXTURES_H
#define SFML_PROJECT_TEXTURES_H

#include "TextureEnum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Textures
{
private:
    static std::map<textureEnum, sf::Texture> map;
    static void load(textureEnum texture);
    static std::string getPath(textureEnum texture);
public:
    static sf::Texture& getTexture(textureEnum texture);
    static void setTexture(sf::Sprite &sprite, textureEnum textenum);
};


#endif //SFML_PROJECT_TEXTURES_H
