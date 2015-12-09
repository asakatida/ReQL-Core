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

#include "./cpp/query.hpp"

#include "./cpp/connection.hpp"
#include "./cpp/cursor.hpp"
#include "./cpp/error.hpp"

#include <algorithm>
#include <array>

namespace ReQL {

std::string
buildArray(const Query &query) {
  std::vector<std::string> array;
  array.reserve(query.p_array.size());

  for (auto &&elem : query.p_array) {
    array.push_back(elem.build());
  }

  return _ReQL::expr(_ReQL::make_array(array));
}

std::string
buildBool(const Query &query) {
  return _ReQL::expr(query.p_bool);
}

std::string
buildNumber(const Query &query) {
  return _ReQL::expr(query.p_number);
}

std::string
buildNull(const Query &) {
  return _ReQL::expr(_ReQL::Null_t());
}

std::string
buildObject(const Query &query) {
  std::map<std::wstring, std::string> object;

  for (auto &&pair : query.p_object) {
    object.insert({pair.first, pair.second.build()});
  }

  return _ReQL::expr(_ReQL::make_object(object));
}

std::string
buildString(const Query &query) {
  return _ReQL::expr(_ReQL::make_string(query.p_string));
}

std::string
buildTerm(const Query &query) {
  std::vector<std::string> array;
  array.reserve(query.p_array.size());

  for (auto &&elem : query.p_array) {
    array.push_back(elem.build());
  }

  return _ReQL::expr(make_reql(query.p_tt, array));
}

std::string
buildTermKwargs(const Query &query) {
  std::vector<std::string> array;
  array.reserve(query.p_array.size());

  for (auto &&elem : query.p_array) {
    array.push_back(elem.build());
  }

  std::map<std::wstring, std::string> object;

  for (auto &&pair : query.p_object) {
    object.insert({pair.first, pair.second.build()});
  }

  return _ReQL::expr(make_reql(query.p_tt, array, object));
}

Query::Query() : p_build(buildNull) {}

Query::Query(const _ReQL::Term_t tt, const Query *other, const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) :
  p_build(buildTermKwargs),
  p_object(kwargs),
  p_tt(tt) {
  p_array.reserve(args.size() + 1);
  p_array.push_back(*other);
  p_array.insert(p_array.end(), args.cbegin(), args.cend());
}

Query::Query(const _ReQL::Term_t tt, const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) :
  p_array(args),
  p_build(buildTermKwargs),
  p_object(kwargs),
  p_tt(tt) {}

Query::Query(const _ReQL::Term_t tt, const Query *other, const std::vector<Query> &args) :
  p_build(buildTerm),
  p_tt(tt) {
  p_array.reserve(args.size() + 1);
  p_array.push_back(*other);
  p_array.insert(p_array.end(), args.cbegin(), args.cend());
}

Query::Query(const _ReQL::Term_t tt, const std::vector<Query> &args) :
  p_array(args),
  p_build(buildTerm),
  p_tt(tt) {}

Query::Query(const std::wstring &val) :
  p_build(buildString),
  p_string(val) {}

Query::Query(const double val) :
  p_build(buildNumber),
  p_number(val) {}

Query::Query(const bool val) :
  p_bool(val),
  p_build(buildBool) {}

Query::Query(const std::vector<Query> &val) :
  p_array(val),
  p_build(buildArray) {}

Query::Query(const std::map<std::wstring, Query> &val) :
  p_build(buildObject),
  p_object(val) {}

Query::Query(const Query &other) :
  p_array(other.p_array),
  p_bool(other.p_bool),
  p_build(other.p_build),
  p_number(other.p_number),
  p_object(other.p_object),
  p_string(other.p_string),
  p_tt(other.p_tt) {}

Query::Query(Query &&other) :
  p_array(std::move(other.p_array)),
  p_bool(std::move(other.p_bool)),
  p_build(std::move(other.p_build)),
  p_number(std::move(other.p_number)),
  p_object(std::move(other.p_object)),
  p_string(std::move(other.p_string)),
  p_tt(std::move(other.p_tt)) {}

Cursor
Query::run(Connection &conn) const {
  return conn.p_conn->run(build());
}

static auto
to_object(const std::map<std::wstring, Query> &kwargs) {
  std::map<std::wstring, std::string> _kwargs;
  std::accumulate(
        kwargs.cbegin(),
        kwargs.cend(),
        _kwargs,
        [](auto val, auto pair) {
    val.insert({pair.first, pair.second.build()}); return val;
  });
  return _kwargs;
}

Cursor
Query::run(Connection &conn, const std::map<std::wstring, Query> &kwargs) const {
  return conn.p_conn->run(build(), to_object(kwargs));
}

void
Query::no_reply(Connection &conn) const {
  auto query = build();
  std::map<std::wstring, Query> kwargs;
  auto opts = to_object(kwargs);
  conn.p_conn->noReply(query, opts);
}

void
Query::no_reply(Connection &conn, const std::map<std::wstring, Query> &kwargs) const {
  conn.p_conn->noReply(build(), to_object(kwargs));
}

Query &
Query::operator=(const Query &other) {
  if (this != &other) {
    p_array = other.p_array;
    p_bool = other.p_bool;
    p_build = other.p_build;
    p_number = other.p_number;
    p_object = other.p_object;
    p_string = other.p_string;
    p_tt = other.p_tt;
  }
  return *this;
}

Query &
Query::operator=(Query &&other) {
  if (this != &other) {
    p_array = std::move(other.p_array);
    p_bool = std::move(other.p_bool);
    p_build = std::move(other.p_build);
    p_number = std::move(other.p_number);
    p_object = std::move(other.p_object);
    p_string = std::move(other.p_string);
    p_tt = std::move(other.p_tt);
  }
  return *this;
}

std::string
Query::build() const {
  return p_build(*this);
}

Query
Query::add(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
add(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::and_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
and_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::append(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
append(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::april(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
april(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::args(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
args(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::asc(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
asc(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::august(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
august(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::avg(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
avg(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::between(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
between(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::between_deprecated(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
between_deprecated(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::binary(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
binary(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::bracket(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
bracket(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::branch(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
branch(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::ceil(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
ceil(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::changes(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
changes(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::change_at(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
change_at(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::circle(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
circle(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::circle(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
circle(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::coerce_to(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
coerce_to(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::concat_map(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
concat_map(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::config(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
config(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::contains(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
contains(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::count(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
count(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::date(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
date(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::datum(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
datum(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::day(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
day(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::day_of_week(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
day_of_week(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::day_of_year(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
day_of_year(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::db(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
db(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::db_create(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
db_create(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::db_drop(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
db_drop(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::db_list(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
db_list(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::december(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
december(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::default_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
default_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::delete_(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
delete_(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::delete_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
delete_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::delete_at(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
delete_at(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::desc(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
desc(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::difference(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
difference(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::distance(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
distance(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::distinct(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
distinct(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::distinct(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
distinct(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::div(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
div(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::downcase(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
downcase(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::during(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
during(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::epoch_time(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
epoch_time(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::eq(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
eq(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::eq_join(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
eq_join(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::eq_join(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
eq_join(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::error(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
error(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::february(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
february(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::fill(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
fill(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::filter(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
filter(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::filter(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
filter(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::floor(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
floor(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::for_each(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
for_each(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::friday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
friday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::func(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
func(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::funcall(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
funcall(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::ge(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
ge(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::geojson(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
geojson(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::get(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
get(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::get_all(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
get_all(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::get_all(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
get_all(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::get_field(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
get_field(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::get_intersecting(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
get_intersecting(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::get_intersecting(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
get_intersecting(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::get_nearest(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
get_nearest(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::get_nearest(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
get_nearest(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::group(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
group(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::group(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
group(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::gt(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
gt(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::has_fields(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
has_fields(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::hours(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
hours(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::http(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
http(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::http(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
http(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::implicit_var(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
implicit_var(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::includes(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
includes(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_create(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
index_create(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::index_create(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_create(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_drop(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_drop(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_list(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_list(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_rename(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
index_rename(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::index_rename(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_rename(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_status(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_status(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::index_wait(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
index_wait(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::info(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
info(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::inner_join(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
inner_join(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::insert(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
insert(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::insert_at(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
insert_at(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::intersects(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
intersects(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::in_timezone(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
in_timezone(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::iso8601(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
iso8601(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::iso8601(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
iso8601(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::is_empty(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
is_empty(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::january(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
january(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::javascript(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
javascript(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::javascript(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
javascript(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::json(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
json(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::july(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
july(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::june(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
june(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::keys(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
keys(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::le(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
le(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::limit(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
limit(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::line(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
line(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::literal(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
literal(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::lt(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
lt(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::make_array(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
make_array(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::make_obj(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
make_obj(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::map(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
map(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::march(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
march(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::match(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
match(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::max(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
max(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::maxval(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
maxval(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::may(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
may(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::merge(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
merge(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::min(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
min(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::minutes(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
minutes(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::minval(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
minval(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::mod(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
mod(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::monday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
monday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::month(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
month(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::mul(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
mul(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::ne(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
ne(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::not_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
not_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::november(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
november(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::now(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
now(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::nth(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
nth(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::object(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
object(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::october(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
october(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::offsets_of(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
offsets_of(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::or_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
or_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::order_by(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
order_by(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::order_by(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
order_by(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::outer_join(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
outer_join(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::pluck(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
pluck(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::point(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
point(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::polygon(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
polygon(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::polygon_sub(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
polygon_sub(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::prepend(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
prepend(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::random(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
random(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::random(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
random(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::range(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
range(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::rebalance(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
rebalance(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::reconfigure(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
reconfigure(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::reduce(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
reduce(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::replace(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
replace(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::replace(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
replace(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::round(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
round(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::sample(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
sample(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::saturday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
saturday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::seconds(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
seconds(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::september(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
september(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::set_difference(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
set_difference(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::set_insert(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
set_insert(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::set_intersection(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
set_intersection(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::set_union(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
set_union(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::skip(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
skip(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::slice(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
slice(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::slice(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
slice(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::splice_at(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
splice_at(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::split(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
split(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::status(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
status(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::sub(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
sub(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::sum(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
sum(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::sunday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
sunday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::sync(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
sync(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::table(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
table(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::table(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
table(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::table_create(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
table_create(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::table_create(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
table_create(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::table_drop(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
table_drop(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::table_list(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
table_list(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::thursday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
thursday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::time(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
time(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::timezone_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
timezone_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::time_of_day(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
time_of_day(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::to_epoch_time(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
to_epoch_time(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::to_geojson(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
to_geojson(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::to_iso8601(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
to_iso8601(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::to_json_string(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
to_json_string(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::tuesday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
tuesday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::type_of(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
type_of(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::ungroup(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
ungroup(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::union_(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
union_(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::upcase(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
upcase(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::update(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) const {
  return Query(_ReQL::REQL_ADD, this, args, kwargs);
}
Query
update(const std::vector<Query> &args, const std::map<std::wstring, Query> &kwargs) {
  return Query(_ReQL::REQL_ADD, args, kwargs);
}
Query
Query::update(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
update(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::uuid(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
uuid(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::values(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
values(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::var(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
var(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::wait(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
wait(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::wednesday(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
wednesday(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::without(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
without(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::with_fields(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
with_fields(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::year(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
year(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

Query
Query::zip(const std::vector<Query> &args) const {
  return Query(_ReQL::REQL_ADD, this, args);
}
Query
zip(const std::vector<Query> &args) {
  return Query(_ReQL::REQL_ADD, args);
}

}  // namespace ReQL
