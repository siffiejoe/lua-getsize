#include <lua.h>


#if LUA_VERSION_NUM == 502
#include "compat.h"
#define LUA_CORE
#include "lua5.2/4/lobject.h"
#include "lua5.2/lstate.h"


void* tableNode_50204(void const* t) {
  TValue const* h = t;
  return hvalue(h)->node;
}


size_t sizeTable_50204(void const* t, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = hvalue((TValue const*)t);
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * *narr +
         sizeof(Node) * *nrec;
}

#endif

