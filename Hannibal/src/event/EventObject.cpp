#include "EventObject.h"

#include <event/EventManager.h>

EventObject::EventObject(EventManagerPtr pEventManager)
{
   pEventManager->RegisterEventObject(this);
}
