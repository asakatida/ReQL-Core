/**
 * @author Adam Grandquist
 */

#include "ReQL-expr-CPP.hpp"

#ifndef _REQL_AST_CPP
#define _REQL_AST_CPP

class ReQL_ast : ReQL_expr {
  int tt;

public:
/* start generated header */

/**
 */
  ReQL_ast *add();

/**
 */
  ReQL_ast *all();

/**
 */
  ReQL_ast *any();

/**
 */
  ReQL_ast *append();

/**
 */
  ReQL_ast *april();

/**
 */
  ReQL_ast *args();

/**
 */
  ReQL_ast *asc();

/**
 */
  ReQL_ast *august();

/**
 */
  ReQL_ast *avg();

/**
 */
  ReQL_ast *between();

/**
 */
  ReQL_ast *binary();

/**
 */
  ReQL_ast *bracket();

/**
 */
  ReQL_ast *branch();

/**
 */
  ReQL_ast *changes();

/**
 */
  ReQL_ast *change_at();

/**
 */
  ReQL_ast *circle();

/**
 */
  ReQL_ast *coerce_to();

/**
 */
  ReQL_ast *concat_map();

/**
 */
  ReQL_ast *contains();

/**
 */
  ReQL_ast *count();

/**
 */
  ReQL_ast *date();

/**
 */
  ReQL_ast *datum();

/**
 */
  ReQL_ast *day();

/**
 */
  ReQL_ast *day_of_week();

/**
 */
  ReQL_ast *day_of_year();

/**
 */
  ReQL_ast *db();

/**
 */
  ReQL_ast *db_create();

/**
 */
  ReQL_ast *db_drop();

/**
 */
  ReQL_ast *db_list();

/**
 */
  ReQL_ast *december();

/**
 */
  ReQL_ast *default_();

/**
 */
  ReQL_ast *delete_();

/**
 */
  ReQL_ast *delete_at();

/**
 */
  ReQL_ast *desc();

/**
 */
  ReQL_ast *difference();

/**
 */
  ReQL_ast *distance();

/**
 */
  ReQL_ast *distinct();

/**
 */
  ReQL_ast *div();

/**
 */
  ReQL_ast *downcase();

/**
 */
  ReQL_ast *during();

/**
 */
  ReQL_ast *epoch_time();

/**
 */
  ReQL_ast *eq();

/**
 */
  ReQL_ast *eq_join();

/**
 */
  ReQL_ast *error();

/**
 */
  ReQL_ast *february();

/**
 */
  ReQL_ast *fill();

/**
 */
  ReQL_ast *filter();

/**
 */
  ReQL_ast *for_each();

/**
 */
  ReQL_ast *friday();

/**
 */
  ReQL_ast *func();

/**
 */
  ReQL_ast *funcall();

/**
 */
  ReQL_ast *ge();

/**
 */
  ReQL_ast *geojson();

/**
 */
  ReQL_ast *get();

/**
 */
  ReQL_ast *get_all();

/**
 */
  ReQL_ast *get_field();

/**
 */
  ReQL_ast *get_intersecting();

/**
 */
  ReQL_ast *get_nearest();

/**
 */
  ReQL_ast *group();

/**
 */
  ReQL_ast *gt();

/**
 */
  ReQL_ast *has_fields();

/**
 */
  ReQL_ast *hours();

/**
 */
  ReQL_ast *http();

/**
 */
  ReQL_ast *implicit_var();

/**
 */
  ReQL_ast *includes();

/**
 */
  ReQL_ast *indexes_of();

/**
 */
  ReQL_ast *index_create();

/**
 */
  ReQL_ast *index_drop();

/**
 */
  ReQL_ast *index_list();

/**
 */
  ReQL_ast *index_rename();

/**
 */
  ReQL_ast *index_status();

/**
 */
  ReQL_ast *index_wait();

/**
 */
  ReQL_ast *info();

/**
 */
  ReQL_ast *inner_join();

/**
 */
  ReQL_ast *insert();

/**
 */
  ReQL_ast *insert_at();

/**
 */
  ReQL_ast *intersects();

/**
 */
  ReQL_ast *in_timezone();

/**
 */
  ReQL_ast *iso8601();

/**
 */
  ReQL_ast *is_empty();

/**
 */
  ReQL_ast *january();

/**
 */
  ReQL_ast *javascript();

/**
 */
  ReQL_ast *json();

/**
 */
  ReQL_ast *july();

/**
 */
  ReQL_ast *june();

/**
 */
  ReQL_ast *keys();

/**
 */
  ReQL_ast *le();

/**
 */
  ReQL_ast *limit();

/**
 */
  ReQL_ast *line();

/**
 */
  ReQL_ast *literal();

/**
 */
  ReQL_ast *lt();

/**
 */
  ReQL_ast *make_array();

/**
 */
  ReQL_ast *make_obj();

/**
 */
  ReQL_ast *map();

/**
 */
  ReQL_ast *march();

/**
 */
  ReQL_ast *match();

/**
 */
  ReQL_ast *max();

/**
 */
  ReQL_ast *may();

/**
 */
  ReQL_ast *merge();

/**
 */
  ReQL_ast *min();

/**
 */
  ReQL_ast *minutes();

/**
 */
  ReQL_ast *mod();

/**
 */
  ReQL_ast *monday();

/**
 */
  ReQL_ast *month();

/**
 */
  ReQL_ast *mul();

/**
 */
  ReQL_ast *ne();

/**
 */
  ReQL_ast *not_();

/**
 */
  ReQL_ast *november();

/**
 */
  ReQL_ast *now();

/**
 */
  ReQL_ast *nth();

/**
 */
  ReQL_ast *object();

/**
 */
  ReQL_ast *october();

/**
 */
  ReQL_ast *order_by();

/**
 */
  ReQL_ast *outer_join();

/**
 */
  ReQL_ast *pluck();

/**
 */
  ReQL_ast *point();

/**
 */
  ReQL_ast *polygon();

/**
 */
  ReQL_ast *polygon_sub();

/**
 */
  ReQL_ast *prepend();

/**
 */
  ReQL_ast *random();

/**
 */
  ReQL_ast *range();

/**
 */
  ReQL_ast *reduce();

/**
 */
  ReQL_ast *replace();

/**
 */
  ReQL_ast *sample();

/**
 */
  ReQL_ast *saturday();

/**
 */
  ReQL_ast *seconds();

/**
 */
  ReQL_ast *september();

/**
 */
  ReQL_ast *set_difference();

/**
 */
  ReQL_ast *set_insert();

/**
 */
  ReQL_ast *set_intersection();

/**
 */
  ReQL_ast *set_union();

/**
 */
  ReQL_ast *skip();

/**
 */
  ReQL_ast *slice();

/**
 */
  ReQL_ast *splice_at();

/**
 */
  ReQL_ast *split();

/**
 */
  ReQL_ast *sub();

/**
 */
  ReQL_ast *sum();

/**
 */
  ReQL_ast *sunday();

/**
 */
  ReQL_ast *sync();

/**
 */
  ReQL_ast *table();

/**
 */
  ReQL_ast *table_create();

/**
 */
  ReQL_ast *table_drop();

/**
 */
  ReQL_ast *table_list();

/**
 */
  ReQL_ast *thursday();

/**
 */
  ReQL_ast *time();

/**
 */
  ReQL_ast *timezone();

/**
 */
  ReQL_ast *time_of_day();

/**
 */
  ReQL_ast *to_epoch_time();

/**
 */
  ReQL_ast *to_geojson();

/**
 */
  ReQL_ast *to_iso8601();

/**
 */
  ReQL_ast *to_json_string();

/**
 */
  ReQL_ast *tuesday();

/**
 */
  ReQL_ast *type_of();

/**
 */
  ReQL_ast *ungroup();

/**
 */
  ReQL_ast *union_();

/**
 */
  ReQL_ast *upcase();

/**
 */
  ReQL_ast *update();

/**
 */
  ReQL_ast *uuid();

/**
 */
  ReQL_ast *var();

/**
 */
  ReQL_ast *wednesday();

/**
 */
  ReQL_ast *without();

/**
 */
  ReQL_ast *with_fields();

/**
 */
  ReQL_ast *year();

/**
 */
  ReQL_ast *zip();
/* end generated header */
};

#endif
