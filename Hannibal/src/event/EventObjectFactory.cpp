#include <cell/Cell.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

EventObject* EventObjectFactory::CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight)
{
   return new Cell(pEventManager, topLeft, botRight);
}

EventObject* EventObjectFactory::CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                            sf::Color colorLine, sf::Color colorArea)
{
   return new Cell(pEventManager, topLeft, botRight, colorLine, colorArea);
}

EventObject* EventObjectFactory::CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                            sf::Color colorLine, sf::Color colorArea, float thickness)
{
   return new Cell(pEventManager, topLeft, botRight, colorLine, colorArea, thickness);
}
