#!/bin/bash -e

# simple bash script to download and build multiple different lua
# versions, and compile the getsize module for each of them

LUA_VERSIONS=( 5.1.4 5.1.5 5.2.2 5.2.3 5.2.4 5.3.0 5.3.1 5.3.2 )
PLATFORM=linux

log() {
  echo -n -e "\033[36m" >&2
  echo -n "# $@" >&2
  echo -e "\033[0m" >&2
}

x() {
  log "$@"
  "$@"
}

build() {
  x gcc -Wall -O2 -fpic -Idummy -I"tests/lua-${v}" -shared -o "tests/lua-${v}/getsize.so" \
    getsize_multi.c layout523.c layout530.c layout531.c
}

for v in "${LUA_VERSIONS[@]}"; do
  x wget -q -nc http://www.lua.org/ftp/lua-"${v}".tar.gz
  x tar xzf lua-"${v}".tar.gz
  log "(cd lua-${v} && make $PLATFORM)"
  (cd lua-"${v}" && make "$PLATFORM" && cp src/lua src/lua.h src/lauxlib.h src/luaconf.h .)
  (cd .. && build "$v")
done

