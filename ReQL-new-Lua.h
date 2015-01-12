/*
Copyright 2014-2015 Adam Grandquist

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

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

#include "ReQL.h"

#ifndef _REQL_NEW_LUA
#define _REQL_NEW_LUA

extern _ReQL_Op
_reql_lua_new_array(lua_State *L, uint32_t size);
extern _ReQL_Op
_reql_lua_new_bool(lua_State *L, const int idx);
extern _ReQL_Op
_reql_lua_new_datum(lua_State *L, _ReQL_Op arg);
extern _ReQL_Op
_reql_lua_new_make_array(lua_State *L, _ReQL_Op arg);
extern _ReQL_Op
_reql_lua_new_make_obj(lua_State *L, _ReQL_Op arg);
extern _ReQL_Op
_reql_lua_new_null(lua_State *L);
extern _ReQL_Op
_reql_lua_new_number(lua_State *L, const int idx);
extern _ReQL_Op
_reql_lua_new_object(lua_State *L, uint32_t idx);
extern _ReQL_Op
_reql_lua_new_string(lua_State *L, const int idx);

#endif
