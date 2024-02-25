#pragma once

#include <helpers/constants.h>
#include <SFML/Graphics.hpp>

class CellDesign
{
public:
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight);
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea);
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea, float thickness);

   void Draw();

   bool IsInside(const sf::Event::MouseButtonEvent& mouseButton) const;
   const sf::Vector2f& GetTopLeft() const;
   const sf::Vector2f& GetBotRight() const;
   void SetFillColor(const sf::Color& color);

private:
   sf::Vector2f m_topLeft;
   sf::Vector2f m_botRight;

   float m_thickness;
   sf::Color m_colorEdge;
   sf::Color m_colorArea;

   sf::RectangleShape m_rectangle;
};

