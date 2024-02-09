#include <SFML/System/Vector2.hpp>

#include <Display.h>
#include <Grid.h>

Display::Display() :
   m_window(Window::Get()),
   m_event(),
   m_colorBackround({200, 200, 200})
{
}

void Display::Show()
{
   m_window.create(sf::VideoMode(1600, 800), "Hannibal", sf::Style::Default);
   while (m_window.isOpen())
   {
      m_window.clear(m_colorBackround);
      DrawGrid();
      while (m_window.pollEvent(m_event))
      {
         EventClosed();
         EventResized();
      }
      m_window.display();
   }
}

void Display::EventClosed()
{
   if (m_event.type == sf::Event::Closed)
   {
      m_window.close();
   }
}

void Display::EventResized()
{
   if (m_event.type == sf::Event::Resized)
   {
      sf::FloatRect view(0, 0, static_cast<float>(m_event.size.width), static_cast<float>(m_event.size.height));
      m_window.setView(sf::View(view));
   }
}

void Display::DrawGrid()
{
   Grid grid(15, 10, sf::Color::Black, m_colorBackround);
   grid.Show();
}
