#include <cell/Cell.h>
#include <event/EventManager.h>

Cell::Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
           sf::Color fillColor, sf::Color outlineColor, float outlineThickness) :
   EventObject(pEventManager),
   m_cellDesign(topLeft, botRight, fillColor, outlineColor, outlineThickness)
{
   m_eventTypes.push_back(sf::Event::EventType::MouseButtonPressed);
}

Cell::~Cell()
{
   DeletionRequest();
}

void Cell::Draw()
{
   m_cellDesign.Draw();
}

void Cell::RunEvent(const sf::Event& event)
{
   for (auto type : m_eventTypes)
   {
      if (type == event.type)
      {
         if (m_cellDesign.IsInside())
         {
            m_cellDesign.SetFillColor(sf::Color::Red);
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
