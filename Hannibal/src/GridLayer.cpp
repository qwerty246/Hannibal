#include <GridLayer.h>
#include <StandardLength.h>

#include <cell/Cell.h>
#include <event/EventManager.h>

GridLayer::GridLayer() :
   m_window(Window::Get()),
   m_rectangle(),
   m_lines()
{
}

void GridLayer::CreateGridLayer(float cellLength, uint horizontalNum, uint verticalNum,
                                sf::Color fillColor, sf::Color colorLine, float lineThickness)
{
   sf::Vector2f center = m_window.GetCenter();
   sf::Vector2f offset = { cellLength * horizontalNum / 2, cellLength * verticalNum / 2 };
   sf::Vector2f topLeft = sf::Vector2f(center.x - offset.x, center.y - offset.y);
   sf::Vector2f botRight = sf::Vector2f(center.x + offset.x, center.y + offset.y);

   SetRectangle(topLeft, botRight, fillColor, colorLine, lineThickness);
}

void GridLayer::Draw() const
{
   m_window.draw(m_rectangle);

   for (auto line : m_lines)
   {
      sf::Vertex sfLine[2] = { line.first, line.second };
      m_window.draw(sfLine, 2, sf::Lines);
   }
}

void GridLayer::SetRectangle(const sf::Vector2f& topLeft, const sf::Vector2f& botRight,
                             const sf::Color& fillColor, const sf::Color& colorLine, float lineThickness)
{
   m_rectangle.setSize({ botRight.x - topLeft.x, botRight.y - topLeft.y });
   m_rectangle.setPosition(topLeft);
   m_rectangle.setFillColor(fillColor);
   m_rectangle.setOutlineColor(colorLine);
   m_rectangle.setOutlineThickness(lineThickness);
}
