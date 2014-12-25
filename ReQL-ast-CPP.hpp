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

class ReQL_ast : ReQL_expr {
public:

/**
 */
  ReQL_ast add(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast all(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast any(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast append(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast april(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast args(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast asc(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast august(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast avg(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast between(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast binary(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast bracket(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast branch(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast changes(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast change_at(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast circle(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast circle(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast coerce_to(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast concat_map(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast contains(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast count(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast date(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast datum(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast day(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast day_of_week(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast day_of_year(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast db(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast db_config(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast db_create(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast db_drop(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast db_list(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast december(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast default_(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast delete_(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast delete_(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast delete_at(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast desc(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast difference(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast distance(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast distinct(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast distinct(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast div(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast downcase(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast during(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast epoch_time(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast eq(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast eq_join(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast eq_join(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast error(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast february(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast fill(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast filter(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast filter(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast for_each(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast friday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast func(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast funcall(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast ge(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast geojson(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast get(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast get_all(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast get_all(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast get_field(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast get_intersecting(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast get_intersecting(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast get_nearest(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast get_nearest(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast group(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast group(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast gt(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast has_fields(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast hours(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast http(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast http(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast implicit_var(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast includes(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast indexes_of(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_create(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast index_create(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_drop(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_list(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_rename(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast index_rename(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_status(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast index_wait(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast info(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast inner_join(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast insert(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast insert_at(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast intersects(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast in_timezone(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast iso8601(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast iso8601(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast is_empty(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast january(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast javascript(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast javascript(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast json(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast july(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast june(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast keys(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast le(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast limit(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast line(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast literal(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast lt(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast make_array(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast make_obj(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast map(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast march(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast match(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast max(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast may(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast merge(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast min(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast minutes(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast mod(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast monday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast month(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast mul(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast ne(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast not_(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast november(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast now(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast nth(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast object(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast october(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast order_by(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast order_by(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast outer_join(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast pluck(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast point(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast polygon(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast polygon_sub(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast prepend(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast random(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast random(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast range(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast rebalance(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast reconfigure(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast reduce(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast replace(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast replace(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast sample(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast saturday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast seconds(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast september(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast set_difference(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast set_insert(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast set_intersection(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast set_union(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast skip(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast slice(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast slice(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast splice_at(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast split(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast sub(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast sum(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast sunday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast sync(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast table(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_config(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_create(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast table_create(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_drop(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_list(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_status(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast table_wait(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast thursday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast time(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast timezone_(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast time_of_day(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast to_epoch_time(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast to_geojson(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast to_iso8601(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast to_json_string(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast tuesday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast type_of(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast ungroup(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast union_(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast upcase(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast update(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
  ReQL_ast update(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast uuid(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast var(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast wednesday(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast without(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast with_fields(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast year(std::vector<ReQL_ast>);

/**
 */
  ReQL_ast zip(std::vector<ReQL_ast>);
};


/**
 */
ReQL_ast add(std::vector<ReQL_ast>);

/**
 */
ReQL_ast all(std::vector<ReQL_ast>);

/**
 */
ReQL_ast any(std::vector<ReQL_ast>);

/**
 */
ReQL_ast append(std::vector<ReQL_ast>);

/**
 */
ReQL_ast april(std::vector<ReQL_ast>);

/**
 */
ReQL_ast args(std::vector<ReQL_ast>);

/**
 */
ReQL_ast asc(std::vector<ReQL_ast>);

/**
 */
ReQL_ast august(std::vector<ReQL_ast>);

/**
 */
ReQL_ast avg(std::vector<ReQL_ast>);

/**
 */
ReQL_ast between(std::vector<ReQL_ast>);

/**
 */
ReQL_ast binary(std::vector<ReQL_ast>);

/**
 */
ReQL_ast bracket(std::vector<ReQL_ast>);

/**
 */
ReQL_ast branch(std::vector<ReQL_ast>);

/**
 */
ReQL_ast changes(std::vector<ReQL_ast>);

/**
 */
ReQL_ast change_at(std::vector<ReQL_ast>);

/**
 */
ReQL_ast circle(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast circle(std::vector<ReQL_ast>);

/**
 */
ReQL_ast coerce_to(std::vector<ReQL_ast>);

/**
 */
ReQL_ast concat_map(std::vector<ReQL_ast>);

/**
 */
ReQL_ast contains(std::vector<ReQL_ast>);

/**
 */
ReQL_ast count(std::vector<ReQL_ast>);

/**
 */
ReQL_ast date(std::vector<ReQL_ast>);

/**
 */
ReQL_ast datum(std::vector<ReQL_ast>);

/**
 */
ReQL_ast day(std::vector<ReQL_ast>);

/**
 */
ReQL_ast day_of_week(std::vector<ReQL_ast>);

/**
 */
ReQL_ast day_of_year(std::vector<ReQL_ast>);

/**
 */
ReQL_ast db(std::vector<ReQL_ast>);

/**
 */
ReQL_ast db_config(std::vector<ReQL_ast>);

/**
 */
ReQL_ast db_create(std::vector<ReQL_ast>);

/**
 */
ReQL_ast db_drop(std::vector<ReQL_ast>);

/**
 */
ReQL_ast db_list(std::vector<ReQL_ast>);

/**
 */
ReQL_ast december(std::vector<ReQL_ast>);

/**
 */
ReQL_ast default_(std::vector<ReQL_ast>);

/**
 */
ReQL_ast delete_(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast delete_(std::vector<ReQL_ast>);

/**
 */
ReQL_ast delete_at(std::vector<ReQL_ast>);

/**
 */
ReQL_ast desc(std::vector<ReQL_ast>);

/**
 */
ReQL_ast difference(std::vector<ReQL_ast>);

/**
 */
ReQL_ast distance(std::vector<ReQL_ast>);

/**
 */
ReQL_ast distinct(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast distinct(std::vector<ReQL_ast>);

/**
 */
ReQL_ast div(std::vector<ReQL_ast>);

/**
 */
ReQL_ast downcase(std::vector<ReQL_ast>);

/**
 */
ReQL_ast during(std::vector<ReQL_ast>);

/**
 */
ReQL_ast epoch_time(std::vector<ReQL_ast>);

/**
 */
ReQL_ast eq(std::vector<ReQL_ast>);

/**
 */
ReQL_ast eq_join(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast eq_join(std::vector<ReQL_ast>);

/**
 */
ReQL_ast error(std::vector<ReQL_ast>);

/**
 */
ReQL_ast february(std::vector<ReQL_ast>);

/**
 */
ReQL_ast fill(std::vector<ReQL_ast>);

/**
 */
ReQL_ast filter(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast filter(std::vector<ReQL_ast>);

/**
 */
ReQL_ast for_each(std::vector<ReQL_ast>);

/**
 */
ReQL_ast friday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast func(std::vector<ReQL_ast>);

/**
 */
ReQL_ast funcall(std::vector<ReQL_ast>);

/**
 */
ReQL_ast ge(std::vector<ReQL_ast>);

/**
 */
ReQL_ast geojson(std::vector<ReQL_ast>);

/**
 */
ReQL_ast get(std::vector<ReQL_ast>);

/**
 */
ReQL_ast get_all(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast get_all(std::vector<ReQL_ast>);

/**
 */
ReQL_ast get_field(std::vector<ReQL_ast>);

/**
 */
ReQL_ast get_intersecting(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast get_intersecting(std::vector<ReQL_ast>);

/**
 */
ReQL_ast get_nearest(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast get_nearest(std::vector<ReQL_ast>);

/**
 */
ReQL_ast group(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast group(std::vector<ReQL_ast>);

/**
 */
ReQL_ast gt(std::vector<ReQL_ast>);

/**
 */
ReQL_ast has_fields(std::vector<ReQL_ast>);

/**
 */
ReQL_ast hours(std::vector<ReQL_ast>);

/**
 */
ReQL_ast http(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast http(std::vector<ReQL_ast>);

/**
 */
ReQL_ast implicit_var(std::vector<ReQL_ast>);

/**
 */
ReQL_ast includes(std::vector<ReQL_ast>);

/**
 */
ReQL_ast indexes_of(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_create(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast index_create(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_drop(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_list(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_rename(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast index_rename(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_status(std::vector<ReQL_ast>);

/**
 */
ReQL_ast index_wait(std::vector<ReQL_ast>);

/**
 */
ReQL_ast info(std::vector<ReQL_ast>);

/**
 */
ReQL_ast inner_join(std::vector<ReQL_ast>);

/**
 */
ReQL_ast insert(std::vector<ReQL_ast>);

/**
 */
ReQL_ast insert_at(std::vector<ReQL_ast>);

/**
 */
ReQL_ast intersects(std::vector<ReQL_ast>);

/**
 */
ReQL_ast in_timezone(std::vector<ReQL_ast>);

/**
 */
ReQL_ast iso8601(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast iso8601(std::vector<ReQL_ast>);

/**
 */
ReQL_ast is_empty(std::vector<ReQL_ast>);

/**
 */
ReQL_ast january(std::vector<ReQL_ast>);

/**
 */
ReQL_ast javascript(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast javascript(std::vector<ReQL_ast>);

/**
 */
ReQL_ast json(std::vector<ReQL_ast>);

/**
 */
ReQL_ast july(std::vector<ReQL_ast>);

/**
 */
ReQL_ast june(std::vector<ReQL_ast>);

/**
 */
ReQL_ast keys(std::vector<ReQL_ast>);

/**
 */
ReQL_ast le(std::vector<ReQL_ast>);

/**
 */
ReQL_ast limit(std::vector<ReQL_ast>);

/**
 */
ReQL_ast line(std::vector<ReQL_ast>);

/**
 */
ReQL_ast literal(std::vector<ReQL_ast>);

/**
 */
ReQL_ast lt(std::vector<ReQL_ast>);

/**
 */
ReQL_ast make_array(std::vector<ReQL_ast>);

/**
 */
ReQL_ast make_obj(std::vector<ReQL_ast>);

/**
 */
ReQL_ast map(std::vector<ReQL_ast>);

/**
 */
ReQL_ast march(std::vector<ReQL_ast>);

/**
 */
ReQL_ast match(std::vector<ReQL_ast>);

/**
 */
ReQL_ast max(std::vector<ReQL_ast>);

/**
 */
ReQL_ast may(std::vector<ReQL_ast>);

/**
 */
ReQL_ast merge(std::vector<ReQL_ast>);

/**
 */
ReQL_ast min(std::vector<ReQL_ast>);

/**
 */
ReQL_ast minutes(std::vector<ReQL_ast>);

/**
 */
ReQL_ast mod(std::vector<ReQL_ast>);

/**
 */
ReQL_ast monday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast month(std::vector<ReQL_ast>);

/**
 */
ReQL_ast mul(std::vector<ReQL_ast>);

/**
 */
ReQL_ast ne(std::vector<ReQL_ast>);

/**
 */
ReQL_ast not_(std::vector<ReQL_ast>);

/**
 */
ReQL_ast november(std::vector<ReQL_ast>);

/**
 */
ReQL_ast now(std::vector<ReQL_ast>);

/**
 */
ReQL_ast nth(std::vector<ReQL_ast>);

/**
 */
ReQL_ast object(std::vector<ReQL_ast>);

/**
 */
ReQL_ast october(std::vector<ReQL_ast>);

/**
 */
ReQL_ast order_by(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast order_by(std::vector<ReQL_ast>);

/**
 */
ReQL_ast outer_join(std::vector<ReQL_ast>);

/**
 */
ReQL_ast pluck(std::vector<ReQL_ast>);

/**
 */
ReQL_ast point(std::vector<ReQL_ast>);

/**
 */
ReQL_ast polygon(std::vector<ReQL_ast>);

/**
 */
ReQL_ast polygon_sub(std::vector<ReQL_ast>);

/**
 */
ReQL_ast prepend(std::vector<ReQL_ast>);

/**
 */
ReQL_ast random(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast random(std::vector<ReQL_ast>);

/**
 */
ReQL_ast range(std::vector<ReQL_ast>);

/**
 */
ReQL_ast rebalance(std::vector<ReQL_ast>);

/**
 */
ReQL_ast reconfigure(std::vector<ReQL_ast>);

/**
 */
ReQL_ast reduce(std::vector<ReQL_ast>);

/**
 */
ReQL_ast replace(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast replace(std::vector<ReQL_ast>);

/**
 */
ReQL_ast sample(std::vector<ReQL_ast>);

/**
 */
ReQL_ast saturday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast seconds(std::vector<ReQL_ast>);

/**
 */
ReQL_ast september(std::vector<ReQL_ast>);

/**
 */
ReQL_ast set_difference(std::vector<ReQL_ast>);

/**
 */
ReQL_ast set_insert(std::vector<ReQL_ast>);

/**
 */
ReQL_ast set_intersection(std::vector<ReQL_ast>);

/**
 */
ReQL_ast set_union(std::vector<ReQL_ast>);

/**
 */
ReQL_ast skip(std::vector<ReQL_ast>);

/**
 */
ReQL_ast slice(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast slice(std::vector<ReQL_ast>);

/**
 */
ReQL_ast splice_at(std::vector<ReQL_ast>);

/**
 */
ReQL_ast split(std::vector<ReQL_ast>);

/**
 */
ReQL_ast sub(std::vector<ReQL_ast>);

/**
 */
ReQL_ast sum(std::vector<ReQL_ast>);

/**
 */
ReQL_ast sunday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast sync(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast table(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_config(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_create(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast table_create(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_drop(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_list(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_status(std::vector<ReQL_ast>);

/**
 */
ReQL_ast table_wait(std::vector<ReQL_ast>);

/**
 */
ReQL_ast thursday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast time(std::vector<ReQL_ast>);

/**
 */
ReQL_ast timezone_(std::vector<ReQL_ast>);

/**
 */
ReQL_ast time_of_day(std::vector<ReQL_ast>);

/**
 */
ReQL_ast to_epoch_time(std::vector<ReQL_ast>);

/**
 */
ReQL_ast to_geojson(std::vector<ReQL_ast>);

/**
 */
ReQL_ast to_iso8601(std::vector<ReQL_ast>);

/**
 */
ReQL_ast to_json_string(std::vector<ReQL_ast>);

/**
 */
ReQL_ast tuesday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast type_of(std::vector<ReQL_ast>);

/**
 */
ReQL_ast ungroup(std::vector<ReQL_ast>);

/**
 */
ReQL_ast union_(std::vector<ReQL_ast>);

/**
 */
ReQL_ast upcase(std::vector<ReQL_ast>);

/**
 */
ReQL_ast update(std::vector<ReQL_ast>, std::map<std::string, ReQL_ast>);
ReQL_ast update(std::vector<ReQL_ast>);

/**
 */
ReQL_ast uuid(std::vector<ReQL_ast>);

/**
 */
ReQL_ast var(std::vector<ReQL_ast>);

/**
 */
ReQL_ast wednesday(std::vector<ReQL_ast>);

/**
 */
ReQL_ast without(std::vector<ReQL_ast>);

/**
 */
ReQL_ast with_fields(std::vector<ReQL_ast>);

/**
 */
ReQL_ast year(std::vector<ReQL_ast>);

/**
 */
ReQL_ast zip(std::vector<ReQL_ast>);


#endif
