#pragma once

#include <vector>

#include <Constants.h>
#include <cell/Cell.h>

class Grid
{
public:
   Grid(uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround);
   ~Grid() = default;

   void Show();
private:
   const uint m_horizontalNum;
   const uint m_verticalNum;
   const sf::Color m_colorLine;
   const sf::Color m_colorBackround;

   std::vector<Cell> m_cells;
};

