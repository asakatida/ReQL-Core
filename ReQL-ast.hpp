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

#include "ReQL-expr.hpp"

#ifndef REQL_AST_HPP
#define REQL_AST_HPP

namespace ReQL {

class AST : public Expr {
protected:
  AST() : Expr() {};
  AST(ReQL_AST_Function f, std::vector<Query> args, std::map<std::string, Query> kwargs) : Expr(f, args, kwargs) {};
  explicit AST(ReQL_Obj_t *val) : Expr(val) {};
  explicit AST(std::string val) : Expr(val) {};
  explicit AST(double val) : Expr(val) {};
  explicit AST(bool val) : Expr(val) {};
  explicit AST(std::vector<Query> val) : Expr(val) {};
  explicit AST(std::map<std::string, Query> val) : Expr(val) {};

  AST(const AST &other) : Expr(other) {};
  AST(const AST &&other) : Expr(other) {};

public:
  /**
   */
  Query
  add(std::vector<Query>);

  /**
   */
  Query
  all(std::vector<Query>);

  /**
   */
  Query
  any(std::vector<Query>);

  /**
   */
  Query
  append(std::vector<Query>);

  /**
   */
  Query
  april(std::vector<Query>);

  /**
   */
  Query
  args(std::vector<Query>);

  /**
   */
  Query
  asc(std::vector<Query>);

  /**
   */
  Query
  august(std::vector<Query>);

  /**
   */
  Query
  avg(std::vector<Query>);

  /**
   */
  Query
  between(std::vector<Query>);

  /**
   */
  Query
  binary(std::vector<Query>);

  /**
   */
  Query
  bracket(std::vector<Query>);

  /**
   */
  Query
  branch(std::vector<Query>);

  /**
   */
  Query
  changes(std::vector<Query>);

  /**
   */
  Query
  change_at(std::vector<Query>);

  /**
   */
  Query
  circle(std::vector<Query>, std::map<std::string, Query>);
  Query
  circle(std::vector<Query>);

  /**
   */
  Query
  coerce_to(std::vector<Query>);

  /**
   */
  Query
  concat_map(std::vector<Query>);

  /**
   */
  Query
  config(std::vector<Query>);

  /**
   */
  Query
  contains(std::vector<Query>);

  /**
   */
  Query
  count(std::vector<Query>);

  /**
   */
  Query
  date(std::vector<Query>);

  /**
   */
  Query
  datum(std::vector<Query>);

  /**
   */
  Query
  day(std::vector<Query>);

  /**
   */
  Query
  day_of_week(std::vector<Query>);

  /**
   */
  Query
  day_of_year(std::vector<Query>);

  /**
   */
  Query
  db(std::vector<Query>);

  /**
   */
  Query
  db_create(std::vector<Query>);

  /**
   */
  Query
  db_drop(std::vector<Query>);

  /**
   */
  Query
  db_list(std::vector<Query>);

  /**
   */
  Query
  december(std::vector<Query>);

  /**
   */
  Query
  default_(std::vector<Query>);

  /**
   */
  Query
  delete_(std::vector<Query>, std::map<std::string, Query>);
  Query
  delete_(std::vector<Query>);

  /**
   */
  Query
  delete_at(std::vector<Query>);

  /**
   */
  Query
  desc(std::vector<Query>);

  /**
   */
  Query
  difference(std::vector<Query>);

  /**
   */
  Query
  distance(std::vector<Query>);

  /**
   */
  Query
  distinct(std::vector<Query>, std::map<std::string, Query>);
  Query
  distinct(std::vector<Query>);

  /**
   */
  Query
  div(std::vector<Query>);

  /**
   */
  Query
  downcase(std::vector<Query>);

  /**
   */
  Query
  during(std::vector<Query>);

  /**
   */
  Query
  epoch_time(std::vector<Query>);

  /**
   */
  Query
  eq(std::vector<Query>);

  /**
   */
  Query
  eq_join(std::vector<Query>, std::map<std::string, Query>);
  Query
  eq_join(std::vector<Query>);

  /**
   */
  Query
  error(std::vector<Query>);

  /**
   */
  Query
  february(std::vector<Query>);

  /**
   */
  Query
  fill(std::vector<Query>);

  /**
   */
  Query
  filter(std::vector<Query>, std::map<std::string, Query>);
  Query
  filter(std::vector<Query>);

  /**
   */
  Query
  for_each(std::vector<Query>);

  /**
   */
  Query
  friday(std::vector<Query>);

  /**
   */
  Query
  func(std::vector<Query>);

  /**
   */
  Query
  funcall(std::vector<Query>);

  /**
   */
  Query
  ge(std::vector<Query>);

  /**
   */
  Query
  geojson(std::vector<Query>);

  /**
   */
  Query
  get(std::vector<Query>);

  /**
   */
  Query
  get_all(std::vector<Query>, std::map<std::string, Query>);
  Query
  get_all(std::vector<Query>);

  /**
   */
  Query
  get_field(std::vector<Query>);

  /**
   */
  Query
  get_intersecting(std::vector<Query>, std::map<std::string, Query>);
  Query
  get_intersecting(std::vector<Query>);

  /**
   */
  Query
  get_nearest(std::vector<Query>, std::map<std::string, Query>);
  Query
  get_nearest(std::vector<Query>);

  /**
   */
  Query
  group(std::vector<Query>, std::map<std::string, Query>);
  Query
  group(std::vector<Query>);

  /**
   */
  Query
  gt(std::vector<Query>);

  /**
   */
  Query
  has_fields(std::vector<Query>);

  /**
   */
  Query
  hours(std::vector<Query>);

  /**
   */
  Query
  http(std::vector<Query>, std::map<std::string, Query>);
  Query
  http(std::vector<Query>);

  /**
   */
  Query
  implicit_var(std::vector<Query>);

  /**
   */
  Query
  includes(std::vector<Query>);

  /**
   */
  Query
  indexes_of(std::vector<Query>);

  /**
   */
  Query
  index_create(std::vector<Query>, std::map<std::string, Query>);
  Query
  index_create(std::vector<Query>);

  /**
   */
  Query
  index_drop(std::vector<Query>);

  /**
   */
  Query
  index_list(std::vector<Query>);

  /**
   */
  Query
  index_rename(std::vector<Query>, std::map<std::string, Query>);
  Query
  index_rename(std::vector<Query>);

  /**
   */
  Query
  index_status(std::vector<Query>);

  /**
   */
  Query
  index_wait(std::vector<Query>);

  /**
   */
  Query
  info(std::vector<Query>);

  /**
   */
  Query
  inner_join(std::vector<Query>);

  /**
   */
  Query
  insert(std::vector<Query>);

  /**
   */
  Query
  insert_at(std::vector<Query>);

  /**
   */
  Query
  intersects(std::vector<Query>);

  /**
   */
  Query
  in_timezone(std::vector<Query>);

  /**
   */
  Query
  iso8601(std::vector<Query>, std::map<std::string, Query>);
  Query
  iso8601(std::vector<Query>);

  /**
   */
  Query
  is_empty(std::vector<Query>);

  /**
   */
  Query
  january(std::vector<Query>);

  /**
   */
  Query
  javascript(std::vector<Query>, std::map<std::string, Query>);
  Query
  javascript(std::vector<Query>);

  /**
   */
  Query
  json(std::vector<Query>);

  /**
   */
  Query
  july(std::vector<Query>);

  /**
   */
  Query
  june(std::vector<Query>);

  /**
   */
  Query
  keys(std::vector<Query>);

  /**
   */
  Query
  le(std::vector<Query>);

  /**
   */
  Query
  limit(std::vector<Query>);

  /**
   */
  Query
  line(std::vector<Query>);

  /**
   */
  Query
  literal(std::vector<Query>);

  /**
   */
  Query
  lt(std::vector<Query>);

  /**
   */
  Query
  make_array(std::vector<Query>);

  /**
   */
  Query
  make_obj(std::vector<Query>);

  /**
   */
  Query
  map(std::vector<Query>);

  /**
   */
  Query
  march(std::vector<Query>);

  /**
   */
  Query
  match(std::vector<Query>);

  /**
   */
  Query
  max(std::vector<Query>);

  /**
   */
  Query
  may(std::vector<Query>);

  /**
   */
  Query
  merge(std::vector<Query>);

  /**
   */
  Query
  min(std::vector<Query>);

  /**
   */
  Query
  minutes(std::vector<Query>);

  /**
   */
  Query
  mod(std::vector<Query>);

  /**
   */
  Query
  monday(std::vector<Query>);

  /**
   */
  Query
  month(std::vector<Query>);

  /**
   */
  Query
  mul(std::vector<Query>);

  /**
   */
  Query
  ne(std::vector<Query>);

  /**
   */
  Query
  not_(std::vector<Query>);

  /**
   */
  Query
  november(std::vector<Query>);

  /**
   */
  Query
  now(std::vector<Query>);

  /**
   */
  Query
  nth(std::vector<Query>);

  /**
   */
  Query
  object(std::vector<Query>);

  /**
   */
  Query
  october(std::vector<Query>);

  /**
   */
  Query
  order_by(std::vector<Query>, std::map<std::string, Query>);
  Query
  order_by(std::vector<Query>);

  /**
   */
  Query
  outer_join(std::vector<Query>);

  /**
   */
  Query
  pluck(std::vector<Query>);

  /**
   */
  Query
  point(std::vector<Query>);

  /**
   */
  Query
  polygon(std::vector<Query>);

  /**
   */
  Query
  polygon_sub(std::vector<Query>);

  /**
   */
  Query
  prepend(std::vector<Query>);

  /**
   */
  Query
  random(std::vector<Query>, std::map<std::string, Query>);
  Query
  random(std::vector<Query>);

  /**
   */
  Query
  range(std::vector<Query>);

  /**
   */
  Query
  rebalance(std::vector<Query>);

  /**
   */
  Query
  reconfigure(std::vector<Query>);

  /**
   */
  Query
  reduce(std::vector<Query>);

  /**
   */
  Query
  replace(std::vector<Query>, std::map<std::string, Query>);
  Query
  replace(std::vector<Query>);

  /**
   */
  Query
  sample(std::vector<Query>);

  /**
   */
  Query
  saturday(std::vector<Query>);

  /**
   */
  Query
  seconds(std::vector<Query>);

  /**
   */
  Query
  september(std::vector<Query>);

  /**
   */
  Query
  set_difference(std::vector<Query>);

  /**
   */
  Query
  set_insert(std::vector<Query>);

  /**
   */
  Query
  set_intersection(std::vector<Query>);

  /**
   */
  Query
  set_union(std::vector<Query>);

  /**
   */
  Query
  skip(std::vector<Query>);

  /**
   */
  Query
  slice(std::vector<Query>, std::map<std::string, Query>);
  Query
  slice(std::vector<Query>);

  /**
   */
  Query
  splice_at(std::vector<Query>);

  /**
   */
  Query
  split(std::vector<Query>);

  /**
   */
  Query
  status(std::vector<Query>);

  /**
   */
  Query
  sub(std::vector<Query>);

  /**
   */
  Query
  sum(std::vector<Query>);

  /**
   */
  Query
  sunday(std::vector<Query>);

  /**
   */
  Query
  sync(std::vector<Query>);

  /**
   */
  Query
  table(std::vector<Query>, std::map<std::string, Query>);
  Query
  table(std::vector<Query>);

  /**
   */
  Query
  table_create(std::vector<Query>, std::map<std::string, Query>);
  Query
  table_create(std::vector<Query>);

  /**
   */
  Query
  table_drop(std::vector<Query>);

  /**
   */
  Query
  table_list(std::vector<Query>);

  /**
   */
  Query
  thursday(std::vector<Query>);

  /**
   */
  Query
  time(std::vector<Query>);

  /**
   */
  Query
  timezone_(std::vector<Query>);

  /**
   */
  Query
  time_of_day(std::vector<Query>);

  /**
   */
  Query
  to_epoch_time(std::vector<Query>);

  /**
   */
  Query
  to_geojson(std::vector<Query>);

  /**
   */
  Query
  to_iso8601(std::vector<Query>);

  /**
   */
  Query
  to_json_string(std::vector<Query>);

  /**
   */
  Query
  tuesday(std::vector<Query>);

  /**
   */
  Query
  type_of(std::vector<Query>);

  /**
   */
  Query
  ungroup(std::vector<Query>);

  /**
   */
  Query
  union_(std::vector<Query>);

  /**
   */
  Query
  upcase(std::vector<Query>);

  /**
   */
  Query
  update(std::vector<Query>, std::map<std::string, Query>);
  Query
  update(std::vector<Query>);

  /**
   */
  Query
  uuid(std::vector<Query>);

  /**
   */
  Query
  var(std::vector<Query>);

  /**
   */
  Query
  wait(std::vector<Query>);

  /**
   */
  Query
  wednesday(std::vector<Query>);

  /**
   */
  Query
  without(std::vector<Query>);

  /**
   */
  Query
  with_fields(std::vector<Query>);

  /**
   */
  Query
  year(std::vector<Query>);

  /**
   */
  Query
  zip(std::vector<Query>);
};


/**
 */
Query
add(std::vector<Query>);

/**
 */
Query
all(std::vector<Query>);

/**
 */
Query
any(std::vector<Query>);

/**
 */
Query
append(std::vector<Query>);

/**
 */
Query
april(std::vector<Query>);

/**
 */
Query
args(std::vector<Query>);

/**
 */
Query
asc(std::vector<Query>);

/**
 */
Query
august(std::vector<Query>);

/**
 */
Query
avg(std::vector<Query>);

/**
 */
Query
between(std::vector<Query>);

/**
 */
Query
binary(std::vector<Query>);

/**
 */
Query
bracket(std::vector<Query>);

/**
 */
Query
branch(std::vector<Query>);

/**
 */
Query
changes(std::vector<Query>);

/**
 */
Query
change_at(std::vector<Query>);

/**
 */
Query
circle(std::vector<Query>, std::map<std::string, Query>);
Query
circle(std::vector<Query>);

/**
 */
Query
coerce_to(std::vector<Query>);

/**
 */
Query
concat_map(std::vector<Query>);

/**
 */
Query
config(std::vector<Query>);

/**
 */
Query
contains(std::vector<Query>);

/**
 */
Query
count(std::vector<Query>);

/**
 */
Query
date(std::vector<Query>);

/**
 */
Query
datum(std::vector<Query>);

/**
 */
Query
day(std::vector<Query>);

/**
 */
Query
day_of_week(std::vector<Query>);

/**
 */
Query
day_of_year(std::vector<Query>);

/**
 */
Query
db(std::vector<Query>);

/**
 */
Query
db_create(std::vector<Query>);

/**
 */
Query
db_drop(std::vector<Query>);

/**
 */
Query
db_list(std::vector<Query>);

/**
 */
Query
december(std::vector<Query>);

/**
 */
Query
default_(std::vector<Query>);

/**
 */
Query
delete_(std::vector<Query>, std::map<std::string, Query>);
Query
delete_(std::vector<Query>);

/**
 */
Query
delete_at(std::vector<Query>);

/**
 */
Query
desc(std::vector<Query>);

/**
 */
Query
difference(std::vector<Query>);

/**
 */
Query
distance(std::vector<Query>);

/**
 */
Query
distinct(std::vector<Query>, std::map<std::string, Query>);
Query
distinct(std::vector<Query>);

/**
 */
Query
div(std::vector<Query>);

/**
 */
Query
downcase(std::vector<Query>);

/**
 */
Query
during(std::vector<Query>);

/**
 */
Query
epoch_time(std::vector<Query>);

/**
 */
Query
eq(std::vector<Query>);

/**
 */
Query
eq_join(std::vector<Query>, std::map<std::string, Query>);
Query
eq_join(std::vector<Query>);

/**
 */
Query
error(std::vector<Query>);

/**
 */
Query
february(std::vector<Query>);

/**
 */
Query
fill(std::vector<Query>);

/**
 */
Query
filter(std::vector<Query>, std::map<std::string, Query>);
Query
filter(std::vector<Query>);

/**
 */
Query
for_each(std::vector<Query>);

/**
 */
Query
friday(std::vector<Query>);

/**
 */
Query
func(std::vector<Query>);

/**
 */
Query
funcall(std::vector<Query>);

/**
 */
Query
ge(std::vector<Query>);

/**
 */
Query
geojson(std::vector<Query>);

/**
 */
Query
get(std::vector<Query>);

/**
 */
Query
get_all(std::vector<Query>, std::map<std::string, Query>);
Query
get_all(std::vector<Query>);

/**
 */
Query
get_field(std::vector<Query>);

/**
 */
Query
get_intersecting(std::vector<Query>, std::map<std::string, Query>);
Query
get_intersecting(std::vector<Query>);

/**
 */
Query
get_nearest(std::vector<Query>, std::map<std::string, Query>);
Query
get_nearest(std::vector<Query>);

/**
 */
Query
group(std::vector<Query>, std::map<std::string, Query>);
Query
group(std::vector<Query>);

/**
 */
Query
gt(std::vector<Query>);

/**
 */
Query
has_fields(std::vector<Query>);

/**
 */
Query
hours(std::vector<Query>);

/**
 */
Query
http(std::vector<Query>, std::map<std::string, Query>);
Query
http(std::vector<Query>);

/**
 */
Query
implicit_var(std::vector<Query>);

/**
 */
Query
includes(std::vector<Query>);

/**
 */
Query
indexes_of(std::vector<Query>);

/**
 */
Query
index_create(std::vector<Query>, std::map<std::string, Query>);
Query
index_create(std::vector<Query>);

/**
 */
Query
index_drop(std::vector<Query>);

/**
 */
Query
index_list(std::vector<Query>);

/**
 */
Query
index_rename(std::vector<Query>, std::map<std::string, Query>);
Query
index_rename(std::vector<Query>);

/**
 */
Query
index_status(std::vector<Query>);

/**
 */
Query
index_wait(std::vector<Query>);

/**
 */
Query
info(std::vector<Query>);

/**
 */
Query
inner_join(std::vector<Query>);

/**
 */
Query
insert(std::vector<Query>);

/**
 */
Query
insert_at(std::vector<Query>);

/**
 */
Query
intersects(std::vector<Query>);

/**
 */
Query
in_timezone(std::vector<Query>);

/**
 */
Query
iso8601(std::vector<Query>, std::map<std::string, Query>);
Query
iso8601(std::vector<Query>);

/**
 */
Query
is_empty(std::vector<Query>);

/**
 */
Query
january(std::vector<Query>);

/**
 */
Query
javascript(std::vector<Query>, std::map<std::string, Query>);
Query
javascript(std::vector<Query>);

/**
 */
Query
json(std::vector<Query>);

/**
 */
Query
july(std::vector<Query>);

/**
 */
Query
june(std::vector<Query>);

/**
 */
Query
keys(std::vector<Query>);

/**
 */
Query
le(std::vector<Query>);

/**
 */
Query
limit(std::vector<Query>);

/**
 */
Query
line(std::vector<Query>);

/**
 */
Query
literal(std::vector<Query>);

/**
 */
Query
lt(std::vector<Query>);

/**
 */
Query
make_array(std::vector<Query>);

/**
 */
Query
make_obj(std::vector<Query>);

/**
 */
Query
map(std::vector<Query>);

/**
 */
Query
march(std::vector<Query>);

/**
 */
Query
match(std::vector<Query>);

/**
 */
Query
max(std::vector<Query>);

/**
 */
Query
may(std::vector<Query>);

/**
 */
Query
merge(std::vector<Query>);

/**
 */
Query
min(std::vector<Query>);

/**
 */
Query
minutes(std::vector<Query>);

/**
 */
Query
mod(std::vector<Query>);

/**
 */
Query
monday(std::vector<Query>);

/**
 */
Query
month(std::vector<Query>);

/**
 */
Query
mul(std::vector<Query>);

/**
 */
Query
ne(std::vector<Query>);

/**
 */
Query
not_(std::vector<Query>);

/**
 */
Query
november(std::vector<Query>);

/**
 */
Query
now(std::vector<Query>);

/**
 */
Query
nth(std::vector<Query>);

/**
 */
Query
object(std::vector<Query>);

/**
 */
Query
october(std::vector<Query>);

/**
 */
Query
order_by(std::vector<Query>, std::map<std::string, Query>);
Query
order_by(std::vector<Query>);

/**
 */
Query
outer_join(std::vector<Query>);

/**
 */
Query
pluck(std::vector<Query>);

/**
 */
Query
point(std::vector<Query>);

/**
 */
Query
polygon(std::vector<Query>);

/**
 */
Query
polygon_sub(std::vector<Query>);

/**
 */
Query
prepend(std::vector<Query>);

/**
 */
Query
random(std::vector<Query>, std::map<std::string, Query>);
Query
random(std::vector<Query>);

/**
 */
Query
range(std::vector<Query>);

/**
 */
Query
rebalance(std::vector<Query>);

/**
 */
Query
reconfigure(std::vector<Query>);

/**
 */
Query
reduce(std::vector<Query>);

/**
 */
Query
replace(std::vector<Query>, std::map<std::string, Query>);
Query
replace(std::vector<Query>);

/**
 */
Query
sample(std::vector<Query>);

/**
 */
Query
saturday(std::vector<Query>);

/**
 */
Query
seconds(std::vector<Query>);

/**
 */
Query
september(std::vector<Query>);

/**
 */
Query
set_difference(std::vector<Query>);

/**
 */
Query
set_insert(std::vector<Query>);

/**
 */
Query
set_intersection(std::vector<Query>);

/**
 */
Query
set_union(std::vector<Query>);

/**
 */
Query
skip(std::vector<Query>);

/**
 */
Query
slice(std::vector<Query>, std::map<std::string, Query>);
Query
slice(std::vector<Query>);

/**
 */
Query
splice_at(std::vector<Query>);

/**
 */
Query
split(std::vector<Query>);

/**
 */
Query
status(std::vector<Query>);

/**
 */
Query
sub(std::vector<Query>);

/**
 */
Query
sum(std::vector<Query>);

/**
 */
Query
sunday(std::vector<Query>);

/**
 */
Query
sync(std::vector<Query>);

/**
 */
Query
table(std::vector<Query>, std::map<std::string, Query>);
Query
table(std::vector<Query>);

/**
 */
Query
table_create(std::vector<Query>, std::map<std::string, Query>);
Query
table_create(std::vector<Query>);

/**
 */
Query
table_drop(std::vector<Query>);

/**
 */
Query
table_list(std::vector<Query>);

/**
 */
Query
thursday(std::vector<Query>);

/**
 */
Query
time(std::vector<Query>);

/**
 */
Query
timezone_(std::vector<Query>);

/**
 */
Query
time_of_day(std::vector<Query>);

/**
 */
Query
to_epoch_time(std::vector<Query>);

/**
 */
Query
to_geojson(std::vector<Query>);

/**
 */
Query
to_iso8601(std::vector<Query>);

/**
 */
Query
to_json_string(std::vector<Query>);

/**
 */
Query
tuesday(std::vector<Query>);

/**
 */
Query
type_of(std::vector<Query>);

/**
 */
Query
ungroup(std::vector<Query>);

/**
 */
Query
union_(std::vector<Query>);

/**
 */
Query
upcase(std::vector<Query>);

/**
 */
Query
update(std::vector<Query>, std::map<std::string, Query>);
Query
update(std::vector<Query>);

/**
 */
Query
uuid(std::vector<Query>);

/**
 */
Query
var(std::vector<Query>);

/**
 */
Query
wait(std::vector<Query>);

/**
 */
Query
wednesday(std::vector<Query>);

/**
 */
Query
without(std::vector<Query>);

/**
 */
Query
with_fields(std::vector<Query>);

/**
 */
Query
year(std::vector<Query>);

/**
 */
Query
zip(std::vector<Query>);

}

#endif
