#include <event/EventManager.h>
#include <event/EventObject.h>

EventObject::EventObject(std::shared_ptr<EventManager> pEventManager)
{
   pEventManager->RegisterEventObject(this);
}
