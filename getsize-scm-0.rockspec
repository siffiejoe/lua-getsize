package="getsize"
version="scm-0"

source = {
  url = "${SRCURL}",
}

description = {
  summary = "Calculates the size of a Lua object.",
  detailed = [[
    Calculates the size of a Lua object by poking in the Lua
    internals. Works for PUC-Rio Lua 5.1 and 5.2, but _not_
    for LuaJIT.
  ]],
  homepage = "http://code.matthewwild.co.uk/lua-getsize/",
  license = "MIT/X11, MIT",
  maintainer = "Philipp Janda <siffiejoe@gmx.net>",
}

dependencies = {
  -- Uses Lua internals. Includes support for Lua 5.1 *and* Lua 5.2.
  "lua >= 5.1, < 5.3"
}

build = {
  type = "builtin",
  modules = {
    getsize = {
      sources = {
        "getsize_multi.c"
      },
      incdirs = {
        "dummy"
      }
    }
  }
}

