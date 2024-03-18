#pragma once

#include <memory>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class EventObjectFactory
{
public:
   static CellFieldPtr CreateCellField(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                       sf::Color colorLine, sf::Color fillColor, float thickness);
   static CellUnitPtr CreateCellUnit(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                     sf::Color colorLine, sf::Color fillColor, float thickness);
};

