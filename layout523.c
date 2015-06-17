#include <stddef.h>
#include <lua.h>

/* use older lobject.h (layout of Table objects changed between
 * Lua 5.2.3 and 5.2.4!)
 */
#if LUA_VERSION_NUM == 502
#  include "lua5.2/lobject523.h"

Node *tableNodeB(Table const *h)
{
  return h->node;
}

size_t sizeTableB(Table const *h, Node const *dummynode)
{
  return sizeof(Table) + sizeof(TValue) * h->sizearray +
         sizeof(Node) * (h->node == dummynode ? 0 : sizenode(h));
}

#endif

