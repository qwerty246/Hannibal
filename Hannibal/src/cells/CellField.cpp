#include <memory>

#include <cells/CellField.h>
#include <event/EventObjectFactory.h>

CellField::CellField(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
                     sf::Color fillColor, sf::Color outlineColor, float outlineThickness) :
   Cell(pEventManager, topLeft, botRight, fillColor, outlineColor, outlineThickness)
{
}

void CellField::CreateCellUnit()
{
   m_pCellUnit = std::dynamic_pointer_cast<CellUnit>(
                 EventObjectFactory::CreateCellUnit(m_pEventManager, m_topLeft, m_botRight,
                                                    m_fillColor, m_outlineColor, m_outlineThickness));
}
