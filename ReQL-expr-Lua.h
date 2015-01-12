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

#include "ReQL-new-Lua.h"

#ifndef _REQL_EXPR_LUA
#define _REQL_EXPR_LUA

#if LUA_VERSION_NUM < 502
#define lua_rawlen lua_objlen
#endif

extern int
_reql_lua_expr(lua_State *L);
extern int
_reql_lua_is_instance(lua_State *L);
extern _ReQL_Op
_reql_from_lua(lua_State *L, const int idx, long nesting_depth);
extern void
_reql_to_lua(lua_State *L, _ReQL_Op query);

extern int
_reql_lua_intsp(lua_State *L);
extern int
_reql_lua_kved(lua_State *L);

extern int
_reql_lua_intspallargs(lua_State *L);
extern int
_reql_lua_reqlqueryprinter__init(lua_State *L);
extern int
_reql_lua_reqlqueryprinter_print_query(lua_State *L);
extern int
_reql_lua_reqlqueryprinter_compose_term(lua_State *L);
extern int
_reql_lua_reqlqueryprinter_join_tree(lua_State *L);
extern int
_reql_lua_ast(lua_State *L);
extern int
_reql_lua___call(lua_State *L);
extern int
_reql_lua___index(lua_State *L);
extern void
_reql_lua_class(lua_State *L, const char *name, const int parent, const int base);

extern int
_reql_lua_connect(lua_State *L);

#endif
