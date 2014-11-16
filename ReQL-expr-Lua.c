/**
 * @author Adam Grandquist
 */

#include "ReQL-expr-Lua.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int _reql_lua_expr(lua_State *L) {
  lua_settop(L, 3);

  const long nesting_depth = luaL_optlong(L, 3, 20);

  _reql_to_lua(L, _reql_from_lua(L, 2, nesting_depth));

  return 1;
}

static int _reql_lua_is_instance(lua_State *L) {
  const int argn = lua_gettop(L);
  const int type_table = lua_istable(L, 1);

  int is = 0;

  int i;
  for (i=2; i<=argn; ++i) {
    const char *instance_name = lua_tostring(L, i);
    if (!strcmp(luaL_typename(L, 1), instance_name)) {
      is = 1;
      break;
    }

    if (type_table) {
      lua_getfield(L, 1, "__class");
      while (!lua_isnil(L, argn + 1)) {
        lua_getfield(L, argn + 1, "__name");
        is = !strcmp(lua_tostring(L, argn + 2), instance_name);

        lua_pop(L, 1);

        if (is) {
          break;
        }

        lua_getfield(L, argn + 1, "__parent");
        lua_replace(L, argn + 1);
      }

      lua_pop(L, 1);

      if (is) {
        break;
      }
    }
  }

  lua_pushboolean(L, is);
  return 1;
}

static int _reql_lua_get_opts(lua_State *L) {
  const int argn = lua_gettop(L);

  if (lua_istable(L, argn)) {
    lua_pushcfunction(L, _reql_lua_is_instance);
    lua_pushvalue(L, argn);
    lua_pushliteral(L, "ReQLOp");
    lua_call(L, 2, 1);
    const int not_reql = !lua_toboolean(L, argn + 1);
    lua_pop(L, 1);

    if (not_reql) {
      lua_insert(L, 1);
      return argn;
    }
  }

  lua_pushnil(L);
  lua_insert(L, 1);

  return argn + 1;
}

static int _reql_lua_intsp(lua_State *L) {
  lua_settop(L, 1);
  lua_rawlen(L, 1);
  const unsigned int table_len = lua_tounsigned(L, 2);
  lua_pop(L, 1);

  lua_createtable(L, table_len * 2, table_len * 2);
  unsigned int i, j=1;
  for (i=1; i<=table_len; ++i) {
    if (i > 1) {
      lua_pushliteral(L, ", ");
      lua_rawseti(L, 2, j++);
    }
    lua_rawgeti(L, 1, i);
    lua_rawseti(L, 2, j++);
  }
  return 1;
}

static int _reql_lua_kved(lua_State *L) {
  lua_settop(L, 1);
  lua_rawlen(L, 1);
  const unsigned int table_len = lua_tounsigned(L, 2);
  lua_pop(L, 1);

  lua_createtable(L, table_len * 3, table_len * 3);

  unsigned int i=1;

  lua_pushnil(L);
  while (lua_next(L, 1)) {
    lua_pushvalue(L, 4);
    lua_pushliteral(L, " = ");
    lua_pushvalue(L, 3);
    lua_rawseti(L, 2, i++);
    lua_rawseti(L, 2, i++);
    lua_rawseti(L, 2, i++);
    lua_pop(L, 1);
  }

  lua_createtable(L, 3, 3);

  lua_pushliteral(L, "}");

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_pushvalue(L, 2);
  lua_call(L, 1, 1);

  lua_pushliteral(L, "{");

  lua_rawseti(L, 3, 1);
  lua_rawseti(L, 3, 2);
  lua_rawseti(L, 3, 3);

  return 1;
}

static int _reql_lua_intspallargs(lua_State *L) {
  lua_settop(L, 2);

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_createtable(L, 2, 2);

  lua_pushcfunction(L, _reql_lua_kved);
  lua_pushvalue(L, 2);
  lua_call(L, 1, 1);

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_pushvalue(L, 1);
  lua_call(L, 1, 1);

  lua_rawseti(L, 3, 1);
  lua_rawseti(L, 3, 2);

  lua_call(L, 1, 1);

  return 1;
}

static int _reql_lua_reqlqueryprinter__init(lua_State *L) {
  lua_settop(L, 3);
  lua_setfield(L, 1, "frames");
  lua_setfield(L, 1, "term");
  return 1;
}

static int _reql_lua_print_query(lua_State *L) {
  lua_settop(L, 1);
  return 1;
}

static int _reql_lua_compose_term(lua_State *L) {
  lua_settop(L, 2);
  if (!lua_istable(L, 2)) {
    lua_tostring(L, 2);
    return 1;
  }

  lua_getfield(L, 2, "args");
  lua_rawlen(L, 3);
  const unsigned int table_len = lua_tounsigned(L, 4);
  lua_pop(L, 1);

  lua_createtable(L, table_len, table_len);

  int i;

  for (i=1; i<=table_len; ++i) {
  }

  lua_pushnil(L);
  while (lua_next(L, 3)) {
    lua_pop(L, 1);
  }

  return 1;
}

static int _reql_lua___call(lua_State *L) {
  lua_createtable(L, 0, 0);
  lua_createtable(L, 2, 2);
  return 1;
}

static int _reql_lua_join_tree(lua_State *L) {
  lua_settop(L, 2);

  lua_rawlen(L, 2);
  const double table_len = lua_tonumber(L, 3);

  long i;

  for (i=1; i<=table_len; ++i) {
  }

  return 1;
}

static int _reql_lua_ast(lua_State *L) {
  return 1;
}

static int _reql_lua___index(lua_State *L) {
  lua_getfield(L, 1, "__base");
  lua_pushvalue(L, 2);
  lua_rawget(L, 2);
  if (lua_isnil(L, 3)) {
    lua_getfield(L, 1, "__parent");
    lua_pushvalue(L, 2);
    lua_rawget(L, 1);
  }
  return 1;
}

static void _reql_lua_class(lua_State *L, const char *name, const int parent, const int base) {
  lua_createtable(L, 4, 0);
  lua_pushliteral(L, "__name");
  lua_pushlstring(L, name, 1);
  lua_pushliteral(L, "__init");
  if (lua_isfunction(L, base)) {
    lua_pushvalue(L, base);
  } else {
    lua_getfield(L, base, "__init");
    lua_pushliteral(L, "__init");
    lua_pushnil(L);
    lua_setfield(L, base, "__init");
  }
}

static _ReQL_Op_t *_reql_from_lua(lua_State *L, const int idx, long nesting_depth) {
  if (nesting_depth <= 0) {
    luaL_error(L, "Nesting depth limit exceeded");
    return NULL;
  }

  switch (lua_type(L, idx)) {
    case LUA_TBOOLEAN: {
      return _reql_expr_bool(lua_toboolean(L, idx));
    }
    case LUA_TFUNCTION: {
      return NULL;
    }
    case LUA_TNIL: {
      return _reql_expr_null();
    }
    case LUA_TNUMBER: {
      return _reql_expr_number(lua_tonumber(L, idx));
    }
    case LUA_TSTRING: {
      size_t len;
      return _reql_expr_string(lua_tolstring(L, idx, &len), len);
    }
    case LUA_TTABLE: {
      const int water_mark = lua_gettop(L);
      lua_pushcfunction(L, _reql_lua_is_instance);
      lua_pushvalue(L, idx);
      lua_pushliteral(L, "ReQLOp");
      lua_call(L, 2, 1);
      const int is_reql = lua_toboolean(L, water_mark + 1);
      lua_pop(L, 1);
      if (is_reql) {
        break;
      }

      char array = 1;
      int table_len = 0;

      lua_pushnil(L);
      while (lua_next(L, idx)) {
        ++table_len;
        switch (lua_type(L, water_mark + 1)) {
          case LUA_TSTRING: {
            array = 0;
          }
          case LUA_TNUMBER: {
            break;
          }
          default: {
            luaL_error(L, "Invalid JSON key type");
            return NULL;
          }
        }
        lua_pop(L, 1);
      }

      int i;
      for (i=1; i<=table_len && array; ++i) {
        lua_rawgeti(L, idx, i);
        if (lua_isnil(L, water_mark + 1)) {
          array = 0;
        }
        lua_pop(L, 1);
      }

      --nesting_depth;

      if (array) {
        _ReQL_Op_t *arr = _reql_expr_array();
        int i;
        for (i=1; i<=table_len; ++i) {
          lua_rawgeti(L, 2, i);
          _reql_array_append(arr, _reql_from_lua(L, water_mark + 2, nesting_depth));
          lua_pop(L, 0);
        }
        return _reql_make_array(arr, NULL);
      }
      _ReQL_Op_t *obj = _reql_expr_object();
      while (lua_next(L, idx)) {
        _reql_object_add(obj, _reql_from_lua(L, water_mark + 1, nesting_depth), _reql_from_lua(L, water_mark + 2, nesting_depth));
        lua_pop(L, 1);
      }
      return _reql_make_obj(NULL, obj);
    }
  }
  luaL_error(L, "Unknown Lua type %i", lua_type(L, idx));
  return NULL;
}

static void _reql_to_lua(lua_State *L, _ReQL_Op_t *query) {
  lua_pushnil(L);
}
