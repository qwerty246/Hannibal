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

   m_rectangle.setSize({ m_botRight.x - m_topLeft.x, m_botRight.y - m_topLeft.y });
   m_rectangle.setPosition(m_topLeft);
   m_rectangle.setFillColor(m_colorArea);
   m_rectangle.setOutlineThickness(m_thickness);
   m_rectangle.setOutlineColor(m_colorEdge);
}

void CellDesign::Draw()
{
   Window::Get().draw(m_rectangle);
}

bool CellDesign::IsInside(const sf::Event::MouseButtonEvent& mouseButton) const
{
   if (mouseButton.x < m_topLeft.x ||
       mouseButton.x > m_botRight.x ||
       mouseButton.y < m_topLeft.y ||
       mouseButton.y > m_botRight.y)
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

void CellDesign::SetFillColor(const sf::Color& color)
{
   m_colorArea = color;
   m_rectangle.setFillColor(m_colorArea);
}
