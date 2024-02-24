#include <Grid.h>
#include <StandardLength.h>
#include <Window.h>

#include <cell/Cell.h>
#include <event/EventManager.h>
#include <event/EventObjectFactory.h>

Grid::Grid(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround) :
   m_pEventManager(pEventManager),
   m_horizontalNum(horizontalNum),
   m_verticalNum(verticalNum),
   m_colorLine(colorLine),
   m_colorBackround(colorBackround),
   m_cells()
{
}

void Grid::CreateGrid()
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
         sf::Vector2f topLeft(i, j);
         sf::Vector2f botRight(i + length, j + length);
         float thickness = 4;

         auto cell = std::dynamic_pointer_cast<Cell>(EventObjectFactory::CreateCell(m_pEventManager, topLeft, botRight, m_colorBackround, m_colorLine, thickness));

         sf::Vector2f topSubLeft(i + thickness, j + thickness);
         sf::Vector2f botSubRight(i + length - thickness, j + length - thickness);
         auto pSubCell = std::make_shared<CellDesign>(topSubLeft, botSubRight,
            m_colorLine, sf::Color::White, thickness - 2);
         cell->CreateSubCellDesign(pSubCell);

         m_cells.push_back(cell);
      }
   }
}

void Grid::Show()
{
   for (auto i : m_cells)
   {
      i->Draw();
   }
}

void Grid::ClearCells()
{
   for (auto i : m_cells)
   {
      i->DeletionRequest();
   }
   m_cells.clear();
}
