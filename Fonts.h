//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H

#include "FontsEnum.h"
#include <SFML/Graphics.hpp>
#include <map>

class Fonts
{
private:
    static std::map<fontEnum, sf::Font> map;
    static void load(fontEnum texture);
    static std::string getPath(fontEnum font);
public:
    static sf::Font& getFont(fontEnum font);
};

#endif //SFML_PROJECT_FONTS_H
