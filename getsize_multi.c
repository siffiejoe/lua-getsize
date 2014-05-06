#define LUA_CORE
#include <lua.h>

#if LUA_VERSION_NUM == 503

#  include "lua5.3/lobject.h"
#  include "lua5.3/lstate.h"
#  include "lua5.3/lstring.h"
#  include "lua5.3/lfunc.h"

#elif LUA_VERSION_NUM == 502

#  include "lua5.2/lobject.h"
#  include "lua5.2/lstate.h"
#  include "lua5.2/lstring.h"
#  include "lua5.2/lfunc.h"

#elif LUA_VERSION_NUM == 501

#  include "lua5.1/lobject.h"
#  include "lua5.1/lstate.h"
#  include "lua5.1/lstring.h"
#  include "lua5.1/lfunc.h"

#else

#  error unsupported Lua version for lua-getsize

#endif

#undef LUA_CORE
#include "getsize.c"

