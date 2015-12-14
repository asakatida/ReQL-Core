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

#ifndef REQL_REQL_QUERY_HPP_
#define REQL_REQL_QUERY_HPP_

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

namespace _ReQL {

enum Term_t {
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

template <class wrap_t>
std::string
expr(const wrap_t &value) {
  std::ostringstream stream;
  stream << std::boolalpha
         << std::setprecision(std::numeric_limits<double>::digits10 + 1)
         << value;
  return stream.str();
}

template <class vect_t>
struct Array_t : public vect_t {
  Array_t(const vect_t &other) : vect_t(other) {}
  Array_t(vect_t &&other) : vect_t(std::move(other)) {}
};

struct Null_t {};

template <class map_t>
struct Obj_t : public map_t {
  Obj_t(const map_t &value) : map_t(value) {}
  Obj_t(map_t &&value) : map_t(std::move(value)) {}
};

template <class str_t>
struct String_t : public str_t {
  String_t(const str_t &value) : str_t(value) {}
  String_t(str_t &&value) : str_t(std::move(value)) {}
};

enum Query_t {
  REQL_CONTINUE = 2,
  REQL_NOREPLY_WAIT = 4,
  REQL_START = 1,
  REQL_STOP = 3
};

template <class vect_t>
Array_t<vect_t>
make_array(const vect_t &vect) {
  return vect;
}

template <class..._ts>
typename std::enable_if<sizeof...(_ts) >= 2, Array_t<std::tuple<_ts...> > >::type
make_array(_ts...Ts) {
  return std::make_tuple(Ts...);
}

template <class map_t>
Obj_t<map_t>
make_object(const map_t &map) {
  return map;
}

template <class map_t, class query_t>
auto
make_query(const query_t &query, const map_t &kwargs) {
  return make_array(REQL_START, query, make_object(kwargs));
}

template <class query_t>
auto
make_query(const query_t &query) {
  return make_array(REQL_START, query, "{}");
}

static auto
make_query(const Query_t type) {
  return make_array(std::make_tuple(type));
}

template <class args_t, class kwargs_t>
auto
make_reql(Term_t tt, args_t args, kwargs_t kwargs) {
  return make_array(tt, make_array(args), make_object(kwargs));
}

template <class args_t>
auto
make_reql(Term_t tt, args_t args) {
  return make_array(tt, make_array(args));
}

static auto
make_reql(Term_t tt) {
  return make_array(std::make_tuple(tt));
}

template <class str_t>
String_t<str_t>
make_string(const str_t &str) {
  return str;
}

template <class vect_t>
std::ostream &
operator <<(std::ostream &stream, const Array_t<vect_t> &value) {
  stream << '[';
  auto first = true;
  for (auto &&elem : value) {
    if (!first) stream << ',';
    stream << elem;
    first = false;
  }
  return stream << ']';
}

template<std::size_t s, class..._ts>
typename std::enable_if<s == 0, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &) {
  return stream;
}

template<std::size_t s, class..._ts>
typename std::enable_if<s == 1, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &iterable) {
  return stream << std::get<0>(iterable);
}

template<std::size_t s, class..._ts>
typename std::enable_if<s >= 2, std::ostream &>::type
unpack(std::ostream &stream, const std::tuple<_ts...> &iterable) {
  return unpack<s-1, _ts...>(stream, iterable) << ',' << std::get<s-1>(iterable);
}

template <class..._ts>
std::ostream &
operator <<(std::ostream &stream, const Array_t<std::tuple<_ts...>> &value) {
  return unpack<sizeof...(_ts), _ts...>(stream << '[', value) << ']';
}

static std::ostream &
operator <<(std::ostream &stream, const Null_t &) {
  return stream << "null";
}

template <class map_t>
std::ostream &
operator <<(std::ostream &stream, const Obj_t<map_t> &value) {
  stream << '{';
  auto first = true;
  for (auto &&pair : value) {
    if (!first) stream << ',';
    stream << make_string(pair.first) << ':' << pair.second;
    first = false;
  }
  return stream << '}';
}

template <class str_t>
static std::ostream &
operator <<(std::ostream &stream, const String_t<str_t> &value) {
  const char *json_esc[] = {
    "\\u0000",  // 0x00
    "\\u0001",  // 0x01
    "\\u0002",  // 0x02
    "\\u0003",  // 0x03
    "\\u0004",  // 0x04
    "\\u0005",  // 0x05
    "\\u0006",  // 0x06
    "\\u0007",  // 0x07
    "\\b",  // 0x08
    "\\t",  // 0x09
    "\\n",  // 0x0A
    "\\u000B",  // 0x0B
    "\\f",  // 0x0C
    "\\r",  // 0x0D
    "\\u000E",  // 0x0E
    "\\u000F",  // 0x0F
    "\\u0010",  // 0x10
    "\\u0011",  // 0x11
    "\\u0012",  // 0x12
    "\\u0013",  // 0x13
    "\\u0014",  // 0x14
    "\\u0015",  // 0x15
    "\\u0016",  // 0x16
    "\\u0017",  // 0x17
    "\\u0018",  // 0x18
    "\\u0019",  // 0x19
    "\\u001A",  // 0x1A
    "\\u001B",  // 0x1B
    "\\u001C",  // 0x1C
    "\\u001D",  // 0x1D
    "\\u001E",  // 0x1E
    "\\u001F",  // 0x1F
    "", "",  // 0x21
    "\\\"",  // 0x22
    "", "", "", "", "", "", "", "", "", "", "", "", "",  // 0x2F
    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",  // 0x3F
    "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",  // 0x4F
    "", "", "", "", "", "", "", "", "", "", "", "",  // 0x5B
    "\\\\"  // 0x5C
  };

  const char *hex = "0123456789ABCDEF";

  stream << '"';
  for (const auto chr : value) {
    auto idx = static_cast<const unsigned int>(chr);
    if (idx > 0xFF) {
      stream << "\\u"
             << hex[(idx >> 12) & 0xF]
             << hex[(idx >> 8) & 0xF]
             << hex[(idx >> 4) & 0xF]
             << hex[(idx >> 0) & 0xF];
    } else if ((idx > 0x5C) || (idx < 0x5C && idx > 0x22) || (idx == 0x21)) {
      stream << static_cast<const char>(idx);
    } else {
      stream << json_esc[idx];
    }
  }
  return stream << '"';
}

}  // namespace _ReQL

#endif  // REQL_REQL_QUERY_HPP_
