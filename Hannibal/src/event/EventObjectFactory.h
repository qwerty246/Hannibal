#pragma once

#include <Constants.h>
#include <event/EventObject.h>

class EventObjectFactory
{
public:
   static EventObject* CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);
   static EventObject* CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea);
   static EventObject* CreateCell(EventManagerPtr pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness);
};

