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

#include "./Lua/expr.h"

static ReQL_Obj_t *
reql_lua_alloc_term(lua_State *L) {
  return lua_newuserdata(L, sizeof(ReQL_Obj_t));
}

extern ReQL_Obj_t *
reql_lua_new_array(lua_State *L, uint32_t size) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  lua_createtable(L, 1, 1);
  lua_pushliteral(L, "_arr");
  ReQL_Obj_t **arr = lua_newuserdata(L, sizeof(ReQL_Obj_t *) * size);
  lua_settable(L, -3);
  lua_setmetatable(L, -2);
  reql_array_init(obj, arr, size);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_bool(lua_State *L, const int idx) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_bool_init(obj, lua_toboolean(L, idx));
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_datum(lua_State *L, ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_ast_datum(obj, arg);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_make_array(lua_State *L, ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_ast_make_array(obj, arg);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_make_obj(lua_State *L, ReQL_Obj_t *arg) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_ast_make_obj(obj, arg);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_null(lua_State *L) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_null_init(obj);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_number(lua_State *L, const int idx) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  reql_number_init(obj, lua_tonumber(L, idx));
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_object(lua_State *L, uint32_t size) {
  ReQL_Obj_t *obj = reql_lua_alloc_term(L);
  lua_createtable(L, 1, 1);
  lua_pushliteral(L, "_pair");
  ReQL_Pair_t *pair = lua_newuserdata(L, sizeof(ReQL_Pair_t) * size);
  reql_object_init(obj, pair, size);
  lua_settable(L, -3);
  lua_setmetatable(L, -2);
  return obj;
}

extern ReQL_Obj_t *
reql_lua_new_string(lua_State *L, const int idx) {
  size_t len;
  ReQL_Byte *str = (ReQL_Byte *)lua_tolstring(L, idx, &len);

  if (len > UINT32_MAX) {
    return NULL;
  }

  ReQL_Obj_t *obj = reql_lua_alloc_term(L);

  reql_string_init(obj, str, str, (ReQL_Size)len);

  return obj;
}
