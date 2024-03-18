#pragma once

#include <cells/Cell.h>

class CellUnit :
    public Cell
{
public:
   CellUnit(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
            sf::Color fillColor, sf::Color outlineColor, float outlineThickness);
};
