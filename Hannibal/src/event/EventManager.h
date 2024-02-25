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

   bool PollEvent();
   void RunAllEvents();
   void RegisterEventObject(EventObjectPtr pEventObject);
   void ClearEventObjectLists();
   void DeletionRequest(const std::vector<sf::Event::EventType>& eventTypes);

private:
   void EventClosed() const;
   void EventResized() const;
   void ClearEventObjectTypes();

private:
   Window& m_window;
   sf::Event m_event;
   std::map<sf::Event::EventType, std::list<EventObjectPtr>> m_eventObjectLists;
   std::vector<sf::Event::EventType> m_eventTypesToDeletion;
};

