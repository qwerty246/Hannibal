#pragma once

#include <memory>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>

class EventObjectFactory
{
public:
   EventObjectFactory(EventManagerPtr pEventManager);

public:
   EventObjectPtr CreateCell(sf::Vector2f topLeft, sf::Vector2f botRight,
                             sf::Color colorLine, sf::Color colorArea, float thickness) const;

private:
   EventManagerPtr m_pEventManager;
};

