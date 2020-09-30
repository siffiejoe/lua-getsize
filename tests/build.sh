#!/bin/bash -e

# simple bash script to download and build multiple different lua
# versions, and compile the getsize module for each of them

LUA_VERSIONS=( 5.1.4 5.1.5 5.2.2 5.2.3 5.2.4 5.3.0 5.3.1 5.3.2 5.3.3 5.3.4 5.3.5 5.3.6 5.4.0 5.4.1 )
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
  x gcc -Wall -Wextra -O2 -fpic -I"tests/lua-$1" -shared -o "tests/lua-$1/getsize.so" \
    getsize.c compat.c compat_*.c
}

for v in "${LUA_VERSIONS[@]}"; do
  x wget -q -nc http://www.lua.org/ftp/lua-"${v}".tar.gz
  x tar xzf lua-"${v}".tar.gz
  log "(cd lua-${v} && make $PLATFORM)"
  (cd lua-"${v}" && make "$PLATFORM" && cp src/lua src/lua.h src/lauxlib.h src/luaconf.h .)
  (cd .. && build "$v")
done

