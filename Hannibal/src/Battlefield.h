#pragma once

#include <vector>

#include <event/EventObjectFactory.h>
#include <GridLayer.h>
#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Battlefield
{
public:
   Battlefield(EventManagerPtr pEventManager, uint horizontalNum, uint verticalNum, const sf::Color& colorLine);
   ~Battlefield() = default;

   void Show() const;

private:
   EventObjectFactory m_eventObjectFactory;
   GridLayer m_gridLayer;
   std::vector<CellPtr> m_cells;
};

