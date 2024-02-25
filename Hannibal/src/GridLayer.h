#pragma once

#include <vector>

#include <event/EventObjectFactory.h>
#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class GridLayer
{
public:
   GridLayer(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine, const sf::Color& colorBackround);
   ~GridLayer() = default;

   void Show() const;

private:
   void CreateGrid();

private:
   EventObjectFactory m_eventObjectFactory;

   const uint m_horizontalNum;
   const uint m_verticalNum;
   const sf::Color m_colorLine;
   const sf::Color m_colorBackround;

   std::vector<CellPtr> m_cells;
};

