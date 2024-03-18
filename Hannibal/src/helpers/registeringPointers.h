#pragma once

#include <memory>

#define REGISTER_SHARED_PTR(T) \
   class T; \
   typedef std::shared_ptr<T> T ## Ptr;

//#define REGISTER_SHARED_PTR_SF(T) \
//   namespace sf \
//   { \
//      class T; \
//   } \
//   typedef std::shared_ptr<sf::T> T ## Ptr;

REGISTER_SHARED_PTR(Cell)
REGISTER_SHARED_PTR(CellField)
REGISTER_SHARED_PTR(CellUnit)
REGISTER_SHARED_PTR(EventManager)
REGISTER_SHARED_PTR(EventObject)
//REGISTER_SHARED_PTR_SF(Vertex)
