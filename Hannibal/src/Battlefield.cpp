#include <Battlefield.h>
#include <StandardLength.h>

#include <cell/Cell.h>
#include <event/EventManager.h>

Battlefield::Battlefield(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine) :
   m_eventObjectFactory(pEventManager),
   m_gridLayer(),
   m_cells()
{
   float length = static_cast<float>(StandardLength::Get());
   float outlineThickness = length / 25;
   m_gridLayer.CreateGridLayer(length, horizontalNum, verticalNum, sf::Color::Green, sf::Color::Red, outlineThickness);

   sf::Vector2f center = Window::Get().GetCenter();
   sf::Vector2f offset = { length * horizontalNum / 2, length * verticalNum / 2 };
   float space = length / 25;

   for (float x = center.x - offset.x; x < center.x + offset.x; x += length)
   {
      for (float y = center.y - offset.y; y < center.y + offset.y; y += length)
      {
         sf::Vector2f topLeft(x + outlineThickness + space, y + outlineThickness + space);
         sf::Vector2f botRight(x + length - (outlineThickness + space), y + length - (outlineThickness + space));

         auto cell = std::dynamic_pointer_cast<Cell>
            (m_eventObjectFactory.CreateCell(topLeft, botRight, sf::Color::White, colorLine, outlineThickness));
         m_cells.push_back(cell);
      }
   }
}

void Battlefield::Show() const
{
   m_gridLayer.Draw();

   for (auto cell : m_cells)
   {
      cell->Draw();
   }
}
