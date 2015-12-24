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

#import <Cocoa/Cocoa.h>

#import <libReQL/Connection.h>

@interface ReQLBool : NSObject

-(BOOL)boolValue;

@end

@interface ReQLQuery : NSObject

+(nullable instancetype)newWithArray:(nonnull NSArray *)val;
+(nullable instancetype)newWithBool:(BOOL)val;
+(nullable instancetype)newWithNumber:(nonnull NSNumber *)val;
+(nullable instancetype)newWithObject:(nonnull NSDictionary *)val;
+(nullable instancetype)newWithString:(nonnull NSString *)val;

-(void)noReply:(nonnull ReQLConnection *)conn;
-(void)noReply:(nonnull ReQLConnection *)conn withOpts:(nonnull NSDictionary *)opts;

/**
 */
+(nullable instancetype)
add:(nullable NSArray *)args;
-(nullable instancetype)
add:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
and:(nullable NSArray *)args;
-(nullable instancetype)
and:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
append:(nullable NSArray *)args;
-(nullable instancetype)
append:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
april:(nullable NSArray *)args;
-(nullable instancetype)
april:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
args:(nullable NSArray *)args;
-(nullable instancetype)
args:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
asc:(nullable NSArray *)args;
-(nullable instancetype)
asc:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
august:(nullable NSArray *)args;
-(nullable instancetype)
august:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
avg:(nullable NSArray *)args;
-(nullable instancetype)
avg:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
between:(nullable NSArray *)args;
-(nullable instancetype)
between:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
between_deprecated:(nullable NSArray *)args;
-(nullable instancetype)
between_deprecated:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
binary:(nullable NSArray *)args;
-(nullable instancetype)
binary:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
bracket:(nullable NSArray *)args;
-(nullable instancetype)
bracket:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
branch:(nullable NSArray *)args;
-(nullable instancetype)
branch:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
ceil:(nullable NSArray *)args;
-(nullable instancetype)
ceil:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
changes:(nullable NSArray *)args;
-(nullable instancetype)
changes:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
change_at:(nullable NSArray *)args;
-(nullable instancetype)
change_at:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
circle:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
circle:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
coerce_to:(nullable NSArray *)args;
-(nullable instancetype)
coerce_to:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
concat_map:(nullable NSArray *)args;
-(nullable instancetype)
concat_map:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
config:(nullable NSArray *)args;
-(nullable instancetype)
config:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
contains:(nullable NSArray *)args;
-(nullable instancetype)
contains:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
count:(nullable NSArray *)args;
-(nullable instancetype)
count:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
date:(nullable NSArray *)args;
-(nullable instancetype)
date:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
datum:(nullable NSArray *)args;
-(nullable instancetype)
datum:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
day:(nullable NSArray *)args;
-(nullable instancetype)
day:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
day_of_week:(nullable NSArray *)args;
-(nullable instancetype)
day_of_week:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
day_of_year:(nullable NSArray *)args;
-(nullable instancetype)
day_of_year:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
db:(nullable NSArray *)args;
-(nullable instancetype)
db:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
db_create:(nullable NSArray *)args;
-(nullable instancetype)
db_create:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
db_drop:(nullable NSArray *)args;
-(nullable instancetype)
db_drop:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
db_list:(nullable NSArray *)args;
-(nullable instancetype)
db_list:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
december:(nullable NSArray *)args;
-(nullable instancetype)
december:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
default:(nullable NSArray *)args;
-(nullable instancetype)
default:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
delete:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
delete:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
delete_at:(nullable NSArray *)args;
-(nullable instancetype)
delete_at:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
desc:(nullable NSArray *)args;
-(nullable instancetype)
desc:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
difference:(nullable NSArray *)args;
-(nullable instancetype)
difference:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
distance:(nullable NSArray *)args;
-(nullable instancetype)
distance:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
distinct:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
distinct:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
div:(nullable NSArray *)args;
-(nullable instancetype)
div:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
downcase:(nullable NSArray *)args;
-(nullable instancetype)
downcase:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
during:(nullable NSArray *)args;
-(nullable instancetype)
during:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
epoch_time:(nullable NSArray *)args;
-(nullable instancetype)
epoch_time:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
eq:(nullable NSArray *)args;
-(nullable instancetype)
eq:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
eq_join:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
eq_join:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
error:(nullable NSArray *)args;
-(nullable instancetype)
error:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
february:(nullable NSArray *)args;
-(nullable instancetype)
february:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
fill:(nullable NSArray *)args;
-(nullable instancetype)
fill:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
filter:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
filter:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
floor:(nullable NSArray *)args;
-(nullable instancetype)
floor:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
for_each:(nullable NSArray *)args;
-(nullable instancetype)
for_each:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
friday:(nullable NSArray *)args;
-(nullable instancetype)
friday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
func:(nullable NSArray *)args;
-(nullable instancetype)
func:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
funcall:(nullable NSArray *)args;
-(nullable instancetype)
funcall:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
ge:(nullable NSArray *)args;
-(nullable instancetype)
ge:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
geojson:(nullable NSArray *)args;
-(nullable instancetype)
geojson:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
get:(nullable NSArray *)args;
-(nullable instancetype)
get:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
get_all:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
get_all:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
get_field:(nullable NSArray *)args;
-(nullable instancetype)
get_field:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
get_intersecting:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
get_intersecting:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
get_nearest:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
get_nearest:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
group:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
group:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
gt:(nullable NSArray *)args;
-(nullable instancetype)
gt:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
has_fields:(nullable NSArray *)args;
-(nullable instancetype)
has_fields:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
hours:(nullable NSArray *)args;
-(nullable instancetype)
hours:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
http:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
http:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
implicit_var:(nullable NSArray *)args;
-(nullable instancetype)
implicit_var:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
includes:(nullable NSArray *)args;
-(nullable instancetype)
includes:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
index_create:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
index_create:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
index_drop:(nullable NSArray *)args;
-(nullable instancetype)
index_drop:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
index_list:(nullable NSArray *)args;
-(nullable instancetype)
index_list:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
index_rename:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
index_rename:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
index_status:(nullable NSArray *)args;
-(nullable instancetype)
index_status:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
index_wait:(nullable NSArray *)args;
-(nullable instancetype)
index_wait:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
info:(nullable NSArray *)args;
-(nullable instancetype)
info:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
inner_join:(nullable NSArray *)args;
-(nullable instancetype)
inner_join:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
insert:(nullable NSArray *)args;
-(nullable instancetype)
insert:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
insert_at:(nullable NSArray *)args;
-(nullable instancetype)
insert_at:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
intersects:(nullable NSArray *)args;
-(nullable instancetype)
intersects:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
in_timezone:(nullable NSArray *)args;
-(nullable instancetype)
in_timezone:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
iso8601:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
iso8601:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
is_empty:(nullable NSArray *)args;
-(nullable instancetype)
is_empty:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
january:(nullable NSArray *)args;
-(nullable instancetype)
january:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
javascript:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
javascript:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
json:(nullable NSArray *)args;
-(nullable instancetype)
json:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
july:(nullable NSArray *)args;
-(nullable instancetype)
july:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
june:(nullable NSArray *)args;
-(nullable instancetype)
june:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
keys:(nullable NSArray *)args;
-(nullable instancetype)
keys:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
le:(nullable NSArray *)args;
-(nullable instancetype)
le:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
limit:(nullable NSArray *)args;
-(nullable instancetype)
limit:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
line:(nullable NSArray *)args;
-(nullable instancetype)
line:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
literal:(nullable NSArray *)args;
-(nullable instancetype)
literal:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
lt:(nullable NSArray *)args;
-(nullable instancetype)
lt:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
make_array:(nullable NSArray *)args;
-(nullable instancetype)
make_array:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
make_obj:(nullable NSArray *)args;
-(nullable instancetype)
make_obj:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
map:(nullable NSArray *)args;
-(nullable instancetype)
map:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
march:(nullable NSArray *)args;
-(nullable instancetype)
march:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
match:(nullable NSArray *)args;
-(nullable instancetype)
match:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
max:(nullable NSArray *)args;
-(nullable instancetype)
max:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
maxval:(nullable NSArray *)args;
-(nullable instancetype)
maxval:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
may:(nullable NSArray *)args;
-(nullable instancetype)
may:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
merge:(nullable NSArray *)args;
-(nullable instancetype)
merge:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
min:(nullable NSArray *)args;
-(nullable instancetype)
min:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
minutes:(nullable NSArray *)args;
-(nullable instancetype)
minutes:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
minval:(nullable NSArray *)args;
-(nullable instancetype)
minval:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
mod:(nullable NSArray *)args;
-(nullable instancetype)
mod:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
monday:(nullable NSArray *)args;
-(nullable instancetype)
monday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
month:(nullable NSArray *)args;
-(nullable instancetype)
month:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
mul:(nullable NSArray *)args;
-(nullable instancetype)
mul:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
ne:(nullable NSArray *)args;
-(nullable instancetype)
ne:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
not:(nullable NSArray *)args;
-(nullable instancetype)
not:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
november:(nullable NSArray *)args;
-(nullable instancetype)
november:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
now:(nullable NSArray *)args;
-(nullable instancetype)
now:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
nth:(nullable NSArray *)args;
-(nullable instancetype)
nth:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
object:(nullable NSArray *)args;
-(nullable instancetype)
object:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
october:(nullable NSArray *)args;
-(nullable instancetype)
october:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
offsets_of:(nullable NSArray *)args;
-(nullable instancetype)
offsets_of:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
or:(nullable NSArray *)args;
-(nullable instancetype)
or:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
order_by:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
order_by:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
outer_join:(nullable NSArray *)args;
-(nullable instancetype)
outer_join:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
pluck:(nullable NSArray *)args;
-(nullable instancetype)
pluck:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
point:(nullable NSArray *)args;
-(nullable instancetype)
point:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
polygon:(nullable NSArray *)args;
-(nullable instancetype)
polygon:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
polygon_sub:(nullable NSArray *)args;
-(nullable instancetype)
polygon_sub:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
prepend:(nullable NSArray *)args;
-(nullable instancetype)
prepend:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
random:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
random:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
range:(nullable NSArray *)args;
-(nullable instancetype)
range:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
rebalance:(nullable NSArray *)args;
-(nullable instancetype)
rebalance:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
reconfigure:(nullable NSArray *)args;
-(nullable instancetype)
reconfigure:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
reduce:(nullable NSArray *)args;
-(nullable instancetype)
reduce:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
replace:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
replace:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
round:(nullable NSArray *)args;
-(nullable instancetype)
round:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
sample:(nullable NSArray *)args;
-(nullable instancetype)
sample:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
saturday:(nullable NSArray *)args;
-(nullable instancetype)
saturday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
seconds:(nullable NSArray *)args;
-(nullable instancetype)
seconds:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
september:(nullable NSArray *)args;
-(nullable instancetype)
september:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
set_difference:(nullable NSArray *)args;
-(nullable instancetype)
set_difference:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
set_insert:(nullable NSArray *)args;
-(nullable instancetype)
set_insert:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
set_intersection:(nullable NSArray *)args;
-(nullable instancetype)
set_intersection:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
set_union:(nullable NSArray *)args;
-(nullable instancetype)
set_union:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
skip:(nullable NSArray *)args;
-(nullable instancetype)
skip:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
slice:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
slice:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
splice_at:(nullable NSArray *)args;
-(nullable instancetype)
splice_at:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
split:(nullable NSArray *)args;
-(nullable instancetype)
split:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
status:(nullable NSArray *)args;
-(nullable instancetype)
status:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
sub:(nullable NSArray *)args;
-(nullable instancetype)
sub:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
sum:(nullable NSArray *)args;
-(nullable instancetype)
sum:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
sunday:(nullable NSArray *)args;
-(nullable instancetype)
sunday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
sync:(nullable NSArray *)args;
-(nullable instancetype)
sync:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
table:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
table:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
table_create:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
table_create:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
table_drop:(nullable NSArray *)args;
-(nullable instancetype)
table_drop:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
table_list:(nullable NSArray *)args;
-(nullable instancetype)
table_list:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
thursday:(nullable NSArray *)args;
-(nullable instancetype)
thursday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
time:(nullable NSArray *)args;
-(nullable instancetype)
time:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
timezone:(nullable NSArray *)args;
-(nullable instancetype)
timezone:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
time_of_day:(nullable NSArray *)args;
-(nullable instancetype)
time_of_day:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
to_epoch_time:(nullable NSArray *)args;
-(nullable instancetype)
to_epoch_time:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
to_geojson:(nullable NSArray *)args;
-(nullable instancetype)
to_geojson:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
to_iso8601:(nullable NSArray *)args;
-(nullable instancetype)
to_iso8601:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
to_json_string:(nullable NSArray *)args;
-(nullable instancetype)
to_json_string:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
tuesday:(nullable NSArray *)args;
-(nullable instancetype)
tuesday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
type_of:(nullable NSArray *)args;
-(nullable instancetype)
type_of:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
ungroup:(nullable NSArray *)args;
-(nullable instancetype)
ungroup:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
union:(nullable NSArray *)args;
-(nullable instancetype)
union:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
upcase:(nullable NSArray *)args;
-(nullable instancetype)
upcase:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
update:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;
-(nullable instancetype)
update:(nullable NSArray *)args :(nullable NSDictionary *)kwargs;

/**
 */
+(nullable instancetype)
uuid:(nullable NSArray *)args;
-(nullable instancetype)
uuid:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
values:(nullable NSArray *)args;
-(nullable instancetype)
values:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
var:(nullable NSArray *)args;
-(nullable instancetype)
var:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
wait:(nullable NSArray *)args;
-(nullable instancetype)
wait:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
wednesday:(nullable NSArray *)args;
-(nullable instancetype)
wednesday:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
without:(nullable NSArray *)args;
-(nullable instancetype)
without:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
with_fields:(nullable NSArray *)args;
-(nullable instancetype)
with_fields:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
year:(nullable NSArray *)args;
-(nullable instancetype)
year:(nullable NSArray *)args;

/**
 */
+(nullable instancetype)
zip:(nullable NSArray *)args;
-(nullable instancetype)
zip:(nullable NSArray *)args;

@end
