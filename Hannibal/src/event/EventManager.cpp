#include <Window.h>

#include <event/EventManager.h>
#include <event/EventObject.h>

EventManager::EventManager() :
   m_event(),
   m_eventTypesToDeletion()
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
         eventObject->RunEvent(m_event);
      }
   }

   ClearEventObjectTypes();
}

void EventManager::RegisterEventObject(EventObjectPtr pEventObject)
{
   for (auto eventType : pEventObject->GetEventTypes())
   {
      auto eventList = m_eventObjectLists.find(eventType);
      if (eventList == m_eventObjectLists.end())
      {
         std::list<EventObjectPtr> eventObjects{ pEventObject };
         auto pair = std::make_pair(eventType , eventObjects);
         m_eventObjectLists.emplace(pair);
      }
      else
      {
         eventList->second.push_back(pEventObject);
      }
   }
}

void EventManager::ClearEventObjectList(sf::Event::EventType eventType)
{
   auto it = m_eventObjectLists.find(eventType);
   if (it != m_eventObjectLists.end())
   {
      it->second.clear();
      m_eventObjectLists.erase(it);
   }
}

void EventManager::DeletionRequest(const std::vector<sf::Event::EventType>& eventTypes)
{
   for (auto typeToDeletion : eventTypes)
   {
      bool needToAdd = true;
      for (auto type : m_eventTypesToDeletion)
      {
         if (typeToDeletion == type)
         {
            needToAdd = false;
            break;
         }
      }
      if (needToAdd)
      {
         m_eventTypesToDeletion.push_back(typeToDeletion);
      }
   }
}

void EventManager::ClearEventObjectTypes()
{
   for (auto type : m_eventTypesToDeletion)
   {
      auto it = m_eventObjectLists.find(type);
      if (it != m_eventObjectLists.end())
      {
         for (auto eventObject : it->second)
         {
            if (eventObject->NeedToDeleteEventObjects())
            {
               it->second.remove(eventObject);
               m_eventObjectLists.erase(it);
            }
         }
      }
   }
}
