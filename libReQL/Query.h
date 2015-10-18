/*
Copyright 2015 Adam Grandquist

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

@import Cocoa;

#import <libReQL/Connection.h>
#import <libReQL/Cursor.h>

@interface ReQLBool : NSObject

-(BOOL)boolValue;

@end

@interface ReQLQuery : NSObject

+(instancetype)newWithArray:(NSArray *)val;
+(instancetype)newWithBool:(BOOL)val;
+(instancetype)newWithNumber:(NSNumber *)val;
+(instancetype)newWithObject:(NSDictionary *)val;
+(instancetype)newWithString:(NSString *)val;

-(ReQLCursor *)run:(ReQLConnection *)conn;
-(ReQLCursor *)run:(ReQLConnection *)conn withOpts:(NSDictionary *)opts;
-(void)noReply:(ReQLConnection *)conn;
-(void)noReply:(ReQLConnection *)conn withOpts:(NSDictionary *)opts;

/**
 */
+(instancetype)
add:(NSArray *)args;
-(instancetype)
add:(NSArray *)args;

/**
 */
+(instancetype)
and:(NSArray *)args;
-(instancetype)
and:(NSArray *)args;

/**
 */
+(instancetype)
append:(NSArray *)args;
-(instancetype)
append:(NSArray *)args;

/**
 */
+(instancetype)
april:(NSArray *)args;
-(instancetype)
april:(NSArray *)args;

/**
 */
+(instancetype)
args:(NSArray *)args;
-(instancetype)
args:(NSArray *)args;

/**
 */
+(instancetype)
asc:(NSArray *)args;
-(instancetype)
asc:(NSArray *)args;

/**
 */
+(instancetype)
august:(NSArray *)args;
-(instancetype)
august:(NSArray *)args;

/**
 */
+(instancetype)
avg:(NSArray *)args;
-(instancetype)
avg:(NSArray *)args;

/**
 */
+(instancetype)
between:(NSArray *)args;
-(instancetype)
between:(NSArray *)args;

/**
 */
+(instancetype)
between_deprecated:(NSArray *)args;
-(instancetype)
between_deprecated:(NSArray *)args;

/**
 */
+(instancetype)
binary:(NSArray *)args;
-(instancetype)
binary:(NSArray *)args;

/**
 */
+(instancetype)
bracket:(NSArray *)args;
-(instancetype)
bracket:(NSArray *)args;

/**
 */
+(instancetype)
branch:(NSArray *)args;
-(instancetype)
branch:(NSArray *)args;

/**
 */
+(instancetype)
ceil:(NSArray *)args;
-(instancetype)
ceil:(NSArray *)args;

/**
 */
+(instancetype)
changes:(NSArray *)args;
-(instancetype)
changes:(NSArray *)args;

/**
 */
+(instancetype)
change_at:(NSArray *)args;
-(instancetype)
change_at:(NSArray *)args;

/**
 */
+(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
coerce_to:(NSArray *)args;
-(instancetype)
coerce_to:(NSArray *)args;

/**
 */
+(instancetype)
concat_map:(NSArray *)args;
-(instancetype)
concat_map:(NSArray *)args;

/**
 */
+(instancetype)
config:(NSArray *)args;
-(instancetype)
config:(NSArray *)args;

/**
 */
+(instancetype)
contains:(NSArray *)args;
-(instancetype)
contains:(NSArray *)args;

/**
 */
+(instancetype)
count:(NSArray *)args;
-(instancetype)
count:(NSArray *)args;

/**
 */
+(instancetype)
date:(NSArray *)args;
-(instancetype)
date:(NSArray *)args;

/**
 */
+(instancetype)
datum:(NSArray *)args;
-(instancetype)
datum:(NSArray *)args;

/**
 */
+(instancetype)
day:(NSArray *)args;
-(instancetype)
day:(NSArray *)args;

/**
 */
+(instancetype)
day_of_week:(NSArray *)args;
-(instancetype)
day_of_week:(NSArray *)args;

/**
 */
+(instancetype)
day_of_year:(NSArray *)args;
-(instancetype)
day_of_year:(NSArray *)args;

/**
 */
+(instancetype)
db:(NSArray *)args;
-(instancetype)
db:(NSArray *)args;

/**
 */
+(instancetype)
db_create:(NSArray *)args;
-(instancetype)
db_create:(NSArray *)args;

/**
 */
+(instancetype)
db_drop:(NSArray *)args;
-(instancetype)
db_drop:(NSArray *)args;

/**
 */
+(instancetype)
db_list:(NSArray *)args;
-(instancetype)
db_list:(NSArray *)args;

/**
 */
+(instancetype)
december:(NSArray *)args;
-(instancetype)
december:(NSArray *)args;

/**
 */
+(instancetype)
default:(NSArray *)args;
-(instancetype)
default:(NSArray *)args;

/**
 */
+(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
delete_at:(NSArray *)args;
-(instancetype)
delete_at:(NSArray *)args;

/**
 */
+(instancetype)
desc:(NSArray *)args;
-(instancetype)
desc:(NSArray *)args;

/**
 */
+(instancetype)
difference:(NSArray *)args;
-(instancetype)
difference:(NSArray *)args;

/**
 */
+(instancetype)
distance:(NSArray *)args;
-(instancetype)
distance:(NSArray *)args;

/**
 */
+(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
div:(NSArray *)args;
-(instancetype)
div:(NSArray *)args;

/**
 */
+(instancetype)
downcase:(NSArray *)args;
-(instancetype)
downcase:(NSArray *)args;

/**
 */
+(instancetype)
during:(NSArray *)args;
-(instancetype)
during:(NSArray *)args;

/**
 */
+(instancetype)
epoch_time:(NSArray *)args;
-(instancetype)
epoch_time:(NSArray *)args;

/**
 */
+(instancetype)
eq:(NSArray *)args;
-(instancetype)
eq:(NSArray *)args;

/**
 */
+(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
error:(NSArray *)args;
-(instancetype)
error:(NSArray *)args;

/**
 */
+(instancetype)
february:(NSArray *)args;
-(instancetype)
february:(NSArray *)args;

/**
 */
+(instancetype)
fill:(NSArray *)args;
-(instancetype)
fill:(NSArray *)args;

/**
 */
+(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
floor:(NSArray *)args;
-(instancetype)
floor:(NSArray *)args;

/**
 */
+(instancetype)
for_each:(NSArray *)args;
-(instancetype)
for_each:(NSArray *)args;

/**
 */
+(instancetype)
friday:(NSArray *)args;
-(instancetype)
friday:(NSArray *)args;

/**
 */
+(instancetype)
func:(NSArray *)args;
-(instancetype)
func:(NSArray *)args;

/**
 */
+(instancetype)
funcall:(NSArray *)args;
-(instancetype)
funcall:(NSArray *)args;

/**
 */
+(instancetype)
ge:(NSArray *)args;
-(instancetype)
ge:(NSArray *)args;

/**
 */
+(instancetype)
geojson:(NSArray *)args;
-(instancetype)
geojson:(NSArray *)args;

/**
 */
+(instancetype)
get:(NSArray *)args;
-(instancetype)
get:(NSArray *)args;

/**
 */
+(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
get_field:(NSArray *)args;
-(instancetype)
get_field:(NSArray *)args;

/**
 */
+(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
gt:(NSArray *)args;
-(instancetype)
gt:(NSArray *)args;

/**
 */
+(instancetype)
has_fields:(NSArray *)args;
-(instancetype)
has_fields:(NSArray *)args;

/**
 */
+(instancetype)
hours:(NSArray *)args;
-(instancetype)
hours:(NSArray *)args;

/**
 */
+(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
implicit_var:(NSArray *)args;
-(instancetype)
implicit_var:(NSArray *)args;

/**
 */
+(instancetype)
includes:(NSArray *)args;
-(instancetype)
includes:(NSArray *)args;

/**
 */
+(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
index_drop:(NSArray *)args;
-(instancetype)
index_drop:(NSArray *)args;

/**
 */
+(instancetype)
index_list:(NSArray *)args;
-(instancetype)
index_list:(NSArray *)args;

/**
 */
+(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
index_status:(NSArray *)args;
-(instancetype)
index_status:(NSArray *)args;

/**
 */
+(instancetype)
index_wait:(NSArray *)args;
-(instancetype)
index_wait:(NSArray *)args;

/**
 */
+(instancetype)
info:(NSArray *)args;
-(instancetype)
info:(NSArray *)args;

/**
 */
+(instancetype)
inner_join:(NSArray *)args;
-(instancetype)
inner_join:(NSArray *)args;

/**
 */
+(instancetype)
insert:(NSArray *)args;
-(instancetype)
insert:(NSArray *)args;

/**
 */
+(instancetype)
insert_at:(NSArray *)args;
-(instancetype)
insert_at:(NSArray *)args;

/**
 */
+(instancetype)
intersects:(NSArray *)args;
-(instancetype)
intersects:(NSArray *)args;

/**
 */
+(instancetype)
in_timezone:(NSArray *)args;
-(instancetype)
in_timezone:(NSArray *)args;

/**
 */
+(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
is_empty:(NSArray *)args;
-(instancetype)
is_empty:(NSArray *)args;

/**
 */
+(instancetype)
january:(NSArray *)args;
-(instancetype)
january:(NSArray *)args;

/**
 */
+(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
json:(NSArray *)args;
-(instancetype)
json:(NSArray *)args;

/**
 */
+(instancetype)
july:(NSArray *)args;
-(instancetype)
july:(NSArray *)args;

/**
 */
+(instancetype)
june:(NSArray *)args;
-(instancetype)
june:(NSArray *)args;

/**
 */
+(instancetype)
keys:(NSArray *)args;
-(instancetype)
keys:(NSArray *)args;

/**
 */
+(instancetype)
le:(NSArray *)args;
-(instancetype)
le:(NSArray *)args;

/**
 */
+(instancetype)
limit:(NSArray *)args;
-(instancetype)
limit:(NSArray *)args;

/**
 */
+(instancetype)
line:(NSArray *)args;
-(instancetype)
line:(NSArray *)args;

/**
 */
+(instancetype)
literal:(NSArray *)args;
-(instancetype)
literal:(NSArray *)args;

/**
 */
+(instancetype)
lt:(NSArray *)args;
-(instancetype)
lt:(NSArray *)args;

/**
 */
+(instancetype)
make_array:(NSArray *)args;
-(instancetype)
make_array:(NSArray *)args;

/**
 */
+(instancetype)
make_obj:(NSArray *)args;
-(instancetype)
make_obj:(NSArray *)args;

/**
 */
+(instancetype)
map:(NSArray *)args;
-(instancetype)
map:(NSArray *)args;

/**
 */
+(instancetype)
march:(NSArray *)args;
-(instancetype)
march:(NSArray *)args;

/**
 */
+(instancetype)
match:(NSArray *)args;
-(instancetype)
match:(NSArray *)args;

/**
 */
+(instancetype)
max:(NSArray *)args;
-(instancetype)
max:(NSArray *)args;

/**
 */
+(instancetype)
maxval:(NSArray *)args;
-(instancetype)
maxval:(NSArray *)args;

/**
 */
+(instancetype)
may:(NSArray *)args;
-(instancetype)
may:(NSArray *)args;

/**
 */
+(instancetype)
merge:(NSArray *)args;
-(instancetype)
merge:(NSArray *)args;

/**
 */
+(instancetype)
min:(NSArray *)args;
-(instancetype)
min:(NSArray *)args;

/**
 */
+(instancetype)
minutes:(NSArray *)args;
-(instancetype)
minutes:(NSArray *)args;

/**
 */
+(instancetype)
minval:(NSArray *)args;
-(instancetype)
minval:(NSArray *)args;

/**
 */
+(instancetype)
mod:(NSArray *)args;
-(instancetype)
mod:(NSArray *)args;

/**
 */
+(instancetype)
monday:(NSArray *)args;
-(instancetype)
monday:(NSArray *)args;

/**
 */
+(instancetype)
month:(NSArray *)args;
-(instancetype)
month:(NSArray *)args;

/**
 */
+(instancetype)
mul:(NSArray *)args;
-(instancetype)
mul:(NSArray *)args;

/**
 */
+(instancetype)
ne:(NSArray *)args;
-(instancetype)
ne:(NSArray *)args;

/**
 */
+(instancetype)
not:(NSArray *)args;
-(instancetype)
not:(NSArray *)args;

/**
 */
+(instancetype)
november:(NSArray *)args;
-(instancetype)
november:(NSArray *)args;

/**
 */
+(instancetype)
now:(NSArray *)args;
-(instancetype)
now:(NSArray *)args;

/**
 */
+(instancetype)
nth:(NSArray *)args;
-(instancetype)
nth:(NSArray *)args;

/**
 */
+(instancetype)
object:(NSArray *)args;
-(instancetype)
object:(NSArray *)args;

/**
 */
+(instancetype)
october:(NSArray *)args;
-(instancetype)
october:(NSArray *)args;

/**
 */
+(instancetype)
offsets_of:(NSArray *)args;
-(instancetype)
offsets_of:(NSArray *)args;

/**
 */
+(instancetype)
or:(NSArray *)args;
-(instancetype)
or:(NSArray *)args;

/**
 */
+(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
outer_join:(NSArray *)args;
-(instancetype)
outer_join:(NSArray *)args;

/**
 */
+(instancetype)
pluck:(NSArray *)args;
-(instancetype)
pluck:(NSArray *)args;

/**
 */
+(instancetype)
point:(NSArray *)args;
-(instancetype)
point:(NSArray *)args;

/**
 */
+(instancetype)
polygon:(NSArray *)args;
-(instancetype)
polygon:(NSArray *)args;

/**
 */
+(instancetype)
polygon_sub:(NSArray *)args;
-(instancetype)
polygon_sub:(NSArray *)args;

/**
 */
+(instancetype)
prepend:(NSArray *)args;
-(instancetype)
prepend:(NSArray *)args;

/**
 */
+(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
range:(NSArray *)args;
-(instancetype)
range:(NSArray *)args;

/**
 */
+(instancetype)
rebalance:(NSArray *)args;
-(instancetype)
rebalance:(NSArray *)args;

/**
 */
+(instancetype)
reconfigure:(NSArray *)args;
-(instancetype)
reconfigure:(NSArray *)args;

/**
 */
+(instancetype)
reduce:(NSArray *)args;
-(instancetype)
reduce:(NSArray *)args;

/**
 */
+(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
round:(NSArray *)args;
-(instancetype)
round:(NSArray *)args;

/**
 */
+(instancetype)
sample:(NSArray *)args;
-(instancetype)
sample:(NSArray *)args;

/**
 */
+(instancetype)
saturday:(NSArray *)args;
-(instancetype)
saturday:(NSArray *)args;

/**
 */
+(instancetype)
seconds:(NSArray *)args;
-(instancetype)
seconds:(NSArray *)args;

/**
 */
+(instancetype)
september:(NSArray *)args;
-(instancetype)
september:(NSArray *)args;

/**
 */
+(instancetype)
set_difference:(NSArray *)args;
-(instancetype)
set_difference:(NSArray *)args;

/**
 */
+(instancetype)
set_insert:(NSArray *)args;
-(instancetype)
set_insert:(NSArray *)args;

/**
 */
+(instancetype)
set_intersection:(NSArray *)args;
-(instancetype)
set_intersection:(NSArray *)args;

/**
 */
+(instancetype)
set_union:(NSArray *)args;
-(instancetype)
set_union:(NSArray *)args;

/**
 */
+(instancetype)
skip:(NSArray *)args;
-(instancetype)
skip:(NSArray *)args;

/**
 */
+(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
splice_at:(NSArray *)args;
-(instancetype)
splice_at:(NSArray *)args;

/**
 */
+(instancetype)
split:(NSArray *)args;
-(instancetype)
split:(NSArray *)args;

/**
 */
+(instancetype)
status:(NSArray *)args;
-(instancetype)
status:(NSArray *)args;

/**
 */
+(instancetype)
sub:(NSArray *)args;
-(instancetype)
sub:(NSArray *)args;

/**
 */
+(instancetype)
sum:(NSArray *)args;
-(instancetype)
sum:(NSArray *)args;

/**
 */
+(instancetype)
sunday:(NSArray *)args;
-(instancetype)
sunday:(NSArray *)args;

/**
 */
+(instancetype)
sync:(NSArray *)args;
-(instancetype)
sync:(NSArray *)args;

/**
 */
+(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
table_drop:(NSArray *)args;
-(instancetype)
table_drop:(NSArray *)args;

/**
 */
+(instancetype)
table_list:(NSArray *)args;
-(instancetype)
table_list:(NSArray *)args;

/**
 */
+(instancetype)
thursday:(NSArray *)args;
-(instancetype)
thursday:(NSArray *)args;

/**
 */
+(instancetype)
time:(NSArray *)args;
-(instancetype)
time:(NSArray *)args;

/**
 */
+(instancetype)
timezone:(NSArray *)args;
-(instancetype)
timezone:(NSArray *)args;

/**
 */
+(instancetype)
time_of_day:(NSArray *)args;
-(instancetype)
time_of_day:(NSArray *)args;

/**
 */
+(instancetype)
to_epoch_time:(NSArray *)args;
-(instancetype)
to_epoch_time:(NSArray *)args;

/**
 */
+(instancetype)
to_geojson:(NSArray *)args;
-(instancetype)
to_geojson:(NSArray *)args;

/**
 */
+(instancetype)
to_iso8601:(NSArray *)args;
-(instancetype)
to_iso8601:(NSArray *)args;

/**
 */
+(instancetype)
to_json_string:(NSArray *)args;
-(instancetype)
to_json_string:(NSArray *)args;

/**
 */
+(instancetype)
tuesday:(NSArray *)args;
-(instancetype)
tuesday:(NSArray *)args;

/**
 */
+(instancetype)
type_of:(NSArray *)args;
-(instancetype)
type_of:(NSArray *)args;

/**
 */
+(instancetype)
ungroup:(NSArray *)args;
-(instancetype)
ungroup:(NSArray *)args;

/**
 */
+(instancetype)
union:(NSArray *)args;
-(instancetype)
union:(NSArray *)args;

/**
 */
+(instancetype)
upcase:(NSArray *)args;
-(instancetype)
upcase:(NSArray *)args;

/**
 */
+(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs;
-(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs;

/**
 */
+(instancetype)
uuid:(NSArray *)args;
-(instancetype)
uuid:(NSArray *)args;

/**
 */
+(instancetype)
values:(NSArray *)args;
-(instancetype)
values:(NSArray *)args;

/**
 */
+(instancetype)
var:(NSArray *)args;
-(instancetype)
var:(NSArray *)args;

/**
 */
+(instancetype)
wait:(NSArray *)args;
-(instancetype)
wait:(NSArray *)args;

/**
 */
+(instancetype)
wednesday:(NSArray *)args;
-(instancetype)
wednesday:(NSArray *)args;

/**
 */
+(instancetype)
without:(NSArray *)args;
-(instancetype)
without:(NSArray *)args;

/**
 */
+(instancetype)
with_fields:(NSArray *)args;
-(instancetype)
with_fields:(NSArray *)args;

/**
 */
+(instancetype)
year:(NSArray *)args;
-(instancetype)
year:(NSArray *)args;

/**
 */
+(instancetype)
zip:(NSArray *)args;
-(instancetype)
zip:(NSArray *)args;

@end
