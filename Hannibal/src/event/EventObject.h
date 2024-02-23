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

   virtual bool CheckEvent(const sf::Event& event) const = 0;
   virtual void DeletionRequest() const = 0;

public:
   const std::vector<sf::Event::EventType>& GetEventTypes() const;

protected:
   std::weak_ptr<EventManager> m_pEventManager;
   std::vector<sf::Event::EventType> m_eventTypes;
};

