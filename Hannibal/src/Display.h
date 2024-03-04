#pragma once

#include <memory>

#include <helpers/constants.h>
#include <helpers/registeringPointers.h>
#include <SFML/Graphics.hpp>
#include <Window.h>

class Display
{
public:
   Display();
   ~Display() = default;

   void Show() const;

private:
   Window& m_window;
   EventManagerPtr m_pEventManager;
   const sf::Color m_colorBackround;
};

