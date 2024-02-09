#pragma once

#include <SFML/Graphics.hpp>

class Window
{
public:
	Window();

	void run();
	void run2();
private:
	sf::RenderWindow m_window;
	sf::Event m_event;
};

