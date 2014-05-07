#!/usr/bin/lua

local N = 1024*128

local maj, min = assert( _VERSION:match( "(%d)%.(%d)$" ) )
package.cpath = "./?-"..maj..min..".so;"..package.cpath

local loadstring = loadstring or load
local newproxy = newproxy
if not newproxy then
  local ok, np = pcall( require, "newproxy" )
  if ok then newproxy = np end
end

local function create( n, f, ... )
  local t = {}
  for i = 1, n do
    t[ i ] = f( ... )
  end
  return t
end

local function create_strings( n, len )
  local t = {}
  local maxlen = #tostring( n )
  assert( len > maxlen )
  local fmt = "%"..len.."s"
  for i = 1, n do
    t[ i ] = string.format( fmt, i )
  end
  return t
end

local function create_arrays( n, i )
  local s = ''
  if i >= 1 then
    s = '""' .. string.rep( ', ""', i-1 )
  end
  local code = "return { " .. s .. " }"
  local f = assert( loadstring( code ) )
  return create( n, f )
end

local function create_records( n, i )
  local x = {}
  for j = 1, i do
    x[ j ] = '["'..j..'"]=true'
  end
  local code = "return { "..table.concat( x, ", " ).. " }"
  local f = assert( loadstring( code ) )
  return create( n, f )
end

local function create_closures( n, i )
  local f
  if i < 1 then
    f = assert( loadstring( "return function() return end" ) )
  else
    local locs = {}
    for j = 1, i do
      locs[ j ] = "_"..j
    end
    locs = table.concat( locs, ", " )
    local code = [[
local ]] .. locs .. [[ = ...
return function() return ]] .. locs .. [[ end ]]
    f = assert( loadstring( code ) )
  end
  return create( n, f )
end

local function create_threads( n )
  local function f() end
  return create( n, coroutine.create, f )
end

local function create_udatas( n )
  return create( n, newproxy )
end


local function measure( s, f, ... )
  local gc = collectgarbage
  gc( "stop" )
  local t = f( N, ... )
  gc( "restart" )
  gc() gc()
  local full = gc( "count" )
  for i = 1, #t do
    t[ i ] = false
  end
  gc() gc()
  local clean = gc( "count" )
  print( s, (full - clean)*1024/N, "bytes" )
end


measure( "array(0):", create_arrays, 0 )
measure( "array(1):", create_arrays, 1 )
measure( "array(2):", create_arrays, 2 )
measure( "array(3):", create_arrays, 3 )
measure( "array(4):", create_arrays, 4 )
measure( "array(5):", create_arrays, 5 )
measure( "array(10):", create_arrays, 10 )
measure( "record(0):", create_records, 0 )
measure( "record(1):", create_records, 1 )
measure( "record(2):", create_records, 2 )
measure( "record(3):", create_records, 3 )
measure( "record(4):", create_records, 4 )
measure( "record(5):", create_records, 5 )
measure( "record(10):", create_records, 10 )
measure( "closure(0):", create_closures, 0 )
measure( "closure(1):", create_closures, 1 )
measure( "closure(2):", create_closures, 2 )
measure( "closure(3):", create_closures, 3 )
measure( "closure(4):", create_closures, 4 )
measure( "closure(5):", create_closures, 5 )
measure( "closure(10):", create_closures, 10 )
measure( "thread: ", create_threads )
if newproxy then
  measure( "udata:  ", create_udatas )
end
measure( "string(10):", create_strings, 10 )
measure( "string(15):", create_strings, 15 )
measure( "string(20):", create_strings, 20 )
measure( "string(25):", create_strings, 25 )
measure( "string(30):", create_strings, 30 )
measure( "string(35):", create_strings, 35 )
measure( "string(40):", create_strings, 40 )
measure( "string(45):", create_strings, 45 )
measure( "string(50):", create_strings, 50 )
measure( "string(60):", create_strings, 60 )

