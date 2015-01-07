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

#include "ReQL-expr.hpp"

#ifndef _REQL_AST_CPP
#define _REQL_AST_CPP

namespace ReQL {

class AST : public Expr {
public:

  AST() : Expr() {};
  explicit AST(_ReQL_Op val) : Expr(val) {};
  explicit AST(std::string val) : Expr(val) {};
  explicit AST(double val) : Expr(val) {};
  explicit AST(bool val) : Expr(val) {};
  explicit AST(std::vector<Query> val) : Expr(val) {};
  explicit AST(std::map<std::string, Query> val) : Expr(val) {};

  /**
   */
  AST add(std::vector<Query>);

  /**
   */
  AST all(std::vector<Query>);

  /**
   */
  AST any(std::vector<Query>);

  /**
   */
  AST append(std::vector<Query>);

  /**
   */
  AST april(std::vector<Query>);

  /**
   */
  AST args(std::vector<Query>);

  /**
   */
  AST asc(std::vector<Query>);

  /**
   */
  AST august(std::vector<Query>);

  /**
   */
  AST avg(std::vector<Query>);

  /**
   */
  AST between(std::vector<Query>);

  /**
   */
  AST binary(std::vector<Query>);

  /**
   */
  AST bracket(std::vector<Query>);

  /**
   */
  AST branch(std::vector<Query>);

  /**
   */
  AST changes(std::vector<Query>);

  /**
   */
  AST change_at(std::vector<Query>);

  /**
   */
  AST circle(std::vector<Query>, std::map<std::string, Query>);
  AST circle(std::vector<Query>);

  /**
   */
  AST coerce_to(std::vector<Query>);

  /**
   */
  AST concat_map(std::vector<Query>);

  /**
   */
  AST contains(std::vector<Query>);

  /**
   */
  AST count(std::vector<Query>);

  /**
   */
  AST date(std::vector<Query>);

  /**
   */
  AST datum(std::vector<Query>);

  /**
   */
  AST day(std::vector<Query>);

  /**
   */
  AST day_of_week(std::vector<Query>);

  /**
   */
  AST day_of_year(std::vector<Query>);

  /**
   */
  AST db(std::vector<Query>);

  /**
   */
  AST db_config(std::vector<Query>);

  /**
   */
  AST db_create(std::vector<Query>);

  /**
   */
  AST db_drop(std::vector<Query>);

  /**
   */
  AST db_list(std::vector<Query>);

  /**
   */
  AST december(std::vector<Query>);

  /**
   */
  AST default_(std::vector<Query>);

  /**
   */
  AST delete_(std::vector<Query>, std::map<std::string, Query>);
  AST delete_(std::vector<Query>);

  /**
   */
  AST delete_at(std::vector<Query>);

  /**
   */
  AST desc(std::vector<Query>);

  /**
   */
  AST difference(std::vector<Query>);

  /**
   */
  AST distance(std::vector<Query>);

  /**
   */
  AST distinct(std::vector<Query>, std::map<std::string, Query>);
  AST distinct(std::vector<Query>);

  /**
   */
  AST div(std::vector<Query>);

  /**
   */
  AST downcase(std::vector<Query>);

  /**
   */
  AST during(std::vector<Query>);

  /**
   */
  AST epoch_time(std::vector<Query>);

  /**
   */
  AST eq(std::vector<Query>);

  /**
   */
  AST eq_join(std::vector<Query>, std::map<std::string, Query>);
  AST eq_join(std::vector<Query>);

  /**
   */
  AST error(std::vector<Query>);

  /**
   */
  AST february(std::vector<Query>);

  /**
   */
  AST fill(std::vector<Query>);

  /**
   */
  AST filter(std::vector<Query>, std::map<std::string, Query>);
  AST filter(std::vector<Query>);

  /**
   */
  AST for_each(std::vector<Query>);

  /**
   */
  AST friday(std::vector<Query>);

  /**
   */
  AST func(std::vector<Query>);

  /**
   */
  AST funcall(std::vector<Query>);

  /**
   */
  AST ge(std::vector<Query>);

  /**
   */
  AST geojson(std::vector<Query>);

  /**
   */
  AST get(std::vector<Query>);

  /**
   */
  AST get_all(std::vector<Query>, std::map<std::string, Query>);
  AST get_all(std::vector<Query>);

  /**
   */
  AST get_field(std::vector<Query>);

  /**
   */
  AST get_intersecting(std::vector<Query>, std::map<std::string, Query>);
  AST get_intersecting(std::vector<Query>);

  /**
   */
  AST get_nearest(std::vector<Query>, std::map<std::string, Query>);
  AST get_nearest(std::vector<Query>);

  /**
   */
  AST group(std::vector<Query>, std::map<std::string, Query>);
  AST group(std::vector<Query>);

  /**
   */
  AST gt(std::vector<Query>);

  /**
   */
  AST has_fields(std::vector<Query>);

  /**
   */
  AST hours(std::vector<Query>);

  /**
   */
  AST http(std::vector<Query>, std::map<std::string, Query>);
  AST http(std::vector<Query>);

  /**
   */
  AST implicit_var(std::vector<Query>);

  /**
   */
  AST includes(std::vector<Query>);

  /**
   */
  AST indexes_of(std::vector<Query>);

  /**
   */
  AST index_create(std::vector<Query>, std::map<std::string, Query>);
  AST index_create(std::vector<Query>);

  /**
   */
  AST index_drop(std::vector<Query>);

  /**
   */
  AST index_list(std::vector<Query>);

  /**
   */
  AST index_rename(std::vector<Query>, std::map<std::string, Query>);
  AST index_rename(std::vector<Query>);

  /**
   */
  AST index_status(std::vector<Query>);

  /**
   */
  AST index_wait(std::vector<Query>);

  /**
   */
  AST info(std::vector<Query>);

  /**
   */
  AST inner_join(std::vector<Query>);

  /**
   */
  AST insert(std::vector<Query>);

  /**
   */
  AST insert_at(std::vector<Query>);

  /**
   */
  AST intersects(std::vector<Query>);

  /**
   */
  AST in_timezone(std::vector<Query>);

  /**
   */
  AST iso8601(std::vector<Query>, std::map<std::string, Query>);
  AST iso8601(std::vector<Query>);

  /**
   */
  AST is_empty(std::vector<Query>);

  /**
   */
  AST january(std::vector<Query>);

  /**
   */
  AST javascript(std::vector<Query>, std::map<std::string, Query>);
  AST javascript(std::vector<Query>);

  /**
   */
  AST json(std::vector<Query>);

  /**
   */
  AST july(std::vector<Query>);

  /**
   */
  AST june(std::vector<Query>);

  /**
   */
  AST keys(std::vector<Query>);

  /**
   */
  AST le(std::vector<Query>);

  /**
   */
  AST limit(std::vector<Query>);

  /**
   */
  AST line(std::vector<Query>);

  /**
   */
  AST literal(std::vector<Query>);

  /**
   */
  AST lt(std::vector<Query>);

  /**
   */
  AST make_array(std::vector<Query>);

  /**
   */
  AST make_obj(std::vector<Query>);

  /**
   */
  AST map(std::vector<Query>);

  /**
   */
  AST march(std::vector<Query>);

  /**
   */
  AST match(std::vector<Query>);

  /**
   */
  AST max(std::vector<Query>);

  /**
   */
  AST may(std::vector<Query>);

  /**
   */
  AST merge(std::vector<Query>);

  /**
   */
  AST min(std::vector<Query>);

  /**
   */
  AST minutes(std::vector<Query>);

  /**
   */
  AST mod(std::vector<Query>);

  /**
   */
  AST monday(std::vector<Query>);

  /**
   */
  AST month(std::vector<Query>);

  /**
   */
  AST mul(std::vector<Query>);

  /**
   */
  AST ne(std::vector<Query>);

  /**
   */
  AST not_(std::vector<Query>);

  /**
   */
  AST november(std::vector<Query>);

  /**
   */
  AST now(std::vector<Query>);

  /**
   */
  AST nth(std::vector<Query>);

  /**
   */
  AST object(std::vector<Query>);

  /**
   */
  AST october(std::vector<Query>);

  /**
   */
  AST order_by(std::vector<Query>, std::map<std::string, Query>);
  AST order_by(std::vector<Query>);

  /**
   */
  AST outer_join(std::vector<Query>);

  /**
   */
  AST pluck(std::vector<Query>);

  /**
   */
  AST point(std::vector<Query>);

  /**
   */
  AST polygon(std::vector<Query>);

  /**
   */
  AST polygon_sub(std::vector<Query>);

  /**
   */
  AST prepend(std::vector<Query>);

  /**
   */
  AST random(std::vector<Query>, std::map<std::string, Query>);
  AST random(std::vector<Query>);

  /**
   */
  AST range(std::vector<Query>);

  /**
   */
  AST rebalance(std::vector<Query>);

  /**
   */
  AST reconfigure(std::vector<Query>);

  /**
   */
  AST reduce(std::vector<Query>);

  /**
   */
  AST replace(std::vector<Query>, std::map<std::string, Query>);
  AST replace(std::vector<Query>);

  /**
   */
  AST sample(std::vector<Query>);

  /**
   */
  AST saturday(std::vector<Query>);

  /**
   */
  AST seconds(std::vector<Query>);

  /**
   */
  AST september(std::vector<Query>);

  /**
   */
  AST set_difference(std::vector<Query>);

  /**
   */
  AST set_insert(std::vector<Query>);

  /**
   */
  AST set_intersection(std::vector<Query>);

  /**
   */
  AST set_union(std::vector<Query>);

  /**
   */
  AST skip(std::vector<Query>);

  /**
   */
  AST slice(std::vector<Query>, std::map<std::string, Query>);
  AST slice(std::vector<Query>);

  /**
   */
  AST splice_at(std::vector<Query>);

  /**
   */
  AST split(std::vector<Query>);

  /**
   */
  AST sub(std::vector<Query>);

  /**
   */
  AST sum(std::vector<Query>);

  /**
   */
  AST sunday(std::vector<Query>);

  /**
   */
  AST sync(std::vector<Query>);

  /**
   */
  AST table(std::vector<Query>, std::map<std::string, Query>);
  AST table(std::vector<Query>);

  /**
   */
  AST table_config(std::vector<Query>);

  /**
   */
  AST table_create(std::vector<Query>, std::map<std::string, Query>);
  AST table_create(std::vector<Query>);

  /**
   */
  AST table_drop(std::vector<Query>);

  /**
   */
  AST table_list(std::vector<Query>);

  /**
   */
  AST table_status(std::vector<Query>);

  /**
   */
  AST table_wait(std::vector<Query>);

  /**
   */
  AST thursday(std::vector<Query>);

  /**
   */
  AST time(std::vector<Query>);

  /**
   */
  AST timezone_(std::vector<Query>);

  /**
   */
  AST time_of_day(std::vector<Query>);

  /**
   */
  AST to_epoch_time(std::vector<Query>);

  /**
   */
  AST to_geojson(std::vector<Query>);

  /**
   */
  AST to_iso8601(std::vector<Query>);

  /**
   */
  AST to_json_string(std::vector<Query>);

  /**
   */
  AST tuesday(std::vector<Query>);

  /**
   */
  AST type_of(std::vector<Query>);

  /**
   */
  AST ungroup(std::vector<Query>);

  /**
   */
  AST union_(std::vector<Query>);

  /**
   */
  AST upcase(std::vector<Query>);

  /**
   */
  AST update(std::vector<Query>, std::map<std::string, Query>);
  AST update(std::vector<Query>);

  /**
   */
  AST uuid(std::vector<Query>);

  /**
   */
  AST var(std::vector<Query>);

  /**
   */
  AST wednesday(std::vector<Query>);

  /**
   */
  AST without(std::vector<Query>);

  /**
   */
  AST with_fields(std::vector<Query>);

  /**
   */
  AST year(std::vector<Query>);

  /**
   */
  AST zip(std::vector<Query>);
};


/**
 */
AST add(std::vector<Query>);

/**
 */
AST all(std::vector<Query>);

/**
 */
AST any(std::vector<Query>);

/**
 */
AST append(std::vector<Query>);

/**
 */
AST april(std::vector<Query>);

/**
 */
AST args(std::vector<Query>);

/**
 */
AST asc(std::vector<Query>);

/**
 */
AST august(std::vector<Query>);

/**
 */
AST avg(std::vector<Query>);

/**
 */
AST between(std::vector<Query>);

/**
 */
AST binary(std::vector<Query>);

/**
 */
AST bracket(std::vector<Query>);

/**
 */
AST branch(std::vector<Query>);

/**
 */
AST changes(std::vector<Query>);

/**
 */
AST change_at(std::vector<Query>);

/**
 */
AST circle(std::vector<Query>, std::map<std::string, Query>);
AST circle(std::vector<Query>);

/**
 */
AST coerce_to(std::vector<Query>);

/**
 */
AST concat_map(std::vector<Query>);

/**
 */
AST contains(std::vector<Query>);

/**
 */
AST count(std::vector<Query>);

/**
 */
AST date(std::vector<Query>);

/**
 */
AST datum(std::vector<Query>);

/**
 */
AST day(std::vector<Query>);

/**
 */
AST day_of_week(std::vector<Query>);

/**
 */
AST day_of_year(std::vector<Query>);

/**
 */
AST db(std::vector<Query>);

/**
 */
AST db_config(std::vector<Query>);

/**
 */
AST db_create(std::vector<Query>);

/**
 */
AST db_drop(std::vector<Query>);

/**
 */
AST db_list(std::vector<Query>);

/**
 */
AST december(std::vector<Query>);

/**
 */
AST default_(std::vector<Query>);

/**
 */
AST delete_(std::vector<Query>, std::map<std::string, Query>);
AST delete_(std::vector<Query>);

/**
 */
AST delete_at(std::vector<Query>);

/**
 */
AST desc(std::vector<Query>);

/**
 */
AST difference(std::vector<Query>);

/**
 */
AST distance(std::vector<Query>);

/**
 */
AST distinct(std::vector<Query>, std::map<std::string, Query>);
AST distinct(std::vector<Query>);

/**
 */
AST div(std::vector<Query>);

/**
 */
AST downcase(std::vector<Query>);

/**
 */
AST during(std::vector<Query>);

/**
 */
AST epoch_time(std::vector<Query>);

/**
 */
AST eq(std::vector<Query>);

/**
 */
AST eq_join(std::vector<Query>, std::map<std::string, Query>);
AST eq_join(std::vector<Query>);

/**
 */
AST error(std::vector<Query>);

/**
 */
AST february(std::vector<Query>);

/**
 */
AST fill(std::vector<Query>);

/**
 */
AST filter(std::vector<Query>, std::map<std::string, Query>);
AST filter(std::vector<Query>);

/**
 */
AST for_each(std::vector<Query>);

/**
 */
AST friday(std::vector<Query>);

/**
 */
AST func(std::vector<Query>);

/**
 */
AST funcall(std::vector<Query>);

/**
 */
AST ge(std::vector<Query>);

/**
 */
AST geojson(std::vector<Query>);

/**
 */
AST get(std::vector<Query>);

/**
 */
AST get_all(std::vector<Query>, std::map<std::string, Query>);
AST get_all(std::vector<Query>);

/**
 */
AST get_field(std::vector<Query>);

/**
 */
AST get_intersecting(std::vector<Query>, std::map<std::string, Query>);
AST get_intersecting(std::vector<Query>);

/**
 */
AST get_nearest(std::vector<Query>, std::map<std::string, Query>);
AST get_nearest(std::vector<Query>);

/**
 */
AST group(std::vector<Query>, std::map<std::string, Query>);
AST group(std::vector<Query>);

/**
 */
AST gt(std::vector<Query>);

/**
 */
AST has_fields(std::vector<Query>);

/**
 */
AST hours(std::vector<Query>);

/**
 */
AST http(std::vector<Query>, std::map<std::string, Query>);
AST http(std::vector<Query>);

/**
 */
AST implicit_var(std::vector<Query>);

/**
 */
AST includes(std::vector<Query>);

/**
 */
AST indexes_of(std::vector<Query>);

/**
 */
AST index_create(std::vector<Query>, std::map<std::string, Query>);
AST index_create(std::vector<Query>);

/**
 */
AST index_drop(std::vector<Query>);

/**
 */
AST index_list(std::vector<Query>);

/**
 */
AST index_rename(std::vector<Query>, std::map<std::string, Query>);
AST index_rename(std::vector<Query>);

/**
 */
AST index_status(std::vector<Query>);

/**
 */
AST index_wait(std::vector<Query>);

/**
 */
AST info(std::vector<Query>);

/**
 */
AST inner_join(std::vector<Query>);

/**
 */
AST insert(std::vector<Query>);

/**
 */
AST insert_at(std::vector<Query>);

/**
 */
AST intersects(std::vector<Query>);

/**
 */
AST in_timezone(std::vector<Query>);

/**
 */
AST iso8601(std::vector<Query>, std::map<std::string, Query>);
AST iso8601(std::vector<Query>);

/**
 */
AST is_empty(std::vector<Query>);

/**
 */
AST january(std::vector<Query>);

/**
 */
AST javascript(std::vector<Query>, std::map<std::string, Query>);
AST javascript(std::vector<Query>);

/**
 */
AST json(std::vector<Query>);

/**
 */
AST july(std::vector<Query>);

/**
 */
AST june(std::vector<Query>);

/**
 */
AST keys(std::vector<Query>);

/**
 */
AST le(std::vector<Query>);

/**
 */
AST limit(std::vector<Query>);

/**
 */
AST line(std::vector<Query>);

/**
 */
AST literal(std::vector<Query>);

/**
 */
AST lt(std::vector<Query>);

/**
 */
AST make_array(std::vector<Query>);

/**
 */
AST make_obj(std::vector<Query>);

/**
 */
AST map(std::vector<Query>);

/**
 */
AST march(std::vector<Query>);

/**
 */
AST match(std::vector<Query>);

/**
 */
AST max(std::vector<Query>);

/**
 */
AST may(std::vector<Query>);

/**
 */
AST merge(std::vector<Query>);

/**
 */
AST min(std::vector<Query>);

/**
 */
AST minutes(std::vector<Query>);

/**
 */
AST mod(std::vector<Query>);

/**
 */
AST monday(std::vector<Query>);

/**
 */
AST month(std::vector<Query>);

/**
 */
AST mul(std::vector<Query>);

/**
 */
AST ne(std::vector<Query>);

/**
 */
AST not_(std::vector<Query>);

/**
 */
AST november(std::vector<Query>);

/**
 */
AST now(std::vector<Query>);

/**
 */
AST nth(std::vector<Query>);

/**
 */
AST object(std::vector<Query>);

/**
 */
AST october(std::vector<Query>);

/**
 */
AST order_by(std::vector<Query>, std::map<std::string, Query>);
AST order_by(std::vector<Query>);

/**
 */
AST outer_join(std::vector<Query>);

/**
 */
AST pluck(std::vector<Query>);

/**
 */
AST point(std::vector<Query>);

/**
 */
AST polygon(std::vector<Query>);

/**
 */
AST polygon_sub(std::vector<Query>);

/**
 */
AST prepend(std::vector<Query>);

/**
 */
AST random(std::vector<Query>, std::map<std::string, Query>);
AST random(std::vector<Query>);

/**
 */
AST range(std::vector<Query>);

/**
 */
AST rebalance(std::vector<Query>);

/**
 */
AST reconfigure(std::vector<Query>);

/**
 */
AST reduce(std::vector<Query>);

/**
 */
AST replace(std::vector<Query>, std::map<std::string, Query>);
AST replace(std::vector<Query>);

/**
 */
AST sample(std::vector<Query>);

/**
 */
AST saturday(std::vector<Query>);

/**
 */
AST seconds(std::vector<Query>);

/**
 */
AST september(std::vector<Query>);

/**
 */
AST set_difference(std::vector<Query>);

/**
 */
AST set_insert(std::vector<Query>);

/**
 */
AST set_intersection(std::vector<Query>);

/**
 */
AST set_union(std::vector<Query>);

/**
 */
AST skip(std::vector<Query>);

/**
 */
AST slice(std::vector<Query>, std::map<std::string, Query>);
AST slice(std::vector<Query>);

/**
 */
AST splice_at(std::vector<Query>);

/**
 */
AST split(std::vector<Query>);

/**
 */
AST sub(std::vector<Query>);

/**
 */
AST sum(std::vector<Query>);

/**
 */
AST sunday(std::vector<Query>);

/**
 */
AST sync(std::vector<Query>);

/**
 */
AST table(std::vector<Query>, std::map<std::string, Query>);
AST table(std::vector<Query>);

/**
 */
AST table_config(std::vector<Query>);

/**
 */
AST table_create(std::vector<Query>, std::map<std::string, Query>);
AST table_create(std::vector<Query>);

/**
 */
AST table_drop(std::vector<Query>);

/**
 */
AST table_list(std::vector<Query>);

/**
 */
AST table_status(std::vector<Query>);

/**
 */
AST table_wait(std::vector<Query>);

/**
 */
AST thursday(std::vector<Query>);

/**
 */
AST time(std::vector<Query>);

/**
 */
AST timezone_(std::vector<Query>);

/**
 */
AST time_of_day(std::vector<Query>);

/**
 */
AST to_epoch_time(std::vector<Query>);

/**
 */
AST to_geojson(std::vector<Query>);

/**
 */
AST to_iso8601(std::vector<Query>);

/**
 */
AST to_json_string(std::vector<Query>);

/**
 */
AST tuesday(std::vector<Query>);

/**
 */
AST type_of(std::vector<Query>);

/**
 */
AST ungroup(std::vector<Query>);

/**
 */
AST union_(std::vector<Query>);

/**
 */
AST upcase(std::vector<Query>);

/**
 */
AST update(std::vector<Query>, std::map<std::string, Query>);
AST update(std::vector<Query>);

/**
 */
AST uuid(std::vector<Query>);

/**
 */
AST var(std::vector<Query>);

/**
 */
AST wednesday(std::vector<Query>);

/**
 */
AST without(std::vector<Query>);

/**
 */
AST with_fields(std::vector<Query>);

/**
 */
AST year(std::vector<Query>);

/**
 */
AST zip(std::vector<Query>);

}

#endif
