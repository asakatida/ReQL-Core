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

#import "Query.h"

#import "./reql/core.h"

#define NEW_REQL_OBJ ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));\
if (obj == NULL) {\
  return NULL;\
}

@protocol Expr <NSObject>

-(ReQL_Obj_t *)build;

@end

@interface ArrayExpr : NSObject <Expr> {
  NSArray *p_data;
}

@property (atomic, readonly) NSArray *p_data;

-(instancetype)init:(NSArray *)val;

@end

@interface BoolExpr : NSObject <Expr> {
  BOOL p_data;
}

@property (atomic, readonly) BOOL p_data;

-(instancetype)init:(BOOL)val;

@end

@interface NullExpr : NSObject <Expr>

@end

@interface NumberExpr : NSObject <Expr> {
  NSNumber *p_data;
}

@property (atomic, readonly) NSNumber *p_data;

-(instancetype)init:(NSNumber *)val;

@end

@interface ObjectExpr : NSObject <Expr> {
  NSDictionary *p_data;
}

@property (atomic, readonly) NSDictionary *p_data;

-(instancetype)init:(NSDictionary *)val;

@end

@interface StringExpr : NSObject <Expr> {
  NSString *p_data;
}

@property (atomic, readonly) NSString *p_data;

-(instancetype)init:(NSString *)val;

@end

@interface TermExpr : NSObject <Expr> {
  ArrayExpr *p_args;
  ObjectExpr *p_kwargs;
  ReQL_Term_t p_tt;
}

-(instancetype)init:(ReQL_Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs;

@end

@implementation ArrayExpr

@synthesize p_data=p_data;

-(instancetype)init:(NSArray *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  NSUInteger size = [p_data count];
  ReQL_Obj_t **buf = malloc(sizeof(ReQL_Obj_t*) * size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_array_init(obj, buf, (ReQL_Size)size);
  for (Query *elem in p_data) {
    ReQL_Obj_t *r_elem = [elem build];
    reql_array_append(obj, r_elem);
  }
  return obj;
}

@end

@implementation BoolExpr

@synthesize p_data=p_data;

-(instancetype)init:(BOOL)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  reql_bool_init(obj, p_data ? 1 == 1 : 0 == 1);
  return obj;
}

@end

@implementation NullExpr

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  reql_null_init(obj);
  return obj;
}

@end

@implementation NumberExpr

@synthesize p_data=p_data;

-(instancetype)init:(NSNumber *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  reql_number_init(obj, [p_data doubleValue]);
  return obj;
}

@end

@implementation ObjectExpr

@synthesize p_data=p_data;

-(instancetype)init:(NSDictionary *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  NSUInteger size = [p_data count];
  ReQL_Pair_t *buf = malloc(sizeof(ReQL_Pair_t) * size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_object_init(obj, buf, (ReQL_Size)size);
  NSEnumerator *enumerator = [p_data keyEnumerator];
  NSString *key;
  while (key = [enumerator nextObject]) {
    Query *val = [p_data valueForKey:key];
    StringExpr *key_ = [[StringExpr alloc] init:key];
    ReQL_Obj_t *r_key = [key_ build];
    [key_ release];
    ReQL_Obj_t *r_val = [val build];
    reql_object_add(obj, r_key, r_val);
  }
  return obj;
}

@end

@implementation StringExpr

@synthesize p_data=p_data;

-(instancetype)init:(NSString *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  NSUInteger size = [p_data lengthOfBytesUsingEncoding:NSUnicodeStringEncoding];
  ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * size);
  if (buf == NULL) {
    free(obj);
    return NULL;
  }
  reql_string_init(obj, buf, (ReQL_Size)size);
  reql_string_append(obj, (ReQL_Byte *)[p_data cStringUsingEncoding:NSUnicodeStringEncoding], (ReQL_Size)size);
  return obj;
}

@end

@implementation TermExpr

-(instancetype)init:(ReQL_Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs {
  if (self = [super init]) {
    p_args = [[ArrayExpr alloc] init:args];
    p_kwargs = [[ObjectExpr alloc] init:kwargs];
  }
  return self;
}

-(ReQL_Obj_t *)build {
  NEW_REQL_OBJ;
  ReQL_Obj_t *r_args = [p_args build];
  ReQL_Obj_t *r_kwargs = [p_kwargs build];
  reql_term_init(obj, p_tt, r_args, r_kwargs);
  return obj;
}

@end

@implementation Query {
  NSObject <Expr> *p_build;
}

-(instancetype)init {
  if (self = [super init]) {
    p_build = [NullExpr new];
  }
  return self;
}

-(instancetype)initWithArray:(NSArray *)val {
  if (self = [super init]) {
    p_build = [[ArrayExpr alloc] init:val];
  }
  return self;
}

-(instancetype)initWithBool:(BOOL)val {
  if (self = [super init]) {
    p_build = [[BoolExpr alloc] init:val];
  }
  return self;
}

-(instancetype)initWithNumber:(NSNumber *)val {
  if (self = [super init]) {
    p_build = [[NumberExpr alloc] init:val];
  }
  return self;
}

-(instancetype)initWithObject:(NSDictionary *)val {
  if (self = [super init]) {
    p_build = [[ObjectExpr alloc] init:val];
  }
  return self;
}

-(instancetype)initWithString:(NSString *)val {
  if (self = [super init]) {
    p_build = [[StringExpr alloc] init:val];
  }
  return self;
}

-(instancetype)init:(ReQL_Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs {
  if (self = [self init]) {
    p_build = [[TermExpr alloc] init:tt :args :kwargs];
  }
  return self;
}

-(instancetype)newTerm:(ReQL_Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs {
  return [[Query alloc] init:tt :[@[self] arrayByAddingObjectsFromArray:args] :kwargs];
}

-(instancetype)newTerm:(ReQL_Term_t)tt :(NSArray *)args {
  return [self newTerm:tt :args :[NSDictionary new]];
}

-(voidPtr)build {
  return [p_build build];
}

-(void)dealloc {
  [p_build release];
  [super dealloc];
}

-(instancetype)
add:(NSArray *)args {
  return [self newTerm:REQL_ADD :args];
}

-(instancetype)
and:(NSArray *)args {
  return self;
}

-(instancetype)
append:(NSArray *)args {
  return self;
}

-(instancetype)
april:(NSArray *)args {
  return self;
}

-(instancetype)
args:(NSArray *)args {
  return self;
}

-(instancetype)
asc:(NSArray *)args {
  return self;
}

-(instancetype)
august:(NSArray *)args {
  return self;
}

-(instancetype)
avg:(NSArray *)args {
  return self;
}

-(instancetype)
between:(NSArray *)args {
  return self;
}

-(instancetype)
between_deprecated:(NSArray *)args {
  return self;
}

-(instancetype)
binary:(NSArray *)args {
  return self;
}

-(instancetype)
bracket:(NSArray *)args {
  return self;
}

-(instancetype)
branch:(NSArray *)args {
  return self;
}

-(instancetype)
ceil:(NSArray *)args {
  return self;
}

-(instancetype)
changes:(NSArray *)args {
  return self;
}

-(instancetype)
change_at:(NSArray *)args {
  return self;
}

-(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
coerce_to:(NSArray *)args {
  return self;
}

-(instancetype)
concat_map:(NSArray *)args {
  return self;
}

-(instancetype)
config:(NSArray *)args {
  return self;
}

-(instancetype)
contains:(NSArray *)args {
  return self;
}

-(instancetype)
count:(NSArray *)args {
  return self;
}

-(instancetype)
date:(NSArray *)args {
  return self;
}

-(instancetype)
datum:(NSArray *)args {
  return self;
}

-(instancetype)
day:(NSArray *)args {
  return self;
}

-(instancetype)
day_of_week:(NSArray *)args {
  return self;
}

-(instancetype)
day_of_year:(NSArray *)args {
  return self;
}

-(instancetype)
db:(NSArray *)args {
  return self;
}

-(instancetype)
db_create:(NSArray *)args {
  return self;
}

-(instancetype)
db_drop:(NSArray *)args {
  return self;
}

-(instancetype)
db_list:(NSArray *)args {
  return self;
}

-(instancetype)
december:(NSArray *)args {
  return self;
}

-(instancetype)
default:(NSArray *)args {
  return self;
}

-(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
delete_at:(NSArray *)args {
  return self;
}

-(instancetype)
desc:(NSArray *)args {
  return self;
}

-(instancetype)
difference:(NSArray *)args {
  return self;
}

-(instancetype)
distance:(NSArray *)args {
  return self;
}

-(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
div:(NSArray *)args {
  return self;
}

-(instancetype)
downcase:(NSArray *)args {
  return self;
}

-(instancetype)
during:(NSArray *)args {
  return self;
}

-(instancetype)
epoch_time:(NSArray *)args {
  return self;
}

-(instancetype)
eq:(NSArray *)args {
  return self;
}

-(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
error:(NSArray *)args {
  return self;
}

-(instancetype)
february:(NSArray *)args {
  return self;
}

-(instancetype)
fill:(NSArray *)args {
  return self;
}

-(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
floor:(NSArray *)args {
  return self;
}

-(instancetype)
for_each:(NSArray *)args {
  return self;
}

-(instancetype)
friday:(NSArray *)args {
  return self;
}

-(instancetype)
func:(NSArray *)args {
  return self;
}

-(instancetype)
funcall:(NSArray *)args {
  return self;
}

-(instancetype)
ge:(NSArray *)args {
  return self;
}

-(instancetype)
geojson:(NSArray *)args {
  return self;
}

-(instancetype)
get:(NSArray *)args {
  return self;
}

-(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
get_field:(NSArray *)args {
  return self;
}

-(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
gt:(NSArray *)args {
  return self;
}

-(instancetype)
has_fields:(NSArray *)args {
  return self;
}

-(instancetype)
hours:(NSArray *)args {
  return self;
}

-(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
implicit_var:(NSArray *)args {
  return self;
}

-(instancetype)
includes:(NSArray *)args {
  return self;
}

-(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
index_drop:(NSArray *)args {
  return self;
}

-(instancetype)
index_list:(NSArray *)args {
  return self;
}

-(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
index_status:(NSArray *)args {
  return self;
}

-(instancetype)
index_wait:(NSArray *)args {
  return self;
}

-(instancetype)
info:(NSArray *)args {
  return self;
}

-(instancetype)
inner_join:(NSArray *)args {
  return self;
}

-(instancetype)
insert:(NSArray *)args {
  return self;
}

-(instancetype)
insert_at:(NSArray *)args {
  return self;
}

-(instancetype)
intersects:(NSArray *)args {
  return self;
}

-(instancetype)
in_timezone:(NSArray *)args {
  return self;
}

-(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
is_empty:(NSArray *)args {
  return self;
}

-(instancetype)
january:(NSArray *)args {
  return self;
}

-(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
json:(NSArray *)args {
  return self;
}

-(instancetype)
july:(NSArray *)args {
  return self;
}

-(instancetype)
june:(NSArray *)args {
  return self;
}

-(instancetype)
keys:(NSArray *)args {
  return self;
}

-(instancetype)
le:(NSArray *)args {
  return self;
}

-(instancetype)
limit:(NSArray *)args {
  return self;
}

-(instancetype)
line:(NSArray *)args {
  return self;
}

-(instancetype)
literal:(NSArray *)args {
  return self;
}

-(instancetype)
lt:(NSArray *)args {
  return self;
}

-(instancetype)
make_array:(NSArray *)args {
  return self;
}

-(instancetype)
make_obj:(NSArray *)args {
  return self;
}

-(instancetype)
map:(NSArray *)args {
  return self;
}

-(instancetype)
march:(NSArray *)args {
  return self;
}

-(instancetype)
match:(NSArray *)args {
  return self;
}

-(instancetype)
max:(NSArray *)args {
  return self;
}

-(instancetype)
maxval:(NSArray *)args {
  return self;
}

-(instancetype)
may:(NSArray *)args {
  return self;
}

-(instancetype)
merge:(NSArray *)args {
  return self;
}

-(instancetype)
min:(NSArray *)args {
  return self;
}

-(instancetype)
minutes:(NSArray *)args {
  return self;
}

-(instancetype)
minval:(NSArray *)args {
  return self;
}

-(instancetype)
mod:(NSArray *)args {
  return self;
}

-(instancetype)
monday:(NSArray *)args {
  return self;
}

-(instancetype)
month:(NSArray *)args {
  return self;
}

-(instancetype)
mul:(NSArray *)args {
  return self;
}

-(instancetype)
ne:(NSArray *)args {
  return self;
}

-(instancetype)
not:(NSArray *)args {
  return self;
}

-(instancetype)
november:(NSArray *)args {
  return self;
}

-(instancetype)
now:(NSArray *)args {
  return self;
}

-(instancetype)
nth:(NSArray *)args {
  return self;
}

-(instancetype)
object:(NSArray *)args {
  return self;
}

-(instancetype)
october:(NSArray *)args {
  return self;
}

-(instancetype)
offsets_of:(NSArray *)args {
  return self;
}

-(instancetype)
or:(NSArray *)args {
  return self;
}

-(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
outer_join:(NSArray *)args {
  return self;
}

-(instancetype)
pluck:(NSArray *)args {
  return self;
}

-(instancetype)
point:(NSArray *)args {
  return self;
}

-(instancetype)
polygon:(NSArray *)args {
  return self;
}

-(instancetype)
polygon_sub:(NSArray *)args {
  return self;
}

-(instancetype)
prepend:(NSArray *)args {
  return self;
}

-(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
range:(NSArray *)args {
  return self;
}

-(instancetype)
rebalance:(NSArray *)args {
  return self;
}

-(instancetype)
reconfigure:(NSArray *)args {
  return self;
}

-(instancetype)
reduce:(NSArray *)args {
  return self;
}

-(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
round:(NSArray *)args {
  return self;
}

-(instancetype)
sample:(NSArray *)args {
  return self;
}

-(instancetype)
saturday:(NSArray *)args {
  return self;
}

-(instancetype)
seconds:(NSArray *)args {
  return self;
}

-(instancetype)
september:(NSArray *)args {
  return self;
}

-(instancetype)
set_difference:(NSArray *)args {
  return self;
}

-(instancetype)
set_insert:(NSArray *)args {
  return self;
}

-(instancetype)
set_intersection:(NSArray *)args {
  return self;
}

-(instancetype)
set_union:(NSArray *)args {
  return self;
}

-(instancetype)
skip:(NSArray *)args {
  return self;
}

-(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
splice_at:(NSArray *)args {
  return self;
}

-(instancetype)
split:(NSArray *)args {
  return self;
}

-(instancetype)
status:(NSArray *)args {
  return self;
}

-(instancetype)
sub:(NSArray *)args {
  return self;
}

-(instancetype)
sum:(NSArray *)args {
  return self;
}

-(instancetype)
sunday:(NSArray *)args {
  return self;
}

-(instancetype)
sync:(NSArray *)args {
  return self;
}

-(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
table_drop:(NSArray *)args {
  return self;
}

-(instancetype)
table_list:(NSArray *)args {
  return self;
}

-(instancetype)
thursday:(NSArray *)args {
  return self;
}

-(instancetype)
time:(NSArray *)args {
  return self;
}

-(instancetype)
timezone:(NSArray *)args {
  return self;
}

-(instancetype)
time_of_day:(NSArray *)args {
  return self;
}

-(instancetype)
to_epoch_time:(NSArray *)args {
  return self;
}

-(instancetype)
to_geojson:(NSArray *)args {
  return self;
}

-(instancetype)
to_iso8601:(NSArray *)args {
  return self;
}

-(instancetype)
to_json_string:(NSArray *)args {
  return self;
}

-(instancetype)
tuesday:(NSArray *)args {
  return self;
}

-(instancetype)
type_of:(NSArray *)args {
  return self;
}

-(instancetype)
ungroup:(NSArray *)args {
  return self;
}

-(instancetype)
union:(NSArray *)args {
  return self;
}

-(instancetype)
upcase:(NSArray *)args {
  return self;
}

-(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs {
  return self;
}

-(instancetype)
uuid:(NSArray *)args {
  return self;
}

-(instancetype)
var:(NSArray *)args {
  return self;
}

-(instancetype)
wait:(NSArray *)args {
  return self;
}

-(instancetype)
wednesday:(NSArray *)args {
  return self;
}

-(instancetype)
without:(NSArray *)args {
  return self;
}

-(instancetype)
with_fields:(NSArray *)args {
  return self;
}

-(instancetype)
year:(NSArray *)args {
  return self;
}

-(instancetype)
zip:(NSArray *)args {
  return [self newTerm:REQL_ZIP :args];
}

@end
