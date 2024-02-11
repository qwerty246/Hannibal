#pragma once

#include <memory>

#include <SFML/Window/Event.hpp>

class EventManager;
typedef std::shared_ptr<EventManager> EventManagerPtr;

class EventObject
{
private:
   EventObject() = delete;

public:
   EventObject(EventManagerPtr pEventManager);
   ~EventObject() = default;

   virtual bool CheckEvent(const sf::Event& event) const = 0;
};

