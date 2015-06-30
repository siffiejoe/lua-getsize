#ifndef LJDETECT_H_
#define LJDETECT_H_

/* Small C header file that provides a helper function that can detect
 * LuaJIT at runtime.
 */

#include <stddef.h>
#include <string.h>
#include <lua.h>
#include <lauxlib.h>


typedef struct {
  size_t written;
  char buffer[ 3 ];
} isluajit_state;


static int isluajit_writer( lua_State* L, const void* p,
                            size_t sz, void* ud ) {
  isluajit_state* s = (isluajit_state*)ud;
  (void)L;
  if( sz > 0 && s->written < sizeof( s->buffer ) ) {
    char const* cp = (char const*)p;
    if( sz > sizeof( s->buffer ) - s->written )
      sz = sizeof( s->buffer ) - s->written;
    memcpy( s->buffer, cp, sz );
    s->written += sz;
    return 0;
  }
  return s->written < sizeof( s->buffer );
}


static int isluajit( lua_State* L ) {
#if LUA_VERSION_NUM == 501
  isluajit_state st;
  /* create a Lua function */
  if( luaL_loadstring( L, "" ) != 0 )
    lua_error( L );
  /* dump the Lua function as bytecode */
  st.written = 0;
  lua_dump( L, isluajit_writer, &st );
  /* remove Lua function from stack */
  lua_pop( L, 1 );
  /* inspect the bytecode header to detect the LuaJIT signature */
  if( st.written < sizeof( st.buffer ) ||
      0 != memcmp( "\033LJ", st.buffer, sizeof( st.buffer ) ) )
    return 0;
  else
    return 1;
#else
  (void)L;
  (void)isluajit_writer;
  return 0;
#endif
}

#endif /* LJDETECT_H_ */

