#pragma once

#include <cell/CellDesign.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

class Cell : public EventObject
{
   friend class EventObjectFactory;

private:
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea);
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness);

   ~Cell() = default;
public:
   void Draw();
   void CreateSubCellDesign(CellDesignPtr pCellDesign);

   bool CheckEvent(const sf::Event& event) const;
private:
   CellDesignPtr m_pCellDesign;
   CellDesignPtr m_pSubCellDesign;
};

