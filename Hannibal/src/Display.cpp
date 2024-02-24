#include <Display.h>
#include <Grid.h>
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
   Grid grid(m_pEventManager, 15, 10, sf::Color::Black, m_colorBackround);
   grid.CreateGrid();
   while (m_window.isOpen())
   {
      m_window.clear(m_colorBackround);
      grid.Show();
      while (m_pEventManager->PollEvent(m_window))
      {
         EventClosed();
         EventResized();
         m_pEventManager->RunAllEvents();
      }
      m_window.display();
   }
}

void Display::EventClosed()
{
   if (m_pEventManager->GetEvent().type == sf::Event::Closed)
   {
      m_window.close();
   }
}

void Display::EventResized()
{
   if (m_pEventManager->GetEvent().type == sf::Event::Resized)
   {
      sf::FloatRect view(0, 0, static_cast<float>(m_pEventManager->GetEvent().size.width), static_cast<float>(m_pEventManager->GetEvent().size.height));
      m_window.setView(sf::View(view));
   }
}

//void Display::DrawGrid()
//{
//   Grid grid(m_pEventManager, 15, 10, sf::Color::Black, m_colorBackround);
//   grid.Show();
//}
