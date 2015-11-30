#include <stddef.h>
#include <lua.h>

/* use older lstate.h (layout of lua_State changed between
 * Lua 5.3.1 and 5.3.2!)
 */
#if LUA_VERSION_NUM == 503
#  include "lua5.3/llimits531.h"
#  include "lua5.3/lstate531.h"

size_t sizeThread_530_531(lua_State const* th)
{
  CallInfo *ci = th->base_ci.next;
  size_t cisize = 0;
  for (; ci != NULL; ci = ci->next)
    cisize += sizeof(CallInfo);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize + cisize;
}

#endif

