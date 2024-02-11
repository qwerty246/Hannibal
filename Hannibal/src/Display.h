#pragma once

#include <Constants.h>
#include <event/EventManager.h>
#include <Window.h>

class Display
{
public:
   Display();
   ~Display() = default;

   void Show();

   void EventClosed();
   void EventResized();

   //void DrawGrid();

private:
   Window& m_window;
   EventManagerPtr m_pEventManager;
   const sf::Color m_colorBackround;
};

