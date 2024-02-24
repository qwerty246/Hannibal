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
   void ClearEventObjectList(sf::Event::EventType eventType);
   void DeletionRequest(const std::vector<sf::Event::EventType>& eventTypes);

private:
   void ClearEventObjectTypes();

private:
   sf::Event m_event;
   std::map<sf::Event::EventType, std::list<EventObjectPtr>> m_eventObjectLists;
   std::vector<sf::Event::EventType> m_eventTypesToDeletion;
};

