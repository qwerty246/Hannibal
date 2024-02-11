#include "Window.h"

Window& Window::Get()
{
   static Window window;
   return window;
}
