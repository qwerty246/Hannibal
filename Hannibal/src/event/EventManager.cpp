#include <event/EventManager.h>
#include <event/EventObject.h>

EventManager::EventManager() :
   m_window(Window::Get()),
   m_event(),
   m_eventTypesToDeletion()
{
}

bool EventManager::PollEvent()
{
   return m_window.pollEvent(m_event);
}

void EventManager::RunAllEvents()
{
   EventClosed();
   EventResized();

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

void EventManager::ClearEventObjectLists()
{
   m_eventObjectLists.clear();
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

void EventManager::EventClosed() const
{
   if (m_event.type == sf::Event::Closed)
   {
      m_window.close();
   }
}

void EventManager::EventResized() const
{
   if (m_event.type == sf::Event::Resized)
   {
      //sf::FloatRect view(0, 0, static_cast<float>(m_event.size.width), static_cast<float>(m_event.size.height));
      //m_window.setView(sf::View(view));

      //sf::View view = m_window.getView();
      //auto oldCenter = view.getCenter();
      //view.setSize({ static_cast<float>(m_event.size.width), static_cast<float>(m_event.size.height) });
      //view.setCenter(m_window.GetCenter());
      //view.move(oldCenter - m_window.GetCenter());
      //m_window.setView(view);

      sf::View view = m_window.getView();
      auto oldCenter = view.getCenter();
      view.setSize({ static_cast<float>(m_event.size.width), static_cast<float>(m_event.size.height) });
      view.setCenter(m_window.GetCenter());
      view.move(oldCenter - m_window.GetCenter());
      m_window.setView(view);
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
