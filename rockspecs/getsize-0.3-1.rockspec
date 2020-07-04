package="getsize"
version="0.3-1"

source = {
  url = "https://github.com/siffiejoe/lua-getsize/archive/v0.3.zip",
  dir = "lua-getsize-0.3",
}

description = {
  summary = "Calculates the size of a Lua object.",
  detailed = [[
    Calculates the size of a Lua object by poking in the Lua
    internals. Works for PUC-Rio Lua 5.1, 5.2, 5.3, and 5.4,
    but _not_ for LuaJIT.
  ]],
  homepage = "http://code.matthewwild.co.uk/lua-getsize/",
  license = "MIT/X11, MIT",
  maintainer = "Philipp Janda <siffiejoe@gmx.net>",
}

dependencies = {
  -- Uses Lua internals. Includes support for Lua 5.1, 5.2, 5.3, and 5.4.
  "lua >= 5.1, < 5.5"
}

build = {
  type = "builtin",
  modules = {
    getsize = {
      sources = {
        "getsize.c",
        "compat.c",
        "compat_50103.c",
        "compat_50200.c",
        "compat_50300.c",
        "compat_50400.c",
        "compat_50204.c",
        "compat_50301.c",
        "compat_50302.c",
      }
    }
  }
}

