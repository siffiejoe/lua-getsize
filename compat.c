#include <stdlib.h>
#include <lua.h>
#include "compat.h"


extern void* getArg_50103(lua_State*, int);
extern void* getArg_50200(lua_State*, int);
extern void* getArg_50300(lua_State*, int);
extern void* getArg_50400(lua_State*, int);

static GetArgFunction const getArgFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, getArg_50103, getArg_50103, getArg_50103
#elif LUA_VERSION_NUM == 502
  getArg_50200, getArg_50200, getArg_50200, getArg_50200, getArg_50200
#elif LUA_VERSION_NUM == 503
  getArg_50300, getArg_50300, getArg_50300, getArg_50300, getArg_50300, getArg_50300, getArg_50300
#elif LUA_VERSION_NUM == 504
  getArg_50400, getArg_50400, getArg_50400, getArg_50400, getArg_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeBoolean_50103(void const*);
extern size_t sizeBoolean_50200(void const*);
extern size_t sizeBoolean_50300(void const*);
extern size_t sizeBoolean_50400(void const*);

static BooleanSizeFunction const booleanSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeBoolean_50103, sizeBoolean_50103, sizeBoolean_50103
#elif LUA_VERSION_NUM == 502
  sizeBoolean_50200, sizeBoolean_50200, sizeBoolean_50200, sizeBoolean_50200, sizeBoolean_50200
#elif LUA_VERSION_NUM == 503
  sizeBoolean_50300, sizeBoolean_50300, sizeBoolean_50300, sizeBoolean_50300, sizeBoolean_50300, sizeBoolean_50300, sizeBoolean_50300
#elif LUA_VERSION_NUM == 504
  sizeBoolean_50400, sizeBoolean_50400, sizeBoolean_50400, sizeBoolean_50400, sizeBoolean_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeNumber_50103(void const*);
extern size_t sizeNumber_50200(void const*);
extern size_t sizeNumber_50300(void const*);
extern size_t sizeNumber_50400(void const*);

static NumberSizeFunction const numberSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeNumber_50103, sizeNumber_50103, sizeNumber_50103
#elif LUA_VERSION_NUM == 502
  sizeNumber_50200, sizeNumber_50200, sizeNumber_50200, sizeNumber_50200, sizeNumber_50200
#elif LUA_VERSION_NUM == 503
  sizeNumber_50300, sizeNumber_50300, sizeNumber_50300, sizeNumber_50300, sizeNumber_50300, sizeNumber_50300, sizeNumber_50300
#elif LUA_VERSION_NUM == 504
  sizeNumber_50400, sizeNumber_50400, sizeNumber_50400, sizeNumber_50400, sizeNumber_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeString_50103(void const*);
extern size_t sizeString_50200(void const*);
extern size_t sizeString_50300(void const*);
extern size_t sizeString_50301(void const*);
extern size_t sizeString_50400(void const*);

static StringSizeFunction const stringSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeString_50103, sizeString_50103, sizeString_50103
#elif LUA_VERSION_NUM == 502
  sizeString_50200, sizeString_50200, sizeString_50200, sizeString_50200, sizeString_50200
#elif LUA_VERSION_NUM == 503
  sizeString_50300, sizeString_50301, sizeString_50301, sizeString_50301, sizeString_50301, sizeString_50301, sizeString_50301
#elif LUA_VERSION_NUM == 504
  sizeString_50400, sizeString_50400, sizeString_50400, sizeString_50400, sizeString_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeFunction_50103(void const*, int, int, int);
extern size_t sizeFunction_50200(void const*, int, int, int);
extern size_t sizeFunction_50300(void const*, int, int, int);
extern size_t sizeFunction_50400(void const*, int, int, int);

static FunctionSizeFunction const functionSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeFunction_50103, sizeFunction_50103, sizeFunction_50103
#elif LUA_VERSION_NUM == 502
  sizeFunction_50200, sizeFunction_50200, sizeFunction_50200, sizeFunction_50200, sizeFunction_50200
#elif LUA_VERSION_NUM == 503
  sizeFunction_50300, sizeFunction_50300, sizeFunction_50300, sizeFunction_50300, sizeFunction_50300, sizeFunction_50300, sizeFunction_50300
#elif LUA_VERSION_NUM == 504
  sizeFunction_50400, sizeFunction_50400, sizeFunction_50400, sizeFunction_50400, sizeFunction_50400
#else
#error unsupported Lua version
#endif
};



extern void* tableNode_50103(void const*);
extern void* tableNode_50200(void const*);
extern void* tableNode_50204(void const*);
extern void* tableNode_50300(void const*);
extern void* tableNode_50400(void const*);

static TableNodeFunction const tableNodeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, tableNode_50103, tableNode_50103, tableNode_50103
#elif LUA_VERSION_NUM == 502
  tableNode_50200, tableNode_50200, tableNode_50200, tableNode_50200, tableNode_50204
#elif LUA_VERSION_NUM == 503
  tableNode_50300, tableNode_50300, tableNode_50300, tableNode_50300, tableNode_50300, tableNode_50300, tableNode_50300
#elif LUA_VERSION_NUM == 504
  tableNode_50400, tableNode_50400, tableNode_50400, tableNode_50400, tableNode_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeTable_50103(void const*, void const*, unsigned*, unsigned*);
extern size_t sizeTable_50200(void const*, void const*, unsigned*, unsigned*);
extern size_t sizeTable_50204(void const*, void const*, unsigned*, unsigned*);
extern size_t sizeTable_50300(void const*, void const*, unsigned*, unsigned*);
extern size_t sizeTable_50400(void const*, void const*, unsigned*, unsigned*);

static TableSizeFunction const tableSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeTable_50103, sizeTable_50103, sizeTable_50103
#elif LUA_VERSION_NUM == 502
  sizeTable_50200, sizeTable_50200, sizeTable_50200, sizeTable_50200, sizeTable_50204
#elif LUA_VERSION_NUM == 503
  sizeTable_50300, sizeTable_50300, sizeTable_50300, sizeTable_50300, sizeTable_50300, sizeTable_50300, sizeTable_50300
#elif LUA_VERSION_NUM == 504
  sizeTable_50400, sizeTable_50400, sizeTable_50400, sizeTable_50400, sizeTable_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeUserdata_50103(void const*);
extern size_t sizeUserdata_50200(void const*);
extern size_t sizeUserdata_50300(void const*);
extern size_t sizeUserdata_50400(void const*);

static UserdataSizeFunction const userdataSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeUserdata_50103, sizeUserdata_50103, sizeUserdata_50103
#elif LUA_VERSION_NUM == 502
  sizeUserdata_50200, sizeUserdata_50200, sizeUserdata_50200, sizeUserdata_50200, sizeUserdata_50200
#elif LUA_VERSION_NUM == 503
  sizeUserdata_50300, sizeUserdata_50300, sizeUserdata_50300, sizeUserdata_50300, sizeUserdata_50300, sizeUserdata_50300, sizeUserdata_50300
#elif LUA_VERSION_NUM == 504
  sizeUserdata_50400, sizeUserdata_50400, sizeUserdata_50400, sizeUserdata_50400, sizeUserdata_50400
#else
#error unsupported Lua version
#endif
};



extern size_t sizeThread_50103(void const*);
extern size_t sizeThread_50200(void const*);
extern size_t sizeThread_50300(void const*);
extern size_t sizeThread_50302(void const*);
extern size_t sizeThread_50400(void const*);
extern size_t sizeThread_50401(void const*);
extern size_t sizeThread_50402(void const*);
extern size_t sizeThread_50403(void const*);

static ThreadSizeFunction const threadSizeFuncs[] = {
#if LUA_VERSION_NUM == 501
  0, 0, 0, sizeThread_50103, sizeThread_50103, sizeThread_50103
#elif LUA_VERSION_NUM == 502
  sizeThread_50200, sizeThread_50200, sizeThread_50200, sizeThread_50200, sizeThread_50200
#elif LUA_VERSION_NUM == 503
  sizeThread_50300, sizeThread_50300, sizeThread_50302, sizeThread_50302, sizeThread_50302, sizeThread_50302, sizeThread_50302
#elif LUA_VERSION_NUM == 504
  sizeThread_50400, sizeThread_50401, sizeThread_50402, sizeThread_50403, sizeThread_50403
#else
#error unsupported Lua version
#endif
};



static void unsupported(lua_State* L)
{
  lua_pushliteral(L, "getsize does not support this Lua (minor) version");
  lua_error(L);
}


GetSizeVTable* compat_init(lua_State* L)
{
  GetSizeVTable* vtable = lua_newuserdata(L, sizeof(*vtable));
  char* endptr = NULL;
  long minor = strtol(LUA_RELEASE+sizeof(LUA_VERSION), &endptr, 10);
  if (minor < 0 || *endptr != '\0')
    unsupported(L);
#define DEFINE_FUNC(_func, _array) \
  do { \
    if ((size_t)minor >= sizeof((_array))/sizeof(*(_array)) || (_array)[minor] == 0) \
      unsupported(L); \
    vtable->_func = (_array)[minor]; \
  } while (0)

  DEFINE_FUNC(getArg, getArgFuncs);
  DEFINE_FUNC(sizeBoolean, booleanSizeFuncs);
  DEFINE_FUNC(sizeNumber, numberSizeFuncs);
  DEFINE_FUNC(sizeString, stringSizeFuncs);
  DEFINE_FUNC(sizeFunction, functionSizeFuncs);
  DEFINE_FUNC(tableNode, tableNodeFuncs);
  DEFINE_FUNC(sizeTable, tableSizeFuncs);
  DEFINE_FUNC(sizeUserdata, userdataSizeFuncs);
  DEFINE_FUNC(sizeThread, threadSizeFuncs);
#undef DEFINE_FUNC
  return vtable;
}

