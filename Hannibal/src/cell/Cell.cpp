#include <cell/Cell.h>
#include <cell/CellDesign.h>
#include <event/EventManager.h>

Cell::Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight) :
   Cell(pEventManager, topLeft, botRight, sf::Color::Black, sf::Color::White, 1)
{
}

Cell::Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
           sf::Color colorLine, sf::Color colorArea) :
   Cell(pEventManager, topLeft, botRight, colorLine, colorArea, 1)
{
}

Cell::Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
           sf::Color colorLine, sf::Color colorArea, float thickness) :
   EventObject(pEventManager),
   m_pCellDesign(new CellDesign(topLeft, botRight, colorLine, colorArea, thickness)),
   m_pSubCellDesign(nullptr)
{
   m_eventTypes.push_back(sf::Event::EventType::MouseButtonPressed);
}

Cell::~Cell()
{
   DeletionRequest();
}

void Cell::Draw()
{
   m_pCellDesign->Draw();
   if (m_pSubCellDesign)
   {
      m_pSubCellDesign->Draw();
   }
}

void Cell::CreateSubCellDesign(CellDesignPtr pCellDesign)
{
   m_pSubCellDesign = pCellDesign;
}

void Cell::RunEvent(const sf::Event& event) const
{
   for (auto type : m_eventTypes)
   {
      if (type == event.type)
      {
         if (m_pCellDesign->IsInside(event.mouseButton))
         {
            m_pSubCellDesign->SetFillColor(sf::Color::Red);
         }
         return;
      }
   }
}

void Cell::DeletionRequest()
{
   m_pEventManager->DeletionRequest(m_eventTypes);
   m_needToDeleteEventObjects = true;
}
