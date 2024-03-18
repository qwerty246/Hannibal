#pragma once

#include <cells/Cell.h>
#include <cells/CellUnit.h>

class CellField :
    public Cell
{
public:
   CellField(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
             sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

public:
   void CreateCellUnit();

private:
   CellUnitPtr m_pCellUnit;
};

