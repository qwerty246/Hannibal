#pragma once

#include <vector>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>
#include <Window.h>

class GridLayer
{
public:
   GridLayer();
   ~GridLayer() = default;

   void CreateGridLayer(float cellLength, uint horizontalNum, uint verticalNum,
                        sf::Color fillColor, sf::Color colorLine, float lineThickness);
   void Draw() const;

private:
   void SetRectangle(const sf::Vector2f& topLeft, const sf::Vector2f& botRight,
                     const sf::Color& fillColor, const sf::Color& colorLine, float lineThickness);

private:
   Window& m_window;
   sf::RectangleShape m_rectangle;
   std::vector<std::pair<sf::Vertex, sf::Vertex>> m_lines;
};

