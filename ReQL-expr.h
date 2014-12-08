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

#ifndef _REQL_EXPR_H
#define _REQL_EXPR_H

typedef enum {
  _REQL_C_ARRAY,
  _REQL_R_ARRAY = 5,
  _REQL_R_BOOL = 2,
  _REQL_R_JSON = 7,
  _REQL_R_NULL = 1,
  _REQL_R_NUM = 3,
  _REQL_R_OBJECT = 6,
  _REQL_R_STR = 4
} _ReQL_Datum_t;

typedef enum {
  _REQL_ADD = 24,
  _REQL_ALL = 67,
  _REQL_ANY = 66,
  _REQL_APPEND = 29,
  _REQL_APRIL = 117,
  _REQL_ARGS = 154,
  _REQL_ASC = 73,
  _REQL_AUGUST = 121,
  _REQL_AVG = 146,
  _REQL_BETWEEN = 36,
  _REQL_BINARY = 155,
  _REQL_BRACKET = 170,
  _REQL_BRANCH = 65,
  _REQL_CHANGES = 152,
  _REQL_CHANGE_AT = 84,
  _REQL_CIRCLE = 165,
  _REQL_COERCE_TO = 51,
  _REQL_CONCAT_MAP = 40,
  _REQL_CONTAINS = 93,
  _REQL_COUNT = 43,
  _REQL_DATE = 106,
  _REQL_DATUM = 1,
  _REQL_DAY = 130,
  _REQL_DAY_OF_WEEK = 131,
  _REQL_DAY_OF_YEAR = 132,
  _REQL_DB = 14,
  _REQL_DB_CREATE = 57,
  _REQL_DB_DROP = 58,
  _REQL_DB_LIST = 59,
  _REQL_DECEMBER = 125,
  _REQL_DEFAULT = 92,
  _REQL_DELETE = 54,
  _REQL_DELETE_AT = 83,
  _REQL_DESC = 74,
  _REQL_DIFFERENCE = 95,
  _REQL_DISTANCE = 162,
  _REQL_DISTINCT = 42,
  _REQL_DIV = 27,
  _REQL_DOWNCASE = 142,
  _REQL_DURING = 105,
  _REQL_EPOCH_TIME = 101,
  _REQL_EQ = 17,
  _REQL_EQ_JOIN = 50,
  _REQL_ERROR = 12,
  _REQL_FEBRUARY = 115,
  _REQL_FILL = 167,
  _REQL_FILTER = 39,
  _REQL_FOR_EACH = 68,
  _REQL_FRIDAY = 111,
  _REQL_FUNC = 69,
  _REQL_FUNCALL = 64,
  _REQL_GE = 22,
  _REQL_GEOJSON = 157,
  _REQL_GET = 16,
  _REQL_GET_ALL = 78,
  _REQL_GET_FIELD = 31,
  _REQL_GET_INTERSECTING = 166,
  _REQL_GET_NEAREST = 168,
  _REQL_GROUP = 144,
  _REQL_GT = 21,
  _REQL_HAS_FIELDS = 32,
  _REQL_HOURS = 133,
  _REQL_HTTP = 153,
  _REQL_IMPLICIT_VAR = 13,
  _REQL_INCLUDES = 164,
  _REQL_INDEXES_OF = 87,
  _REQL_INDEX_CREATE = 75,
  _REQL_INDEX_DROP = 76,
  _REQL_INDEX_LIST = 77,
  _REQL_INDEX_RENAME = 156,
  _REQL_INDEX_STATUS = 139,
  _REQL_INDEX_WAIT = 140,
  _REQL_INFO = 79,
  _REQL_INNER_JOIN = 48,
  _REQL_INSERT = 56,
  _REQL_INSERT_AT = 82,
  _REQL_INTERSECTS = 163,
  _REQL_IN_TIMEZONE = 104,
  _REQL_ISO8601 = 99,
  _REQL_IS_EMPTY = 86,
  _REQL_JANUARY = 114,
  _REQL_JAVASCRIPT = 11,
  _REQL_JSON = 98,
  _REQL_JULY = 120,
  _REQL_JUNE = 119,
  _REQL_KEYS = 94,
  _REQL_LE = 20,
  _REQL_LIMIT = 71,
  _REQL_LINE = 160,
  _REQL_LITERAL = 137,
  _REQL_LT = 19,
  _REQL_MAKE_ARRAY = 2,
  _REQL_MAKE_OBJ = 3,
  _REQL_MAP = 38,
  _REQL_MARCH = 116,
  _REQL_MATCH = 97,
  _REQL_MAX = 148,
  _REQL_MAY = 118,
  _REQL_MERGE = 35,
  _REQL_MIN = 147,
  _REQL_MINUTES = 134,
  _REQL_MOD = 28,
  _REQL_MONDAY = 107,
  _REQL_MONTH = 129,
  _REQL_MUL = 26,
  _REQL_NE = 18,
  _REQL_NOT = 23,
  _REQL_NOVEMBER = 124,
  _REQL_NOW = 103,
  _REQL_NTH = 45,
  _REQL_OBJECT = 143,
  _REQL_OCTOBER = 123,
  _REQL_ORDER_BY = 41,
  _REQL_OUTER_JOIN = 49,
  _REQL_PLUCK = 33,
  _REQL_POINT = 159,
  _REQL_POLYGON = 161,
  _REQL_POLYGON_SUB = 171,
  _REQL_PREPEND = 80,
  _REQL_RANDOM = 151,
  _REQL_RANGE = 173,
  _REQL_REDUCE = 37,
  _REQL_REPLACE = 55,
  _REQL_SAMPLE = 81,
  _REQL_SATURDAY = 112,
  _REQL_SECONDS = 135,
  _REQL_SEPTEMBER = 122,
  _REQL_SET_DIFFERENCE = 91,
  _REQL_SET_INSERT = 88,
  _REQL_SET_INTERSECTION = 89,
  _REQL_SET_UNION = 90,
  _REQL_SKIP = 70,
  _REQL_SLICE = 30,
  _REQL_SPLICE_AT = 85,
  _REQL_SPLIT = 149,
  _REQL_SUB = 25,
  _REQL_SUM = 145,
  _REQL_SUNDAY = 113,
  _REQL_SYNC = 138,
  _REQL_TABLE = 15,
  _REQL_TABLE_CREATE = 60,
  _REQL_TABLE_DROP = 61,
  _REQL_TABLE_LIST = 62,
  _REQL_THURSDAY = 110,
  _REQL_TIME = 136,
  _REQL_TIMEZONE = 127,
  _REQL_TIME_OF_DAY = 126,
  _REQL_TO_EPOCH_TIME = 102,
  _REQL_TO_GEOJSON = 158,
  _REQL_TO_ISO8601 = 100,
  _REQL_TO_JSON_STRING = 172,
  _REQL_TUESDAY = 108,
  _REQL_TYPE_OF = 52,
  _REQL_UNGROUP = 150,
  _REQL_UNION = 44,
  _REQL_UPCASE = 141,
  _REQL_UPDATE = 53,
  _REQL_UUID = 169,
  _REQL_VAR = 10,
  _REQL_WEDNESDAY = 109,
  _REQL_WITHOUT = 34,
  _REQL_WITH_FIELDS = 96,
  _REQL_YEAR = 128,
  _REQL_ZIP = 72
} _ReQL_Term_t;

struct _ReQL_Op_s {
  _ReQL_Term_t tt;
  _ReQL_Datum_t dt;

  unsigned long str_len;
  char *str;

  double num;

  struct _ReQL_Op_s *key;
  struct _ReQL_Op_s *val;
  struct _ReQL_Op_s *args;
  struct _ReQL_Op_s *kwargs;
  struct _ReQL_Op_s *next;
  struct _ReQL_Op_s *prev;
};
typedef struct _ReQL_Op_s _ReQL_Op_t;
typedef _ReQL_Op_t* _ReQL_Op;

_ReQL_Op _reql_expr_bool(int val);
int _reql_to_bool(_ReQL_Op obj, int *val);
_ReQL_Op _reql_expr_null();
int _reql_is_null(_ReQL_Op obj);
_ReQL_Op _reql_expr_number(double val);
int _reql_to_number(_ReQL_Op obj, double *val);
_ReQL_Op _reql_expr_string(const char *val, unsigned long str_len);
int _reql_to_string(_ReQL_Op obj, const char **val, unsigned long *str_len);

_ReQL_Op _reql_expr_c_array(unsigned long size);
int _reql_to_c_array(_ReQL_Op obj, unsigned long *size);
void _reql_c_array_insert(_ReQL_Op obj, _ReQL_Op val, unsigned long idx);
_ReQL_Op _reql_c_array_index(_ReQL_Op obj, unsigned long idx);

_ReQL_Op _reql_expr_array();
_ReQL_Op _reql_to_array(_ReQL_Op obj);
void _reql_array_append(_ReQL_Op arr, _ReQL_Op val);
int _reql_array_next(_ReQL_Op *arr, _ReQL_Op *val);
_ReQL_Op _reql_array_pop(_ReQL_Op obj);
_ReQL_Op _reql_array_last(_ReQL_Op obj);

_ReQL_Op _reql_expr_object();
_ReQL_Op _reql_to_object(_ReQL_Op obj);
void _reql_object_add(_ReQL_Op obj, _ReQL_Op key, _ReQL_Op val);
int _reql_object_next(_ReQL_Op *obj, _ReQL_Op *key, _ReQL_Op *val);

int _reql_op_eq(_ReQL_Op l, _ReQL_Op r);
void _reql_expr_free(_ReQL_Op obj);
_ReQL_Op _reql_expr_copy(_ReQL_Op obj);

_ReQL_Op _reql_build(_ReQL_Op query);

#endif
