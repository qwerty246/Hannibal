#include <Window.h>

#include <event/EventManager.h>
#include <event/EventObject.h>

EventManager::EventManager() :
   m_event()
{
}

const sf::Event& EventManager::GetEvent() const
{
   return m_event;
}

bool EventManager::PollEvent(Window& window)
{
   return window.pollEvent(m_event);
}

void EventManager::RunAllEvents()
{
   for (auto eventObjectList : m_eventObjectLists)
   {
      for (auto eventObject : eventObjectList.second)
      {
         eventObject->CheckEvent(m_event);
      }
   }
}

void EventManager::RegisterEventObject(EventObjectPtr pEventObject)
{
   for (auto it : pEventObject->GetEventTypes())
   {
      auto eventList = m_eventObjectLists.find(it);
      if (eventList != m_eventObjectLists.end())
      {
         eventList->second.push_back(pEventObject);
      }
   }
}
