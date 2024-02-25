#include <cell/Cell.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

EventObjectFactory::EventObjectFactory(EventManagerPtr pEventManager) :
   m_pEventManager(pEventManager)
{
}

EventObjectPtr EventObjectFactory::CreateCell(sf::Vector2f topLeft, sf::Vector2f botRight,
                                              sf::Color colorLine, sf::Color colorArea, float thickness) const
{
   auto pCell = std::make_shared<Cell>(Cell(m_pEventManager, topLeft, botRight, colorLine, colorArea, thickness));
   m_pEventManager->RegisterEventObject(pCell);
   return pCell;
}
