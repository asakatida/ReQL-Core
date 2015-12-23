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

#import "./reql/array.hpp"
#import "./reql/null.hpp"
#import "./reql/object.hpp"
#import "./reql/query.hpp"
#import "./reql/string.hpp"
#import "./reql/term.hpp"

#import <map>
#import <string>
#import <vector>

@interface ReQLBool ()

@property BOOL value;

+(instancetype)boolean:(BOOL)boolean;

@end

@implementation ReQLBool

@synthesize value=p_value;

+(instancetype)boolean:(BOOL)boolean {
  ReQLBool *inst = [ReQLBool new];
  inst.value = boolean;
  return inst;
}

-(BOOL)boolValue {
  return self.value;
}

@end

@interface ReQLConnection ()

-(RACSequence *)run:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs;

-(void)noReply:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs;

@end

static std::wstring
to_string(const NSString *string) {
  auto data = [string dataUsingEncoding:NSUTF16StringEncoding];
  return std::wstring(reinterpret_cast<const wchar_t *>([data bytes]), [data length]);
}

static ReQLQuery *
toQuery(id expr);

static ReQLQuery *
toQuery(id expr) {
  if ([expr isKindOfClass:[ReQLQuery class]]) {
    return expr;
  } else if ([expr isKindOfClass:[NSArray class]]) {
    return [ReQLQuery newWithArray:expr];
  } else if ([expr isKindOfClass:[NSNull class]]) {
    return [ReQLQuery new];
  } else if ([expr isKindOfClass:[NSNumber class]]) {
    return [ReQLQuery newWithNumber:expr];
  } else if ([expr isKindOfClass:[NSString class]]) {
    return [ReQLQuery newWithString:expr];
  } else if ([expr isKindOfClass:[NSDictionary class]]) {
    return [ReQLQuery newWithObject:expr];
  }
  return nil;
}

@interface ReQLQuery ()

@property NSArray *array;
@property NSNull *null;
@property NSNumber *number;
@property NSString *string;
@property NSDictionary *object;
@property NSDictionary *kwargs;
@property NSArray *args;
@property _ReQL::Term_t tt;
@property BOOL flag;

@end

@implementation ReQLQuery

@synthesize array=p_array;
@synthesize null=p_null;
@synthesize number=p_number;
@synthesize string=p_string;
@synthesize object=p_object;
@synthesize kwargs=p_kwargs;
@synthesize args=p_args;
@synthesize tt=p_tt;
@synthesize flag=p_flag;

+(instancetype)newWithArray:(NSArray *)val {
  ReQLQuery *inst = [self new];
  inst.array = [val copy];
  return inst;
}

+(instancetype)newWithBool:(BOOL)val {
  ReQLQuery *inst = [self new];
  inst.flag = YES;
  inst.number = [NSNumber numberWithBool:val];
  return inst;
}

+(instancetype)newWithNumber:(NSNumber *)val {
  ReQLQuery *inst = [self new];
  inst.number = [val copy];
  return inst;
}

+(instancetype)newWithObject:(NSDictionary *)val {
  ReQLQuery *inst = [self new];
  inst.object = [val copy];
  return inst;
}

+(instancetype)newWithString:(NSString *)val {
  ReQLQuery *inst = [self new];
  inst.string = [val copy];
  return inst;
}

+(instancetype)newTerm:(_ReQL::Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs {
  ReQLQuery *inst = [self new];
  inst.tt = tt;
  inst.args = [args copy];
  inst.kwargs = [kwargs copy];
  return inst;
}

+(instancetype)newTerm:(_ReQL::Term_t)tt :(NSArray *)args {
  ReQLQuery *inst = [self new];
  inst.tt = tt;
  inst.args = [args copy];
  return inst;
}

+(instancetype)newTerm:(_ReQL::Term_t)tt {
  ReQLQuery *inst = [self new];
  inst.tt = tt;
  return inst;
}

-(instancetype)newTerm:(_ReQL::Term_t)tt :(NSArray *)args :(NSDictionary *)kwargs {
  return [ReQLQuery newTerm:tt :[@[self] arrayByAddingObjectsFromArray:args] :kwargs];
}

-(instancetype)newTerm:(_ReQL::Term_t)tt :(NSArray *)args {
  return [ReQLQuery newTerm:tt :[@[self] arrayByAddingObjectsFromArray:args]];
}

-(instancetype)newTerm:(_ReQL::Term_t)tt {
  return [ReQLQuery newTerm:tt :@[self]];
}

-(RACSequence *)run:(nonnull ReQLConnection *)conn {
  return [self run:conn withOpts:@{}];
}

-(RACSequence *)run:(nonnull ReQLConnection *)conn withOpts:(nonnull NSDictionary *)opts {
  return [conn run:self kwargs:opts];
}

-(void)noReply:(ReQLConnection *)conn {
  return [self noReply:conn withOpts:@{}];
}

-(void)noReply:(nonnull ReQLConnection *)conn withOpts:(nonnull NSDictionary *)opts {
  NSMutableDictionary *temp = [NSMutableDictionary dictionaryWithDictionary:opts];
  temp[@"no_reply"] = [ReQLQuery newWithBool:YES];
  return [conn noReply:self kwargs:[NSDictionary dictionaryWithDictionary:temp]];
}

-(std::string)build {
  if (self.array) {
    std::vector<std::string> array;
    for (id elem in self.array) {
      array.push_back([toQuery(elem) build]);
    }
    return _ReQL::expr(_ReQL::make_array(array));
  } else if (self.null) {
    return _ReQL::expr(_ReQL::Null_t());
  } else if (self.number) {
    if (self.flag) {
      return _ReQL::expr([self.number boolValue] ? true : false);
    }
    return _ReQL::expr([self.number doubleValue]);
  } else if (self.string) {
    return _ReQL::expr(_ReQL::make_string(to_string(self.string)));
  } else if (self.object) {
    std::map<std::wstring, std::string> object;
    for (NSString *key in self.object) {
      object.insert({to_string(key), [toQuery(self.object[key]) build]});
    }
    return _ReQL::expr(_ReQL::make_object(object));
  } else if (self.kwargs) {
    std::vector<std::string> array;
    for (id elem in self.args) {
      array.push_back([toQuery(elem) build]);
    }
    std::map<std::wstring, std::string> object;
    for (NSString *key in self.kwargs) {
      object.insert({to_string(key), [toQuery(self.object[key]) build]});
    }
    return _ReQL::expr(make_reql(self.tt, array, object));
  } else if (self.args) {
    std::vector<std::string> array;
    for (id elem in self.args) {
      array.push_back([toQuery(elem) build]);
    }
    return _ReQL::expr(make_reql(self.tt, array));
  }
  return _ReQL::expr(_ReQL::make_array(std::make_tuple(self.tt)));
}

+(instancetype)
add:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ADD :args];
}

-(instancetype)
add:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ADD :args];
}

+(instancetype)
and:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AND :args];
}

-(instancetype)
and:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AND :args];
}

+(instancetype)
append:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_APPEND :args];
}

-(instancetype)
append:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_APPEND :args];
}

+(instancetype)
april:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_APRIL :args];
}

-(instancetype)
april:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_APRIL :args];
}

+(instancetype)
args:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ARGS :args];
}

-(instancetype)
args:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ARGS :args];
}

+(instancetype)
asc:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ASC :args];
}

-(instancetype)
asc:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ASC :args];
}

+(instancetype)
august:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AUGUST :args];
}

-(instancetype)
august:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AUGUST :args];
}

+(instancetype)
avg:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AVG :args];
}

-(instancetype)
avg:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_AVG :args];
}

+(instancetype)
between:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BETWEEN :args];
}

-(instancetype)
between:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BETWEEN :args];
}

+(instancetype)
between_deprecated:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BETWEEN_DEPRECATED :args];
}

-(instancetype)
between_deprecated:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BETWEEN_DEPRECATED :args];
}

+(instancetype)
binary:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BINARY :args];
}

-(instancetype)
binary:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BINARY :args];
}

+(instancetype)
bracket:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BRACKET :args];
}

-(instancetype)
bracket:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BRACKET :args];
}

+(instancetype)
branch:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BRANCH :args];
}

-(instancetype)
branch:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_BRANCH :args];
}

+(instancetype)
ceil:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CEIL :args];
}

-(instancetype)
ceil:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CEIL :args];
}

+(instancetype)
changes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CHANGES :args];
}

-(instancetype)
changes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CHANGES :args];
}

+(instancetype)
change_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CHANGE_AT :args];
}

-(instancetype)
change_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CHANGE_AT :args];
}

+(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_CIRCLE :args :kwargs];
}

-(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_CIRCLE :args :kwargs];
}

+(instancetype)
coerce_to:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_COERCE_TO :args];
}

-(instancetype)
coerce_to:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_COERCE_TO :args];
}

+(instancetype)
concat_map:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONCAT_MAP :args];
}

-(instancetype)
concat_map:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONCAT_MAP :args];
}

+(instancetype)
config:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONFIG :args];
}

-(instancetype)
config:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONFIG :args];
}

+(instancetype)
contains:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONTAINS :args];
}

-(instancetype)
contains:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_CONTAINS :args];
}

+(instancetype)
count:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_COUNT :args];
}

-(instancetype)
count:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_COUNT :args];
}

+(instancetype)
date:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DATE :args];
}

-(instancetype)
date:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DATE :args];
}

+(instancetype)
datum:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DATUM :args];
}

-(instancetype)
datum:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DATUM :args];
}

+(instancetype)
day:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY :args];
}

-(instancetype)
day:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY :args];
}

+(instancetype)
day_of_week:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY_OF_WEEK :args];
}

-(instancetype)
day_of_week:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY_OF_WEEK :args];
}

+(instancetype)
day_of_year:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY_OF_YEAR :args];
}

-(instancetype)
day_of_year:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DAY_OF_YEAR :args];
}

+(instancetype)
db:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB :args];
}

-(instancetype)
db:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB :args];
}

+(instancetype)
db_create:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_CREATE :args];
}

-(instancetype)
db_create:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_CREATE :args];
}

+(instancetype)
db_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_DROP :args];
}

-(instancetype)
db_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_DROP :args];
}

+(instancetype)
db_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_LIST :args];
}

-(instancetype)
db_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DB_LIST :args];
}

+(instancetype)
december:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DECEMBER :args];
}

-(instancetype)
december:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DECEMBER :args];
}

+(instancetype)
default:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DEFAULT :args];
}

-(instancetype)
default:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DEFAULT :args];
}

+(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_DELETE :args :kwargs];
}

-(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_DELETE :args :kwargs];
}

+(instancetype)
delete_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DELETE_AT :args];
}

-(instancetype)
delete_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DELETE_AT :args];
}

+(instancetype)
desc:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DESC :args];
}

-(instancetype)
desc:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DESC :args];
}

+(instancetype)
difference:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DIFFERENCE :args];
}

-(instancetype)
difference:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DIFFERENCE :args];
}

+(instancetype)
distance:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DISTANCE :args];
}

-(instancetype)
distance:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DISTANCE :args];
}

+(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_DISTINCT :args :kwargs];
}

-(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_DISTINCT :args :kwargs];
}

+(instancetype)
div:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DIV :args];
}

-(instancetype)
div:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DIV :args];
}

+(instancetype)
downcase:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DOWNCASE :args];
}

-(instancetype)
downcase:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DOWNCASE :args];
}

+(instancetype)
during:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DURING :args];
}

-(instancetype)
during:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_DURING :args];
}

+(instancetype)
epoch_time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_EPOCH_TIME :args];
}

-(instancetype)
epoch_time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_EPOCH_TIME :args];
}

+(instancetype)
eq:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_EQ :args];
}

-(instancetype)
eq:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_EQ :args];
}

+(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_EQ_JOIN :args :kwargs];
}

-(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_EQ_JOIN :args :kwargs];
}

+(instancetype)
error:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ERROR :args];
}

-(instancetype)
error:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ERROR :args];
}

+(instancetype)
february:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FEBRUARY :args];
}

-(instancetype)
february:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FEBRUARY :args];
}

+(instancetype)
fill:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FILL :args];
}

-(instancetype)
fill:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FILL :args];
}

+(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_FILTER :args :kwargs];
}

-(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_FILTER :args :kwargs];
}

+(instancetype)
floor:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FLOOR :args];
}

-(instancetype)
floor:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FLOOR :args];
}

+(instancetype)
for_each:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FOR_EACH :args];
}

-(instancetype)
for_each:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FOR_EACH :args];
}

+(instancetype)
friday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FRIDAY :args];
}

-(instancetype)
friday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FRIDAY :args];
}

+(instancetype)
func:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FUNC :args];
}

-(instancetype)
func:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FUNC :args];
}

+(instancetype)
funcall:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FUNCALL :args];
}

-(instancetype)
funcall:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_FUNCALL :args];
}

+(instancetype)
ge:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GE :args];
}

-(instancetype)
ge:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GE :args];
}

+(instancetype)
geojson:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GEOJSON :args];
}

-(instancetype)
geojson:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GEOJSON :args];
}

+(instancetype)
get:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GET :args];
}

-(instancetype)
get:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GET :args];
}

+(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_ALL :args :kwargs];
}

-(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_ALL :args :kwargs];
}

+(instancetype)
get_field:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GET_FIELD :args];
}

-(instancetype)
get_field:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GET_FIELD :args];
}

+(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_INTERSECTING :args :kwargs];
}

-(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_INTERSECTING :args :kwargs];
}

+(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_NEAREST :args :kwargs];
}

-(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GET_NEAREST :args :kwargs];
}

+(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GROUP :args :kwargs];
}

-(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_GROUP :args :kwargs];
}

+(instancetype)
gt:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GT :args];
}

-(instancetype)
gt:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_GT :args];
}

+(instancetype)
has_fields:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_HAS_FIELDS :args];
}

-(instancetype)
has_fields:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_HAS_FIELDS :args];
}

+(instancetype)
hours:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_HOURS :args];
}

-(instancetype)
hours:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_HOURS :args];
}

+(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_HTTP :args :kwargs];
}

-(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_HTTP :args :kwargs];
}

+(instancetype)
implicit_var:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IMPLICIT_VAR :args];
}

-(instancetype)
implicit_var:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IMPLICIT_VAR :args];
}

+(instancetype)
includes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INCLUDES :args];
}

-(instancetype)
includes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INCLUDES :args];
}

+(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_INDEX_CREATE :args :kwargs];
}

-(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_INDEX_CREATE :args :kwargs];
}

+(instancetype)
index_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_DROP :args];
}

-(instancetype)
index_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_DROP :args];
}

+(instancetype)
index_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_LIST :args];
}

-(instancetype)
index_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_LIST :args];
}

+(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_INDEX_RENAME :args :kwargs];
}

-(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_INDEX_RENAME :args :kwargs];
}

+(instancetype)
index_status:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_STATUS :args];
}

-(instancetype)
index_status:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_STATUS :args];
}

+(instancetype)
index_wait:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_WAIT :args];
}

-(instancetype)
index_wait:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INDEX_WAIT :args];
}

+(instancetype)
info:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INFO :args];
}

-(instancetype)
info:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INFO :args];
}

+(instancetype)
inner_join:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INNER_JOIN :args];
}

-(instancetype)
inner_join:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INNER_JOIN :args];
}

+(instancetype)
insert:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INSERT :args];
}

-(instancetype)
insert:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INSERT :args];
}

+(instancetype)
insert_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INSERT_AT :args];
}

-(instancetype)
insert_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INSERT_AT :args];
}

+(instancetype)
intersects:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INTERSECTS :args];
}

-(instancetype)
intersects:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_INTERSECTS :args];
}

+(instancetype)
in_timezone:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IN_TIMEZONE :args];
}

-(instancetype)
in_timezone:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IN_TIMEZONE :args];
}

+(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_ISO8601 :args :kwargs];
}

-(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_ISO8601 :args :kwargs];
}

+(instancetype)
is_empty:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IS_EMPTY :args];
}

-(instancetype)
is_empty:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_IS_EMPTY :args];
}

+(instancetype)
january:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JANUARY :args];
}

-(instancetype)
january:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JANUARY :args];
}

+(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_JAVASCRIPT :args :kwargs];
}

-(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_JAVASCRIPT :args :kwargs];
}

+(instancetype)
json:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JSON :args];
}

-(instancetype)
json:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JSON :args];
}

+(instancetype)
july:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JULY :args];
}

-(instancetype)
july:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JULY :args];
}

+(instancetype)
june:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JUNE :args];
}

-(instancetype)
june:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_JUNE :args];
}

+(instancetype)
keys:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_KEYS :args];
}

-(instancetype)
keys:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_KEYS :args];
}

+(instancetype)
le:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LE :args];
}

-(instancetype)
le:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LE :args];
}

+(instancetype)
limit:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LIMIT :args];
}

-(instancetype)
limit:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LIMIT :args];
}

+(instancetype)
line:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LINE :args];
}

-(instancetype)
line:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LINE :args];
}

+(instancetype)
literal:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LITERAL :args];
}

-(instancetype)
literal:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LITERAL :args];
}

+(instancetype)
lt:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LT :args];
}

-(instancetype)
lt:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_LT :args];
}

+(instancetype)
make_array:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAKE_ARRAY :args];
}

-(instancetype)
make_array:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAKE_ARRAY :args];
}

+(instancetype)
make_obj:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAKE_OBJ :args];
}

-(instancetype)
make_obj:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAKE_OBJ :args];
}

+(instancetype)
map:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAP :args];
}

-(instancetype)
map:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAP :args];
}

+(instancetype)
march:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MARCH :args];
}

-(instancetype)
march:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MARCH :args];
}

+(instancetype)
match:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MATCH :args];
}

-(instancetype)
match:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MATCH :args];
}

+(instancetype)
max:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAX :args];
}

-(instancetype)
max:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAX :args];
}

+(instancetype)
maxval:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAXVAL :args];
}

-(instancetype)
maxval:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAXVAL :args];
}

+(instancetype)
may:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAY :args];
}

-(instancetype)
may:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MAY :args];
}

+(instancetype)
merge:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MERGE :args];
}

-(instancetype)
merge:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MERGE :args];
}

+(instancetype)
min:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MIN :args];
}

-(instancetype)
min:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MIN :args];
}

+(instancetype)
minutes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MINUTES :args];
}

-(instancetype)
minutes:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MINUTES :args];
}

+(instancetype)
minval:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MINVAL :args];
}

-(instancetype)
minval:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MINVAL :args];
}

+(instancetype)
mod:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MOD :args];
}

-(instancetype)
mod:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MOD :args];
}

+(instancetype)
monday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MONDAY :args];
}

-(instancetype)
monday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MONDAY :args];
}

+(instancetype)
month:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MONTH :args];
}

-(instancetype)
month:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MONTH :args];
}

+(instancetype)
mul:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MUL :args];
}

-(instancetype)
mul:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_MUL :args];
}

+(instancetype)
ne:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NE :args];
}

-(instancetype)
ne:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NE :args];
}

+(instancetype)
not:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOT :args];
}

-(instancetype)
not:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOT :args];
}

+(instancetype)
november:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOVEMBER :args];
}

-(instancetype)
november:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOVEMBER :args];
}

+(instancetype)
now:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOW :args];
}

-(instancetype)
now:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NOW :args];
}

+(instancetype)
nth:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NTH :args];
}

-(instancetype)
nth:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_NTH :args];
}

+(instancetype)
object:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OBJECT :args];
}

-(instancetype)
object:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OBJECT :args];
}

+(instancetype)
october:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OCTOBER :args];
}

-(instancetype)
october:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OCTOBER :args];
}

+(instancetype)
offsets_of:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OFFSETS_OF :args];
}

-(instancetype)
offsets_of:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OFFSETS_OF :args];
}

+(instancetype)
or:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OR :args];
}

-(instancetype)
or:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OR :args];
}

+(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_ORDER_BY :args :kwargs];
}

-(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_ORDER_BY :args :kwargs];
}

+(instancetype)
outer_join:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OUTER_JOIN :args];
}

-(instancetype)
outer_join:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_OUTER_JOIN :args];
}

+(instancetype)
pluck:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_PLUCK :args];
}

-(instancetype)
pluck:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_PLUCK :args];
}

+(instancetype)
point:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POINT :args];
}

-(instancetype)
point:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POINT :args];
}

+(instancetype)
polygon:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POLYGON :args];
}

-(instancetype)
polygon:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POLYGON :args];
}

+(instancetype)
polygon_sub:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POLYGON_SUB :args];
}

-(instancetype)
polygon_sub:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_POLYGON_SUB :args];
}

+(instancetype)
prepend:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_PREPEND :args];
}

-(instancetype)
prepend:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_PREPEND :args];
}

+(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_RANDOM :args :kwargs];
}

-(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_RANDOM :args :kwargs];
}

+(instancetype)
range:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_RANGE :args];
}

-(instancetype)
range:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_RANGE :args];
}

+(instancetype)
rebalance:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_REBALANCE :args];
}

-(instancetype)
rebalance:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_REBALANCE :args];
}

+(instancetype)
reconfigure:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_RECONFIGURE :args];
}

-(instancetype)
reconfigure:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_RECONFIGURE :args];
}

+(instancetype)
reduce:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_REDUCE :args];
}

-(instancetype)
reduce:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_REDUCE :args];
}

+(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_REPLACE :args :kwargs];
}

-(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_REPLACE :args :kwargs];
}

+(instancetype)
round:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ROUND :args];
}

-(instancetype)
round:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ROUND :args];
}

+(instancetype)
sample:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SAMPLE :args];
}

-(instancetype)
sample:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SAMPLE :args];
}

+(instancetype)
saturday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SATURDAY :args];
}

-(instancetype)
saturday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SATURDAY :args];
}

+(instancetype)
seconds:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SECONDS :args];
}

-(instancetype)
seconds:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SECONDS :args];
}

+(instancetype)
september:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SEPTEMBER :args];
}

-(instancetype)
september:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SEPTEMBER :args];
}

+(instancetype)
set_difference:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_DIFFERENCE :args];
}

-(instancetype)
set_difference:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_DIFFERENCE :args];
}

+(instancetype)
set_insert:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_INSERT :args];
}

-(instancetype)
set_insert:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_INSERT :args];
}

+(instancetype)
set_intersection:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_INTERSECTION :args];
}

-(instancetype)
set_intersection:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_INTERSECTION :args];
}

+(instancetype)
set_union:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_UNION :args];
}

-(instancetype)
set_union:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SET_UNION :args];
}

+(instancetype)
skip:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SKIP :args];
}

-(instancetype)
skip:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SKIP :args];
}

+(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_SLICE :args :kwargs];
}

-(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_SLICE :args :kwargs];
}

+(instancetype)
splice_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SPLICE_AT :args];
}

-(instancetype)
splice_at:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SPLICE_AT :args];
}

+(instancetype)
split:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SPLIT :args];
}

-(instancetype)
split:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SPLIT :args];
}

+(instancetype)
status:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_STATUS :args];
}

-(instancetype)
status:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_STATUS :args];
}

+(instancetype)
sub:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUB :args];
}

-(instancetype)
sub:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUB :args];
}

+(instancetype)
sum:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUM :args];
}

-(instancetype)
sum:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUM :args];
}

+(instancetype)
sunday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUNDAY :args];
}

-(instancetype)
sunday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SUNDAY :args];
}

+(instancetype)
sync:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SYNC :args];
}

-(instancetype)
sync:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_SYNC :args];
}

+(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_TABLE :args :kwargs];
}

-(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_TABLE :args :kwargs];
}

+(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_TABLE_CREATE :args :kwargs];
}

-(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_TABLE_CREATE :args :kwargs];
}

+(instancetype)
table_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TABLE_DROP :args];
}

-(instancetype)
table_drop:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TABLE_DROP :args];
}

+(instancetype)
table_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TABLE_LIST :args];
}

-(instancetype)
table_list:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TABLE_LIST :args];
}

+(instancetype)
thursday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_THURSDAY :args];
}

-(instancetype)
thursday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_THURSDAY :args];
}

+(instancetype)
time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIME :args];
}

-(instancetype)
time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIME :args];
}

+(instancetype)
timezone:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIMEZONE :args];
}

-(instancetype)
timezone:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIMEZONE :args];
}

+(instancetype)
time_of_day:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIME_OF_DAY :args];
}

-(instancetype)
time_of_day:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TIME_OF_DAY :args];
}

+(instancetype)
to_epoch_time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_EPOCH_TIME :args];
}

-(instancetype)
to_epoch_time:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_EPOCH_TIME :args];
}

+(instancetype)
to_geojson:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_GEOJSON :args];
}

-(instancetype)
to_geojson:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_GEOJSON :args];
}

+(instancetype)
to_iso8601:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_ISO8601 :args];
}

-(instancetype)
to_iso8601:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_ISO8601 :args];
}

+(instancetype)
to_json_string:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_JSON_STRING :args];
}

-(instancetype)
to_json_string:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TO_JSON_STRING :args];
}

+(instancetype)
tuesday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TUESDAY :args];
}

-(instancetype)
tuesday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TUESDAY :args];
}

+(instancetype)
type_of:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TYPE_OF :args];
}

-(instancetype)
type_of:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_TYPE_OF :args];
}

+(instancetype)
ungroup:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UNGROUP :args];
}

-(instancetype)
ungroup:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UNGROUP :args];
}

+(instancetype)
union:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UNION :args];
}

-(instancetype)
union:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UNION :args];
}

+(instancetype)
upcase:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UPCASE :args];
}

-(instancetype)
upcase:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UPCASE :args];
}

+(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_UPDATE :args :kwargs];
}

-(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:_ReQL::REQL_UPDATE :args :kwargs];
}

+(instancetype)
uuid:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UUID :args];
}

-(instancetype)
uuid:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_UUID :args];
}

+(instancetype)
values:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_VALUES :args];
}

-(instancetype)
values:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_VALUES :args];
}

+(instancetype)
var:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_VAR :args];
}

-(instancetype)
var:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_VAR :args];
}

+(instancetype)
wait:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WAIT :args];
}

-(instancetype)
wait:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WAIT :args];
}

+(instancetype)
wednesday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WEDNESDAY :args];
}

-(instancetype)
wednesday:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WEDNESDAY :args];
}

+(instancetype)
without:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WITHOUT :args];
}

-(instancetype)
without:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WITHOUT :args];
}

+(instancetype)
with_fields:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WITH_FIELDS :args];
}

-(instancetype)
with_fields:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_WITH_FIELDS :args];
}

+(instancetype)
year:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_YEAR :args];
}

-(instancetype)
year:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_YEAR :args];
}

+(instancetype)
zip:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ZIP :args];
}

-(instancetype)
zip:(NSArray *)args {
  return [self newTerm:_ReQL::REQL_ZIP :args];
}

@end
