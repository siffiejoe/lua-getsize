#ifndef GETSIZE_COMPAT_H_
#define GETSIZE_COMPAT_H_

#include <lua.h>


typedef /* TValue */ void* (*GetArgFunction)(lua_State*, int);
typedef size_t (*BooleanSizeFunction)(/* TValue */ void const*);
typedef size_t (*NumberSizeFunction)(/* TValue */ void const*);
typedef size_t (*StringSizeFunction)(/* TValue */ void const*);
typedef size_t (*FunctionSizeFunction)(/* TValue */ void const*, int, int);
typedef /* Node */ void* (*TableNodeFunction)(/* TValue */ void const*);
typedef size_t (*TableSizeFunction)(/* TValue */ void const*,
                                    /* Node */ void const*,
                                    unsigned*,
                                    unsigned*);
typedef size_t (*UserdataSizeFunction)(/* TValue */ void const*);
typedef size_t (*ThreadSizeFunction)(/* TValue */ void const*);

typedef struct {
  GetArgFunction getArg;
  BooleanSizeFunction sizeBoolean;
  NumberSizeFunction sizeNumber;
  StringSizeFunction sizeString;
  FunctionSizeFunction sizeFunction;
  TableNodeFunction tableNode;
  TableSizeFunction sizeTable;
  UserdataSizeFunction sizeUserdata;
  ThreadSizeFunction sizeThread;
} GetSizeVTable;


GetSizeVTable* compat_init(lua_State* L);


#endif /* GETSIZE_COMPAT_H_ */

