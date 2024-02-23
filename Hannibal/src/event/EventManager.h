#pragma once

#include <list>
#include <map>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Window;

class EventManager
{
public:
   EventManager();
   ~EventManager() = default;

   const sf::Event& GetEvent() const;
   bool PollEvent(Window& window);
   void RunAllEvents();
   void RegisterEventObject(EventObjectPtr pEventObject);

private:
   sf::Event m_event;
   std::map<sf::Event::EventType, std::list<EventObjectPtr>> m_eventObjectLists;
};

