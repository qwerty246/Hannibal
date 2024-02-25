#include <Window.h>

#include <cell/CellDesign.h>

CellDesign::CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorArea, sf::Color colorOutline, float outlineThickness) :
   m_topLeft(),
   m_botRight()
{
   m_topLeft = { topLeft.x + outlineThickness, topLeft.y + outlineThickness };
   m_botRight = { botRight.x - outlineThickness, botRight.y - outlineThickness };

   m_rectangle.setSize({ m_botRight.x - m_topLeft.x, m_botRight.y - m_topLeft.y });
   m_rectangle.setPosition(m_topLeft);
   m_rectangle.setFillColor(colorArea);
   m_rectangle.setOutlineColor(colorOutline);
   m_rectangle.setOutlineThickness(outlineThickness);
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
   m_rectangle.setFillColor(color);
}
