#include <Display.h>
#include <Battlefield.h>

#include <event/EventManager.h>

Display::Display() :
   m_window(Window::Get()),
   m_pEventManager(std::make_shared<EventManager>(EventManager())),
   m_colorBackround({200, 200, 200})
{
}

void Display::Show() const
{
   m_window.create(sf::VideoMode(1600, 800), "Hannibal", sf::Style::Default);
   Battlefield battlefield(m_pEventManager, 15, 10, sf::Color::Black);

   while (m_window.isOpen())
   {
      while (m_pEventManager->PollEvent())
      {
         m_pEventManager->RunAllEvents();
      }
      m_window.clear(m_colorBackround);
      battlefield.Show();
      m_window.display();
   }

   m_pEventManager->ClearEventObjectLists();
}
