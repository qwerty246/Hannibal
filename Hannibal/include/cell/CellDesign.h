#pragma once

#include <Constants.h>

class CellDesign;
typedef std::shared_ptr<CellDesign> CellDesignPtr;

class CellDesign
{
public:
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight);
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea);
   CellDesign(sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorEdge, sf::Color colorArea, float thickness);

   void Draw();

   virtual bool IsInside(const sf::Vector2f& point) const;
   const sf::Vector2f& GetTopLeft() const;
   const sf::Vector2f& GetBotRight() const;
private:
   sf::Vector2f m_topLeft;
   sf::Vector2f m_botRight;

   float m_thickness;
   sf::Color m_colorEdge;
   sf::Color m_colorArea;
};

