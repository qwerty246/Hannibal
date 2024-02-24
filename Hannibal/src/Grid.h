#pragma once

#include <vector>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Grid
{
public:
   Grid(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround);
   ~Grid() = default;

   void CreateGrid();
   void Show();
   void ClearCells();
private:
   EventManagerPtr m_pEventManager;

   const uint m_horizontalNum;
   const uint m_verticalNum;
   const sf::Color m_colorLine;
   const sf::Color m_colorBackround;

   std::vector<CellPtr> m_cells;
};

