#pragma once

#include <memory>
#include <vector>

#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class EventObject
{
private:
   EventObject() = delete;

public:
   EventObject(EventManagerPtr pEventManager);
   ~EventObject() = default;

   virtual void RunEvent(const sf::Event& event) = 0;

public:
   const std::vector<sf::Event::EventType>& GetEventTypes() const;
   bool NeedToDeleteEventObjects() const;

protected:
   virtual void DeletionRequest() = 0;

protected:
   std::shared_ptr<EventManager> m_pEventManager;
   std::vector<sf::Event::EventType> m_eventTypes;
   bool m_needToDeleteEventObjects;
};

