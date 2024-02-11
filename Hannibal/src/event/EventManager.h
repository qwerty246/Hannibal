#pragma once

#include <list>

#include <Constants.h>
#include <event/EventObject.h>
#include <Window.h>

class EventManager
{
public:
   EventManager();
   ~EventManager();

   const sf::Event& GetEvent() const;
   bool PollEvent(Window& window);
   void RunCurrentEvent();
   void RegisterEventObject(EventObject* pEventObject);

private:
   sf::Event m_event;
   std::list<EventObject*> m_eventObjectList;
};

