/*
Copyright 2014 Adam Grandquist

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

#ifndef _REQL_EXPR_LUA
#define _REQL_EXPR_LUA

static int _reql_lua_expr(lua_State *L);
static int _reql_lua_get_opts(lua_State *L);
static int _reql_lua_is_instance(lua_State *L);
static _ReQL_Op_t *_reql_from_lua(lua_State *L, const int idx, long nesting_depth);
static void _reql_to_lua(lua_State *L, _ReQL_Op_t *query);

static int _reql_lua_intsp(lua_State *L);
static int _reql_lua_kved(lua_State *L);

static int _reql_lua_intspallargs(lua_State *L);
static int _reql_lua_reqlqueryprinter__init(lua_State *L);
static int _reql_lua_reqlqueryprinter_print_query(lua_State *L);
static int _reql_lua_reqlqueryprinter_compose_term(lua_State *L);
static int _reql_lua_reqlqueryprinter_join_tree(lua_State *L);
static int _reql_lua_ast(lua_State *L);
static int _reql_lua___call(lua_State *L);
static int _reql_lua___index(lua_State *L);
static void _reql_lua_class(lua_State *L, const char *name, const int parent, const int base);

#endif
