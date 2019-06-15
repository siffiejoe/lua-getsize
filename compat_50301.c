#include <lua.h>


#if LUA_VERSION_NUM == 503
#define LUA_CORE
#include "lua5.3/1/lobject.h"
#include "lua5.3/1/lstring.h"


size_t sizeString_50301(void const* o) {
  TValue const* v = o;
  return sizelstring(tsslen(tsvalue(v)));
}

#endif

