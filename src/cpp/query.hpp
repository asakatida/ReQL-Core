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

#ifndef REQL_CPP_QUERY_HPP_
#define REQL_CPP_QUERY_HPP_

#include "./cpp/connection.hpp"
#include "./cpp/cursor.hpp"
#include "./cpp/new.hpp"

namespace ReQL {

class Query {
public:
  Query();
  Query(const _C::ReQL_AST_Function &f, const Types::array &args);
  Query(const _C::ReQL_AST_Function_Kwargs &f, const Types::array &args, const Types::object &kwargs);
  explicit Query(const Types::string &val);
  explicit Query(const double &val);
  explicit Query(const bool &val);
  explicit Query(const Types::array &val);
  explicit Query(const Types::object &val);
  explicit Query(_C::ReQL_Obj_t *val);

  Query(const Query &other);
  Query(Query &&other);

  Query &operator=(const Query &other);
  Query &operator=(Query &&other);

  _C::ReQL_Obj_t *build();

  void no_reply(const Connection &conn) const;
  void no_reply(const Connection &conn, const Types::object &kwargs) const;
  Cursor run(const Connection &conn) const;
  Cursor run(const Connection &conn, const Types::object &kwargs) const;

private:
  static _C::ReQL_Obj_t *buildArray();
  static _C::ReQL_Obj_t *buildBool();
  static _C::ReQL_Obj_t *buildNumber();
  static _C::ReQL_Obj_t *buildNull();
  static _C::ReQL_Obj_t *buildObject();
  static _C::ReQL_Obj_t *buildString();
  static _C::ReQL_Obj_t *buildTerm();
  static _C::ReQL_Obj_t *buildTermKwargs();
  typedef _C::ReQL_Obj_t *(*QueryBuilder)();
  Types::array p_array;
  bool p_bool;
  QueryBuilder p_build;
  _C::ReQL_AST_Function p_func;
  _C::ReQL_AST_Function_Kwargs p_func_kwargs;
  double p_number;
  Types::object p_object;
  Types::string p_string;

public:
  /**
   */
  Query
  add(const Types::array &args) const;

  /**
   */
  Query
  and_(const Types::array &args) const;

  /**
   */
  Query
  append(const Types::array &args) const;

  /**
   */
  Query
  april(const Types::array &args) const;

  /**
   */
  Query
  args(const Types::array &args) const;

  /**
   */
  Query
  asc(const Types::array &args) const;

  /**
   */
  Query
  august(const Types::array &args) const;

  /**
   */
  Query
  avg(const Types::array &args) const;

  /**
   */
  Query
  between(const Types::array &args) const;

  /**
   */
  Query
  between_deprecated(const Types::array &args) const;

  /**
   */
  Query
  binary(const Types::array &args) const;

  /**
   */
  Query
  bracket(const Types::array &args) const;

  /**
   */
  Query
  branch(const Types::array &args) const;

  /**
   */
  Query
  ceil(const Types::array &args) const;

  /**
   */
  Query
  changes(const Types::array &args) const;

  /**
   */
  Query
  change_at(const Types::array &args) const;

  /**
   */
  Query
  circle(const Types::array &args, const Types::object &kwargs) const;
  Query
  circle(const Types::array &args) const;

  /**
   */
  Query
  coerce_to(const Types::array &args) const;

  /**
   */
  Query
  concat_map(const Types::array &args) const;

  /**
   */
  Query
  config(const Types::array &args) const;

  /**
   */
  Query
  contains(const Types::array &args) const;

  /**
   */
  Query
  count(const Types::array &args) const;

  /**
   */
  Query
  date(const Types::array &args) const;

  /**
   */
  Query
  datum(const Types::array &args) const;

  /**
   */
  Query
  day(const Types::array &args) const;

  /**
   */
  Query
  day_of_week(const Types::array &args) const;

  /**
   */
  Query
  day_of_year(const Types::array &args) const;

  /**
   */
  Query
  db(const Types::array &args) const;

  /**
   */
  Query
  db_create(const Types::array &args) const;

  /**
   */
  Query
  db_drop(const Types::array &args) const;

  /**
   */
  Query
  db_list(const Types::array &args) const;

  /**
   */
  Query
  december(const Types::array &args) const;

  /**
   */
  Query
  default_(const Types::array &args) const;

  /**
   */
  Query
  delete_(const Types::array &args, const Types::object &kwargs) const;
  Query
  delete_(const Types::array &args) const;

  /**
   */
  Query
  delete_at(const Types::array &args) const;

  /**
   */
  Query
  desc(const Types::array &args) const;

  /**
   */
  Query
  difference(const Types::array &args) const;

  /**
   */
  Query
  distance(const Types::array &args) const;

  /**
   */
  Query
  distinct(const Types::array &args, const Types::object &kwargs) const;
  Query
  distinct(const Types::array &args) const;

  /**
   */
  Query
  div(const Types::array &args) const;

  /**
   */
  Query
  downcase(const Types::array &args) const;

  /**
   */
  Query
  during(const Types::array &args) const;

  /**
   */
  Query
  epoch_time(const Types::array &args) const;

  /**
   */
  Query
  eq(const Types::array &args) const;

  /**
   */
  Query
  eq_join(const Types::array &args, const Types::object &kwargs) const;
  Query
  eq_join(const Types::array &args) const;

  /**
   */
  Query
  error(const Types::array &args) const;

  /**
   */
  Query
  february(const Types::array &args) const;

  /**
   */
  Query
  fill(const Types::array &args) const;

  /**
   */
  Query
  filter(const Types::array &args, const Types::object &kwargs) const;
  Query
  filter(const Types::array &args) const;

  /**
   */
  Query
  floor(const Types::array &args) const;

  /**
   */
  Query
  for_each(const Types::array &args) const;

  /**
   */
  Query
  friday(const Types::array &args) const;

  /**
   */
  Query
  func(const Types::array &args) const;

  /**
   */
  Query
  funcall(const Types::array &args) const;

  /**
   */
  Query
  ge(const Types::array &args) const;

  /**
   */
  Query
  geojson(const Types::array &args) const;

  /**
   */
  Query
  get(const Types::array &args) const;

  /**
   */
  Query
  get_all(const Types::array &args, const Types::object &kwargs) const;
  Query
  get_all(const Types::array &args) const;

  /**
   */
  Query
  get_field(const Types::array &args) const;

  /**
   */
  Query
  get_intersecting(const Types::array &args, const Types::object &kwargs) const;
  Query
  get_intersecting(const Types::array &args) const;

  /**
   */
  Query
  get_nearest(const Types::array &args, const Types::object &kwargs) const;
  Query
  get_nearest(const Types::array &args) const;

  /**
   */
  Query
  group(const Types::array &args, const Types::object &kwargs) const;
  Query
  group(const Types::array &args) const;

  /**
   */
  Query
  gt(const Types::array &args) const;

  /**
   */
  Query
  has_fields(const Types::array &args) const;

  /**
   */
  Query
  hours(const Types::array &args) const;

  /**
   */
  Query
  http(const Types::array &args, const Types::object &kwargs) const;
  Query
  http(const Types::array &args) const;

  /**
   */
  Query
  implicit_var(const Types::array &args) const;

  /**
   */
  Query
  includes(const Types::array &args) const;

  /**
   */
  Query
  index_create(const Types::array &args, const Types::object &kwargs) const;
  Query
  index_create(const Types::array &args) const;

  /**
   */
  Query
  index_drop(const Types::array &args) const;

  /**
   */
  Query
  index_list(const Types::array &args) const;

  /**
   */
  Query
  index_rename(const Types::array &args, const Types::object &kwargs) const;
  Query
  index_rename(const Types::array &args) const;

  /**
   */
  Query
  index_status(const Types::array &args) const;

  /**
   */
  Query
  index_wait(const Types::array &args) const;

  /**
   */
  Query
  info(const Types::array &args) const;

  /**
   */
  Query
  inner_join(const Types::array &args) const;

  /**
   */
  Query
  insert(const Types::array &args) const;

  /**
   */
  Query
  insert_at(const Types::array &args) const;

  /**
   */
  Query
  intersects(const Types::array &args) const;

  /**
   */
  Query
  in_timezone(const Types::array &args) const;

  /**
   */
  Query
  iso8601(const Types::array &args, const Types::object &kwargs) const;
  Query
  iso8601(const Types::array &args) const;

  /**
   */
  Query
  is_empty(const Types::array &args) const;

  /**
   */
  Query
  january(const Types::array &args) const;

  /**
   */
  Query
  javascript(const Types::array &args, const Types::object &kwargs) const;
  Query
  javascript(const Types::array &args) const;

  /**
   */
  Query
  json(const Types::array &args) const;

  /**
   */
  Query
  july(const Types::array &args) const;

  /**
   */
  Query
  june(const Types::array &args) const;

  /**
   */
  Query
  keys(const Types::array &args) const;

  /**
   */
  Query
  le(const Types::array &args) const;

  /**
   */
  Query
  limit(const Types::array &args) const;

  /**
   */
  Query
  line(const Types::array &args) const;

  /**
   */
  Query
  literal(const Types::array &args) const;

  /**
   */
  Query
  lt(const Types::array &args) const;

  /**
   */
  Query
  make_array(const Types::array &args) const;

  /**
   */
  Query
  make_obj(const Types::array &args) const;

  /**
   */
  Query
  map(const Types::array &args) const;

  /**
   */
  Query
  march(const Types::array &args) const;

  /**
   */
  Query
  match(const Types::array &args) const;

  /**
   */
  Query
  max(const Types::array &args) const;

  /**
   */
  Query
  maxval(const Types::array &args) const;

  /**
   */
  Query
  may(const Types::array &args) const;

  /**
   */
  Query
  merge(const Types::array &args) const;

  /**
   */
  Query
  min(const Types::array &args) const;

  /**
   */
  Query
  minutes(const Types::array &args) const;

  /**
   */
  Query
  minval(const Types::array &args) const;

  /**
   */
  Query
  mod(const Types::array &args) const;

  /**
   */
  Query
  monday(const Types::array &args) const;

  /**
   */
  Query
  month(const Types::array &args) const;

  /**
   */
  Query
  mul(const Types::array &args) const;

  /**
   */
  Query
  ne(const Types::array &args) const;

  /**
   */
  Query
  not_(const Types::array &args) const;

  /**
   */
  Query
  november(const Types::array &args) const;

  /**
   */
  Query
  now(const Types::array &args) const;

  /**
   */
  Query
  nth(const Types::array &args) const;

  /**
   */
  Query
  object(const Types::array &args) const;

  /**
   */
  Query
  october(const Types::array &args) const;

  /**
   */
  Query
  offsets_of(const Types::array &args) const;

  /**
   */
  Query
  or_(const Types::array &args) const;

  /**
   */
  Query
  order_by(const Types::array &args, const Types::object &kwargs) const;
  Query
  order_by(const Types::array &args) const;

  /**
   */
  Query
  outer_join(const Types::array &args) const;

  /**
   */
  Query
  pluck(const Types::array &args) const;

  /**
   */
  Query
  point(const Types::array &args) const;

  /**
   */
  Query
  polygon(const Types::array &args) const;

  /**
   */
  Query
  polygon_sub(const Types::array &args) const;

  /**
   */
  Query
  prepend(const Types::array &args) const;

  /**
   */
  Query
  random(const Types::array &args, const Types::object &kwargs) const;
  Query
  random(const Types::array &args) const;

  /**
   */
  Query
  range(const Types::array &args) const;

  /**
   */
  Query
  rebalance(const Types::array &args) const;

  /**
   */
  Query
  reconfigure(const Types::array &args) const;

  /**
   */
  Query
  reduce(const Types::array &args) const;

  /**
   */
  Query
  replace(const Types::array &args, const Types::object &kwargs) const;
  Query
  replace(const Types::array &args) const;

  /**
   */
  Query
  round(const Types::array &args) const;

  /**
   */
  Query
  sample(const Types::array &args) const;

  /**
   */
  Query
  saturday(const Types::array &args) const;

  /**
   */
  Query
  seconds(const Types::array &args) const;

  /**
   */
  Query
  september(const Types::array &args) const;

  /**
   */
  Query
  set_difference(const Types::array &args) const;

  /**
   */
  Query
  set_insert(const Types::array &args) const;

  /**
   */
  Query
  set_intersection(const Types::array &args) const;

  /**
   */
  Query
  set_union(const Types::array &args) const;

  /**
   */
  Query
  skip(const Types::array &args) const;

  /**
   */
  Query
  slice(const Types::array &args, const Types::object &kwargs) const;
  Query
  slice(const Types::array &args) const;

  /**
   */
  Query
  splice_at(const Types::array &args) const;

  /**
   */
  Query
  split(const Types::array &args) const;

  /**
   */
  Query
  status(const Types::array &args) const;

  /**
   */
  Query
  sub(const Types::array &args) const;

  /**
   */
  Query
  sum(const Types::array &args) const;

  /**
   */
  Query
  sunday(const Types::array &args) const;

  /**
   */
  Query
  sync(const Types::array &args) const;

  /**
   */
  Query
  table(const Types::array &args, const Types::object &kwargs) const;
  Query
  table(const Types::array &args) const;

  /**
   */
  Query
  table_create(const Types::array &args, const Types::object &kwargs) const;
  Query
  table_create(const Types::array &args) const;

  /**
   */
  Query
  table_drop(const Types::array &args) const;

  /**
   */
  Query
  table_list(const Types::array &args) const;

  /**
   */
  Query
  thursday(const Types::array &args) const;

  /**
   */
  Query
  time(const Types::array &args) const;

  /**
   */
  Query
  timezone_(const Types::array &args) const;

  /**
   */
  Query
  time_of_day(const Types::array &args) const;

  /**
   */
  Query
  to_epoch_time(const Types::array &args) const;

  /**
   */
  Query
  to_geojson(const Types::array &args) const;

  /**
   */
  Query
  to_iso8601(const Types::array &args) const;

  /**
   */
  Query
  to_json_string(const Types::array &args) const;

  /**
   */
  Query
  tuesday(const Types::array &args) const;

  /**
   */
  Query
  type_of(const Types::array &args) const;

  /**
   */
  Query
  ungroup(const Types::array &args) const;

  /**
   */
  Query
  union_(const Types::array &args) const;

  /**
   */
  Query
  upcase(const Types::array &args) const;

  /**
   */
  Query
  update(const Types::array &args, const Types::object &kwargs) const;
  Query
  update(const Types::array &args) const;

  /**
   */
  Query
  uuid(const Types::array &args) const;

  /**
   */
  Query
  var(const Types::array &args) const;

  /**
   */
  Query
  wait(const Types::array &args) const;

  /**
   */
  Query
  wednesday(const Types::array &args) const;

  /**
   */
  Query
  without(const Types::array &args) const;

  /**
   */
  Query
  with_fields(const Types::array &args) const;

  /**
   */
  Query
  year(const Types::array &args) const;

  /**
   */
  Query
  zip(const Types::array &args) const;
};

/**
 */
Query
add(const Types::array &args);

/**
 */
Query
and_(const Types::array &args);

/**
 */
Query
append(const Types::array &args);

/**
 */
Query
april(const Types::array &args);

/**
 */
Query
args(const Types::array &args);

/**
 */
Query
asc(const Types::array &args);

/**
 */
Query
august(const Types::array &args);

/**
 */
Query
avg(const Types::array &args);

/**
 */
Query
between(const Types::array &args);

/**
 */
Query
between_deprecated(const Types::array &args);

/**
 */
Query
binary(const Types::array &args);

/**
 */
Query
bracket(const Types::array &args);

/**
 */
Query
branch(const Types::array &args);

/**
 */
Query
ceil(const Types::array &args);

/**
 */
Query
changes(const Types::array &args);

/**
 */
Query
change_at(const Types::array &args);

/**
 */
Query
circle(const Types::array &args, const Types::object &kwargs);
Query
circle(const Types::array &args);

/**
 */
Query
coerce_to(const Types::array &args);

/**
 */
Query
concat_map(const Types::array &args);

/**
 */
Query
config(const Types::array &args);

/**
 */
Query
contains(const Types::array &args);

/**
 */
Query
count(const Types::array &args);

/**
 */
Query
date(const Types::array &args);

/**
 */
Query
datum(const Types::array &args);

/**
 */
Query
day(const Types::array &args);

/**
 */
Query
day_of_week(const Types::array &args);

/**
 */
Query
day_of_year(const Types::array &args);

/**
 */
Query
db(const Types::array &args);

/**
 */
Query
db_create(const Types::array &args);

/**
 */
Query
db_drop(const Types::array &args);

/**
 */
Query
db_list(const Types::array &args);

/**
 */
Query
december(const Types::array &args);

/**
 */
Query
default_(const Types::array &args);

/**
 */
Query
delete_(const Types::array &args, const Types::object &kwargs);
Query
delete_(const Types::array &args);

/**
 */
Query
delete_at(const Types::array &args);

/**
 */
Query
desc(const Types::array &args);

/**
 */
Query
difference(const Types::array &args);

/**
 */
Query
distance(const Types::array &args);

/**
 */
Query
distinct(const Types::array &args, const Types::object &kwargs);
Query
distinct(const Types::array &args);

/**
 */
Query
div(const Types::array &args);

/**
 */
Query
downcase(const Types::array &args);

/**
 */
Query
during(const Types::array &args);

/**
 */
Query
epoch_time(const Types::array &args);

/**
 */
Query
eq(const Types::array &args);

/**
 */
Query
eq_join(const Types::array &args, const Types::object &kwargs);
Query
eq_join(const Types::array &args);

/**
 */
Query
error(const Types::array &args);

/**
 */
Query
february(const Types::array &args);

/**
 */
Query
fill(const Types::array &args);

/**
 */
Query
filter(const Types::array &args, const Types::object &kwargs);
Query
filter(const Types::array &args);

/**
 */
Query
floor(const Types::array &args);

/**
 */
Query
for_each(const Types::array &args);

/**
 */
Query
friday(const Types::array &args);

/**
 */
Query
func(const Types::array &args);

/**
 */
Query
funcall(const Types::array &args);

/**
 */
Query
ge(const Types::array &args);

/**
 */
Query
geojson(const Types::array &args);

/**
 */
Query
get(const Types::array &args);

/**
 */
Query
get_all(const Types::array &args, const Types::object &kwargs);
Query
get_all(const Types::array &args);

/**
 */
Query
get_field(const Types::array &args);

/**
 */
Query
get_intersecting(const Types::array &args, const Types::object &kwargs);
Query
get_intersecting(const Types::array &args);

/**
 */
Query
get_nearest(const Types::array &args, const Types::object &kwargs);
Query
get_nearest(const Types::array &args);

/**
 */
Query
group(const Types::array &args, const Types::object &kwargs);
Query
group(const Types::array &args);

/**
 */
Query
gt(const Types::array &args);

/**
 */
Query
has_fields(const Types::array &args);

/**
 */
Query
hours(const Types::array &args);

/**
 */
Query
http(const Types::array &args, const Types::object &kwargs);
Query
http(const Types::array &args);

/**
 */
Query
implicit_var(const Types::array &args);

/**
 */
Query
includes(const Types::array &args);

/**
 */
Query
index_create(const Types::array &args, const Types::object &kwargs);
Query
index_create(const Types::array &args);

/**
 */
Query
index_drop(const Types::array &args);

/**
 */
Query
index_list(const Types::array &args);

/**
 */
Query
index_rename(const Types::array &args, const Types::object &kwargs);
Query
index_rename(const Types::array &args);

/**
 */
Query
index_status(const Types::array &args);

/**
 */
Query
index_wait(const Types::array &args);

/**
 */
Query
info(const Types::array &args);

/**
 */
Query
inner_join(const Types::array &args);

/**
 */
Query
insert(const Types::array &args);

/**
 */
Query
insert_at(const Types::array &args);

/**
 */
Query
intersects(const Types::array &args);

/**
 */
Query
in_timezone(const Types::array &args);

/**
 */
Query
iso8601(const Types::array &args, const Types::object &kwargs);
Query
iso8601(const Types::array &args);

/**
 */
Query
is_empty(const Types::array &args);

/**
 */
Query
january(const Types::array &args);

/**
 */
Query
javascript(const Types::array &args, const Types::object &kwargs);
Query
javascript(const Types::array &args);

/**
 */
Query
json(const Types::array &args);

/**
 */
Query
july(const Types::array &args);

/**
 */
Query
june(const Types::array &args);

/**
 */
Query
keys(const Types::array &args);

/**
 */
Query
le(const Types::array &args);

/**
 */
Query
limit(const Types::array &args);

/**
 */
Query
line(const Types::array &args);

/**
 */
Query
literal(const Types::array &args);

/**
 */
Query
lt(const Types::array &args);

/**
 */
Query
make_array(const Types::array &args);

/**
 */
Query
make_obj(const Types::array &args);

/**
 */
Query
map(const Types::array &args);

/**
 */
Query
march(const Types::array &args);

/**
 */
Query
match(const Types::array &args);

/**
 */
Query
max(const Types::array &args);

/**
 */
Query
maxval(const Types::array &args);

/**
 */
Query
may(const Types::array &args);

/**
 */
Query
merge(const Types::array &args);

/**
 */
Query
min(const Types::array &args);

/**
 */
Query
minutes(const Types::array &args);

/**
 */
Query
minval(const Types::array &args);

/**
 */
Query
mod(const Types::array &args);

/**
 */
Query
monday(const Types::array &args);

/**
 */
Query
month(const Types::array &args);

/**
 */
Query
mul(const Types::array &args);

/**
 */
Query
ne(const Types::array &args);

/**
 */
Query
not_(const Types::array &args);

/**
 */
Query
november(const Types::array &args);

/**
 */
Query
now(const Types::array &args);

/**
 */
Query
nth(const Types::array &args);

/**
 */
Query
object(const Types::array &args);

/**
 */
Query
october(const Types::array &args);

/**
 */
Query
offsets_of(const Types::array &args);

/**
 */
Query
or_(const Types::array &args);

/**
 */
Query
order_by(const Types::array &args, const Types::object &kwargs);
Query
order_by(const Types::array &args);

/**
 */
Query
outer_join(const Types::array &args);

/**
 */
Query
pluck(const Types::array &args);

/**
 */
Query
point(const Types::array &args);

/**
 */
Query
polygon(const Types::array &args);

/**
 */
Query
polygon_sub(const Types::array &args);

/**
 */
Query
prepend(const Types::array &args);

/**
 */
Query
random(const Types::array &args, const Types::object &kwargs);
Query
random(const Types::array &args);

/**
 */
Query
range(const Types::array &args);

/**
 */
Query
rebalance(const Types::array &args);

/**
 */
Query
reconfigure(const Types::array &args);

/**
 */
Query
reduce(const Types::array &args);

/**
 */
Query
replace(const Types::array &args, const Types::object &kwargs);
Query
replace(const Types::array &args);

/**
 */
Query
round(const Types::array &args);

/**
 */
Query
sample(const Types::array &args);

/**
 */
Query
saturday(const Types::array &args);

/**
 */
Query
seconds(const Types::array &args);

/**
 */
Query
september(const Types::array &args);

/**
 */
Query
set_difference(const Types::array &args);

/**
 */
Query
set_insert(const Types::array &args);

/**
 */
Query
set_intersection(const Types::array &args);

/**
 */
Query
set_union(const Types::array &args);

/**
 */
Query
skip(const Types::array &args);

/**
 */
Query
slice(const Types::array &args, const Types::object &kwargs);
Query
slice(const Types::array &args);

/**
 */
Query
splice_at(const Types::array &args);

/**
 */
Query
split(const Types::array &args);

/**
 */
Query
status(const Types::array &args);

/**
 */
Query
sub(const Types::array &args);

/**
 */
Query
sum(const Types::array &args);

/**
 */
Query
sunday(const Types::array &args);

/**
 */
Query
sync(const Types::array &args);

/**
 */
Query
table(const Types::array &args, const Types::object &kwargs);
Query
table(const Types::array &args);

/**
 */
Query
table_create(const Types::array &args, const Types::object &kwargs);
Query
table_create(const Types::array &args);

/**
 */
Query
table_drop(const Types::array &args);

/**
 */
Query
table_list(const Types::array &args);

/**
 */
Query
thursday(const Types::array &args);

/**
 */
Query
time(const Types::array &args);

/**
 */
Query
timezone_(const Types::array &args);

/**
 */
Query
time_of_day(const Types::array &args);

/**
 */
Query
to_epoch_time(const Types::array &args);

/**
 */
Query
to_geojson(const Types::array &args);

/**
 */
Query
to_iso8601(const Types::array &args);

/**
 */
Query
to_json_string(const Types::array &args);

/**
 */
Query
tuesday(const Types::array &args);

/**
 */
Query
type_of(const Types::array &args);

/**
 */
Query
ungroup(const Types::array &args);

/**
 */
Query
union_(const Types::array &args);

/**
 */
Query
upcase(const Types::array &args);

/**
 */
Query
update(const Types::array &args, const Types::object &kwargs);
Query
update(const Types::array &args);

/**
 */
Query
uuid(const Types::array &args);

/**
 */
Query
var(const Types::array &args);

/**
 */
Query
wait(const Types::array &args);

/**
 */
Query
wednesday(const Types::array &args);

/**
 */
Query
without(const Types::array &args);

/**
 */
Query
with_fields(const Types::array &args);

/**
 */
Query
year(const Types::array &args);

/**
 */
Query
zip(const Types::array &args);

}  // namespace ReQL

#endif  // REQL_CPP_QUERY_HPP_
