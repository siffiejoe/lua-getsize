#include <lua.h>


#if LUA_VERSION_NUM == 501
#define LUA_CORE
#include "lua5.1/lstate.h"
#include "lua5.1/lobject.h"
#include "lua5.1/lfunc.h"
#include "lua5.1/lstring.h"


void* getArg_50103(lua_State* L, int n)
{
  return L->base + n - 1;
}


size_t sizeBoolean_50103(void const* o)
{
  (void)o;
  return sizeof(int);
}


size_t sizeNumber_50103(void const* o)
{
  (void)o;
  return sizeof(lua_Number);
}


size_t sizeString_50103(void const* o)
{
  TValue const* v = o;
  return sizestring(tsvalue(v));
}


static size_t sizeProto(Proto const* p)
{
  return sizeof(Proto) + sizeof(Instruction) * p->sizecode +
                         sizeof(Proto*) * p->sizep +
                         sizeof(TValue) * p->sizek +
                         sizeof(int) * p->sizelineinfo +
                         sizeof(LocVar) * p->sizelocvars +
                         sizeof(*(p->upvalues)) * p->sizeupvalues;
}

size_t sizeFunction_50103(void const* o, int count_protos, int count_upvalues)
{
  TValue const* v = o;
  Closure *cl = clvalue(v);
  if (cl->c.isC)
    return sizeCclosure(cl->c.nupvalues);
  else
    return sizeLclosure(cl->l.nupvalues) +
           (count_upvalues ? cl->l.nupvalues * sizeof(UpVal) : 0) +
           (count_protos ? sizeProto(cl->l.p) : 0);
}


void* tableNode_50103(void const* o)
{
  TValue const* h = o;
  return hvalue(h)->node;
}


size_t sizeTable_50103(void const* o, void const* n,
                       unsigned* narr, unsigned* nrec)
{
  Table const* h = hvalue((TValue const*)o);
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * *narr +
         sizeof(Node) * *nrec;
}


size_t sizeUserdata_50103(void const* o)
{
  TValue const* v = o;
  return sizeudata(uvalue(v));
}


size_t sizeThread_50103(void const* o)
{
  lua_State const* th = thvalue((TValue const*)o);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
                             sizeof(CallInfo) * th->size_ci;
}

#endif

