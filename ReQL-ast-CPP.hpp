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

#include "ReQL-expr-CPP.hpp"

#ifndef _REQL_AST_CPP
#define _REQL_AST_CPP

namespace ReQL {

class AST : public Expr {
public:

  /**
   */
  AST add(std::vector<AST>);

  /**
   */
  AST all(std::vector<AST>);

  /**
   */
  AST any(std::vector<AST>);

  /**
   */
  AST append(std::vector<AST>);

  /**
   */
  AST april(std::vector<AST>);

  /**
   */
  AST args(std::vector<AST>);

  /**
   */
  AST asc(std::vector<AST>);

  /**
   */
  AST august(std::vector<AST>);

  /**
   */
  AST avg(std::vector<AST>);

  /**
   */
  AST between(std::vector<AST>);

  /**
   */
  AST binary(std::vector<AST>);

  /**
   */
  AST bracket(std::vector<AST>);

  /**
   */
  AST branch(std::vector<AST>);

  /**
   */
  AST changes(std::vector<AST>);

  /**
   */
  AST change_at(std::vector<AST>);

  /**
   */
  AST circle(std::vector<AST>, std::map<std::string, AST>);
  AST circle(std::vector<AST>);

  /**
   */
  AST coerce_to(std::vector<AST>);

  /**
   */
  AST concat_map(std::vector<AST>);

  /**
   */
  AST contains(std::vector<AST>);

  /**
   */
  AST count(std::vector<AST>);

  /**
   */
  AST date(std::vector<AST>);

  /**
   */
  AST datum(std::vector<AST>);

  /**
   */
  AST day(std::vector<AST>);

  /**
   */
  AST day_of_week(std::vector<AST>);

  /**
   */
  AST day_of_year(std::vector<AST>);

  /**
   */
  AST db(std::vector<AST>);

  /**
   */
  AST db_config(std::vector<AST>);

  /**
   */
  AST db_create(std::vector<AST>);

  /**
   */
  AST db_drop(std::vector<AST>);

  /**
   */
  AST db_list(std::vector<AST>);

  /**
   */
  AST december(std::vector<AST>);

  /**
   */
  AST default_(std::vector<AST>);

  /**
   */
  AST delete_(std::vector<AST>, std::map<std::string, AST>);
  AST delete_(std::vector<AST>);

  /**
   */
  AST delete_at(std::vector<AST>);

  /**
   */
  AST desc(std::vector<AST>);

  /**
   */
  AST difference(std::vector<AST>);

  /**
   */
  AST distance(std::vector<AST>);

  /**
   */
  AST distinct(std::vector<AST>, std::map<std::string, AST>);
  AST distinct(std::vector<AST>);

  /**
   */
  AST div(std::vector<AST>);

  /**
   */
  AST downcase(std::vector<AST>);

  /**
   */
  AST during(std::vector<AST>);

  /**
   */
  AST epoch_time(std::vector<AST>);

  /**
   */
  AST eq(std::vector<AST>);

  /**
   */
  AST eq_join(std::vector<AST>, std::map<std::string, AST>);
  AST eq_join(std::vector<AST>);

  /**
   */
  AST error(std::vector<AST>);

  /**
   */
  AST february(std::vector<AST>);

  /**
   */
  AST fill(std::vector<AST>);

  /**
   */
  AST filter(std::vector<AST>, std::map<std::string, AST>);
  AST filter(std::vector<AST>);

  /**
   */
  AST for_each(std::vector<AST>);

  /**
   */
  AST friday(std::vector<AST>);

  /**
   */
  AST func(std::vector<AST>);

  /**
   */
  AST funcall(std::vector<AST>);

  /**
   */
  AST ge(std::vector<AST>);

  /**
   */
  AST geojson(std::vector<AST>);

  /**
   */
  AST get(std::vector<AST>);

  /**
   */
  AST get_all(std::vector<AST>, std::map<std::string, AST>);
  AST get_all(std::vector<AST>);

  /**
   */
  AST get_field(std::vector<AST>);

  /**
   */
  AST get_intersecting(std::vector<AST>, std::map<std::string, AST>);
  AST get_intersecting(std::vector<AST>);

  /**
   */
  AST get_nearest(std::vector<AST>, std::map<std::string, AST>);
  AST get_nearest(std::vector<AST>);

  /**
   */
  AST group(std::vector<AST>, std::map<std::string, AST>);
  AST group(std::vector<AST>);

  /**
   */
  AST gt(std::vector<AST>);

  /**
   */
  AST has_fields(std::vector<AST>);

  /**
   */
  AST hours(std::vector<AST>);

  /**
   */
  AST http(std::vector<AST>, std::map<std::string, AST>);
  AST http(std::vector<AST>);

  /**
   */
  AST implicit_var(std::vector<AST>);

  /**
   */
  AST includes(std::vector<AST>);

  /**
   */
  AST indexes_of(std::vector<AST>);

  /**
   */
  AST index_create(std::vector<AST>, std::map<std::string, AST>);
  AST index_create(std::vector<AST>);

  /**
   */
  AST index_drop(std::vector<AST>);

  /**
   */
  AST index_list(std::vector<AST>);

  /**
   */
  AST index_rename(std::vector<AST>, std::map<std::string, AST>);
  AST index_rename(std::vector<AST>);

  /**
   */
  AST index_status(std::vector<AST>);

  /**
   */
  AST index_wait(std::vector<AST>);

  /**
   */
  AST info(std::vector<AST>);

  /**
   */
  AST inner_join(std::vector<AST>);

  /**
   */
  AST insert(std::vector<AST>);

  /**
   */
  AST insert_at(std::vector<AST>);

  /**
   */
  AST intersects(std::vector<AST>);

  /**
   */
  AST in_timezone(std::vector<AST>);

  /**
   */
  AST iso8601(std::vector<AST>, std::map<std::string, AST>);
  AST iso8601(std::vector<AST>);

  /**
   */
  AST is_empty(std::vector<AST>);

  /**
   */
  AST january(std::vector<AST>);

  /**
   */
  AST javascript(std::vector<AST>, std::map<std::string, AST>);
  AST javascript(std::vector<AST>);

  /**
   */
  AST json(std::vector<AST>);

  /**
   */
  AST july(std::vector<AST>);

  /**
   */
  AST june(std::vector<AST>);

  /**
   */
  AST keys(std::vector<AST>);

  /**
   */
  AST le(std::vector<AST>);

  /**
   */
  AST limit(std::vector<AST>);

  /**
   */
  AST line(std::vector<AST>);

  /**
   */
  AST literal(std::vector<AST>);

  /**
   */
  AST lt(std::vector<AST>);

  /**
   */
  AST make_array(std::vector<AST>);

  /**
   */
  AST make_obj(std::vector<AST>);

  /**
   */
  AST map(std::vector<AST>);

  /**
   */
  AST march(std::vector<AST>);

  /**
   */
  AST match(std::vector<AST>);

  /**
   */
  AST max(std::vector<AST>);

  /**
   */
  AST may(std::vector<AST>);

  /**
   */
  AST merge(std::vector<AST>);

  /**
   */
  AST min(std::vector<AST>);

  /**
   */
  AST minutes(std::vector<AST>);

  /**
   */
  AST mod(std::vector<AST>);

  /**
   */
  AST monday(std::vector<AST>);

  /**
   */
  AST month(std::vector<AST>);

  /**
   */
  AST mul(std::vector<AST>);

  /**
   */
  AST ne(std::vector<AST>);

  /**
   */
  AST not_(std::vector<AST>);

  /**
   */
  AST november(std::vector<AST>);

  /**
   */
  AST now(std::vector<AST>);

  /**
   */
  AST nth(std::vector<AST>);

  /**
   */
  AST object(std::vector<AST>);

  /**
   */
  AST october(std::vector<AST>);

  /**
   */
  AST order_by(std::vector<AST>, std::map<std::string, AST>);
  AST order_by(std::vector<AST>);

  /**
   */
  AST outer_join(std::vector<AST>);

  /**
   */
  AST pluck(std::vector<AST>);

  /**
   */
  AST point(std::vector<AST>);

  /**
   */
  AST polygon(std::vector<AST>);

  /**
   */
  AST polygon_sub(std::vector<AST>);

  /**
   */
  AST prepend(std::vector<AST>);

  /**
   */
  AST random(std::vector<AST>, std::map<std::string, AST>);
  AST random(std::vector<AST>);

  /**
   */
  AST range(std::vector<AST>);

  /**
   */
  AST rebalance(std::vector<AST>);

  /**
   */
  AST reconfigure(std::vector<AST>);

  /**
   */
  AST reduce(std::vector<AST>);

  /**
   */
  AST replace(std::vector<AST>, std::map<std::string, AST>);
  AST replace(std::vector<AST>);

  /**
   */
  AST sample(std::vector<AST>);

  /**
   */
  AST saturday(std::vector<AST>);

  /**
   */
  AST seconds(std::vector<AST>);

  /**
   */
  AST september(std::vector<AST>);

  /**
   */
  AST set_difference(std::vector<AST>);

  /**
   */
  AST set_insert(std::vector<AST>);

  /**
   */
  AST set_intersection(std::vector<AST>);

  /**
   */
  AST set_union(std::vector<AST>);

  /**
   */
  AST skip(std::vector<AST>);

  /**
   */
  AST slice(std::vector<AST>, std::map<std::string, AST>);
  AST slice(std::vector<AST>);

  /**
   */
  AST splice_at(std::vector<AST>);

  /**
   */
  AST split(std::vector<AST>);

  /**
   */
  AST sub(std::vector<AST>);

  /**
   */
  AST sum(std::vector<AST>);

  /**
   */
  AST sunday(std::vector<AST>);

  /**
   */
  AST sync(std::vector<AST>);

  /**
   */
  AST table(std::vector<AST>, std::map<std::string, AST>);
  AST table(std::vector<AST>);

  /**
   */
  AST table_config(std::vector<AST>);

  /**
   */
  AST table_create(std::vector<AST>, std::map<std::string, AST>);
  AST table_create(std::vector<AST>);

  /**
   */
  AST table_drop(std::vector<AST>);

  /**
   */
  AST table_list(std::vector<AST>);

  /**
   */
  AST table_status(std::vector<AST>);

  /**
   */
  AST table_wait(std::vector<AST>);

  /**
   */
  AST thursday(std::vector<AST>);

  /**
   */
  AST time(std::vector<AST>);

  /**
   */
  AST timezone_(std::vector<AST>);

  /**
   */
  AST time_of_day(std::vector<AST>);

  /**
   */
  AST to_epoch_time(std::vector<AST>);

  /**
   */
  AST to_geojson(std::vector<AST>);

  /**
   */
  AST to_iso8601(std::vector<AST>);

  /**
   */
  AST to_json_string(std::vector<AST>);

  /**
   */
  AST tuesday(std::vector<AST>);

  /**
   */
  AST type_of(std::vector<AST>);

  /**
   */
  AST ungroup(std::vector<AST>);

  /**
   */
  AST union_(std::vector<AST>);

  /**
   */
  AST upcase(std::vector<AST>);

  /**
   */
  AST update(std::vector<AST>, std::map<std::string, AST>);
  AST update(std::vector<AST>);

  /**
   */
  AST uuid(std::vector<AST>);

  /**
   */
  AST var(std::vector<AST>);

  /**
   */
  AST wednesday(std::vector<AST>);

  /**
   */
  AST without(std::vector<AST>);

  /**
   */
  AST with_fields(std::vector<AST>);

  /**
   */
  AST year(std::vector<AST>);

  /**
   */
  AST zip(std::vector<AST>);
};


/**
 */
AST add(std::vector<AST>);

/**
 */
AST all(std::vector<AST>);

/**
 */
AST any(std::vector<AST>);

/**
 */
AST append(std::vector<AST>);

/**
 */
AST april(std::vector<AST>);

/**
 */
AST args(std::vector<AST>);

/**
 */
AST asc(std::vector<AST>);

/**
 */
AST august(std::vector<AST>);

/**
 */
AST avg(std::vector<AST>);

/**
 */
AST between(std::vector<AST>);

/**
 */
AST binary(std::vector<AST>);

/**
 */
AST bracket(std::vector<AST>);

/**
 */
AST branch(std::vector<AST>);

/**
 */
AST changes(std::vector<AST>);

/**
 */
AST change_at(std::vector<AST>);

/**
 */
AST circle(std::vector<AST>, std::map<std::string, AST>);
AST circle(std::vector<AST>);

/**
 */
AST coerce_to(std::vector<AST>);

/**
 */
AST concat_map(std::vector<AST>);

/**
 */
AST contains(std::vector<AST>);

/**
 */
AST count(std::vector<AST>);

/**
 */
AST date(std::vector<AST>);

/**
 */
AST datum(std::vector<AST>);

/**
 */
AST day(std::vector<AST>);

/**
 */
AST day_of_week(std::vector<AST>);

/**
 */
AST day_of_year(std::vector<AST>);

/**
 */
AST db(std::vector<AST>);

/**
 */
AST db_config(std::vector<AST>);

/**
 */
AST db_create(std::vector<AST>);

/**
 */
AST db_drop(std::vector<AST>);

/**
 */
AST db_list(std::vector<AST>);

/**
 */
AST december(std::vector<AST>);

/**
 */
AST default_(std::vector<AST>);

/**
 */
AST delete_(std::vector<AST>, std::map<std::string, AST>);
AST delete_(std::vector<AST>);

/**
 */
AST delete_at(std::vector<AST>);

/**
 */
AST desc(std::vector<AST>);

/**
 */
AST difference(std::vector<AST>);

/**
 */
AST distance(std::vector<AST>);

/**
 */
AST distinct(std::vector<AST>, std::map<std::string, AST>);
AST distinct(std::vector<AST>);

/**
 */
AST div(std::vector<AST>);

/**
 */
AST downcase(std::vector<AST>);

/**
 */
AST during(std::vector<AST>);

/**
 */
AST epoch_time(std::vector<AST>);

/**
 */
AST eq(std::vector<AST>);

/**
 */
AST eq_join(std::vector<AST>, std::map<std::string, AST>);
AST eq_join(std::vector<AST>);

/**
 */
AST error(std::vector<AST>);

/**
 */
AST february(std::vector<AST>);

/**
 */
AST fill(std::vector<AST>);

/**
 */
AST filter(std::vector<AST>, std::map<std::string, AST>);
AST filter(std::vector<AST>);

/**
 */
AST for_each(std::vector<AST>);

/**
 */
AST friday(std::vector<AST>);

/**
 */
AST func(std::vector<AST>);

/**
 */
AST funcall(std::vector<AST>);

/**
 */
AST ge(std::vector<AST>);

/**
 */
AST geojson(std::vector<AST>);

/**
 */
AST get(std::vector<AST>);

/**
 */
AST get_all(std::vector<AST>, std::map<std::string, AST>);
AST get_all(std::vector<AST>);

/**
 */
AST get_field(std::vector<AST>);

/**
 */
AST get_intersecting(std::vector<AST>, std::map<std::string, AST>);
AST get_intersecting(std::vector<AST>);

/**
 */
AST get_nearest(std::vector<AST>, std::map<std::string, AST>);
AST get_nearest(std::vector<AST>);

/**
 */
AST group(std::vector<AST>, std::map<std::string, AST>);
AST group(std::vector<AST>);

/**
 */
AST gt(std::vector<AST>);

/**
 */
AST has_fields(std::vector<AST>);

/**
 */
AST hours(std::vector<AST>);

/**
 */
AST http(std::vector<AST>, std::map<std::string, AST>);
AST http(std::vector<AST>);

/**
 */
AST implicit_var(std::vector<AST>);

/**
 */
AST includes(std::vector<AST>);

/**
 */
AST indexes_of(std::vector<AST>);

/**
 */
AST index_create(std::vector<AST>, std::map<std::string, AST>);
AST index_create(std::vector<AST>);

/**
 */
AST index_drop(std::vector<AST>);

/**
 */
AST index_list(std::vector<AST>);

/**
 */
AST index_rename(std::vector<AST>, std::map<std::string, AST>);
AST index_rename(std::vector<AST>);

/**
 */
AST index_status(std::vector<AST>);

/**
 */
AST index_wait(std::vector<AST>);

/**
 */
AST info(std::vector<AST>);

/**
 */
AST inner_join(std::vector<AST>);

/**
 */
AST insert(std::vector<AST>);

/**
 */
AST insert_at(std::vector<AST>);

/**
 */
AST intersects(std::vector<AST>);

/**
 */
AST in_timezone(std::vector<AST>);

/**
 */
AST iso8601(std::vector<AST>, std::map<std::string, AST>);
AST iso8601(std::vector<AST>);

/**
 */
AST is_empty(std::vector<AST>);

/**
 */
AST january(std::vector<AST>);

/**
 */
AST javascript(std::vector<AST>, std::map<std::string, AST>);
AST javascript(std::vector<AST>);

/**
 */
AST json(std::vector<AST>);

/**
 */
AST july(std::vector<AST>);

/**
 */
AST june(std::vector<AST>);

/**
 */
AST keys(std::vector<AST>);

/**
 */
AST le(std::vector<AST>);

/**
 */
AST limit(std::vector<AST>);

/**
 */
AST line(std::vector<AST>);

/**
 */
AST literal(std::vector<AST>);

/**
 */
AST lt(std::vector<AST>);

/**
 */
AST make_array(std::vector<AST>);

/**
 */
AST make_obj(std::vector<AST>);

/**
 */
AST map(std::vector<AST>);

/**
 */
AST march(std::vector<AST>);

/**
 */
AST match(std::vector<AST>);

/**
 */
AST max(std::vector<AST>);

/**
 */
AST may(std::vector<AST>);

/**
 */
AST merge(std::vector<AST>);

/**
 */
AST min(std::vector<AST>);

/**
 */
AST minutes(std::vector<AST>);

/**
 */
AST mod(std::vector<AST>);

/**
 */
AST monday(std::vector<AST>);

/**
 */
AST month(std::vector<AST>);

/**
 */
AST mul(std::vector<AST>);

/**
 */
AST ne(std::vector<AST>);

/**
 */
AST not_(std::vector<AST>);

/**
 */
AST november(std::vector<AST>);

/**
 */
AST now(std::vector<AST>);

/**
 */
AST nth(std::vector<AST>);

/**
 */
AST object(std::vector<AST>);

/**
 */
AST october(std::vector<AST>);

/**
 */
AST order_by(std::vector<AST>, std::map<std::string, AST>);
AST order_by(std::vector<AST>);

/**
 */
AST outer_join(std::vector<AST>);

/**
 */
AST pluck(std::vector<AST>);

/**
 */
AST point(std::vector<AST>);

/**
 */
AST polygon(std::vector<AST>);

/**
 */
AST polygon_sub(std::vector<AST>);

/**
 */
AST prepend(std::vector<AST>);

/**
 */
AST random(std::vector<AST>, std::map<std::string, AST>);
AST random(std::vector<AST>);

/**
 */
AST range(std::vector<AST>);

/**
 */
AST rebalance(std::vector<AST>);

/**
 */
AST reconfigure(std::vector<AST>);

/**
 */
AST reduce(std::vector<AST>);

/**
 */
AST replace(std::vector<AST>, std::map<std::string, AST>);
AST replace(std::vector<AST>);

/**
 */
AST sample(std::vector<AST>);

/**
 */
AST saturday(std::vector<AST>);

/**
 */
AST seconds(std::vector<AST>);

/**
 */
AST september(std::vector<AST>);

/**
 */
AST set_difference(std::vector<AST>);

/**
 */
AST set_insert(std::vector<AST>);

/**
 */
AST set_intersection(std::vector<AST>);

/**
 */
AST set_union(std::vector<AST>);

/**
 */
AST skip(std::vector<AST>);

/**
 */
AST slice(std::vector<AST>, std::map<std::string, AST>);
AST slice(std::vector<AST>);

/**
 */
AST splice_at(std::vector<AST>);

/**
 */
AST split(std::vector<AST>);

/**
 */
AST sub(std::vector<AST>);

/**
 */
AST sum(std::vector<AST>);

/**
 */
AST sunday(std::vector<AST>);

/**
 */
AST sync(std::vector<AST>);

/**
 */
AST table(std::vector<AST>, std::map<std::string, AST>);
AST table(std::vector<AST>);

/**
 */
AST table_config(std::vector<AST>);

/**
 */
AST table_create(std::vector<AST>, std::map<std::string, AST>);
AST table_create(std::vector<AST>);

/**
 */
AST table_drop(std::vector<AST>);

/**
 */
AST table_list(std::vector<AST>);

/**
 */
AST table_status(std::vector<AST>);

/**
 */
AST table_wait(std::vector<AST>);

/**
 */
AST thursday(std::vector<AST>);

/**
 */
AST time(std::vector<AST>);

/**
 */
AST timezone_(std::vector<AST>);

/**
 */
AST time_of_day(std::vector<AST>);

/**
 */
AST to_epoch_time(std::vector<AST>);

/**
 */
AST to_geojson(std::vector<AST>);

/**
 */
AST to_iso8601(std::vector<AST>);

/**
 */
AST to_json_string(std::vector<AST>);

/**
 */
AST tuesday(std::vector<AST>);

/**
 */
AST type_of(std::vector<AST>);

/**
 */
AST ungroup(std::vector<AST>);

/**
 */
AST union_(std::vector<AST>);

/**
 */
AST upcase(std::vector<AST>);

/**
 */
AST update(std::vector<AST>, std::map<std::string, AST>);
AST update(std::vector<AST>);

/**
 */
AST uuid(std::vector<AST>);

/**
 */
AST var(std::vector<AST>);

/**
 */
AST wednesday(std::vector<AST>);

/**
 */
AST without(std::vector<AST>);

/**
 */
AST with_fields(std::vector<AST>);

/**
 */
AST year(std::vector<AST>);

/**
 */
AST zip(std::vector<AST>);

}

#endif
