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

#ifndef REQL_CPP_AST_HPP_
#define REQL_CPP_AST_HPP_

#include "./cpp/expr.hpp"

#include <map>
#include <string>
#include <vector>

namespace ReQL {

class AST : public Expr {
protected:
  AST();
  AST(const ReQL_AST_Function &f, const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
  explicit AST(const std::string &val);
  explicit AST(const double &val);
  explicit AST(const bool &val);
  explicit AST(const std::vector<Query> &val);
  explicit AST(const std::map<std::string, Query> &val);

  AST(const AST &other);
  AST(AST &&other);

public:
  /**
   */
  Query
  add(const std::vector<Query> &args) const;

  /**
   */
  Query
  and_(const std::vector<Query> &args) const;

  /**
   */
  Query
  append(const std::vector<Query> &args) const;

  /**
   */
  Query
  april(const std::vector<Query> &args) const;

  /**
   */
  Query
  args(const std::vector<Query> &args) const;

  /**
   */
  Query
  asc(const std::vector<Query> &args) const;

  /**
   */
  Query
  august(const std::vector<Query> &args) const;

  /**
   */
  Query
  avg(const std::vector<Query> &args) const;

  /**
   */
  Query
  between(const std::vector<Query> &args) const;

  /**
   */
  Query
  between_deprecated(const std::vector<Query> &args) const;

  /**
   */
  Query
  binary(const std::vector<Query> &args) const;

  /**
   */
  Query
  bracket(const std::vector<Query> &args) const;

  /**
   */
  Query
  branch(const std::vector<Query> &args) const;

  /**
   */
  Query
  ceil(const std::vector<Query> &args) const;

  /**
   */
  Query
  changes(const std::vector<Query> &args) const;

  /**
   */
  Query
  change_at(const std::vector<Query> &args) const;

  /**
   */
  Query
  circle(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  circle(const std::vector<Query> &args) const;

  /**
   */
  Query
  coerce_to(const std::vector<Query> &args) const;

  /**
   */
  Query
  concat_map(const std::vector<Query> &args) const;

  /**
   */
  Query
  config(const std::vector<Query> &args) const;

  /**
   */
  Query
  contains(const std::vector<Query> &args) const;

  /**
   */
  Query
  count(const std::vector<Query> &args) const;

  /**
   */
  Query
  date(const std::vector<Query> &args) const;

  /**
   */
  Query
  datum(const std::vector<Query> &args) const;

  /**
   */
  Query
  day(const std::vector<Query> &args) const;

  /**
   */
  Query
  day_of_week(const std::vector<Query> &args) const;

  /**
   */
  Query
  day_of_year(const std::vector<Query> &args) const;

  /**
   */
  Query
  db(const std::vector<Query> &args) const;

  /**
   */
  Query
  db_create(const std::vector<Query> &args) const;

  /**
   */
  Query
  db_drop(const std::vector<Query> &args) const;

  /**
   */
  Query
  db_list(const std::vector<Query> &args) const;

  /**
   */
  Query
  december(const std::vector<Query> &args) const;

  /**
   */
  Query
  default_(const std::vector<Query> &args) const;

  /**
   */
  Query
  delete_(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  delete_(const std::vector<Query> &args) const;

  /**
   */
  Query
  delete_at(const std::vector<Query> &args) const;

  /**
   */
  Query
  desc(const std::vector<Query> &args) const;

  /**
   */
  Query
  difference(const std::vector<Query> &args) const;

  /**
   */
  Query
  distance(const std::vector<Query> &args) const;

  /**
   */
  Query
  distinct(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  distinct(const std::vector<Query> &args) const;

  /**
   */
  Query
  div(const std::vector<Query> &args) const;

  /**
   */
  Query
  downcase(const std::vector<Query> &args) const;

  /**
   */
  Query
  during(const std::vector<Query> &args) const;

  /**
   */
  Query
  epoch_time(const std::vector<Query> &args) const;

  /**
   */
  Query
  eq(const std::vector<Query> &args) const;

  /**
   */
  Query
  eq_join(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  eq_join(const std::vector<Query> &args) const;

  /**
   */
  Query
  error(const std::vector<Query> &args) const;

  /**
   */
  Query
  february(const std::vector<Query> &args) const;

  /**
   */
  Query
  fill(const std::vector<Query> &args) const;

  /**
   */
  Query
  filter(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  filter(const std::vector<Query> &args) const;

  /**
   */
  Query
  floor(const std::vector<Query> &args) const;

  /**
   */
  Query
  for_each(const std::vector<Query> &args) const;

  /**
   */
  Query
  friday(const std::vector<Query> &args) const;

  /**
   */
  Query
  func(const std::vector<Query> &args) const;

  /**
   */
  Query
  funcall(const std::vector<Query> &args) const;

  /**
   */
  Query
  ge(const std::vector<Query> &args) const;

  /**
   */
  Query
  geojson(const std::vector<Query> &args) const;

  /**
   */
  Query
  get(const std::vector<Query> &args) const;

  /**
   */
  Query
  get_all(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  get_all(const std::vector<Query> &args) const;

  /**
   */
  Query
  get_field(const std::vector<Query> &args) const;

  /**
   */
  Query
  get_intersecting(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  get_intersecting(const std::vector<Query> &args) const;

  /**
   */
  Query
  get_nearest(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  get_nearest(const std::vector<Query> &args) const;

  /**
   */
  Query
  group(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  group(const std::vector<Query> &args) const;

  /**
   */
  Query
  gt(const std::vector<Query> &args) const;

  /**
   */
  Query
  has_fields(const std::vector<Query> &args) const;

  /**
   */
  Query
  hours(const std::vector<Query> &args) const;

  /**
   */
  Query
  http(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  http(const std::vector<Query> &args) const;

  /**
   */
  Query
  implicit_var(const std::vector<Query> &args) const;

  /**
   */
  Query
  includes(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  index_create(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_drop(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_list(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_rename(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  index_rename(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_status(const std::vector<Query> &args) const;

  /**
   */
  Query
  index_wait(const std::vector<Query> &args) const;

  /**
   */
  Query
  info(const std::vector<Query> &args) const;

  /**
   */
  Query
  inner_join(const std::vector<Query> &args) const;

  /**
   */
  Query
  insert(const std::vector<Query> &args) const;

  /**
   */
  Query
  insert_at(const std::vector<Query> &args) const;

  /**
   */
  Query
  intersects(const std::vector<Query> &args) const;

  /**
   */
  Query
  in_timezone(const std::vector<Query> &args) const;

  /**
   */
  Query
  iso8601(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  iso8601(const std::vector<Query> &args) const;

  /**
   */
  Query
  is_empty(const std::vector<Query> &args) const;

  /**
   */
  Query
  january(const std::vector<Query> &args) const;

  /**
   */
  Query
  javascript(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  javascript(const std::vector<Query> &args) const;

  /**
   */
  Query
  json(const std::vector<Query> &args) const;

  /**
   */
  Query
  july(const std::vector<Query> &args) const;

  /**
   */
  Query
  june(const std::vector<Query> &args) const;

  /**
   */
  Query
  keys(const std::vector<Query> &args) const;

  /**
   */
  Query
  le(const std::vector<Query> &args) const;

  /**
   */
  Query
  limit(const std::vector<Query> &args) const;

  /**
   */
  Query
  line(const std::vector<Query> &args) const;

  /**
   */
  Query
  literal(const std::vector<Query> &args) const;

  /**
   */
  Query
  lt(const std::vector<Query> &args) const;

  /**
   */
  Query
  make_array(const std::vector<Query> &args) const;

  /**
   */
  Query
  make_obj(const std::vector<Query> &args) const;

  /**
   */
  Query
  map(const std::vector<Query> &args) const;

  /**
   */
  Query
  march(const std::vector<Query> &args) const;

  /**
   */
  Query
  match(const std::vector<Query> &args) const;

  /**
   */
  Query
  max(const std::vector<Query> &args) const;

  /**
   */
  Query
  maxval(const std::vector<Query> &args) const;

  /**
   */
  Query
  may(const std::vector<Query> &args) const;

  /**
   */
  Query
  merge(const std::vector<Query> &args) const;

  /**
   */
  Query
  min(const std::vector<Query> &args) const;

  /**
   */
  Query
  minutes(const std::vector<Query> &args) const;

  /**
   */
  Query
  minval(const std::vector<Query> &args) const;

  /**
   */
  Query
  mod(const std::vector<Query> &args) const;

  /**
   */
  Query
  monday(const std::vector<Query> &args) const;

  /**
   */
  Query
  month(const std::vector<Query> &args) const;

  /**
   */
  Query
  mul(const std::vector<Query> &args) const;

  /**
   */
  Query
  ne(const std::vector<Query> &args) const;

  /**
   */
  Query
  not_(const std::vector<Query> &args) const;

  /**
   */
  Query
  november(const std::vector<Query> &args) const;

  /**
   */
  Query
  now(const std::vector<Query> &args) const;

  /**
   */
  Query
  nth(const std::vector<Query> &args) const;

  /**
   */
  Query
  object(const std::vector<Query> &args) const;

  /**
   */
  Query
  october(const std::vector<Query> &args) const;

  /**
   */
  Query
  offsets_of(const std::vector<Query> &args) const;

  /**
   */
  Query
  or_(const std::vector<Query> &args) const;

  /**
   */
  Query
  order_by(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  order_by(const std::vector<Query> &args) const;

  /**
   */
  Query
  outer_join(const std::vector<Query> &args) const;

  /**
   */
  Query
  pluck(const std::vector<Query> &args) const;

  /**
   */
  Query
  point(const std::vector<Query> &args) const;

  /**
   */
  Query
  polygon(const std::vector<Query> &args) const;

  /**
   */
  Query
  polygon_sub(const std::vector<Query> &args) const;

  /**
   */
  Query
  prepend(const std::vector<Query> &args) const;

  /**
   */
  Query
  random(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  random(const std::vector<Query> &args) const;

  /**
   */
  Query
  range(const std::vector<Query> &args) const;

  /**
   */
  Query
  rebalance(const std::vector<Query> &args) const;

  /**
   */
  Query
  reconfigure(const std::vector<Query> &args) const;

  /**
   */
  Query
  reduce(const std::vector<Query> &args) const;

  /**
   */
  Query
  replace(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  replace(const std::vector<Query> &args) const;

  /**
   */
  Query
  round(const std::vector<Query> &args) const;

  /**
   */
  Query
  sample(const std::vector<Query> &args) const;

  /**
   */
  Query
  saturday(const std::vector<Query> &args) const;

  /**
   */
  Query
  seconds(const std::vector<Query> &args) const;

  /**
   */
  Query
  september(const std::vector<Query> &args) const;

  /**
   */
  Query
  set_difference(const std::vector<Query> &args) const;

  /**
   */
  Query
  set_insert(const std::vector<Query> &args) const;

  /**
   */
  Query
  set_intersection(const std::vector<Query> &args) const;

  /**
   */
  Query
  set_union(const std::vector<Query> &args) const;

  /**
   */
  Query
  skip(const std::vector<Query> &args) const;

  /**
   */
  Query
  slice(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  slice(const std::vector<Query> &args) const;

  /**
   */
  Query
  splice_at(const std::vector<Query> &args) const;

  /**
   */
  Query
  split(const std::vector<Query> &args) const;

  /**
   */
  Query
  status(const std::vector<Query> &args) const;

  /**
   */
  Query
  sub(const std::vector<Query> &args) const;

  /**
   */
  Query
  sum(const std::vector<Query> &args) const;

  /**
   */
  Query
  sunday(const std::vector<Query> &args) const;

  /**
   */
  Query
  sync(const std::vector<Query> &args) const;

  /**
   */
  Query
  table(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  table(const std::vector<Query> &args) const;

  /**
   */
  Query
  table_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  table_create(const std::vector<Query> &args) const;

  /**
   */
  Query
  table_drop(const std::vector<Query> &args) const;

  /**
   */
  Query
  table_list(const std::vector<Query> &args) const;

  /**
   */
  Query
  thursday(const std::vector<Query> &args) const;

  /**
   */
  Query
  time(const std::vector<Query> &args) const;

  /**
   */
  Query
  timezone_(const std::vector<Query> &args) const;

  /**
   */
  Query
  time_of_day(const std::vector<Query> &args) const;

  /**
   */
  Query
  to_epoch_time(const std::vector<Query> &args) const;

  /**
   */
  Query
  to_geojson(const std::vector<Query> &args) const;

  /**
   */
  Query
  to_iso8601(const std::vector<Query> &args) const;

  /**
   */
  Query
  to_json_string(const std::vector<Query> &args) const;

  /**
   */
  Query
  tuesday(const std::vector<Query> &args) const;

  /**
   */
  Query
  type_of(const std::vector<Query> &args) const;

  /**
   */
  Query
  ungroup(const std::vector<Query> &args) const;

  /**
   */
  Query
  union_(const std::vector<Query> &args) const;

  /**
   */
  Query
  upcase(const std::vector<Query> &args) const;

  /**
   */
  Query
  update(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs) const;
  Query
  update(const std::vector<Query> &args) const;

  /**
   */
  Query
  uuid(const std::vector<Query> &args) const;

  /**
   */
  Query
  var(const std::vector<Query> &args) const;

  /**
   */
  Query
  wait(const std::vector<Query> &args) const;

  /**
   */
  Query
  wednesday(const std::vector<Query> &args) const;

  /**
   */
  Query
  without(const std::vector<Query> &args) const;

  /**
   */
  Query
  with_fields(const std::vector<Query> &args) const;

  /**
   */
  Query
  year(const std::vector<Query> &args) const;

  /**
   */
  Query
  zip(const std::vector<Query> &args) const;
};


/**
 */
Query
add(const std::vector<Query> &args);

/**
 */
Query
and_(const std::vector<Query> &args);

/**
 */
Query
append(const std::vector<Query> &args);

/**
 */
Query
april(const std::vector<Query> &args);

/**
 */
Query
args(const std::vector<Query> &args);

/**
 */
Query
asc(const std::vector<Query> &args);

/**
 */
Query
august(const std::vector<Query> &args);

/**
 */
Query
avg(const std::vector<Query> &args);

/**
 */
Query
between(const std::vector<Query> &args);

/**
 */
Query
between_deprecated(const std::vector<Query> &args);

/**
 */
Query
binary(const std::vector<Query> &args);

/**
 */
Query
bracket(const std::vector<Query> &args);

/**
 */
Query
branch(const std::vector<Query> &args);

/**
 */
Query
ceil(const std::vector<Query> &args);

/**
 */
Query
changes(const std::vector<Query> &args);

/**
 */
Query
change_at(const std::vector<Query> &args);

/**
 */
Query
circle(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
circle(const std::vector<Query> &args);

/**
 */
Query
coerce_to(const std::vector<Query> &args);

/**
 */
Query
concat_map(const std::vector<Query> &args);

/**
 */
Query
config(const std::vector<Query> &args);

/**
 */
Query
contains(const std::vector<Query> &args);

/**
 */
Query
count(const std::vector<Query> &args);

/**
 */
Query
date(const std::vector<Query> &args);

/**
 */
Query
datum(const std::vector<Query> &args);

/**
 */
Query
day(const std::vector<Query> &args);

/**
 */
Query
day_of_week(const std::vector<Query> &args);

/**
 */
Query
day_of_year(const std::vector<Query> &args);

/**
 */
Query
db(const std::vector<Query> &args);

/**
 */
Query
db_create(const std::vector<Query> &args);

/**
 */
Query
db_drop(const std::vector<Query> &args);

/**
 */
Query
db_list(const std::vector<Query> &args);

/**
 */
Query
december(const std::vector<Query> &args);

/**
 */
Query
default_(const std::vector<Query> &args);

/**
 */
Query
delete_(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
delete_(const std::vector<Query> &args);

/**
 */
Query
delete_at(const std::vector<Query> &args);

/**
 */
Query
desc(const std::vector<Query> &args);

/**
 */
Query
difference(const std::vector<Query> &args);

/**
 */
Query
distance(const std::vector<Query> &args);

/**
 */
Query
distinct(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
distinct(const std::vector<Query> &args);

/**
 */
Query
div(const std::vector<Query> &args);

/**
 */
Query
downcase(const std::vector<Query> &args);

/**
 */
Query
during(const std::vector<Query> &args);

/**
 */
Query
epoch_time(const std::vector<Query> &args);

/**
 */
Query
eq(const std::vector<Query> &args);

/**
 */
Query
eq_join(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
eq_join(const std::vector<Query> &args);

/**
 */
Query
error(const std::vector<Query> &args);

/**
 */
Query
february(const std::vector<Query> &args);

/**
 */
Query
fill(const std::vector<Query> &args);

/**
 */
Query
filter(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
filter(const std::vector<Query> &args);

/**
 */
Query
floor(const std::vector<Query> &args);

/**
 */
Query
for_each(const std::vector<Query> &args);

/**
 */
Query
friday(const std::vector<Query> &args);

/**
 */
Query
func(const std::vector<Query> &args);

/**
 */
Query
funcall(const std::vector<Query> &args);

/**
 */
Query
ge(const std::vector<Query> &args);

/**
 */
Query
geojson(const std::vector<Query> &args);

/**
 */
Query
get(const std::vector<Query> &args);

/**
 */
Query
get_all(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
get_all(const std::vector<Query> &args);

/**
 */
Query
get_field(const std::vector<Query> &args);

/**
 */
Query
get_intersecting(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
get_intersecting(const std::vector<Query> &args);

/**
 */
Query
get_nearest(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
get_nearest(const std::vector<Query> &args);

/**
 */
Query
group(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
group(const std::vector<Query> &args);

/**
 */
Query
gt(const std::vector<Query> &args);

/**
 */
Query
has_fields(const std::vector<Query> &args);

/**
 */
Query
hours(const std::vector<Query> &args);

/**
 */
Query
http(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
http(const std::vector<Query> &args);

/**
 */
Query
implicit_var(const std::vector<Query> &args);

/**
 */
Query
includes(const std::vector<Query> &args);

/**
 */
Query
index_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
index_create(const std::vector<Query> &args);

/**
 */
Query
index_drop(const std::vector<Query> &args);

/**
 */
Query
index_list(const std::vector<Query> &args);

/**
 */
Query
index_rename(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
index_rename(const std::vector<Query> &args);

/**
 */
Query
index_status(const std::vector<Query> &args);

/**
 */
Query
index_wait(const std::vector<Query> &args);

/**
 */
Query
info(const std::vector<Query> &args);

/**
 */
Query
inner_join(const std::vector<Query> &args);

/**
 */
Query
insert(const std::vector<Query> &args);

/**
 */
Query
insert_at(const std::vector<Query> &args);

/**
 */
Query
intersects(const std::vector<Query> &args);

/**
 */
Query
in_timezone(const std::vector<Query> &args);

/**
 */
Query
iso8601(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
iso8601(const std::vector<Query> &args);

/**
 */
Query
is_empty(const std::vector<Query> &args);

/**
 */
Query
january(const std::vector<Query> &args);

/**
 */
Query
javascript(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
javascript(const std::vector<Query> &args);

/**
 */
Query
json(const std::vector<Query> &args);

/**
 */
Query
july(const std::vector<Query> &args);

/**
 */
Query
june(const std::vector<Query> &args);

/**
 */
Query
keys(const std::vector<Query> &args);

/**
 */
Query
le(const std::vector<Query> &args);

/**
 */
Query
limit(const std::vector<Query> &args);

/**
 */
Query
line(const std::vector<Query> &args);

/**
 */
Query
literal(const std::vector<Query> &args);

/**
 */
Query
lt(const std::vector<Query> &args);

/**
 */
Query
make_array(const std::vector<Query> &args);

/**
 */
Query
make_obj(const std::vector<Query> &args);

/**
 */
Query
map(const std::vector<Query> &args);

/**
 */
Query
march(const std::vector<Query> &args);

/**
 */
Query
match(const std::vector<Query> &args);

/**
 */
Query
max(const std::vector<Query> &args);

/**
 */
Query
maxval(const std::vector<Query> &args);

/**
 */
Query
may(const std::vector<Query> &args);

/**
 */
Query
merge(const std::vector<Query> &args);

/**
 */
Query
min(const std::vector<Query> &args);

/**
 */
Query
minutes(const std::vector<Query> &args);

/**
 */
Query
minval(const std::vector<Query> &args);

/**
 */
Query
mod(const std::vector<Query> &args);

/**
 */
Query
monday(const std::vector<Query> &args);

/**
 */
Query
month(const std::vector<Query> &args);

/**
 */
Query
mul(const std::vector<Query> &args);

/**
 */
Query
ne(const std::vector<Query> &args);

/**
 */
Query
not_(const std::vector<Query> &args);

/**
 */
Query
november(const std::vector<Query> &args);

/**
 */
Query
now(const std::vector<Query> &args);

/**
 */
Query
nth(const std::vector<Query> &args);

/**
 */
Query
object(const std::vector<Query> &args);

/**
 */
Query
october(const std::vector<Query> &args);

/**
 */
Query
offsets_of(const std::vector<Query> &args);

/**
 */
Query
or_(const std::vector<Query> &args);

/**
 */
Query
order_by(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
order_by(const std::vector<Query> &args);

/**
 */
Query
outer_join(const std::vector<Query> &args);

/**
 */
Query
pluck(const std::vector<Query> &args);

/**
 */
Query
point(const std::vector<Query> &args);

/**
 */
Query
polygon(const std::vector<Query> &args);

/**
 */
Query
polygon_sub(const std::vector<Query> &args);

/**
 */
Query
prepend(const std::vector<Query> &args);

/**
 */
Query
random(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
random(const std::vector<Query> &args);

/**
 */
Query
range(const std::vector<Query> &args);

/**
 */
Query
rebalance(const std::vector<Query> &args);

/**
 */
Query
reconfigure(const std::vector<Query> &args);

/**
 */
Query
reduce(const std::vector<Query> &args);

/**
 */
Query
replace(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
replace(const std::vector<Query> &args);

/**
 */
Query
round(const std::vector<Query> &args);

/**
 */
Query
sample(const std::vector<Query> &args);

/**
 */
Query
saturday(const std::vector<Query> &args);

/**
 */
Query
seconds(const std::vector<Query> &args);

/**
 */
Query
september(const std::vector<Query> &args);

/**
 */
Query
set_difference(const std::vector<Query> &args);

/**
 */
Query
set_insert(const std::vector<Query> &args);

/**
 */
Query
set_intersection(const std::vector<Query> &args);

/**
 */
Query
set_union(const std::vector<Query> &args);

/**
 */
Query
skip(const std::vector<Query> &args);

/**
 */
Query
slice(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
slice(const std::vector<Query> &args);

/**
 */
Query
splice_at(const std::vector<Query> &args);

/**
 */
Query
split(const std::vector<Query> &args);

/**
 */
Query
status(const std::vector<Query> &args);

/**
 */
Query
sub(const std::vector<Query> &args);

/**
 */
Query
sum(const std::vector<Query> &args);

/**
 */
Query
sunday(const std::vector<Query> &args);

/**
 */
Query
sync(const std::vector<Query> &args);

/**
 */
Query
table(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
table(const std::vector<Query> &args);

/**
 */
Query
table_create(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
table_create(const std::vector<Query> &args);

/**
 */
Query
table_drop(const std::vector<Query> &args);

/**
 */
Query
table_list(const std::vector<Query> &args);

/**
 */
Query
thursday(const std::vector<Query> &args);

/**
 */
Query
time(const std::vector<Query> &args);

/**
 */
Query
timezone_(const std::vector<Query> &args);

/**
 */
Query
time_of_day(const std::vector<Query> &args);

/**
 */
Query
to_epoch_time(const std::vector<Query> &args);

/**
 */
Query
to_geojson(const std::vector<Query> &args);

/**
 */
Query
to_iso8601(const std::vector<Query> &args);

/**
 */
Query
to_json_string(const std::vector<Query> &args);

/**
 */
Query
tuesday(const std::vector<Query> &args);

/**
 */
Query
type_of(const std::vector<Query> &args);

/**
 */
Query
ungroup(const std::vector<Query> &args);

/**
 */
Query
union_(const std::vector<Query> &args);

/**
 */
Query
upcase(const std::vector<Query> &args);

/**
 */
Query
update(const std::vector<Query> &args, const std::map<std::string, Query> &kwargs);
Query
update(const std::vector<Query> &args);

/**
 */
Query
uuid(const std::vector<Query> &args);

/**
 */
Query
var(const std::vector<Query> &args);

/**
 */
Query
wait(const std::vector<Query> &args);

/**
 */
Query
wednesday(const std::vector<Query> &args);

/**
 */
Query
without(const std::vector<Query> &args);

/**
 */
Query
with_fields(const std::vector<Query> &args);

/**
 */
Query
year(const std::vector<Query> &args);

/**
 */
Query
zip(const std::vector<Query> &args);

}  // namespace ReQL

#endif  // REQL_CPP_AST_HPP_
