#include <GridLayer.h>
#include <StandardLength.h>
#include <Window.h>

#include <cell/Cell.h>
#include <event/EventManager.h>

GridLayer::GridLayer(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround) :
   m_eventObjectFactory(pEventManager),
   m_horizontalNum(horizontalNum),
   m_verticalNum(verticalNum),
   m_colorLine(colorLine),
   m_colorBackround(colorBackround),
   m_cells()
{
   CreateGrid();
}

void GridLayer::CreateGrid()
{
   auto windowSize = Window::Get().getSize();
   float length = static_cast<float>(StandardLength::Get());

   float centerX = static_cast<float>(windowSize.x / 2);
   float centerY = static_cast<float>(windowSize.y / 2);

   float offsetX = length * m_horizontalNum / 2;
   float offsetY = length * m_verticalNum / 2;

   for (float i = centerX - offsetX; i < centerX + offsetX; i += length)
   {
      for (float j = centerY - offsetY; j < centerY + offsetY; j += length)
      {
         float outlineThickness = 2;
         float space = 2;
         sf::Vector2f topLeft(i + outlineThickness + space, j + outlineThickness + space);
         sf::Vector2f botRight(i + length - (outlineThickness + space), j + length - (outlineThickness + space));

         auto cell = std::dynamic_pointer_cast<Cell>(m_eventObjectFactory.CreateCell(topLeft, botRight, sf::Color::White, m_colorLine, outlineThickness));
         m_cells.push_back(cell);
      }
   }
}

void GridLayer::Show() const
{
   for (auto i : m_cells)
   {
      i->Draw();
   }
}
