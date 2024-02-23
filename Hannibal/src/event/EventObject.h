#pragma once

#include <memory>

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

private:
   std::weak_ptr<EventManager> m_pEventManager;
};

