#include <cell/CellDesign.h>
#include <Window.h>

CellDesign::CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight,
                       sf::Color fillColor, sf::Color outlineColor, float outlineThickness) :
   m_rectangle(),
   m_topLeft(topLeft.x, topLeft.y),
   m_botRight(botRight.x, botRight.y),
   m_colorOutline(outlineColor)
{
   m_rectangle.setSize({ m_botRight.x - m_topLeft.x, m_botRight.y - m_topLeft.y });
   m_rectangle.setPosition(m_topLeft);
   m_rectangle.setFillColor(fillColor);
   m_rectangle.setOutlineColor(outlineColor);
   m_rectangle.setOutlineThickness(outlineThickness);
}

void CellDesign::Draw()
{
   Window::Get().draw(m_rectangle);
}

bool CellDesign::IsInside() const
{
   auto mouseButton = Window::GetMouseWorldPos();
   if (mouseButton.x < m_topLeft.x ||
       mouseButton.x > m_botRight.x ||
       mouseButton.y < m_topLeft.y ||
       mouseButton.y > m_botRight.y)
   {
      return false;
   }
   return true;
}

void CellDesign::SetFillColor(const sf::Color& color)
{
   m_rectangle.setFillColor(color);
   m_rectangle.setOutlineColor(m_colorOutline);
}
