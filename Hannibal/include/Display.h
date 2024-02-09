#pragma once

#include <Constants.h>
#include <Window.h>

class Display
{
public:
   Display();
   ~Display() = default;

   void Show();

   void EventClosed();
   void EventResized();

   void DrawGrid();

private:
   Window& m_window;
   sf::Event m_event;
   const sf::Color m_colorBackround;
};

