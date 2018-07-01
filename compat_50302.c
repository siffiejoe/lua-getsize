#include <lua.h>


#if LUA_VERSION_NUM == 503
#include "compat.h"
#define LUA_CORE
#include "lua5.3/2/lstate.h"


size_t sizeThread_50302(lua_State const* th) {
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
                             sizeof(CallInfo) * th->nci;
}

#endif

