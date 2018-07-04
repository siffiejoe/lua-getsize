/* lua-getsize
   Author: (C) 2009 Matthew Wild
   License: MIT/X11 license
   Description: Adds a debug.getsize() function which
                returns the size in bytes of a Lua object
*/

#include <stdio.h>

#define LUA_CORE
#include <lua.h>
#if LUA_VERSION_NUM == 503

#include "lua5.3/lobject.h"
#include "lua5.3/lstate.h"
#include "lua5.3/lstring.h"
#include "lua5.3/lfunc.h"

#elif LUA_VERSION_NUM == 502

#include "lua5.2/lobject.h"
#include "lua5.2/lstate.h"
#include "lua5.2/lstring.h"
#include "lua5.2/lfunc.h"

#elif LUA_VERSION_NUM == 501

#include "lua5.1/lobject.h"
#include "lua5.1/lstate.h"
#include "lua5.1/lstring.h"
#include "lua5.1/lfunc.h"

#else

#error unsupported Lua version for getsize

#endif

#undef LUA_CORE
#include <lauxlib.h>
#include "ljdetect/ljdetect.h"
#include "compat.h"



static size_t sizeProto(Proto const *p)
{
  return sizeof(Proto) + sizeof(Instruction) * p->sizecode +
                         sizeof(Proto*) * p->sizep +
                         sizeof(TValue) * p->sizek +
                         sizeof(int) * p->sizelineinfo +
                         sizeof(LocVar) * p->sizelocvars +
                         sizeof(*(p->upvalues)) * p->sizeupvalues;
}


static int debug_getsize(lua_State *L)
{
  GetSizeVTable* vtable = lua_touserdata(L, lua_upvalueindex(1));
  Node const *dummynode = lua_touserdata(L, lua_upvalueindex(2));
  TValue *o = vtable->getArg(L, 1);
  size_t olen = 0;
  char const *options = luaL_optlstring(L, 2, "", &olen);
  int count_upvalues = 1;
  int count_protos = 0;
  size_t i = 0;
  for (i = 0; i < olen; ++i) {
    switch (options[i]) {
      case 'p': count_protos = 1; break;
      case 'P': count_protos = 0; break;
      case 'u': count_upvalues = 1; break;
      case 'U': count_upvalues = 0; break;
      default:
        luaL_error(L, "unkown option for 'getsize': %c", (int)options[i]);
        break;
    }
  }
  switch (ttype(o)) {
    case LUA_TTABLE: {
      Table *h = hvalue(o);
      unsigned narr = 0;
      unsigned nrec = 0;
      lua_pushinteger(L, vtable->sizeTable(h, dummynode, &narr, &nrec));
      lua_pushinteger(L, narr);
      lua_pushinteger(L, nrec);
      return 3;
    }
#if LUA_VERSION_NUM == 501
    case LUA_TFUNCTION: {
      Closure *cl = clvalue(o);
      if (cl->c.isC)
        lua_pushinteger(L, sizeCclosure(cl->c.nupvalues));
      else
        lua_pushinteger(L, sizeLclosure(cl->l.nupvalues) +
                           (count_upvalues ? cl->l.nupvalues * sizeof(UpVal) : 0) +
                           (count_protos ? sizeProto(cl->l.p) : 0));
      return 1;
    }
#endif
#ifdef LUA_TLCL
    case LUA_TLCL: { /* Lua closure */
      Closure *cl = clvalue(o);
      lua_pushinteger(L, sizeLclosure(cl->l.nupvalues) +
                         (count_upvalues ? cl->l.nupvalues * sizeof(UpVal) : 0) +
                         (count_protos ? sizeProto(cl->l.p) : 0));
      return 1;
    }
#endif
#ifdef LUA_TLCF
    case LUA_TLCF: { /* light C function */
      lua_pushinteger(L, sizeof(lua_CFunction));
      return 1;
    }
#endif
#ifdef LUA_TCCL
    case LUA_TCCL: { /* C closure */
      Closure *cl = clvalue(o);
      lua_pushinteger(L, sizeCclosure(cl->c.nupvalues));
      return 1;
    }
#endif
    case LUA_TTHREAD: {
      lua_pushinteger(L, vtable->sizeThread(thvalue(o)));
      return 1;
    }
    case LUA_TUSERDATA: {
      lua_pushinteger(L, sizeudata(uvalue(o)));
      return 1;
    }
    case LUA_TLIGHTUSERDATA: {
      lua_pushinteger(L, sizeof(void*));
      return 1;
    }
#ifdef LUA_TLNGSTR
    case LUA_TLNGSTR: /* fall through */
#endif
    case LUA_TSTRING: {
      lua_pushinteger(L, vtable->sizeString(o));
      return 1;
    }
#ifdef LUA_TNUMINT
    case LUA_TNUMINT: {
      lua_pushinteger(L, sizeof(lua_Integer));
      return 1;
    }
#endif
    case LUA_TNUMBER: {
      lua_pushinteger(L, sizeof(lua_Number));
      return 1;
    }
    case LUA_TBOOLEAN: {
      lua_pushinteger(L, sizeof(int));
      return 1;
    }
    case LUA_TNIL: {
      lua_pushinteger(L, 0);
      return 1;
    }
  }
  return 0;
}


int luaopen_getsize(lua_State* L)
{
  GetSizeVTable* vtable = NULL;
  if (isluajit(L))
    luaL_error(L, "LuaJIT is not supported by getsize");
  lua_settop(L, 0);
  lua_getglobal(L, "debug");
  lua_createtable(L, 0, 0); /* to get dummynode pointer */
  vtable = compat_init(L);
  lua_pushlightuserdata(L, vtable->tableNode(hvalue((TValue*)vtable->getArg(L, 2))));
  lua_pushcclosure(L, debug_getsize, 2);
  if (lua_type(L, 1) == LUA_TTABLE) {
    lua_pushvalue(L, -1);
    lua_setfield(L, 1, "getsize");
  }
  return 1;
}

