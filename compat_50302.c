#include <lua.h>


#if LUA_VERSION_NUM == 503
#define LUA_CORE
#include "lua5.3/2/lstate.h"


size_t sizeThread_50302(void const* o) {
  lua_State const* th = thvalue((TValue const*)o);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
                             sizeof(CallInfo) * th->nci;
}

#endif

