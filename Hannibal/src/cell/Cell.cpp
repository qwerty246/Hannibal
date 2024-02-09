#include <cell/Cell.h>

Cell::Cell(sf::Vector2f topLeft, sf::Vector2f botRight) :
   Cell(topLeft, botRight, sf::Color::Black, sf::Color::White, 1)
{
}

Cell::Cell(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea) :
   Cell(topLeft, botRight, colorLine, colorArea, 1)
{
}

Cell::Cell(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness) :
   m_pCellDesign(new CellDesign(topLeft, botRight, colorLine, colorArea, thickness)),
   m_pSubCellDesign(nullptr)
{
}

void Cell::Draw()
{
   m_pCellDesign->Draw();
   if (m_pSubCellDesign)
   {
      m_pSubCellDesign->Draw();
   }
}

void Cell::CreateSubCellDesign(CellDesignPtr pCellDesign)
{
   m_pSubCellDesign = pCellDesign;
}

bool Cell::IsInside(const sf::Vector2f& point) const
{
   return m_pCellDesign->IsInside(point);
}
