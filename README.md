[![Build Status](https://travis-ci.org/siffiejoe/lua-getsize.svg?branch=master)](https://travis-ci.org/siffiejoe/lua-getsize)

#                             lua-getsize                            #

This is a bundle of Matthew Wild's lua-getsize module with the
necessary bits from Lua's sources (5.1, 5.2, 5.3, and 5.4) included to
make it build as a standalone rock.

lua-getsize is MIT/X11-licensed. Lua's source code is available
under the MIT license.

    http://code.matthewwild.co.uk/lua-getsize/
    http://www.lua.org/

At the moment the code in this repository includes the following
changes to the original lua-getsize code:

*   ported to Lua 5.2, 5.3 and 5.4
*   fixed sizes of tables with empty hash part
*   report a userdata's full memory not just its payload
*   detect LuaJIT and raise an error
*   additionally report the sizes of a table's array/hash parts
*   additional option argument for counting shared internal objects
    like Lua upvalues and/or proto objects.
    "p" will count proto objects, "P" will _not_ count proto objects
    (the default), "u" will count Lua upvalues (the default), and "U"
    will _not_ count Lua upvalues. You can combine those options.

##                          Getting Started                         ##


This module exports just one function:

```lua
local getsize = require("getsize")
```

Calling this function with a Lua value as argument will return the
size of the value in bytes. For tables it will return the lengths of
array and hash part as additional return values. For functions you can
decide whether you want to include the sizes of the proto object
and/or the upvalues.

```lua
print(getsize(getsize))                    # -> 64
local function f() return getsize end
print(getsize(f))                          # -> 80
print(getsize(f, "uP"))                    # -> 80
print(getsize(f, "up"))                    # -> 264
print(getsize(f, "UP"))                    # -> 40
print(getsize({ 1, 2, 3, x = 4, y = 5 })   # -> 152  3  2
```

