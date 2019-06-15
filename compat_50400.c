#include <lua.h>


#if LUA_VERSION_NUM == 504
#define LUA_CORE
#include "lua5.4/lstate.h"
#include "lua5.4/lobject.h"
#include "lua5.4/lfunc.h"
#include "lua5.4/lstring.h"


void* getArg_50400(lua_State* L, int n) {
  return L->ci->func+n;
}


size_t sizeNumber_50400(void const* o) {
  TValue const* v = o;
  if (ttypetag(v) == LUA_TNUMINT)
    return sizeof(lua_Integer);
  else
    return sizeof(lua_Number);
}


size_t sizeString_50400(void const* o) {
  TValue const* v = o;
  return sizelstring(vslen(v));
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

size_t sizeFunction_50400(void const* o, int count_protos, int count_upvalues) {
  TValue const* v = o;
  switch (ttypetag(v)) {
    case LUA_TLCL: /* Lua closure */
    {
      Closure *cl = clvalue(v);
      return sizeLclosure(cl->l.nupvalues) +
             (count_upvalues ? cl->l.nupvalues * sizeof(UpVal) : 0) +
             (count_protos ? sizeProto(cl->l.p) : 0);
    }
    case LUA_TLCF: /* light C function */
      return sizeof(lua_CFunction);
    case LUA_TCCL: /* C closure */
      return sizeCclosure(clvalue(v)->c.nupvalues);
  }
  return 0;
}


void* tableNode_50400(void const* o) {
  TValue const* h = o;
  return hvalue(h)->node;
}


size_t sizeTable_50400(void const* o, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = hvalue((TValue const*)o);
  Node const* dummynode = n;
  *narr = h->alimit;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * *narr +
         sizeof(Node) * *nrec;
}


size_t sizeUserdata_50400(void const* o) {
  TValue const* v = o;
  return sizeudata(uvalue(v)->nuvalue, uvalue(v)->len);
}


size_t sizeThread_50400(void const* o) {
  lua_State const* th = thvalue((TValue const*)o);
  CallInfo *ci = th->base_ci.next;
  size_t cisize = 0;
  for (; ci != NULL; ci = ci->next)
    cisize += sizeof(CallInfo);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize + cisize;
}

#endif

