#include <event/EventManager.h>
#include <event/EventObject.h>

EventObject::EventObject(EventManagerPtr pEventManager) :
   m_pEventManager(pEventManager)
{
}
