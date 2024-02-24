#include <Window.h>

#include <event/EventManager.h>
#include <event/EventObject.h>

EventManager::EventManager() :
   m_event(),
   eventTypesToDeletion()
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

   ClearEventObjectTypes();
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
      bool needToaAdd = true;
      for (auto type : eventTypesToDeletion)
      {
         if (typeToDeletion == type)
         {
            needToaAdd = false;
            break;
         }
      }
      if (needToaAdd)
      {
         eventTypesToDeletion.push_back(typeToDeletion);
      }
   }
}

void EventManager::ClearEventObjectTypes()
{
   for (auto type : eventTypesToDeletion)
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
