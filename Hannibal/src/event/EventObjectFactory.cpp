#include <cells/Cell.h>
#include <cells/CellField.h>
#include <cells/CellUnit.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

CellFieldPtr EventObjectFactory::CreateCellField(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                                 sf::Color colorLine, sf::Color fillColor, float thickness)
{
   auto pCell = std::make_shared<CellField>(CellField(pEventManager, topLeft, botRight, colorLine, fillColor, thickness));
   pEventManager->RegisterEventObject(pCell);
   return pCell;
}

CellUnitPtr EventObjectFactory::CreateCellUnit(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                                               sf::Color colorLine, sf::Color fillColor, float thickness)
{
   auto pCell = std::make_shared<CellUnit>(CellUnit(pEventManager, topLeft, botRight, colorLine, fillColor, thickness));
   pEventManager->RegisterEventObject(pCell);
   return pCell;
}
