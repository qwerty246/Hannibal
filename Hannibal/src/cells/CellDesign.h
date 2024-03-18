#pragma once

#include <helpers/constants.h>
#include <SFML/Graphics.hpp>

class CellDesign
{
public:
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight,
              sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

   void Draw();

   bool IsInside() const;
   void SetFillColor(const sf::Color& color);

private:
   sf::RectangleShape m_rectangle;

   sf::Vector2f m_topLeft;
   sf::Vector2f m_botRight;
   sf::Color m_colorOutline;
};

