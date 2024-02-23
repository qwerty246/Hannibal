#pragma once

#include <cell/CellDesign.h>
#include <event/EventObjectFactory.h>

class EventManager;

class Cell : public EventObject
{
   friend class EventObjectFactory;

private:
   Cell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);

   Cell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color colorLine, sf::Color colorArea);

   Cell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color colorLine, sf::Color colorArea, float thickness);

   ~Cell() = default;
public:
   void Draw();
   void CreateSubCellDesign(std::shared_ptr<CellDesign> pCellDesign);

   bool CheckEvent(const sf::Event& event) const;
private:
   std::shared_ptr<CellDesign> m_pCellDesign;
   std::shared_ptr<CellDesign> m_pSubCellDesign;
};

