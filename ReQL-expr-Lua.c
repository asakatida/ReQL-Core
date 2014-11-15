/**
 * @author Adam Grandquist
 */

#include <lauxlib.h>
#include <lualib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ReQL-ast-Lua.h"

#include "ReQL-expr-Lua.h"

static int _reql_lua_expr(lua_State *L) {
  lua_settop(L, 3);

  const long nesting_depth = luaL_optlong(L, 3, 20) - 1;

  if (nesting_depth <= 0) {
    return luaL_error(L, "Nesting depth limit exceeded");
  }

  switch (lua_type(L, 2)) {
    case LUA_TFUNCTION: {
      lua_pushcfunction(L, _reql_lua_func);
      lua_pushnil(L);
      lua_pushvalue(L, 2);
      lua_call(L, 2, 1);
      break;
    }
    case LUA_TTABLE: {
      lua_pushcfunction(L, _reql_lua_is_instance);
      lua_pushvalue(L, 2);
      lua_pushliteral(L, "ReQLOp");
      lua_call(L, 2, 1);
      const int is_reql = lua_toboolean(L, 4);
      lua_pop(L, 1);
      if (is_reql) {
        lua_pushvalue(L, 2);
        break;
      }

      char array = 1;
      int table_len = 0;

      lua_pushnil(L);
      while (lua_next(L, 2)) {
        ++table_len;
        switch (lua_type(L, 4)) {
          case LUA_TSTRING: {
            array = 0;
          }
          case LUA_TNUMBER: {
            lua_pushcfunction(L, _reql_lua_expr);
            lua_pushvalue(L, 1);
            lua_pushvalue(L, 5);
            lua_pushnumber(L, nesting_depth);
            lua_call(L, 3, 1);
            lua_pushvalue(L, 8);
            lua_insert(L, 5);
            lua_settable(L, 2);
            break;
          }
          default:
            return luaL_error(L, "Invalid JSON key type");
        }
        lua_pop(L, 1);
      }

      if (array) {
        for (int i=1; i<=table_len; ++i) {
          lua_pushnumber(L, i);
          lua_getfield(L, 2);
          if (lua_isnil(L, 4)) {
            array = 0;
          }
          lua_pop(L, 2);
        }
      }

      if (array) {
        lua_rawlen(L, 2);
        const int arr_len = lua_tointeger(L, 4);
        lua_pop(L, 1);
        lua_pushcfunction(L, _reql_lua_make_array);
        lua_pushnil(L);
        for (int i=1; i<=arr_len; ++i) {
          lua_rawgeti(L, 2, i);
        }
        lua_call(L, arr_len + 1, 1);
      } else {
        lua_pushcfunction(L, _reql_lua_make_obj);
        lua_pushvalue(L, 2);
        lua_call(L, 1, 1);
      }
      break;
    }
    default: {
      lua_pushcfunction(L, _reql_lua_datum);
      lua_pushvalue(L, 2);
      lua_call(L, 1, 1);
    }
  }

  return 1;
}

static int _reql_lua_is_instance(lua_State *L) {
  const int argn = lua_gettop(L);
  const int type_table = lua_istable(L, 1);

  int is = 0;

  for (int i=2; i<=argn; ++i) {
    if (!strcmp(luaL_typename(L, 1), lua_tostring(L, i))) {
      is = 1;
      break;
    }

    if (type_table) {
      lua_getfield(L, 1, "__class");
      while (!lua_isnil(L, argn + 1)) {
        lua_getfield(L, argn + 1, "__name");
        is = lua_compare(L, argn + 2, i, LUA_OPEQ);

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
  const long table_len = lua_tonumber(L, 2);
  lua_pop(L, 1);

  lua_createtable(L, table_len, table_len);
  for (long i=1; i<=table_len; ++i) {
    if (i > 1) {
      lua_pushliteral(L, ", ");
      lua_setfield(L, 2);
    }
    lua_pushnumber(L, i);
    lua_getfield(L, 1);
    lua_setfield(L, 2);
  }
  return 1;
}

static int _reql_lua_kved(lua_State *L) {
  lua_settop(L, 1);
  lua_rawlen(L, 1);
  const long table_len = lua_tonumber(L, 2);
  lua_pop(L, 1);

  lua_createtable(L, table_len, table_len);

  lua_pushnil(L);
  while (lua_next(L, 1)) {
    lua_pushvalue(L, 3);
    lua_pushliteral(L, " = ");
    lua_pushvalue(L, 4);
    lua_setfield(L, 2);
    lua_setfield(L, 2);
    lua_setfield(L, 2);
    lua_pop(L, 1);
  }

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_pushvalue(L, 2);
  lua_call(L, 1, 1);

  lua_pushliteral(L, "{");
  lua_pushliteral(L, "}");
  lua_setfield(L, 2);
  lua_setfield(L, 2);

  return 1;
}

static int _reql_lua_intspallargs(lua_State *L) {
  lua_settop(L, 2);

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_createtable(L, 2, 2);

  lua_pushcfunction(L, _reql_lua_intsp);
  lua_pushvalue(L, 1);
  lua_call(L, 1, 1);

  lua_pushcfunction(L, _reql_lua_kved);
  lua_pushvalue(L, 1);
  lua_call(L, 1, 1);

  lua_setfield(L, 3);
  lua_setfield(L, 3);

  lua_call(L, 2, 1);

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
  lua_rawlen(L);
  const long table_len = lua_tonumber(L, 4);
  lua_pop(L, 1);

  lua_createtable(L, table_len, table_len);

  for (int i=1; i<=table_len; ++i) {
    lua_pushnumber(L, i);
    lua_pushcfunction(L, _reql_lua_compose_term);
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
  lua_setfield(L, 2);
  lua_setfield(L, 2);
  return 1;
}

static int _reql_lua_join_tree(lua_State *L) {
  lua_settop(L, 2);

  lua_rawlen(L, 2);
  const long table_len = lua_tonumber(L, 3);

  long str_len = table_len;

  char *str = malloc(sizeof(char) * str_len);

  for (long i=1; i<=table_len; ++i) {
    lua_getfield(L, 2, i);
    if (lua_istable(L, 3)) {
      lua_rawlen(L, 3);
    }
    const char *term = lua_tostring(L, 3);
    strcat(str, term);
    lua_pop(L, 1);
  }

  lua_pushlstring(str, str_len);

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

static _ReQL_Op_t *_reql_from_lua(lua_State *L, const int idx) {
  switch (lua_type(L, idx)) {
    case LUA_TBOOLEAN: {
      return _reql_expr_bool(lua_toboolean(L, idx));
    }
    case LUA_TFUNCTION: {
      return _reql_lua_func(L);
    }
    case LUA_TNIL: {
      return _reql_expr_null();
    }
    case LUA_TNUMBER: {
      return _reql_expr_number(lua_tonumber(L, idx));
    }
    case LUA_TSTRING: {
      return _reql_expr_string(lua_tostring(L, idx), 0);
    }
    case LUA_TTABLE: {
      lua_pushcfunction(L, _reql_lua_is_instance);
      lua_pushvalue(L, idx);
      lua_pushliteral(L, "ReQLOp");
      lua_call(L, 2, 1);
      const char is_reql = lua_toboolean(L, -1);
      lua_pop(L, 1);
      if (is_reql) {
        return NULL;
      }
      char array = 1;
      lua_pushnil(L);
      while (lua_next(L, idx)) {
        switch (lua_type(L, -2)) {
          case LUA_TSTRING:
            array = 0;
          case LUA_TNUMBER:
            break;
          default:
            luaL_error(L, "Invalid JSON key type");
            return NULL;
        }
        lua_pop(L, 1);
      }
      _ReQL_Op_t *obj;
      lua_pushnil(L);
      if (array) {
        obj = _reql_expr_array();
        while (lua_next(L, idx)) {
          _reql_array_append(obj, _reql_from_lua(L, -1));
          lua_pop(L, 1);
        }
      } else {
        obj = _reql_expr_object();
        while (lua_next(L, idx)) {
          _reql_object_add(obj, _reql_from_lua(L, -2), _reql_from_lua(L, -1));
          lua_pop(L, 1);
        }
      }
      return obj;
    }
    default : {
      luaL_error(L, "Unknown Lua type");
      return NULL;
    }
  }
}

static void _reql_to_lua(lua_State *L, _ReQL_Op_t *query) {
  lua_pushnil(L);
}
