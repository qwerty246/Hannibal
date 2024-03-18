#pragma once

#include <vector>

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
   EventManagerPtr m_pEventManager;
   GridLayer m_gridLayer;
   std::vector<CellFieldPtr> m_cellFields;
};

