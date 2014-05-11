#                             lua-getsize                            #

This is a bundle of Matthew Wild's lua-getsize module with the
necessary bits from Lua's sources (5.1 and 5.2) included to make it
build as a standalone rock.

"lua-getsize" is MIT/X11-licensed. Lua's source code is available
under the MIT license.

    http://code.matthewwild.co.uk/lua-getsize/
    http://www.lua.org/

At the moment the code in this repository includes the following
changes to the original lua-getsize code:

*   ported to Lua 5.2 (and Lua 5.3work2)
*   fixed sizes of tables with empty hash part
*   include sizes of upvalues for Lua closures
*   report a userdata's full memory not just its payload

