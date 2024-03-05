//
// Created by minau on 2/29/2024.
//

#ifndef SFML_PROJECT_MOUSEEVENT_CPP
#define SFML_PROJECT_MOUSEEVENT_CPP
#include "MouseEvent.h"

template<class T>
bool MouseEvents::isHover(const T &Obj, const sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return Obj.getGlobalBounds().contains(mpos);
}



template<class T>
bool MouseEvents::isClicked(const T &Obj, const sf::RenderWindow &window) {
    return isHover(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isNotClicked(const T &Obj, const sf::RenderWindow &window) {
    return !isHover(Obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif
