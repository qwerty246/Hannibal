#include "EventObjectFactory.h"

#include <cell/Cell.h>

EventObject* EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight)
{
   return new Cell(pEventManager, topLeft, botRight);
}

EventObject* EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                            sf::Color colorLine, sf::Color colorArea)
{
   return new Cell(pEventManager, topLeft, botRight, colorLine, colorArea);
}

EventObject* EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                            sf::Color colorLine, sf::Color colorArea, float thickness)
{
   return new Cell(pEventManager, topLeft, botRight, colorLine, colorArea, thickness);
}
