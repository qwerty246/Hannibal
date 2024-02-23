#pragma once

#include <Constants.h>

class StandardLength
{
private:
   StandardLength() = delete;
   StandardLength(StandardLength const&) = delete;
   StandardLength& operator= (StandardLength const&) = delete;

   StandardLength(uint length);
   ~StandardLength() = default;

   static StandardLength& GetInstance(uint length = 100);

public:
   static void Initialization(uint length);
   static uint Get();
   static uint Get(float scale);

private:
   uint m_length;
};

