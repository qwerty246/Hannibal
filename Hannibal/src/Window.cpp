#include <Window.h>
#include <SFML/Window/Mouse.hpp>

Window& Window::Get()
{
   static Window window;
   return window;
}

sf::Vector2f Window::GetMouseWorldPos()
{
   sf::Vector2i pixelPos = sf::Mouse::getPosition(Get());
   return Get().mapPixelToCoords(pixelPos);
}

sf::Vector2f Window::GetCenter() const
{
   float x = static_cast<float>(Get().getSize().x / 2);
   float y = static_cast<float>(Get().getSize().y / 2);
   return { x, y };
}
