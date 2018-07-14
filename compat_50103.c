#include <lua.h>


#if LUA_VERSION_NUM == 501
#include "compat.h"
#define LUA_CORE
#include "lua5.1/lstate.h"
#include "lua5.1/lobject.h"
#include "lua5.1/lfunc.h"
#include "lua5.1/lstring.h"


void* getArg_50103(lua_State* L, int n) {
  return L->base + n - 1;
}


int getType_50103(void const* v) {
  TValue const* o = v;
  return ttype(o);
}


size_t sizeString_50103(void const* s) {
  TValue const* v = s;
  return sizestring(tsvalue(v));
}


void* tableNode_50103(void const* t) {
  TValue const* h = t;
  return hvalue(h)->node;
}


size_t sizeTable_50103(void const* t, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = hvalue((TValue const*)t);
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * *narr +
         sizeof(Node) * *nrec;
}


size_t sizeUserdata_50103(void const* u) {
  TValue const* v = u;
  return sizeudata(uvalue(v));
}


size_t sizeThread_50103(void const* v) {
  lua_State const* th = thvalue((TValue const*)v);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
                             sizeof(CallInfo) * th->size_ci;
}

#endif

