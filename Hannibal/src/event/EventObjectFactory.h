#pragma once

#include <memory>

#include <helpers/constants.h>
#include <SFML/Graphics.hpp>

class EventObjectFactory
{
public:
   static EventObjectPtr CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);
   static EventObjectPtr CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea);
   static EventObjectPtr CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness);
};

