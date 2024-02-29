//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_MOUSEEVENT_H
#define SFML_PROJECT_MOUSEEVENT_H

#include <SFML/Graphics.hpp>
class MouseEvents
{
public:
    template<class T>
    static bool isHover(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isClicked(const T& Obj, const sf::RenderWindow& window);
    template<class T>
    static bool isNotClicked(const T& Obj, const sf::RenderWindow &window );
};
#include "MouseEvent.cpp"

#endif //SFML_PROJECT_MOUSEEVENT_H
