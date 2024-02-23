#pragma once

#include <vector>

#include <Constants.h>

#include <SFML/Graphics.hpp>

class Cell;
class EventManager;
class sf::Color;

class Grid
{
public:
   Grid(std::shared_ptr<EventManager> pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround);
   ~Grid() = default;

   void CreateGrid();
   void Show();
private:
   std::shared_ptr<EventManager> m_pEventManager;

   const uint m_horizontalNum;
   const uint m_verticalNum;
   const sf::Color m_colorLine;
   const sf::Color m_colorBackround;

   std::vector<Cell*> m_cells;
};

