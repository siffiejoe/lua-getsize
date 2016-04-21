#include <stddef.h>
#include <lua.h>

/* use older lobject.h (layout of Table objects changed between
 * Lua 5.2.3 and 5.2.4!)
 */
#if LUA_VERSION_NUM == 502
#  include "lua5.2/lobject523.h"

Node *tableNode_520_523(Table const *h)
{
  return h->node;
}

size_t sizeTable_520_523(Table const *h, Node const *dummynode,
                         unsigned* narr, unsigned* nrec)
{
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * h->sizearray +
         sizeof(Node) * (h->node == dummynode ? 0 : sizenode(h));
}

#endif

