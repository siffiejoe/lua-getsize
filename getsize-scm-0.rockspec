package="getsize"
version="scm-0"

source = {
  url = "git://github.com/siffiejoe/lua-getsize.git",
}

description = {
  summary = "Calculates the size of a Lua object.",
  detailed = [[
    Calculates the size of a Lua object by poking in the Lua
    internals. Works for PUC-Rio Lua 5.1, 5.2, and 5.3, but
    _not_ for LuaJIT.
  ]],
  homepage = "http://code.matthewwild.co.uk/lua-getsize/",
  license = "MIT/X11, MIT",
  maintainer = "Philipp Janda <siffiejoe@gmx.net>",
}

dependencies = {
  -- Uses Lua internals. Includes support for Lua 5.1, 5.2, and 5.3.
  "lua >= 5.1, < 5.4"
}

build = {
  type = "builtin",
  modules = {
    getsize = {
      sources = {
        "getsize_multi.c",
        "layout523.c",
        "layout530.c",
      },
      incdirs = {
        "dummy"
      }
    }
  }
}

