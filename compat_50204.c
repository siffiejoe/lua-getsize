#include <lua.h>


#if LUA_VERSION_NUM == 502
#include "compat.h"
#define LUA_CORE
#include "lua5.2/4/lobject.h"


void* tableNode_50204(void const* t) {
  Table const* h = t;
  return h->node;
}


size_t sizeTable_50204(void const* t, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = t;
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * h->sizearray +
         sizeof(Node) * *nrec;
}

#endif

