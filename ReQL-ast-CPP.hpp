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
  void add();

/**
 */
  void all();

/**
 */
  void any();

/**
 */
  void append();

/**
 */
  void april();

/**
 */
  void args();

/**
 */
  void asc();

/**
 */
  void august();

/**
 */
  void avg();

/**
 */
  void between();

/**
 */
  void binary();

/**
 */
  void bracket();

/**
 */
  void branch();

/**
 */
  void changes();

/**
 */
  void change_at();

/**
 */
  void circle();

/**
 */
  void coerce_to();

/**
 */
  void concat_map();

/**
 */
  void contains();

/**
 */
  void count();

/**
 */
  void date();

/**
 */
  void datum();

/**
 */
  void day();

/**
 */
  void day_of_week();

/**
 */
  void day_of_year();

/**
 */
  void db();

/**
 */
  void db_create();

/**
 */
  void db_drop();

/**
 */
  void db_list();

/**
 */
  void december();

/**
 */
  void default_();

/**
 */
  void delete_();

/**
 */
  void delete_at();

/**
 */
  void desc();

/**
 */
  void difference();

/**
 */
  void distance();

/**
 */
  void distinct();

/**
 */
  void div();

/**
 */
  void downcase();

/**
 */
  void during();

/**
 */
  void epoch_time();

/**
 */
  void eq();

/**
 */
  void eq_join();

/**
 */
  void error();

/**
 */
  void february();

/**
 */
  void fill();

/**
 */
  void filter();

/**
 */
  void for_each();

/**
 */
  void friday();

/**
 */
  void func();

/**
 */
  void funcall();

/**
 */
  void ge();

/**
 */
  void geojson();

/**
 */
  void get();

/**
 */
  void get_all();

/**
 */
  void get_field();

/**
 */
  void get_intersecting();

/**
 */
  void get_nearest();

/**
 */
  void group();

/**
 */
  void gt();

/**
 */
  void has_fields();

/**
 */
  void hours();

/**
 */
  void http();

/**
 */
  void implicit_var();

/**
 */
  void includes();

/**
 */
  void indexes_of();

/**
 */
  void index_create();

/**
 */
  void index_drop();

/**
 */
  void index_list();

/**
 */
  void index_rename();

/**
 */
  void index_status();

/**
 */
  void index_wait();

/**
 */
  void info();

/**
 */
  void inner_join();

/**
 */
  void insert();

/**
 */
  void insert_at();

/**
 */
  void intersects();

/**
 */
  void in_timezone();

/**
 */
  void iso8601();

/**
 */
  void is_empty();

/**
 */
  void january();

/**
 */
  void javascript();

/**
 */
  void json();

/**
 */
  void july();

/**
 */
  void june();

/**
 */
  void keys();

/**
 */
  void le();

/**
 */
  void limit();

/**
 */
  void line();

/**
 */
  void literal();

/**
 */
  void lt();

/**
 */
  void make_array();

/**
 */
  void make_obj();

/**
 */
  void map();

/**
 */
  void march();

/**
 */
  void match();

/**
 */
  void max();

/**
 */
  void may();

/**
 */
  void merge();

/**
 */
  void min();

/**
 */
  void minutes();

/**
 */
  void mod();

/**
 */
  void monday();

/**
 */
  void month();

/**
 */
  void mul();

/**
 */
  void ne();

/**
 */
  void not_();

/**
 */
  void november();

/**
 */
  void now();

/**
 */
  void nth();

/**
 */
  void object();

/**
 */
  void october();

/**
 */
  void order_by();

/**
 */
  void outer_join();

/**
 */
  void pluck();

/**
 */
  void point();

/**
 */
  void polygon();

/**
 */
  void polygon_sub();

/**
 */
  void prepend();

/**
 */
  void random();

/**
 */
  void range();

/**
 */
  void reduce();

/**
 */
  void replace();

/**
 */
  void sample();

/**
 */
  void saturday();

/**
 */
  void seconds();

/**
 */
  void september();

/**
 */
  void set_difference();

/**
 */
  void set_insert();

/**
 */
  void set_intersection();

/**
 */
  void set_union();

/**
 */
  void skip();

/**
 */
  void slice();

/**
 */
  void splice_at();

/**
 */
  void split();

/**
 */
  void sub();

/**
 */
  void sum();

/**
 */
  void sunday();

/**
 */
  void sync();

/**
 */
  void table();

/**
 */
  void table_create();

/**
 */
  void table_drop();

/**
 */
  void table_list();

/**
 */
  void thursday();

/**
 */
  void time();

/**
 */
  void timezone();

/**
 */
  void time_of_day();

/**
 */
  void to_epoch_time();

/**
 */
  void to_geojson();

/**
 */
  void to_iso8601();

/**
 */
  void to_json_string();

/**
 */
  void tuesday();

/**
 */
  void type_of();

/**
 */
  void ungroup();

/**
 */
  void union_();

/**
 */
  void upcase();

/**
 */
  void update();

/**
 */
  void uuid();

/**
 */
  void var();

/**
 */
  void wednesday();

/**
 */
  void without();

/**
 */
  void with_fields();

/**
 */
  void year();

/**
 */
  void zip();
/* end generated header */
};

#endif
