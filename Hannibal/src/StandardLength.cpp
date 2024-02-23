#include <StandardLength.h>

StandardLength::StandardLength(uint length) :
   m_length(length)
{
}

StandardLength& StandardLength::GetInstance(uint length)
{
   static StandardLength standardLength(length);
   return standardLength;
}

void StandardLength::Initialization(uint length)
{
   GetInstance(length);
}

uint StandardLength::Get()
{
   StandardLength& standardLength = GetInstance();
   return standardLength.m_length;
}

uint StandardLength::Get(float scale)
{
   StandardLength& standardLength = GetInstance();
   return static_cast<uint>(standardLength.m_length * scale);
}
