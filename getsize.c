/* lua-getsize
   Author: (C) 2009 Matthew Wild
   License: MIT/X11 license
   Description: Adds a debug.getsize() function which
                returns the size in bytes of a Lua object
*/

#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include "ljdetect/ljdetect.h"
#include "compat.h"


static int debug_getsize(lua_State* L)
{
  GetSizeVTable const* const vtable = lua_touserdata(L, lua_upvalueindex(1));
  /* TValue */ void const* const o = vtable->getArg(L, 1);
  size_t olen = 0;
  char const* options = luaL_optlstring(L, 2, "", &olen);
  int count_upvalues = 1;
  int count_protos = 0;
  size_t i = 0;
  for (i = 0; i < olen; ++i)
  {
    switch (options[i])
    {
      case 'p': count_protos = 1; break;
      case 'P': count_protos = 0; break;
      case 'u': count_upvalues = 1; break;
      case 'U': count_upvalues = 0; break;
      default:
        luaL_error(L, "unknown option for 'getsize': %c", options[i]);
        break;
    }
  }
  switch (lua_type(L, 1))
  {
    case LUA_TNIL:
    {
      lua_pushinteger(L, 0);
      return 1;
    }
    case LUA_TBOOLEAN:
    {
      lua_pushinteger(L, vtable->sizeBoolean(o));
      return 1;
    }
    case LUA_TLIGHTUSERDATA:
    {
      lua_pushinteger(L, sizeof(void*));
      return 1;
    }
    case LUA_TNUMBER:
    {
      lua_pushinteger(L, vtable->sizeNumber(o));
      return 1;
    }
    case LUA_TSTRING:
    {
      lua_pushinteger(L, vtable->sizeString(o));
      return 1;
    }
    case LUA_TTABLE:
    {
      /* Node */ void const* const dummynode = lua_touserdata(L, lua_upvalueindex(2));
      unsigned narr = 0;
      unsigned nrec = 0;
      lua_pushinteger(L, vtable->sizeTable(o, dummynode, &narr, &nrec));
      lua_pushinteger(L, narr);
      lua_pushinteger(L, nrec);
      return 3;
    }
    case LUA_TFUNCTION:
    {
      lua_pushinteger(L, vtable->sizeFunction(o, count_protos, count_upvalues));
      return 1;
    }
    case LUA_TUSERDATA:
    {
      lua_pushinteger(L, vtable->sizeUserdata(o));
      return 1;
    }
    case LUA_TTHREAD:
    {
      lua_pushinteger(L, vtable->sizeThread(o));
      return 1;
    }
  }
  return 0;
}


int luaopen_getsize(lua_State* L)
{
  GetSizeVTable const* vtable = NULL;
  if (isluajit(L))
    luaL_error(L, "LuaJIT is not supported by getsize");
  lua_settop(L, 0);
  lua_getglobal(L, "debug");
  lua_createtable(L, 0, 0); /* to get dummynode pointer */
  vtable = compat_init(L);
  lua_pushlightuserdata(L, vtable->tableNode(vtable->getArg(L, 2)));
  lua_pushcclosure(L, debug_getsize, 2);
  if (lua_type(L, 1) == LUA_TTABLE)
  {
    lua_pushvalue(L, -1);
    lua_setfield(L, 1, "getsize");
  }
  return 1;
}

