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

#ifndef REQL_REQL_TYPES_H_
#define REQL_REQL_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <pthread.h>

typedef uint8_t ReQL_Byte;
typedef uint32_t ReQL_Size;
typedef uint64_t ReQL_Token;

typedef struct ReQL_Array_s ReQL_Array_t;
typedef char ReQL_Bool_t;
typedef double ReQL_Num_t;
typedef struct ReQL_Obj_s ReQL_Obj_t;
typedef struct ReQL_ReQL_s ReQL_ReQL_t;
typedef struct ReQL_String_s ReQL_String_t;

typedef struct ReQL_Any_s ReQL_Any_t;
typedef struct ReQL_Pair_s ReQL_Pair_t;

typedef struct ReQL_Array_Iter_s ReQL_Array_Iter_t;
typedef struct ReQL_Object_Iter_s ReQL_Object_Iter_t;

typedef struct ReQL_Conn_s ReQL_Conn_t;
typedef struct ReQL_Cur_s ReQL_Cur_t;
typedef struct ReQL_Parse_s ReQL_Parse_t;

typedef int(*ReQL_Each_Function)(void *, void *);
typedef void(*ReQL_End_Function)(void *);
typedef void(*ReQL_Error_Function)(void *, void *);

/**
 * @brief JSON types.
 */
enum ReQL_Datum_e {
  REQL_R_REQL,
  REQL_R_ARRAY = 5,
  REQL_R_BOOL = 2,
  REQL_R_JSON = 7,
  REQL_R_NULL = 1,
  REQL_R_NUM = 3,
  REQL_R_OBJECT = 6,
  REQL_R_STR = 4
};
typedef enum ReQL_Datum_e ReQL_Datum_t;

enum ReQL_Term_e {
  REQL_ADD = 24,
  REQL_AND = 67,
  REQL_APPEND = 29,
  REQL_APRIL = 117,
  REQL_ARGS = 154,
  REQL_ASC = 73,
  REQL_AUGUST = 121,
  REQL_AVG = 146,
  REQL_BETWEEN = 182,
  REQL_BETWEEN_DEPRECATED = 36,
  REQL_BINARY = 155,
  REQL_BRACKET = 170,
  REQL_BRANCH = 65,
  REQL_CEIL = 184,
  REQL_CHANGES = 152,
  REQL_CHANGE_AT = 84,
  REQL_CIRCLE = 165,
  REQL_COERCE_TO = 51,
  REQL_CONCAT_MAP = 40,
  REQL_CONFIG = 174,
  REQL_CONTAINS = 93,
  REQL_COUNT = 43,
  REQL_DATE = 106,
  REQL_DATUM = 1,
  REQL_DAY = 130,
  REQL_DAY_OF_WEEK = 131,
  REQL_DAY_OF_YEAR = 132,
  REQL_DB = 14,
  REQL_DB_CREATE = 57,
  REQL_DB_DROP = 58,
  REQL_DB_LIST = 59,
  REQL_DECEMBER = 125,
  REQL_DEFAULT = 92,
  REQL_DELETE = 54,
  REQL_DELETE_AT = 83,
  REQL_DESC = 74,
  REQL_DIFFERENCE = 95,
  REQL_DISTANCE = 162,
  REQL_DISTINCT = 42,
  REQL_DIV = 27,
  REQL_DOWNCASE = 142,
  REQL_DURING = 105,
  REQL_EPOCH_TIME = 101,
  REQL_EQ = 17,
  REQL_EQ_JOIN = 50,
  REQL_ERROR = 12,
  REQL_FEBRUARY = 115,
  REQL_FILL = 167,
  REQL_FILTER = 39,
  REQL_FLOOR = 183,
  REQL_FOR_EACH = 68,
  REQL_FRIDAY = 111,
  REQL_FUNC = 69,
  REQL_FUNCALL = 64,
  REQL_GE = 22,
  REQL_GEOJSON = 157,
  REQL_GET = 16,
  REQL_GET_ALL = 78,
  REQL_GET_FIELD = 31,
  REQL_GET_INTERSECTING = 166,
  REQL_GET_NEAREST = 168,
  REQL_GROUP = 144,
  REQL_GT = 21,
  REQL_HAS_FIELDS = 32,
  REQL_HOURS = 133,
  REQL_HTTP = 153,
  REQL_IMPLICIT_VAR = 13,
  REQL_INCLUDES = 164,
  REQL_INDEX_CREATE = 75,
  REQL_INDEX_DROP = 76,
  REQL_INDEX_LIST = 77,
  REQL_INDEX_RENAME = 156,
  REQL_INDEX_STATUS = 139,
  REQL_INDEX_WAIT = 140,
  REQL_INFO = 79,
  REQL_INNER_JOIN = 48,
  REQL_INSERT = 56,
  REQL_INSERT_AT = 82,
  REQL_INTERSECTS = 163,
  REQL_IN_TIMEZONE = 104,
  REQL_ISO8601 = 99,
  REQL_IS_EMPTY = 86,
  REQL_JANUARY = 114,
  REQL_JAVASCRIPT = 11,
  REQL_JSON = 98,
  REQL_JULY = 120,
  REQL_JUNE = 119,
  REQL_KEYS = 94,
  REQL_LE = 20,
  REQL_LIMIT = 71,
  REQL_LINE = 160,
  REQL_LITERAL = 137,
  REQL_LT = 19,
  REQL_MAKE_ARRAY = 2,
  REQL_MAKE_OBJ = 3,
  REQL_MAP = 38,
  REQL_MARCH = 116,
  REQL_MATCH = 97,
  REQL_MAX = 148,
  REQL_MAXVAL = 181,
  REQL_MAY = 118,
  REQL_MERGE = 35,
  REQL_MIN = 147,
  REQL_MINUTES = 134,
  REQL_MINVAL = 180,
  REQL_MOD = 28,
  REQL_MONDAY = 107,
  REQL_MONTH = 129,
  REQL_MUL = 26,
  REQL_NE = 18,
  REQL_NOT = 23,
  REQL_NOVEMBER = 124,
  REQL_NOW = 103,
  REQL_NTH = 45,
  REQL_OBJECT = 143,
  REQL_OCTOBER = 123,
  REQL_OFFSETS_OF = 87,
  REQL_OR = 66,
  REQL_ORDER_BY = 41,
  REQL_OUTER_JOIN = 49,
  REQL_PLUCK = 33,
  REQL_POINT = 159,
  REQL_POLYGON = 161,
  REQL_POLYGON_SUB = 171,
  REQL_PREPEND = 80,
  REQL_RANDOM = 151,
  REQL_RANGE = 173,
  REQL_REBALANCE = 179,
  REQL_RECONFIGURE = 176,
  REQL_REDUCE = 37,
  REQL_REPLACE = 55,
  REQL_ROUND = 185,
  REQL_SAMPLE = 81,
  REQL_SATURDAY = 112,
  REQL_SECONDS = 135,
  REQL_SEPTEMBER = 122,
  REQL_SET_DIFFERENCE = 91,
  REQL_SET_INSERT = 88,
  REQL_SET_INTERSECTION = 89,
  REQL_SET_UNION = 90,
  REQL_SKIP = 70,
  REQL_SLICE = 30,
  REQL_SPLICE_AT = 85,
  REQL_SPLIT = 149,
  REQL_STATUS = 175,
  REQL_SUB = 25,
  REQL_SUM = 145,
  REQL_SUNDAY = 113,
  REQL_SYNC = 138,
  REQL_TABLE = 15,
  REQL_TABLE_CREATE = 60,
  REQL_TABLE_DROP = 61,
  REQL_TABLE_LIST = 62,
  REQL_THURSDAY = 110,
  REQL_TIME = 136,
  REQL_TIMEZONE = 127,
  REQL_TIME_OF_DAY = 126,
  REQL_TO_EPOCH_TIME = 102,
  REQL_TO_GEOJSON = 158,
  REQL_TO_ISO8601 = 100,
  REQL_TO_JSON_STRING = 172,
  REQL_TUESDAY = 108,
  REQL_TYPE_OF = 52,
  REQL_UNGROUP = 150,
  REQL_UNION = 44,
  REQL_UPCASE = 141,
  REQL_UPDATE = 53,
  REQL_UUID = 169,
  REQL_VALUES = 186,
  REQL_VAR = 10,
  REQL_WAIT = 177,
  REQL_WEDNESDAY = 109,
  REQL_WITHOUT = 34,
  REQL_WITH_FIELDS = 96,
  REQL_YEAR = 128,
  REQL_ZIP = 72
};
typedef enum ReQL_Term_e ReQL_Term_t;

enum ReQL_Response_e {
  REQL_CLIENT_ERROR = 16,
  REQL_COMPILE_ERROR = 17,
  REQL_RUNTIME_ERROR = 18,
  REQL_SUCCESS_ATOM = 1,
  REQL_SUCCESS_PARTIAL = 3,
  REQL_SUCCESS_SEQUENCE = 2,
  REQL_WAIT_COMPLETE = 4
};
typedef enum ReQL_Response_e ReQL_Response_t;

struct ReQL_Array_s {
  ReQL_Size (*size)(void *);
  ReQL_Any_t *(*get)(void *, ReQL_Size);
  void *data;
};

struct ReQL_Obj_s {
  ReQL_Size (*size)(void *);
  ReQL_Pair_t *(*get)(void *, ReQL_Size);
  void *data;
};

struct ReQL_ReQL_s {
  ReQL_Term_t tt;
  ReQL_Array_t (*args)(void *);
  ReQL_Obj_t (*kwargs)(void *);
  void *data;
};

struct ReQL_String_s {
  ReQL_Size (*size)(void *);
  ReQL_Byte *(*buffer)(void *);
  void *data;
};

struct ReQL_Any_s {
  ReQL_Datum_t dt;
  union {
    ReQL_Array_t array;
    ReQL_Bool_t boolean;
    ReQL_Num_t num;
    ReQL_Obj_t object;
    ReQL_ReQL_t reql;
    ReQL_String_t string;
  } any;
};

/**
 * @brief A single key and associated value for objects.
 */
struct ReQL_Pair_s {
  ReQL_Size key_size;
  ReQL_Byte *key;
  ReQL_Any_t val;
};

/**
 * @brief Iterator for easy enumeration.
 *
 * Supports arrays.
 */
struct ReQL_Array_Iter_s {
  ReQL_Size idx;
  const ReQL_Array_t *obj;
};

/**
 * @brief Iterator for easy enumeration.
 *
 * Supports objects.
 */
struct ReQL_Object_Iter_s {
  ReQL_Size idx;
  const ReQL_Obj_t *obj;
};

struct ReQL_Parse_s {
  void *data;
  int(*start_parse)(ReQL_Parse_t *);
  int(*end_parse)(ReQL_Parse_t *);
  int(*start_object)(ReQL_Parse_t *);
  int(*start_key_value)(ReQL_Parse_t *);
  int(*end_key_value)(ReQL_Parse_t *, const char *, size_t);
  int(*end_object)(ReQL_Parse_t *);
  int(*start_array)(ReQL_Parse_t *);
  int(*start_element)(ReQL_Parse_t *);
  int(*end_element)(ReQL_Parse_t *);
  int(*end_array)(ReQL_Parse_t *);
  int(*add_null)(ReQL_Parse_t *);
  int(*add_bool)(ReQL_Parse_t *, char);
  int(*add_number)(ReQL_Parse_t *, double);
  int(*add_string)(ReQL_Parse_t *, const char *, size_t);
  void(*error)(ReQL_Parse_t *);
};

struct ReQL_Cur_s {
  struct {
    pthread_mutex_t *mutex;
    pthread_t thread;
  } condition;
  ReQL_Token token;
  void *response;
  int r_type;
  ReQL_Parse_t(*get_parser)();
  ReQL_Conn_t *conn;
  ReQL_Cur_t *next;
  ReQL_Cur_t *prev;
  struct {
    void *data[3];
    ReQL_Each_Function each;
    ReQL_End_Function end;
    ReQL_Error_Function error;
  } cb;
};

/**
 * @brief connection object
 */
struct ReQL_Conn_s {
  ReQL_Size auth_size;
  int socket;

  ReQL_Token max_token;

  ReQL_Token timeout_s;
  ReQL_Token timeout_us;

  void *port;
  char *addr;

  char *auth;
  ReQL_Cur_t *cursors;

  struct {
    pthread_mutex_t *mutex;
    pthread_t thread;
  } condition;
};

#ifdef __cplusplus
}
#endif

#endif  // REQL_REQL_TYPES_H_
