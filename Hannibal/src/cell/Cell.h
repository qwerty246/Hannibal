#pragma once

#include <memory>

#include <cell/CellDesign.h>
#include <event/EventObject.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Cell : public EventObject
{
public:
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);

   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color colorLine, sf::Color colorArea);

   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color colorLine, sf::Color colorArea, float thickness);

   ~Cell() = default;
public:
   void Draw();
   void CreateSubCellDesign(CellDesignPtr pCellDesign);

   bool CheckEvent(const sf::Event& event) const override;
   void DeletionRequest() override;
private:
   CellDesignPtr m_pCellDesign;
   CellDesignPtr m_pSubCellDesign;
};

