#!/usr/bin/lua

local maj,min = assert( _VERSION:match( "(%d+)%.(%d+)$" ) )
package.cpath = "../?-"..maj..min..".so;"..package.cpath
local size = require( "getsize" )
local dummy

local function f1()
  coroutine.yield()
end

local function f2()
  f1()
end

local th = coroutine.create( function() f2() end )
coroutine.resume( th )


print( "nil", size( nil ) )
print( "2.5", size( 2.5 ) )
print( "300", size( 300 ) )
print( "true", size( true ) )
print( "false", size( false ) )
print( "{}", size( {} ) )
print( "{ 1 }", size( { 1 } ) )
print( "{ 1, 2 }", size( { 1, 2 } ) )
print( "{ x=1 }", size( { x=1 } ) )
print( "{ x=1, y=2 }", size( { x=1, y=2 } ) )
print( "{ x=1, y=2, z=3 }", size( { x=1, y=2, z=3 } ) )
print( "io.stdout", size( io.stdout ) )
print( "print", size( print ) )
print( "size", size( size ) )
print( "[0 upvalues]", size( function() return end ) )
print( "[1 upvalue]", size( function() return size end ) )
print( "[2 upvalues]", size( function() return size, dummy end ) )
print( "[used thread]", size( th ) )
th = coroutine.create( function() end )
print( "[new thread]", size( th ) )
print( "[30 chars]", size( ("x"):rep( 30 ) ) )
print( "[60 chars]", size( ("y"):rep( 60 ) ) )

