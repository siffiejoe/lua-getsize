#include <lua.h>


#if LUA_VERSION_NUM == 504
#define LUA_CORE
#include "lua5.4/3/lstate.h"


size_t sizeThread_50403(void const* o)
{
  lua_State const* th = thvalue((TValue const*)o);
  CallInfo *ci = th->base_ci.next;
  size_t cisize = 0;
  for (; ci != NULL; ci = ci->next)
    cisize += sizeof(CallInfo);
  return sizeof(lua_State) + sizeof(TValue) * (stacksize(th) + EXTRA_STACK) + cisize;
}

#endif

