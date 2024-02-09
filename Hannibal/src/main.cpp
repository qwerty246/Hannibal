#include <SFML/Graphics.hpp>

#include <Display.h>
#include <StandardLength.h>

int main()
{
   StandardLength::Initialization(50);

   Display display;
   display.Show();

   return 0;
}
