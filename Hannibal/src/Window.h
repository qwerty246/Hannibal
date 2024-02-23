#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class Window : public sf::RenderWindow
{
private:
   Window() = default;
   Window(Window const&) = delete;
   Window& operator= (Window const&) = delete;
   ~Window() = default;

public:
   static Window& Get();
};

