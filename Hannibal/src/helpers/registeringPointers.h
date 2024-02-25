#pragma once

#include <memory>

#define REGISTER_SHARED_PTR(T) \
   class T; \
   typedef std::shared_ptr<T> T ## Ptr;

REGISTER_SHARED_PTR(Cell)
REGISTER_SHARED_PTR(EventManager)
REGISTER_SHARED_PTR(EventObject)
