#include <event/EventManager.h>
#include <event/EventObject.h>

EventObject::EventObject(EventManagerPtr pEventManager) :
   m_pEventManager(pEventManager),
   m_needToDeleteEventObjects(false)
{
}

const std::vector<sf::Event::EventType>& EventObject::GetEventTypes() const
{
   return m_eventTypes;
}

bool EventObject::NeedToDeleteEventObjects() const
{
   return m_needToDeleteEventObjects;
}
