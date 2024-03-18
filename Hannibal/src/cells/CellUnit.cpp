#include <cells/CellUnit.h>

CellUnit::CellUnit(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                   sf::Color fillColor, sf::Color outlineColor, float outlineThickness) :
   Cell(pEventManager, topLeft, botRight, fillColor, outlineColor, outlineThickness)
{
}
