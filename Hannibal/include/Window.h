#pragma once

#include <SFML/Graphics.hpp>

class Window;
typedef std::shared_ptr<Window> WindowPtr;

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

