#pragma once

#include <memory>

class sf::Event;
class EventManager;

class EventObject
{
private:
   EventObject() = delete;

public:
   EventObject(std::shared_ptr<EventManager> pEventManager);
   ~EventObject() = default;

   virtual bool CheckEvent(const sf::Event& event) const = 0;
};

