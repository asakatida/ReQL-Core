/*
Copyright 2015 Adam Grandquist

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
 */
/**
 * @author Adam Grandquist
 * @copyright Apache
 */

#include "./Lua/connection.hpp"

#include "./reql/core.hpp"

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

extern int
reql_lua_connect(lua_State *L) {
  lua_settop(L, 3);

  ReQL_Conn_t *conn = lua_newuserdata(L, sizeof(ReQL_Conn_t));

  reql_conn_init(conn);
  ReQL_Byte msg[500];

  if (reql_conn_connect(conn, msg, 500) != 0) {
    lua_pop(L, 1);
    return 0;
  }

  return 1;
}
