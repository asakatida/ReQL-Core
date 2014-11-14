/**
 * @author Adam Grandquist
 */

#include <lua.h>

#include "ReQL.h"

#ifndef _REQL_EXPR_LUA
#define _REQL_EXPR_LUA

static int _reql_lua_expr(lua_State *L);
static int _reql_lua_get_opts(lua_State *L);
static int _reql_lua_is_instance(lua_State *L);
static _ReQL_Op_t *_reql_from_lua(lua_State *L, const int idx);
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
