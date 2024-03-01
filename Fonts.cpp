//
// Created by minau on 2/29/2024.
//

#include "Fonts.h"
std::map<fontEnum, sf::Font> Fonts::map;

void Fonts::load(fontEnum texture) {
    map[texture].loadFromFile(getPath(texture));
}

std::string Fonts::getPath(fontEnum font)
{
    switch(font)
    {

    }
}

sf::Font &Fonts::getFont(fontEnum font) {
    load(font);
    return map[font];
}