#pragma once

#include <memory>

#include <Constants.h>

#include <SFML/Graphics/Color.hpp>

class EventManager;
class Window;
class sf::Color;

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
   std::shared_ptr<EventManager> m_pEventManager;
   const sf::Color m_colorBackround;
};

