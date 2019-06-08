#include <lua.h>


#if LUA_VERSION_NUM == 502
#include "compat.h"
#define LUA_CORE
#include "lua5.2/lstate.h"
#include "lua5.2/lobject.h"
#include "lua5.2/lfunc.h"
#include "lua5.2/lstring.h"


void* getArg_50200(lua_State* L, int n) {
  return L->ci->func+n;
}


size_t sizeNumber_50200(void const* n) {
  (void)n;
  return sizeof(lua_Number);
}


size_t sizeString_50200(void const* s) {
  TValue const* v = s;
  return sizestring(tsvalue(v));
}


static size_t sizeProto(Proto const* p) {
  return sizeof(Proto) + sizeof(Instruction) * p->sizecode +
                         sizeof(Proto*) * p->sizep +
                         sizeof(TValue) * p->sizek +
                         sizeof(int) * p->sizelineinfo +
                         sizeof(LocVar) * p->sizelocvars +
                         sizeof(*(p->upvalues)) * p->sizeupvalues;
}

size_t sizeFunction_50200(void const* v, int count_protos, int count_upvalues) {
  TValue const* o = v;
  switch (ttype(o)) {
    case LUA_TLCL: /* Lua closure */
    {
      Closure *cl = clvalue(o);
      return sizeLclosure(cl->l.nupvalues) +
             (count_upvalues ? cl->l.nupvalues * sizeof(UpVal) : 0) +
             (count_protos ? sizeProto(cl->l.p) : 0);
    }
    case LUA_TLCF: /* light C function */
      return sizeof(lua_CFunction);
    case LUA_TCCL: /* C closure */
      return sizeCclosure(clvalue(o)->c.nupvalues);
  }
  return 0;
}


void* tableNode_50200(void const* t) {
  TValue const* h = t;
  return hvalue(h)->node;
}


size_t sizeTable_50200(void const* t, void const* n,
                       unsigned* narr, unsigned* nrec) {
  Table const* h = hvalue((TValue const*)t);
  Node const* dummynode = n;
  *narr = h->sizearray;
  *nrec = (h->node == dummynode ? 0 : sizenode(h));
  return sizeof(Table) + sizeof(TValue) * *narr +
         sizeof(Node) * *nrec;
}


size_t sizeUserdata_50200(void const* u) {
  TValue const* v = u;
  return sizeudata(uvalue(v));
}


size_t sizeThread_50200(void const* v) {
  lua_State const* th = thvalue((TValue const*)v);
  CallInfo* ci = th->base_ci.next;
  size_t cisize = 0;
  for(; ci != NULL; ci = ci->next)
    cisize += sizeof(CallInfo);
  return sizeof(lua_State) + sizeof(TValue) * th->stacksize + cisize;
}

#endif

