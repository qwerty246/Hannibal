#include "Window.h"

Window::Window() :
	m_window(sf::VideoMode(600, 600), "Hannibal")
{
}

void Window::run()
{
	while (m_window.isOpen())
	{
		m_window.clear({ 100, 0, 0 });
		while (m_window.pollEvent(m_event))
		{
			run2();
		}
	}
}

void Window::run2()
{
	if (m_event.type == sf::Event::Closed)
	{
		m_window.close();
	}

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(150, 150))
	};

	m_window.draw(line, 2, sf::Lines);
	m_window.display();
}
