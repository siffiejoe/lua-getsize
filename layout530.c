#include <stddef.h>
#include <lua.h>

/* use older lstring.h/lobject.h (layout of strings changed between
 * Lua 5.3.0 and 5.3.1!)
 */
#if LUA_VERSION_NUM == 503
#  include "lua5.3/lobject530.h"
#  include "lua5.3/lstring530.h"

size_t sizeString_530(TValue const* v)
{
  return sizestring(tsvalue(v));
}

#endif

