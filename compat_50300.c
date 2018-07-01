#include <lua.h>


#if LUA_VERSION_NUM == 503
#include "compat.h"
#define LUA_CORE
#include "lua5.3/lstate.h"
#include "lua5.3/lobject.h"
#include "lua5.3/lfunc.h"
#include "lua5.3/lstring.h"


void* getArg_50300(lua_State* L, int n) {
  return L->ci->func+n;
}


size_t sizeString_50300(void const* s) {
  TValue const* v = s;
  return sizestring(tsvalue(v));
}


void* tableNode_50300(void const* t) {
  Table const* h = t;
  return h->node;
}


size_t sizeTable_50300(void const* t, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = t;
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * h->sizearray +
         sizeof(Node) * *nrec;
}


size_t sizeThread_50300(lua_State const* th) {
  CallInfo *ci = th->base_ci.next;
  size_t cisize = 0;
  for (; ci != NULL; ci = ci->next)
    cisize += sizeof(CallInfo);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize + cisize;
}

#endif

