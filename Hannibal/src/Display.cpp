#include <Display.h>
#include <GridLayer.h>
#include <Window.h>

#include <event/EventManager.h>

Display::Display() :
   m_window(Window::Get()),
   m_pEventManager(std::make_shared<EventManager>(EventManager())),
   m_colorBackround({200, 200, 200})
{
}

void Display::Show()
{
   m_window.create(sf::VideoMode(1600, 800), "Hannibal", sf::Style::Default);
   GridLayer gridLayer(m_pEventManager, 15, 10, sf::Color::Black, m_colorBackround);

   while (m_window.isOpen())
   {
      while (m_pEventManager->PollEvent(m_window))
      {
         m_pEventManager->RunAllEvents();
      }
      m_window.clear(m_colorBackround);
      gridLayer.Show();
      m_window.display();
   }

   m_pEventManager->ClearEventObjectLists();
}
