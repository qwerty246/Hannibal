#pragma once

#include <cell/CellDesign.h>

class Cell
{
public:
   Cell(sf::Vector2f topLeft, sf::Vector2f botRight);
   Cell(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea);
   Cell(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness);

   void Draw();
   void CreateSubCellDesign(CellDesignPtr pCellDesign);

   bool IsInside(const sf::Vector2f& point) const;
private:
   CellDesignPtr m_pCellDesign;
   CellDesignPtr m_pSubCellDesign;
};

