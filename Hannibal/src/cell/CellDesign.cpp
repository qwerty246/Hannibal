#include <Window.h>

#include <cell/CellDesign.h>

CellDesign::CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight) :
   CellDesign(topLeft, botRight, sf::Color::Black, sf::Color::White, 1)
{
}

CellDesign::CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea) :
   CellDesign(topLeft, botRight, colorEdge, colorArea, 1)
{
}

CellDesign::CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea, float thickness) :
   m_topLeft(),
   m_botRight(),
   m_thickness(thickness),
   m_colorEdge(colorEdge),
   m_colorArea(colorArea)
{
   m_topLeft = { topLeft.x + thickness, topLeft.y + thickness };
   m_botRight = { botRight.x - thickness, botRight.y - thickness };
}

void CellDesign::Draw()
{
   sf::RectangleShape rectangle({ m_botRight.x - m_topLeft.x, m_botRight.y - m_topLeft.y });
   rectangle.setPosition(m_topLeft);
   rectangle.setOutlineThickness(m_thickness);
   rectangle.setOutlineColor(m_colorEdge);
   rectangle.setFillColor(m_colorArea);
   Window::Get().draw(rectangle);
}

bool CellDesign::IsInside(const sf::Event::MouseMoveEvent& mouseMove) const
{
   if (mouseMove.x < m_topLeft.x ||
       mouseMove.x > m_botRight.x ||
       mouseMove.y < m_topLeft.y ||
       mouseMove.y > m_botRight.y)
   {
      return false;
   }
   return true;
}

const sf::Vector2f& CellDesign::GetTopLeft() const
{
   return m_topLeft;
}

const sf::Vector2f& CellDesign::GetBotRight() const
{
   return m_botRight;
}
