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

#include "ReQL-expr-Lua.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _reql_lua_expr(lua_State *L) {
  lua_settop(L, 3);

  const long nesting_depth = luaL_optlong(L, 3, 20);

  _reql_to_lua(L, _reql_from_lua(L, 2, nesting_depth));

  return 1;
}

int _reql_lua_is_instance(lua_State *L) {
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

int _reql_lua_intsp(lua_State *L) {
  lua_settop(L, 1);

  const unsigned int table_len = (unsigned int)lua_rawlen(L, 1);

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

int _reql_lua_kved(lua_State *L) {
  lua_settop(L, 1);

  const unsigned int table_len = (unsigned int)lua_rawlen(L, 1);

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

int _reql_lua_intspallargs(lua_State *L) {
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

int _reql_lua_reqlqueryprinter__init(lua_State *L) {
  lua_settop(L, 3);
  lua_setfield(L, 1, "frames");
  lua_setfield(L, 1, "term");
  return 1;
}

int _reql_lua_print_query(lua_State *L) {
  lua_settop(L, 1);
  return 1;
}

int _reql_lua_compose_term(lua_State *L) {
  lua_settop(L, 2);
  if (!lua_istable(L, 2)) {
    lua_tostring(L, 2);
    return 1;
  }

  lua_getfield(L, 2, "args");

  const unsigned int table_len = (unsigned int)lua_rawlen(L, 3);

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

int _reql_lua___call(lua_State *L) {
  lua_createtable(L, 0, 0);
  lua_createtable(L, 2, 2);
  return 1;
}

int _reql_lua_join_tree(lua_State *L) {
  lua_settop(L, 2);

  const unsigned int table_len = (unsigned int)lua_rawlen(L, 2);

  long i;

  for (i=1; i<=table_len; ++i) {
  }

  return 1;
}

int _reql_lua_ast(lua_State *L) {
  return 1;
}

int _reql_lua___index(lua_State *L) {
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

void _reql_lua_class(lua_State *L, const char *name, const int parent, const int base) {
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

_ReQL_Op _reql_from_lua(lua_State *L, const int idx, long nesting_depth) {
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
      return _reql_expr_string((char *)lua_tolstring(L, idx, &len), len);
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
        _ReQL_Op arr = _reql_json_c_array(NULL, table_len);
        int i;
        for (i=1; i<=table_len; ++i) {
          lua_rawgeti(L, 2, i);
          _reql_c_array_insert(arr, _reql_from_lua(L, water_mark + 2, nesting_depth), i);
          lua_pop(L, 1);
        }
        return _reql_expr(arr);
      }
      _ReQL_Op obj = _reql_json_object(NULL);
      while (lua_next(L, idx)) {
        _reql_object_add(obj, _reql_from_lua(L, water_mark + 1, nesting_depth), _reql_from_lua(L, water_mark + 2, nesting_depth));
        lua_pop(L, 1);
      }
      return _reql_expr(obj);
    }
  }
  luaL_error(L, "Unknown Lua type %i", lua_type(L, idx));
  return NULL;
}

void _reql_to_lua(lua_State *L, _ReQL_Op query) {
  switch (query->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;

      if (_reql_to_c_array(query, &size)) {
        lua_pushnil(L);
        break;
      }

      int trunc_size = (int)size;
      int i;

      lua_createtable(L, trunc_size, trunc_size);
      int table_idx = lua_gettop(L);

      for (i=0; i<trunc_size; ++i) {
        _reql_to_lua(L, _reql_c_array_index(query, i));
        lua_rawseti(L, table_idx, i);
      }
      break;
    }
    case _REQL_R_ARRAY: {
      _ReQL_Op iter = _reql_to_array(query);
      if (!iter) {
        lua_pushnil(L);
        break;
      }

      _ReQL_Op elem;
      int i = 0;

      lua_newtable(L);
      int table_idx = lua_gettop(L);

      while (_reql_array_next(&iter, &elem)) {
        ++i;
        _reql_to_lua(L, elem);
        lua_rawseti(L, table_idx, i);
      }
      break;
    }
    case _REQL_R_BOOL: {
      int value;
      if (_reql_to_bool(query, &value)) {
        lua_pushnil(L);
        break;
      }
      lua_pushboolean(L, value);
      break;
    }
    case _REQL_R_JSON: {
      lua_pushnil(L);
      break;
    }
    case _REQL_R_NULL: {
      lua_pushnil(L);
      break;
    }
    case _REQL_R_NUM: {
      double value;
      if (_reql_to_number(query, &value)) {
        lua_pushnil(L);
        break;
      }
      lua_pushnumber(L, query->num);
      break;
    }
    case _REQL_R_OBJECT: {
      _ReQL_Op iter = _reql_to_object(query);
      if (!iter) {
        lua_pushnil(L);
        break;
      }

      _ReQL_Op key;
      _ReQL_Op val;

      lua_newtable(L);
      int table_idx = lua_gettop(L);

      while (_reql_object_next(&iter, &key, &val)) {
        _reql_to_lua(L, key);
        _reql_to_lua(L, val);
        lua_settable(L, table_idx);
      }
      break;
    }
    case _REQL_R_STR: {
      unsigned long str_len;
      char *str;
      if (_reql_to_string(query, &str, &str_len)) {
        lua_pushnil(L);
        break;
      }
      lua_pushlstring(L, str, str_len);
      break;
    }
  }
}

int _reql_lua_connect(lua_State *L) {
  lua_settop(L, 3);
  switch (lua_type(L, 2)) {
    case LUA_TFUNCTION:
      lua_createtable(L, 0, 0);
      lua_insert(L, 2);
      break;
    case LUA_TSTRING:
      lua_createtable(L, 1, 1);
      lua_pushliteral(L, "host");
      lua_rawset(L, 2);
      lua_insert(L, 2);
      break;
    default:
      break;
  }

  _ReQL_Conn_t *conn = lua_newuserdata(L, sizeof(_ReQL_Conn_t));

  conn = _reql_new_connection(conn);
  char *msg;

  if (_reql_connect(conn, &msg)) {
    return 0;
  }

  lua_rawset(L, 1);

  return 1;
}
