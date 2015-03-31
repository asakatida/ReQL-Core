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

#ifndef REQL_AST_OBJC_H_
#define REQL_AST_OBJC_H_

#import "ReQL-expr-ObjC.h"

@interface libReQL_ast : libReQL_expr

/**
 */
-(instancetype)
add;

/**
 */
-(instancetype)
and_;

/**
 */
-(instancetype)
append;

/**
 */
-(instancetype)
april;

/**
 */
-(instancetype)
args;

/**
 */
-(instancetype)
asc;

/**
 */
-(instancetype)
august;

/**
 */
-(instancetype)
avg;

/**
 */
-(instancetype)
between;

/**
 */
-(instancetype)
between_deprecated;

/**
 */
-(instancetype)
binary;

/**
 */
-(instancetype)
bracket;

/**
 */
-(instancetype)
branch;

/**
 */
-(instancetype)
ceil;

/**
 */
-(instancetype)
changes;

/**
 */
-(instancetype)
change_at;

/**
 */
-(instancetype)
circle;

/**
 */
-(instancetype)
coerce_to;

/**
 */
-(instancetype)
concat_map;

/**
 */
-(instancetype)
config;

/**
 */
-(instancetype)
contains;

/**
 */
-(instancetype)
count;

/**
 */
-(instancetype)
date;

/**
 */
-(instancetype)
datum;

/**
 */
-(instancetype)
day;

/**
 */
-(instancetype)
day_of_week;

/**
 */
-(instancetype)
day_of_year;

/**
 */
-(instancetype)
db;

/**
 */
-(instancetype)
db_create;

/**
 */
-(instancetype)
db_drop;

/**
 */
-(instancetype)
db_list;

/**
 */
-(instancetype)
december;

/**
 */
-(instancetype)
default;

/**
 */
-(instancetype)
delete;

/**
 */
-(instancetype)
delete_at;

/**
 */
-(instancetype)
desc;

/**
 */
-(instancetype)
difference;

/**
 */
-(instancetype)
distance;

/**
 */
-(instancetype)
distinct;

/**
 */
-(instancetype)
div;

/**
 */
-(instancetype)
downcase;

/**
 */
-(instancetype)
during;

/**
 */
-(instancetype)
epoch_time;

/**
 */
-(instancetype)
eq;

/**
 */
-(instancetype)
eq_join;

/**
 */
-(instancetype)
error;

/**
 */
-(instancetype)
february;

/**
 */
-(instancetype)
fill;

/**
 */
-(instancetype)
filter;

/**
 */
-(instancetype)
floor;

/**
 */
-(instancetype)
for_each;

/**
 */
-(instancetype)
friday;

/**
 */
-(instancetype)
func;

/**
 */
-(instancetype)
funcall;

/**
 */
-(instancetype)
ge;

/**
 */
-(instancetype)
geojson;

/**
 */
-(instancetype)
get;

/**
 */
-(instancetype)
get_all;

/**
 */
-(instancetype)
get_field;

/**
 */
-(instancetype)
get_intersecting;

/**
 */
-(instancetype)
get_nearest;

/**
 */
-(instancetype)
group;

/**
 */
-(instancetype)
gt;

/**
 */
-(instancetype)
has_fields;

/**
 */
-(instancetype)
hours;

/**
 */
-(instancetype)
http;

/**
 */
-(instancetype)
implicit_var;

/**
 */
-(instancetype)
includes;

/**
 */
-(instancetype)
index_create;

/**
 */
-(instancetype)
index_drop;

/**
 */
-(instancetype)
index_list;

/**
 */
-(instancetype)
index_rename;

/**
 */
-(instancetype)
index_status;

/**
 */
-(instancetype)
index_wait;

/**
 */
-(instancetype)
info;

/**
 */
-(instancetype)
inner_join;

/**
 */
-(instancetype)
insert;

/**
 */
-(instancetype)
insert_at;

/**
 */
-(instancetype)
intersects;

/**
 */
-(instancetype)
in_timezone;

/**
 */
-(instancetype)
iso8601;

/**
 */
-(instancetype)
is_empty;

/**
 */
-(instancetype)
january;

/**
 */
-(instancetype)
javascript;

/**
 */
-(instancetype)
json;

/**
 */
-(instancetype)
july;

/**
 */
-(instancetype)
june;

/**
 */
-(instancetype)
keys;

/**
 */
-(instancetype)
le;

/**
 */
-(instancetype)
limit;

/**
 */
-(instancetype)
line;

/**
 */
-(instancetype)
literal;

/**
 */
-(instancetype)
lt;

/**
 */
-(instancetype)
make_array;

/**
 */
-(instancetype)
make_obj;

/**
 */
-(instancetype)
map;

/**
 */
-(instancetype)
march;

/**
 */
-(instancetype)
match;

/**
 */
-(instancetype)
max;

/**
 */
-(instancetype)
maxval;

/**
 */
-(instancetype)
may;

/**
 */
-(instancetype)
merge;

/**
 */
-(instancetype)
min;

/**
 */
-(instancetype)
minutes;

/**
 */
-(instancetype)
minval;

/**
 */
-(instancetype)
mod;

/**
 */
-(instancetype)
monday;

/**
 */
-(instancetype)
month;

/**
 */
-(instancetype)
mul;

/**
 */
-(instancetype)
ne;

/**
 */
-(instancetype)
not;

/**
 */
-(instancetype)
november;

/**
 */
-(instancetype)
now;

/**
 */
-(instancetype)
nth;

/**
 */
-(instancetype)
object;

/**
 */
-(instancetype)
october;

/**
 */
-(instancetype)
offsets_of;

/**
 */
-(instancetype)
or_;

/**
 */
-(instancetype)
order_by;

/**
 */
-(instancetype)
outer_join;

/**
 */
-(instancetype)
pluck;

/**
 */
-(instancetype)
point;

/**
 */
-(instancetype)
polygon;

/**
 */
-(instancetype)
polygon_sub;

/**
 */
-(instancetype)
prepend;

/**
 */
-(instancetype)
random;

/**
 */
-(instancetype)
range;

/**
 */
-(instancetype)
rebalance;

/**
 */
-(instancetype)
reconfigure;

/**
 */
-(instancetype)
reduce;

/**
 */
-(instancetype)
replace;

/**
 */
-(instancetype)
round;

/**
 */
-(instancetype)
sample;

/**
 */
-(instancetype)
saturday;

/**
 */
-(instancetype)
seconds;

/**
 */
-(instancetype)
september;

/**
 */
-(instancetype)
set_difference;

/**
 */
-(instancetype)
set_insert;

/**
 */
-(instancetype)
set_intersection;

/**
 */
-(instancetype)
set_union;

/**
 */
-(instancetype)
skip;

/**
 */
-(instancetype)
slice;

/**
 */
-(instancetype)
splice_at;

/**
 */
-(instancetype)
split;

/**
 */
-(instancetype)
status;

/**
 */
-(instancetype)
sub;

/**
 */
-(instancetype)
sum;

/**
 */
-(instancetype)
sunday;

/**
 */
-(instancetype)
sync;

/**
 */
-(instancetype)
table;

/**
 */
-(instancetype)
table_create;

/**
 */
-(instancetype)
table_drop;

/**
 */
-(instancetype)
table_list;

/**
 */
-(instancetype)
thursday;

/**
 */
-(instancetype)
time;

/**
 */
-(instancetype)
timezone;

/**
 */
-(instancetype)
time_of_day;

/**
 */
-(instancetype)
to_epoch_time;

/**
 */
-(instancetype)
to_geojson;

/**
 */
-(instancetype)
to_iso8601;

/**
 */
-(instancetype)
to_json_string;

/**
 */
-(instancetype)
tuesday;

/**
 */
-(instancetype)
type_of;

/**
 */
-(instancetype)
ungroup;

/**
 */
-(instancetype)
union;

/**
 */
-(instancetype)
upcase;

/**
 */
-(instancetype)
update;

/**
 */
-(instancetype)
uuid;

/**
 */
-(instancetype)
var;

/**
 */
-(instancetype)
wait;

/**
 */
-(instancetype)
wednesday;

/**
 */
-(instancetype)
without;

/**
 */
-(instancetype)
with_fields;

/**
 */
-(instancetype)
year;

/**
 */
-(instancetype)
zip;

@end

#endif  // REQL_AST_OBJC_H_
