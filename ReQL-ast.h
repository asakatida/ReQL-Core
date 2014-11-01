/**
 * @author Adam Grandquist
 */

#include "ReQL-expr.h"

#ifndef _REQL_AST_H
#define _REQL_AST_H

/* start generated constants */
const int _REQL_VERSION = 0x5f75e83e;
const int _REQL_PROTOCOL = 0x7e6970c7;
enum {
  _REQL_CONTINUE = 2,
  _REQL_NOREPLY_WAIT = 4,
  _REQL_START = 1,
  _REQL_STOP = 3
};
enum {
  _REQL_CLIENT_ERROR = 16,
  _REQL_COMPILE_ERROR = 17,
  _REQL_RUNTIME_ERROR = 18,
  _REQL_SUCCESS_ATOM = 1,
  _REQL_SUCCESS_FEED = 5,
  _REQL_SUCCESS_PARTIAL = 3,
  _REQL_SUCCESS_SEQUENCE = 2,
  _REQL_WAIT_COMPLETE = 4
};
enum {
  _REQL_R_ARRAY = 5,
  _REQL_R_BOOL = 2,
  _REQL_R_JSON = 7,
  _REQL_R_NULL = 1,
  _REQL_R_NUM = 3,
  _REQL_R_OBJECT = 6,
  _REQL_R_STR = 4
};
enum {
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
  _REQL_DEFAULT_ = 92,
  _REQL_DELETE_ = 54,
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
  _REQL_NOT_ = 23,
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
  _REQL_UNION_ = 44,
  _REQL_UPCASE = 141,
  _REQL_UPDATE = 53,
  _REQL_UUID = 169,
  _REQL_VAR = 10,
  _REQL_WEDNESDAY = 109,
  _REQL_WITHOUT = 34,
  _REQL_WITH_FIELDS = 96,
  _REQL_YEAR = 128,
  _REQL_ZIP = 72
};
/* end generated constants */

/* start generated header */

/**
 */
_ReQL_Op_t *_reql_add(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_all(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_any(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_append(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_april(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_args(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_asc(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_august(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_avg(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_between(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_binary(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_bracket(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_branch(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_changes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_change_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_circle(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_coerce_to(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_concat_map(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_contains(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_count(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_date(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_datum(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day_of_week(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_day_of_year(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_db_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_december(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_default_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_delete_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_delete_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_desc(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_difference(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_distance(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_distinct(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_div(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_downcase(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_during(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_epoch_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_eq(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_eq_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_error(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_february(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_fill(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_filter(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_for_each(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_friday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_func(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_funcall(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ge(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_geojson(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_all(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_field(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_intersecting(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_get_nearest(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_group(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_gt(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_has_fields(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_hours(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_http(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_implicit_var(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_includes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_indexes_of(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_rename(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_status(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_index_wait(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_info(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_inner_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_insert(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_insert_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_intersects(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_in_timezone(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_iso8601(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_is_empty(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_january(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_javascript(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_json(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_july(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_june(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_keys(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_le(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_limit(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_line(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_literal(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_lt(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_make_array(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_make_obj(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_map(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_march(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_match(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_max(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_may(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_merge(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_min(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_minutes(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_mod(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_monday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_month(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_mul(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ne(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_not_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_november(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_now(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_nth(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_object(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_october(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_order_by(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_outer_join(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_pluck(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_point(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_polygon(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_polygon_sub(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_prepend(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_random(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_range(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_reduce(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_replace(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sample(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_saturday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_seconds(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_september(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_difference(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_insert(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_intersection(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_set_union(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_skip(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_slice(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_splice_at(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_split(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sub(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sum(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sunday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_sync(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_create(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_drop(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_table_list(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_thursday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_timezone(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_time_of_day(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_epoch_time(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_geojson(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_iso8601(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_to_json_string(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_tuesday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_type_of(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_ungroup(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_union_(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_upcase(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_update(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_uuid(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_var(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_wednesday(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_without(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_with_fields(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_year(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);

/**
 */
_ReQL_Op_t *_reql_zip(_ReQL_Op_t *args, _ReQL_Op_t *kwargs);
/* end generated header */

#endif
