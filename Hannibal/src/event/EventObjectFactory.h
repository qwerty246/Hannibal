#pragma once

#include <Constants.h>

#include <event/EventObject.h>
#include <SFML/System/Vector2.hpp>

class EventManager;
class sf::Color;

class EventObjectFactory
{
public:
   static EventObject* CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight);
   static EventObject* CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea);
   static EventObject* CreateCell(std::shared_ptr<EventManager> pEventManager, sf::Vector2f topLeft, sf::Vector2f botRight, sf::Color colorLine, sf::Color colorArea, float thickness);
};

