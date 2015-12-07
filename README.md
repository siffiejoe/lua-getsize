#                             lua-getsize                            #

This is a bundle of Matthew Wild's lua-getsize module with the
necessary bits from Lua's sources (5.1, 5.2, and 5.3) included to make
it build as a standalone rock.

lua-getsize is MIT/X11-licensed. Lua's source code is available
under the MIT license.

    http://code.matthewwild.co.uk/lua-getsize/
    http://www.lua.org/

At the moment the code in this repository includes the following
changes to the original lua-getsize code:

*   ported to Lua 5.2 and Lua 5.3
*   fixed sizes of tables with empty hash part
*   report a userdata's full memory not just its payload
*   detect LuaJIT and raise an error
*   additional option argument for counting shared internal objects
    like Lua upvalues and/or proto objects.
    "p" will count proto objects, "P" will _not_ count proto objects
    (the default), "u" will count Lua upvalues (the default), and "U"
    will _not_ count Lua upvalues. You can combine those options.

[![Build Status](https://travis-ci.org/siffiejoe/lua-getsize.svg?branch=master)](https://travis-ci.org/siffiejoe/lua-getsize)

