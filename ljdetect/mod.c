#include <stdio.h>
#include <lua.h>
#include "ljdetect.h"


static int func( lua_State* L ) {
  if( isluajit( L ) ) {
    fprintf( stderr, "LuaJIT\n" );
  } else {
    fprintf( stderr, "PUC-Rio Lua\n" );
  }
  return 0;
}


int luaopen_mod( lua_State* L ) {
  lua_pushcfunction( L, func );
  return 1;
}

