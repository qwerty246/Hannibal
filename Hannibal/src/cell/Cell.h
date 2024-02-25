#pragma once

#include <memory>

#include <cell/CellDesign.h>
#include <event/EventObject.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Cell : public EventObject
{
public:
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color colorArea, sf::Color colorOutline, float outlineThickness);

   ~Cell();

public:
   void Draw();
   void CreateSubCellDesign(CellDesignPtr pCellDesign);

   void RunEvent(const sf::Event& event) const override;

private:
   void DeletionRequest() override;

private:
   CellDesignPtr m_pCellDesign;
   CellDesignPtr m_pSubCellDesign;
};

