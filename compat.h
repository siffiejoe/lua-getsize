#ifndef GETSIZE_COMPAT_H_
#define GETSIZE_COMPAT_H_

#include <lua.h>


typedef /* TValue */ void* (*GetArgFunction)(lua_State*, int);
typedef size_t (*StringSizeFunction)(/* TValue */ void const*);
typedef /* Node */ void* (*TableNodeFunction)(/* Table */ void const*);
typedef size_t (*TableSizeFunction)(/* Table */ void const*,
                                    /* Node */ void const*,
                                    unsigned* narr,
                                    unsigned* nrec);
typedef size_t (*ThreadSizeFunction)(lua_State const* th);

typedef struct {
  GetArgFunction getArg;
  StringSizeFunction sizeString;
  TableNodeFunction tableNode;
  TableSizeFunction sizeTable;
  ThreadSizeFunction sizeThread;
} GetSizeVTable;


GetSizeVTable* compat_init(lua_State* L);


#endif /* GETSIZE_COMPAT_H_ */

