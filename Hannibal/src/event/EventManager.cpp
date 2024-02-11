#include "EventManager.h"

EventManager::EventManager() :
   m_event()
{
}

EventManager::~EventManager()
{
   for (auto eventObject : m_eventObjectList)
   {
      if (eventObject)
      {
         delete eventObject;
      }
   }
}

const sf::Event& EventManager::GetEvent() const
{
   return m_event;
}

bool EventManager::PollEvent(Window& window)
{
   return window.pollEvent(m_event);
}

void EventManager::RunCurrentEvent()
{
   for (auto pEventObject : m_eventObjectList)
   {
      pEventObject->CheckEvent(m_event);
   }
}

void EventManager::RegisterEventObject(EventObject* pEventObject)
{

}
