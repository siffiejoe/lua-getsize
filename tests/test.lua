#!/usr/bin/lua

local maj,min = assert( _VERSION:match( "(%d+)%.(%d+)$" ) )
package.cpath = "./?.so;../?-"..maj..min..".so;"..package.cpath
local size = require( "getsize" )
local dummy

local function f1()
  coroutine.yield()
end

local function f2()
  f1()
end

local function f3()
  return
end

local function f4()
  return size
end

local function f5()
  return size, dummy
end

local th = coroutine.create( function() f2() end )
coroutine.resume( th )


print( "nil", size( nil, "V" ), size( nil ) )
print( "2.5", size( 2.5, "V" ), size( 2.5 ) )
print( "300", size( 300, "V" ), size( 300 ) )
print( "true", size( true, "V" ), size( true ) )
print( "false", size( false, "V" ), size( false ) )
print( "{}", size( {} ) )
print( "{ 1 }", size( { 1 } ) )
print( "{ 1, 2 }", size( { 1, 2 } ) )
print( "{ x=1 }", size( { x=1 } ) )
print( "{ x=1, y=2 }", size( { x=1, y=2 } ) )
print( "{ x=1, y=2, z=3 }", size( { x=1, y=2, z=3 } ) )
print( "io.stdout", size( io.stdout ) )
print( "print", size( print, "V" ), size( print ) )
print( "size", size( size ) )
print( "[0 upvalues]", size( f3 ) )
print( "[1 upvalue]", size( f4 ) )
print( "[2 upvalues]", size( f5 ) )
print( "[0 upvalues(U)]", size( f3, "U" ) )
print( "[1 upvalue(U)]", size( f4, "U" ) )
print( "[2 upvalues(U)]", size( f5, "U" ) )
print( "[0 upvalues(p)]", size( f3, "p" ) )
print( "[1 upvalue(p)]", size( f4, "p" ) )
print( "[2 upvalues(p)]", size( f5, "p" ) )
print( "[used thread]", size( th ) )
th = coroutine.create( function() end )
print( "[new thread]", size( th ) )
print( "[30 chars]", size( ("x"):rep( 30 ) ) )
print( "[60 chars]", size( ("y"):rep( 60 ) ) )

