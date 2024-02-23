#include <cell/Cell.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

EventObjectPtr EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight)
{
   auto pCell = std::make_shared<Cell>(Cell(pEventManager, topLeft, botRight));
   pEventManager->RegisterEventObject(pCell);
   return pCell;
}

EventObjectPtr EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                              sf::Color colorLine, sf::Color colorArea)
{
   auto pCell = std::make_shared<Cell>(Cell(pEventManager, topLeft, botRight, colorLine, colorArea));
   pEventManager->RegisterEventObject(pCell);
   return pCell;
}

EventObjectPtr EventObjectFactory::CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                              sf::Color colorLine, sf::Color colorArea, float thickness)
{
   auto pCell = std::make_shared<Cell>(Cell(pEventManager, topLeft, botRight, colorLine, colorArea, thickness));
   pEventManager->RegisterEventObject(pCell);
   return pCell;
}
