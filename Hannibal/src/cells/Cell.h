#pragma once

#include <memory>

#include <cells/CellDesign.h>
#include <event/EventObject.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class Cell :
   public EventObject
{
public:
   Cell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight,
        sf::Color fillColor, sf::Color outlineColor, float outlineThickness);

   ~Cell();

public:
   void Draw();
   void RunEvent(const sf::Event& event) override;

private:
   void DeletionRequest() override;

protected:
   sf::Vector2f m_topLeft;
   sf::Vector2f m_botRight;
   sf::Color m_fillColor;
   sf::Color m_outlineColor;
   float m_outlineThickness;

   CellDesign m_cellDesign;
};

