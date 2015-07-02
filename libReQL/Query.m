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

@interface ReQLObject : NSObject

@property(nonatomic) ReQL_Obj_t *pointer;

+(instancetype)newArray:(ReQL_Size)size;

+(instancetype)newObject:(ReQL_Size)size;

+(instancetype)newString:(const ReQL_Byte *)str withSize:(ReQL_Size)size;

-(ReQL_Obj_t *)steal;

@end

@implementation ReQLObject

@synthesize pointer=pointer;

-(instancetype)initArray:(ReQL_Size)size {
  if (self = [super init]) {
    ReQL_Obj_t **array = malloc(sizeof(ReQL_Obj_t*) * size);
    if (array == NULL) {
      pointer = NULL;
      return nil;
    }
    pointer = malloc(sizeof(ReQL_Obj_t));
    if (pointer == NULL) {
      free(array); array = NULL;
      return nil;
    }
    reql_array_init(pointer, array, size);
  }
  return self;
}

+(instancetype)newArray:(ReQL_Size)size {
  return [[self alloc] initArray:size];
}

-(instancetype)initObject:(ReQL_Size)size {
  if (self = [super init]) {
    ReQL_Pair_t *pairs = malloc(sizeof(ReQL_Pair_t) * size);
    if (pairs == NULL) {
      pointer = NULL;
      return nil;
    }
    pointer = malloc(sizeof(ReQL_Obj_t));
    if (pointer == NULL) {
      free(pairs); pairs = NULL;
      return nil;
    }
    reql_object_init(pointer, pairs, size);
  }
  return self;
}

+(instancetype)newObject:(ReQL_Size)size {
  return [[self alloc] initObject:size];
}

-(instancetype)initString:(const ReQL_Byte *)str withSize:(ReQL_Size)size {
  if (self = [super init]) {
    ReQL_Byte *buf = malloc(sizeof(ReQL_Byte) * size);
    if (buf == NULL) {
      pointer = NULL;
      return nil;
    }
    pointer = malloc(sizeof(ReQL_Obj_t));
    if (pointer == NULL) {
      free(buf); buf = NULL;
      return nil;
    }
    reql_string_init(pointer, buf, str, size);
  }
  return self;
}

+(instancetype)newString:(const ReQL_Byte *)str withSize:(ReQL_Size)size {
  return [[self alloc] initString:str withSize:size];
}

-(instancetype)init {
  if (self = [super init]) {
    pointer = malloc(sizeof(ReQL_Obj_t));
    if (pointer == NULL) {
      return nil;
    }
  }
  return self;
}

-(ReQL_Obj_t *)steal {
  ReQL_Obj_t *obj = pointer;
  pointer = NULL;
  return obj;
}

-(void)dealloc {
  reql_json_destroy(pointer);
}

@end

@interface ReQLQuery ()

-(ReQLObject *)build;

@end

@protocol Expr <NSObject>

-(ReQLObject *)build;

@end

@interface ArrayExpr : NSObject <Expr> {
  NSArray *p_data;
}

+(instancetype)newTermFromArray:(NSArray *)val;

@end

@interface BoolExpr : NSObject <Expr> {
  BOOL p_data;
}

+(instancetype)newTermFromBool:(BOOL)val;

@end

@interface NullExpr : NSObject <Expr>

@end

@interface NumberExpr : NSObject <Expr> {
  NSNumber *p_data;
}

+(instancetype)newTermFromNumber:(NSNumber *)val;

@end

@interface DictionaryExpr : NSObject <Expr> {
  NSDictionary *p_data;
}

+(instancetype)newTermFromDictionary:(NSDictionary *)val;

@end

@interface StringExpr : NSObject <Expr> {
  NSString *p_data;
}

+(instancetype)newTermFromString:(NSString *)val;

@end

@interface TermExpr : NSObject <Expr> {
  NSArray *p_args;
  ReQL_AST_Function p_func;
}

+(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args;

@end

@interface TermKwargsExpr : NSObject <Expr> {
  NSArray *p_args;
  NSDictionary *p_kwargs;
  ReQL_AST_Function_Kwargs p_func;
}

+(instancetype)newTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs;

@end

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

@implementation ArrayExpr

+(instancetype)newTermFromArray:(NSArray *)val {
  return [[self alloc] initTermWithArray:val];
}

-(instancetype)initTermWithArray:(NSArray *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject newArray:(ReQL_Size)[p_data count]];
  if (obj == nil) {
    return nil;
  }
  for (id elem in p_data) {
    ReQLObject *r_elem = [toQuery(elem) build];
    if (!r_elem) {
      return nil;
    }
    reql_array_append(obj.pointer, [r_elem steal]);
  }
  return obj;
}


@end

@implementation BoolExpr

+(instancetype)newTermFromBool:(BOOL)val {
  return [[self alloc] initTermWithBool:val];
}

-(instancetype)initTermWithBool:(BOOL)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject new];
  if (obj == nil) {
    return nil;
  }
  reql_bool_init(obj.pointer, p_data ? 1 : 0);
  return obj;
}

@end

@implementation NullExpr

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject new];
  if (obj == nil) {
    return nil;
  }
  reql_null_init(obj.pointer);
  return obj;
}

@end

@implementation NumberExpr

+(instancetype)newTermFromNumber:(NSNumber *)val {
  return [[self alloc] initTermWithNumber:val];
}

-(instancetype)initTermWithNumber:(NSNumber *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject new];
  if (obj == nil) {
    return nil;
  }
  reql_number_init(obj.pointer, [p_data doubleValue]);
  return obj;
}


@end

@implementation DictionaryExpr

+(instancetype)newTermFromDictionary:(NSDictionary *)val {
  return [[self alloc] initTermWithDictionary:val];
}

-(instancetype)initTermWithDictionary:(NSDictionary *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject newObject:(ReQL_Size)[p_data count]];
  if (obj == nil) {
    return nil;
  }
  for (id key in p_data) {
    @autoreleasepool {
      id val = [p_data objectForKey:key];
      ReQLObject *r_key = [toQuery(key) build];
      ReQLObject *r_val = [toQuery(val) build];
      if (!(r_key && r_val)) {
        return nil;
      }
      reql_object_add(obj.pointer, [r_key steal], [r_val steal]);
    }
  }
  return obj;
}


@end

@implementation StringExpr

+(instancetype)newTermFromString:(NSString *)val {
  return [[self alloc] initTermWithString:val];
}

-(instancetype)initTermWithString:(NSString *)val {
  if (self = [super init]) {
    p_data = val;
  }
  return self;
}

-(ReQLObject *)build {
  return [ReQLObject
          newString:(const ReQL_Byte *)[p_data cStringUsingEncoding:NSUTF8StringEncoding]
          withSize:(ReQL_Size)[p_data lengthOfBytesUsingEncoding:NSUTF8StringEncoding]];
}


@end

@implementation TermExpr

+(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args {
  return [[self alloc] initTerm:func :args];
}

-(instancetype)initTerm:(ReQL_AST_Function)func :(NSArray *)args {
  if (self = [super init]) {
    p_args = args;
    p_func = func;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject new];
  if (obj == nil) {
    return nil;
  }
  ReQLObject *r_args = [toQuery(p_args) build];
  if (!r_args) {
    return nil;
  }
  p_func(obj.pointer, [r_args steal]);
  return obj;
}


@end

@implementation TermKwargsExpr

+(instancetype)newTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  return [[self alloc] initTerm:func :args :kwargs];
}

-(instancetype)initTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  if (self = [super init]) {
    p_args = args;
    p_kwargs = kwargs;
    p_func = func;
  }
  return self;
}

-(ReQLObject *)build {
  ReQLObject *obj = [ReQLObject new];
  if (obj == nil) {
    return nil;
  }
  ReQLObject *r_args = [toQuery(p_args) build];
  if (!r_args) {
    return nil;
  }
  ReQLObject *r_kwargs = nil;
  if (p_kwargs) {
    r_kwargs = [toQuery(p_kwargs) build];
    if (!r_kwargs) {
      return nil;
    }
  }
  p_func(obj.pointer, [r_args steal], [r_kwargs steal]);
  return obj;
}


@end

@implementation ReQLQuery {
  NSObject <Expr> *p_build;
}

+(instancetype)newWithArray:(NSArray *)val {
  return [[self alloc] initTermWithArray:val];
}

+(instancetype)newWithBool:(BOOL)val {
  return [[self alloc] initTermWithBool:val];
}

+(instancetype)newWithNumber:(NSNumber *)val {
  return [[self alloc] initTermWithNumber:val];
}

+(instancetype)newWithObject:(NSDictionary *)val {
  return [[self alloc] initTermWithObject:val];
}

+(instancetype)newWithString:(NSString *)val {
  return [[self alloc] initTermWithString:val];
}

+(instancetype)newTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  return [[ReQLQuery alloc] init:func :args :kwargs];
}

+(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args {
  return [[ReQLQuery alloc] init:func :args];
}

-(instancetype)init {
  if (self = [super init]) {
    p_build = [NullExpr new];
  }
  return self;
}

-(instancetype)initTermWithArray:(NSArray *)val {
  if (self = [super init]) {
    p_build = [ArrayExpr newTermFromArray:val];
  }
  return self;
}

-(instancetype)initTermWithBool:(BOOL)val {
  if (self = [super init]) {
    p_build = [BoolExpr newTermFromBool:val];
  }
  return self;
}

-(instancetype)initTermWithNumber:(NSNumber *)val {
  if (self = [super init]) {
    p_build = [NumberExpr newTermFromNumber:val];
  }
  return self;
}

-(instancetype)initTermWithObject:(NSDictionary *)val {
  if (self = [super init]) {
    p_build = [DictionaryExpr newTermFromDictionary:val];
  }
  return self;
}

-(instancetype)initTermWithString:(NSString *)val {
  if (self = [super init]) {
    p_build = [StringExpr newTermFromString:val];
  }
  return self;
}

-(instancetype)init:(ReQL_AST_Function)func :(NSArray *)args {
  if (self = [super init]) {
    p_build = [TermExpr newTerm:func :args];
  }
  return self;
}

-(instancetype)init:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  if (self = [super init]) {
    p_build = [TermKwargsExpr newTerm:func :args :kwargs];
  }
  return self;
}

-(instancetype)newTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  return [[ReQLQuery alloc] init:func :[@[self] arrayByAddingObjectsFromArray:args] :kwargs];
}

-(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args {
  return [[ReQLQuery alloc] init:func :[@[self] arrayByAddingObjectsFromArray:args]];
}

-(ReQLCursor *)run:(ReQLConnection *)conn {
  return [self run:conn withOpts:nil];
}

-(ReQLCursor *)run:(ReQLConnection *)conn withOpts:(NSDictionary *)opts {
  ReQLCursor *cur = [ReQLCursor new];
  if (cur == nil) {
    return nil;
  }
  ReQLObject *query = [self build];
  if (query == NULL) {
    return nil;
  }
  ReQLObject *kwargs = NULL;
  if (opts) {
    kwargs = [[ReQLQuery newWithObject:opts] build];
    if (!kwargs) {
      return nil;
    }
  }
  reql_run([cur data], query.pointer, [conn data], kwargs.pointer);
  return cur;
}

-(void)noReply:(ReQLConnection *)conn {
  [self noReply:conn withOpts:nil];
}

-(void)noReply:(ReQLConnection *)conn withOpts:(NSDictionary *)opts {
  ReQLObject *query = [self build];
  if (query == NULL) {
    return;
  }
  ReQLObject *kwargs = NULL;
  if (opts) {
    kwargs = [[ReQLQuery newWithObject:opts] build];
    if (!kwargs) {
      return;
    }
  }
  reql_run(NULL, query.pointer, [conn data], kwargs.pointer);
}

-(ReQLObject *)build {
  return [p_build build];
}

+(instancetype)
add:(NSArray *)args {
  return [self newTerm:reql_ast_add :args];
}

-(instancetype)
add:(NSArray *)args {
  return [self newTerm:reql_ast_add :args];
}

+(instancetype)
and:(NSArray *)args {
  return [self newTerm:reql_ast_and :args];
}

-(instancetype)
and:(NSArray *)args {
  return [self newTerm:reql_ast_and :args];
}

+(instancetype)
append:(NSArray *)args {
  return [self newTerm:reql_ast_append :args];
}

-(instancetype)
append:(NSArray *)args {
  return [self newTerm:reql_ast_append :args];
}

+(instancetype)
april:(NSArray *)args {
  return [self newTerm:reql_ast_april :args];
}

-(instancetype)
april:(NSArray *)args {
  return [self newTerm:reql_ast_april :args];
}

+(instancetype)
args:(NSArray *)args {
  return [self newTerm:reql_ast_args :args];
}

-(instancetype)
args:(NSArray *)args {
  return [self newTerm:reql_ast_args :args];
}

+(instancetype)
asc:(NSArray *)args {
  return [self newTerm:reql_ast_asc :args];
}

-(instancetype)
asc:(NSArray *)args {
  return [self newTerm:reql_ast_asc :args];
}

+(instancetype)
august:(NSArray *)args {
  return [self newTerm:reql_ast_august :args];
}

-(instancetype)
august:(NSArray *)args {
  return [self newTerm:reql_ast_august :args];
}

+(instancetype)
avg:(NSArray *)args {
  return [self newTerm:reql_ast_avg :args];
}

-(instancetype)
avg:(NSArray *)args {
  return [self newTerm:reql_ast_avg :args];
}

+(instancetype)
between:(NSArray *)args {
  return [self newTerm:reql_ast_between :args];
}

-(instancetype)
between:(NSArray *)args {
  return [self newTerm:reql_ast_between :args];
}

+(instancetype)
between_deprecated:(NSArray *)args {
  return [self newTerm:reql_ast_between_deprecated :args];
}

-(instancetype)
between_deprecated:(NSArray *)args {
  return [self newTerm:reql_ast_between_deprecated :args];
}

+(instancetype)
binary:(NSArray *)args {
  return [self newTerm:reql_ast_binary :args];
}

-(instancetype)
binary:(NSArray *)args {
  return [self newTerm:reql_ast_binary :args];
}

+(instancetype)
bracket:(NSArray *)args {
  return [self newTerm:reql_ast_bracket :args];
}

-(instancetype)
bracket:(NSArray *)args {
  return [self newTerm:reql_ast_bracket :args];
}

+(instancetype)
branch:(NSArray *)args {
  return [self newTerm:reql_ast_branch :args];
}

-(instancetype)
branch:(NSArray *)args {
  return [self newTerm:reql_ast_branch :args];
}

+(instancetype)
ceil:(NSArray *)args {
  return [self newTerm:reql_ast_ceil :args];
}

-(instancetype)
ceil:(NSArray *)args {
  return [self newTerm:reql_ast_ceil :args];
}

+(instancetype)
changes:(NSArray *)args {
  return [self newTerm:reql_ast_changes :args];
}

-(instancetype)
changes:(NSArray *)args {
  return [self newTerm:reql_ast_changes :args];
}

+(instancetype)
change_at:(NSArray *)args {
  return [self newTerm:reql_ast_change_at :args];
}

-(instancetype)
change_at:(NSArray *)args {
  return [self newTerm:reql_ast_change_at :args];
}

+(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_circle :args :kwargs];
}

-(instancetype)
circle:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_circle :args :kwargs];
}

+(instancetype)
coerce_to:(NSArray *)args {
  return [self newTerm:reql_ast_coerce_to :args];
}

-(instancetype)
coerce_to:(NSArray *)args {
  return [self newTerm:reql_ast_coerce_to :args];
}

+(instancetype)
concat_map:(NSArray *)args {
  return [self newTerm:reql_ast_concat_map :args];
}

-(instancetype)
concat_map:(NSArray *)args {
  return [self newTerm:reql_ast_concat_map :args];
}

+(instancetype)
config:(NSArray *)args {
  return [self newTerm:reql_ast_config :args];
}

-(instancetype)
config:(NSArray *)args {
  return [self newTerm:reql_ast_config :args];
}

+(instancetype)
contains:(NSArray *)args {
  return [self newTerm:reql_ast_contains :args];
}

-(instancetype)
contains:(NSArray *)args {
  return [self newTerm:reql_ast_contains :args];
}

+(instancetype)
count:(NSArray *)args {
  return [self newTerm:reql_ast_count :args];
}

-(instancetype)
count:(NSArray *)args {
  return [self newTerm:reql_ast_count :args];
}

+(instancetype)
date:(NSArray *)args {
  return [self newTerm:reql_ast_date :args];
}

-(instancetype)
date:(NSArray *)args {
  return [self newTerm:reql_ast_date :args];
}

+(instancetype)
datum:(NSArray *)args {
  return [self newTerm:reql_ast_datum :args];
}

-(instancetype)
datum:(NSArray *)args {
  return [self newTerm:reql_ast_datum :args];
}

+(instancetype)
day:(NSArray *)args {
  return [self newTerm:reql_ast_day :args];
}

-(instancetype)
day:(NSArray *)args {
  return [self newTerm:reql_ast_day :args];
}

+(instancetype)
day_of_week:(NSArray *)args {
  return [self newTerm:reql_ast_day_of_week :args];
}

-(instancetype)
day_of_week:(NSArray *)args {
  return [self newTerm:reql_ast_day_of_week :args];
}

+(instancetype)
day_of_year:(NSArray *)args {
  return [self newTerm:reql_ast_day_of_year :args];
}

-(instancetype)
day_of_year:(NSArray *)args {
  return [self newTerm:reql_ast_day_of_year :args];
}

+(instancetype)
db:(NSArray *)args {
  return [self newTerm:reql_ast_db :args];
}

-(instancetype)
db:(NSArray *)args {
  return [self newTerm:reql_ast_db :args];
}

+(instancetype)
db_create:(NSArray *)args {
  return [self newTerm:reql_ast_db_create :args];
}

-(instancetype)
db_create:(NSArray *)args {
  return [self newTerm:reql_ast_db_create :args];
}

+(instancetype)
db_drop:(NSArray *)args {
  return [self newTerm:reql_ast_db_drop :args];
}

-(instancetype)
db_drop:(NSArray *)args {
  return [self newTerm:reql_ast_db_drop :args];
}

+(instancetype)
db_list:(NSArray *)args {
  return [self newTerm:reql_ast_db_list :args];
}

-(instancetype)
db_list:(NSArray *)args {
  return [self newTerm:reql_ast_db_list :args];
}

+(instancetype)
december:(NSArray *)args {
  return [self newTerm:reql_ast_december :args];
}

-(instancetype)
december:(NSArray *)args {
  return [self newTerm:reql_ast_december :args];
}

+(instancetype)
default:(NSArray *)args {
  return [self newTerm:reql_ast_default :args];
}

-(instancetype)
default:(NSArray *)args {
  return [self newTerm:reql_ast_default :args];
}

+(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_delete :args :kwargs];
}

-(instancetype)
delete:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_delete :args :kwargs];
}

+(instancetype)
delete_at:(NSArray *)args {
  return [self newTerm:reql_ast_delete_at :args];
}

-(instancetype)
delete_at:(NSArray *)args {
  return [self newTerm:reql_ast_delete_at :args];
}

+(instancetype)
desc:(NSArray *)args {
  return [self newTerm:reql_ast_desc :args];
}

-(instancetype)
desc:(NSArray *)args {
  return [self newTerm:reql_ast_desc :args];
}

+(instancetype)
difference:(NSArray *)args {
  return [self newTerm:reql_ast_difference :args];
}

-(instancetype)
difference:(NSArray *)args {
  return [self newTerm:reql_ast_difference :args];
}

+(instancetype)
distance:(NSArray *)args {
  return [self newTerm:reql_ast_distance :args];
}

-(instancetype)
distance:(NSArray *)args {
  return [self newTerm:reql_ast_distance :args];
}

+(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_distinct :args :kwargs];
}

-(instancetype)
distinct:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_distinct :args :kwargs];
}

+(instancetype)
div:(NSArray *)args {
  return [self newTerm:reql_ast_div :args];
}

-(instancetype)
div:(NSArray *)args {
  return [self newTerm:reql_ast_div :args];
}

+(instancetype)
downcase:(NSArray *)args {
  return [self newTerm:reql_ast_downcase :args];
}

-(instancetype)
downcase:(NSArray *)args {
  return [self newTerm:reql_ast_downcase :args];
}

+(instancetype)
during:(NSArray *)args {
  return [self newTerm:reql_ast_during :args];
}

-(instancetype)
during:(NSArray *)args {
  return [self newTerm:reql_ast_during :args];
}

+(instancetype)
epoch_time:(NSArray *)args {
  return [self newTerm:reql_ast_epoch_time :args];
}

-(instancetype)
epoch_time:(NSArray *)args {
  return [self newTerm:reql_ast_epoch_time :args];
}

+(instancetype)
eq:(NSArray *)args {
  return [self newTerm:reql_ast_eq :args];
}

-(instancetype)
eq:(NSArray *)args {
  return [self newTerm:reql_ast_eq :args];
}

+(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_eq_join :args :kwargs];
}

-(instancetype)
eq_join:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_eq_join :args :kwargs];
}

+(instancetype)
error:(NSArray *)args {
  return [self newTerm:reql_ast_error :args];
}

-(instancetype)
error:(NSArray *)args {
  return [self newTerm:reql_ast_error :args];
}

+(instancetype)
february:(NSArray *)args {
  return [self newTerm:reql_ast_february :args];
}

-(instancetype)
february:(NSArray *)args {
  return [self newTerm:reql_ast_february :args];
}

+(instancetype)
fill:(NSArray *)args {
  return [self newTerm:reql_ast_fill :args];
}

-(instancetype)
fill:(NSArray *)args {
  return [self newTerm:reql_ast_fill :args];
}

+(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_filter :args :kwargs];
}

-(instancetype)
filter:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_filter :args :kwargs];
}

+(instancetype)
floor:(NSArray *)args {
  return [self newTerm:reql_ast_floor :args];
}

-(instancetype)
floor:(NSArray *)args {
  return [self newTerm:reql_ast_floor :args];
}

+(instancetype)
for_each:(NSArray *)args {
  return [self newTerm:reql_ast_for_each :args];
}

-(instancetype)
for_each:(NSArray *)args {
  return [self newTerm:reql_ast_for_each :args];
}

+(instancetype)
friday:(NSArray *)args {
  return [self newTerm:reql_ast_friday :args];
}

-(instancetype)
friday:(NSArray *)args {
  return [self newTerm:reql_ast_friday :args];
}

+(instancetype)
func:(NSArray *)args {
  return [self newTerm:reql_ast_func :args];
}

-(instancetype)
func:(NSArray *)args {
  return [self newTerm:reql_ast_func :args];
}

+(instancetype)
funcall:(NSArray *)args {
  return [self newTerm:reql_ast_funcall :args];
}

-(instancetype)
funcall:(NSArray *)args {
  return [self newTerm:reql_ast_funcall :args];
}

+(instancetype)
ge:(NSArray *)args {
  return [self newTerm:reql_ast_ge :args];
}

-(instancetype)
ge:(NSArray *)args {
  return [self newTerm:reql_ast_ge :args];
}

+(instancetype)
geojson:(NSArray *)args {
  return [self newTerm:reql_ast_geojson :args];
}

-(instancetype)
geojson:(NSArray *)args {
  return [self newTerm:reql_ast_geojson :args];
}

+(instancetype)
get:(NSArray *)args {
  return [self newTerm:reql_ast_get :args];
}

-(instancetype)
get:(NSArray *)args {
  return [self newTerm:reql_ast_get :args];
}

+(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_all :args :kwargs];
}

-(instancetype)
get_all:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_all :args :kwargs];
}

+(instancetype)
get_field:(NSArray *)args {
  return [self newTerm:reql_ast_get_field :args];
}

-(instancetype)
get_field:(NSArray *)args {
  return [self newTerm:reql_ast_get_field :args];
}

+(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_intersecting :args :kwargs];
}

-(instancetype)
get_intersecting:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_intersecting :args :kwargs];
}

+(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_nearest :args :kwargs];
}

-(instancetype)
get_nearest:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_get_nearest :args :kwargs];
}

+(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_group :args :kwargs];
}

-(instancetype)
group:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_group :args :kwargs];
}

+(instancetype)
gt:(NSArray *)args {
  return [self newTerm:reql_ast_gt :args];
}

-(instancetype)
gt:(NSArray *)args {
  return [self newTerm:reql_ast_gt :args];
}

+(instancetype)
has_fields:(NSArray *)args {
  return [self newTerm:reql_ast_has_fields :args];
}

-(instancetype)
has_fields:(NSArray *)args {
  return [self newTerm:reql_ast_has_fields :args];
}

+(instancetype)
hours:(NSArray *)args {
  return [self newTerm:reql_ast_hours :args];
}

-(instancetype)
hours:(NSArray *)args {
  return [self newTerm:reql_ast_hours :args];
}

+(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_http :args :kwargs];
}

-(instancetype)
http:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_http :args :kwargs];
}

+(instancetype)
implicit_var:(NSArray *)args {
  return [self newTerm:reql_ast_implicit_var :args];
}

-(instancetype)
implicit_var:(NSArray *)args {
  return [self newTerm:reql_ast_implicit_var :args];
}

+(instancetype)
includes:(NSArray *)args {
  return [self newTerm:reql_ast_includes :args];
}

-(instancetype)
includes:(NSArray *)args {
  return [self newTerm:reql_ast_includes :args];
}

+(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_index_create :args :kwargs];
}

-(instancetype)
index_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_index_create :args :kwargs];
}

+(instancetype)
index_drop:(NSArray *)args {
  return [self newTerm:reql_ast_index_drop :args];
}

-(instancetype)
index_drop:(NSArray *)args {
  return [self newTerm:reql_ast_index_drop :args];
}

+(instancetype)
index_list:(NSArray *)args {
  return [self newTerm:reql_ast_index_list :args];
}

-(instancetype)
index_list:(NSArray *)args {
  return [self newTerm:reql_ast_index_list :args];
}

+(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_index_rename :args :kwargs];
}

-(instancetype)
index_rename:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_index_rename :args :kwargs];
}

+(instancetype)
index_status:(NSArray *)args {
  return [self newTerm:reql_ast_index_status :args];
}

-(instancetype)
index_status:(NSArray *)args {
  return [self newTerm:reql_ast_index_status :args];
}

+(instancetype)
index_wait:(NSArray *)args {
  return [self newTerm:reql_ast_index_wait :args];
}

-(instancetype)
index_wait:(NSArray *)args {
  return [self newTerm:reql_ast_index_wait :args];
}

+(instancetype)
info:(NSArray *)args {
  return [self newTerm:reql_ast_info :args];
}

-(instancetype)
info:(NSArray *)args {
  return [self newTerm:reql_ast_info :args];
}

+(instancetype)
inner_join:(NSArray *)args {
  return [self newTerm:reql_ast_inner_join :args];
}

-(instancetype)
inner_join:(NSArray *)args {
  return [self newTerm:reql_ast_inner_join :args];
}

+(instancetype)
insert:(NSArray *)args {
  return [self newTerm:reql_ast_insert :args];
}

-(instancetype)
insert:(NSArray *)args {
  return [self newTerm:reql_ast_insert :args];
}

+(instancetype)
insert_at:(NSArray *)args {
  return [self newTerm:reql_ast_insert_at :args];
}

-(instancetype)
insert_at:(NSArray *)args {
  return [self newTerm:reql_ast_insert_at :args];
}

+(instancetype)
intersects:(NSArray *)args {
  return [self newTerm:reql_ast_intersects :args];
}

-(instancetype)
intersects:(NSArray *)args {
  return [self newTerm:reql_ast_intersects :args];
}

+(instancetype)
in_timezone:(NSArray *)args {
  return [self newTerm:reql_ast_in_timezone :args];
}

-(instancetype)
in_timezone:(NSArray *)args {
  return [self newTerm:reql_ast_in_timezone :args];
}

+(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_iso8601 :args :kwargs];
}

-(instancetype)
iso8601:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_iso8601 :args :kwargs];
}

+(instancetype)
is_empty:(NSArray *)args {
  return [self newTerm:reql_ast_is_empty :args];
}

-(instancetype)
is_empty:(NSArray *)args {
  return [self newTerm:reql_ast_is_empty :args];
}

+(instancetype)
january:(NSArray *)args {
  return [self newTerm:reql_ast_january :args];
}

-(instancetype)
january:(NSArray *)args {
  return [self newTerm:reql_ast_january :args];
}

+(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_javascript :args :kwargs];
}

-(instancetype)
javascript:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_javascript :args :kwargs];
}

+(instancetype)
json:(NSArray *)args {
  return [self newTerm:reql_ast_json :args];
}

-(instancetype)
json:(NSArray *)args {
  return [self newTerm:reql_ast_json :args];
}

+(instancetype)
july:(NSArray *)args {
  return [self newTerm:reql_ast_july :args];
}

-(instancetype)
july:(NSArray *)args {
  return [self newTerm:reql_ast_july :args];
}

+(instancetype)
june:(NSArray *)args {
  return [self newTerm:reql_ast_june :args];
}

-(instancetype)
june:(NSArray *)args {
  return [self newTerm:reql_ast_june :args];
}

+(instancetype)
keys:(NSArray *)args {
  return [self newTerm:reql_ast_keys :args];
}

-(instancetype)
keys:(NSArray *)args {
  return [self newTerm:reql_ast_keys :args];
}

+(instancetype)
le:(NSArray *)args {
  return [self newTerm:reql_ast_le :args];
}

-(instancetype)
le:(NSArray *)args {
  return [self newTerm:reql_ast_le :args];
}

+(instancetype)
limit:(NSArray *)args {
  return [self newTerm:reql_ast_limit :args];
}

-(instancetype)
limit:(NSArray *)args {
  return [self newTerm:reql_ast_limit :args];
}

+(instancetype)
line:(NSArray *)args {
  return [self newTerm:reql_ast_line :args];
}

-(instancetype)
line:(NSArray *)args {
  return [self newTerm:reql_ast_line :args];
}

+(instancetype)
literal:(NSArray *)args {
  return [self newTerm:reql_ast_literal :args];
}

-(instancetype)
literal:(NSArray *)args {
  return [self newTerm:reql_ast_literal :args];
}

+(instancetype)
lt:(NSArray *)args {
  return [self newTerm:reql_ast_lt :args];
}

-(instancetype)
lt:(NSArray *)args {
  return [self newTerm:reql_ast_lt :args];
}

+(instancetype)
make_array:(NSArray *)args {
  return [self newTerm:reql_ast_make_array :args];
}

-(instancetype)
make_array:(NSArray *)args {
  return [self newTerm:reql_ast_make_array :args];
}

+(instancetype)
make_obj:(NSArray *)args {
  return [self newTerm:reql_ast_make_obj :args];
}

-(instancetype)
make_obj:(NSArray *)args {
  return [self newTerm:reql_ast_make_obj :args];
}

+(instancetype)
map:(NSArray *)args {
  return [self newTerm:reql_ast_map :args];
}

-(instancetype)
map:(NSArray *)args {
  return [self newTerm:reql_ast_map :args];
}

+(instancetype)
march:(NSArray *)args {
  return [self newTerm:reql_ast_march :args];
}

-(instancetype)
march:(NSArray *)args {
  return [self newTerm:reql_ast_march :args];
}

+(instancetype)
match:(NSArray *)args {
  return [self newTerm:reql_ast_match :args];
}

-(instancetype)
match:(NSArray *)args {
  return [self newTerm:reql_ast_match :args];
}

+(instancetype)
max:(NSArray *)args {
  return [self newTerm:reql_ast_max :args];
}

-(instancetype)
max:(NSArray *)args {
  return [self newTerm:reql_ast_max :args];
}

+(instancetype)
maxval:(NSArray *)args {
  return [self newTerm:reql_ast_maxval :args];
}

-(instancetype)
maxval:(NSArray *)args {
  return [self newTerm:reql_ast_maxval :args];
}

+(instancetype)
may:(NSArray *)args {
  return [self newTerm:reql_ast_may :args];
}

-(instancetype)
may:(NSArray *)args {
  return [self newTerm:reql_ast_may :args];
}

+(instancetype)
merge:(NSArray *)args {
  return [self newTerm:reql_ast_merge :args];
}

-(instancetype)
merge:(NSArray *)args {
  return [self newTerm:reql_ast_merge :args];
}

+(instancetype)
min:(NSArray *)args {
  return [self newTerm:reql_ast_min :args];
}

-(instancetype)
min:(NSArray *)args {
  return [self newTerm:reql_ast_min :args];
}

+(instancetype)
minutes:(NSArray *)args {
  return [self newTerm:reql_ast_minutes :args];
}

-(instancetype)
minutes:(NSArray *)args {
  return [self newTerm:reql_ast_minutes :args];
}

+(instancetype)
minval:(NSArray *)args {
  return [self newTerm:reql_ast_minval :args];
}

-(instancetype)
minval:(NSArray *)args {
  return [self newTerm:reql_ast_minval :args];
}

+(instancetype)
mod:(NSArray *)args {
  return [self newTerm:reql_ast_mod :args];
}

-(instancetype)
mod:(NSArray *)args {
  return [self newTerm:reql_ast_mod :args];
}

+(instancetype)
monday:(NSArray *)args {
  return [self newTerm:reql_ast_monday :args];
}

-(instancetype)
monday:(NSArray *)args {
  return [self newTerm:reql_ast_monday :args];
}

+(instancetype)
month:(NSArray *)args {
  return [self newTerm:reql_ast_month :args];
}

-(instancetype)
month:(NSArray *)args {
  return [self newTerm:reql_ast_month :args];
}

+(instancetype)
mul:(NSArray *)args {
  return [self newTerm:reql_ast_mul :args];
}

-(instancetype)
mul:(NSArray *)args {
  return [self newTerm:reql_ast_mul :args];
}

+(instancetype)
ne:(NSArray *)args {
  return [self newTerm:reql_ast_ne :args];
}

-(instancetype)
ne:(NSArray *)args {
  return [self newTerm:reql_ast_ne :args];
}

+(instancetype)
not:(NSArray *)args {
  return [self newTerm:reql_ast_not :args];
}

-(instancetype)
not:(NSArray *)args {
  return [self newTerm:reql_ast_not :args];
}

+(instancetype)
november:(NSArray *)args {
  return [self newTerm:reql_ast_november :args];
}

-(instancetype)
november:(NSArray *)args {
  return [self newTerm:reql_ast_november :args];
}

+(instancetype)
now:(NSArray *)args {
  return [self newTerm:reql_ast_now :args];
}

-(instancetype)
now:(NSArray *)args {
  return [self newTerm:reql_ast_now :args];
}

+(instancetype)
nth:(NSArray *)args {
  return [self newTerm:reql_ast_nth :args];
}

-(instancetype)
nth:(NSArray *)args {
  return [self newTerm:reql_ast_nth :args];
}

+(instancetype)
object:(NSArray *)args {
  return [self newTerm:reql_ast_object :args];
}

-(instancetype)
object:(NSArray *)args {
  return [self newTerm:reql_ast_object :args];
}

+(instancetype)
october:(NSArray *)args {
  return [self newTerm:reql_ast_october :args];
}

-(instancetype)
october:(NSArray *)args {
  return [self newTerm:reql_ast_october :args];
}

+(instancetype)
offsets_of:(NSArray *)args {
  return [self newTerm:reql_ast_offsets_of :args];
}

-(instancetype)
offsets_of:(NSArray *)args {
  return [self newTerm:reql_ast_offsets_of :args];
}

+(instancetype)
or:(NSArray *)args {
  return [self newTerm:reql_ast_or :args];
}

-(instancetype)
or:(NSArray *)args {
  return [self newTerm:reql_ast_or :args];
}

+(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_order_by :args :kwargs];
}

-(instancetype)
order_by:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_order_by :args :kwargs];
}

+(instancetype)
outer_join:(NSArray *)args {
  return [self newTerm:reql_ast_outer_join :args];
}

-(instancetype)
outer_join:(NSArray *)args {
  return [self newTerm:reql_ast_outer_join :args];
}

+(instancetype)
pluck:(NSArray *)args {
  return [self newTerm:reql_ast_pluck :args];
}

-(instancetype)
pluck:(NSArray *)args {
  return [self newTerm:reql_ast_pluck :args];
}

+(instancetype)
point:(NSArray *)args {
  return [self newTerm:reql_ast_point :args];
}

-(instancetype)
point:(NSArray *)args {
  return [self newTerm:reql_ast_point :args];
}

+(instancetype)
polygon:(NSArray *)args {
  return [self newTerm:reql_ast_polygon :args];
}

-(instancetype)
polygon:(NSArray *)args {
  return [self newTerm:reql_ast_polygon :args];
}

+(instancetype)
polygon_sub:(NSArray *)args {
  return [self newTerm:reql_ast_polygon_sub :args];
}

-(instancetype)
polygon_sub:(NSArray *)args {
  return [self newTerm:reql_ast_polygon_sub :args];
}

+(instancetype)
prepend:(NSArray *)args {
  return [self newTerm:reql_ast_prepend :args];
}

-(instancetype)
prepend:(NSArray *)args {
  return [self newTerm:reql_ast_prepend :args];
}

+(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_random :args :kwargs];
}

-(instancetype)
random:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_random :args :kwargs];
}

+(instancetype)
range:(NSArray *)args {
  return [self newTerm:reql_ast_range :args];
}

-(instancetype)
range:(NSArray *)args {
  return [self newTerm:reql_ast_range :args];
}

+(instancetype)
rebalance:(NSArray *)args {
  return [self newTerm:reql_ast_rebalance :args];
}

-(instancetype)
rebalance:(NSArray *)args {
  return [self newTerm:reql_ast_rebalance :args];
}

+(instancetype)
reconfigure:(NSArray *)args {
  return [self newTerm:reql_ast_reconfigure :args];
}

-(instancetype)
reconfigure:(NSArray *)args {
  return [self newTerm:reql_ast_reconfigure :args];
}

+(instancetype)
reduce:(NSArray *)args {
  return [self newTerm:reql_ast_reduce :args];
}

-(instancetype)
reduce:(NSArray *)args {
  return [self newTerm:reql_ast_reduce :args];
}

+(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_replace :args :kwargs];
}

-(instancetype)
replace:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_replace :args :kwargs];
}

+(instancetype)
round:(NSArray *)args {
  return [self newTerm:reql_ast_round :args];
}

-(instancetype)
round:(NSArray *)args {
  return [self newTerm:reql_ast_round :args];
}

+(instancetype)
sample:(NSArray *)args {
  return [self newTerm:reql_ast_sample :args];
}

-(instancetype)
sample:(NSArray *)args {
  return [self newTerm:reql_ast_sample :args];
}

+(instancetype)
saturday:(NSArray *)args {
  return [self newTerm:reql_ast_saturday :args];
}

-(instancetype)
saturday:(NSArray *)args {
  return [self newTerm:reql_ast_saturday :args];
}

+(instancetype)
seconds:(NSArray *)args {
  return [self newTerm:reql_ast_seconds :args];
}

-(instancetype)
seconds:(NSArray *)args {
  return [self newTerm:reql_ast_seconds :args];
}

+(instancetype)
september:(NSArray *)args {
  return [self newTerm:reql_ast_september :args];
}

-(instancetype)
september:(NSArray *)args {
  return [self newTerm:reql_ast_september :args];
}

+(instancetype)
set_difference:(NSArray *)args {
  return [self newTerm:reql_ast_set_difference :args];
}

-(instancetype)
set_difference:(NSArray *)args {
  return [self newTerm:reql_ast_set_difference :args];
}

+(instancetype)
set_insert:(NSArray *)args {
  return [self newTerm:reql_ast_set_insert :args];
}

-(instancetype)
set_insert:(NSArray *)args {
  return [self newTerm:reql_ast_set_insert :args];
}

+(instancetype)
set_intersection:(NSArray *)args {
  return [self newTerm:reql_ast_set_intersection :args];
}

-(instancetype)
set_intersection:(NSArray *)args {
  return [self newTerm:reql_ast_set_intersection :args];
}

+(instancetype)
set_union:(NSArray *)args {
  return [self newTerm:reql_ast_set_union :args];
}

-(instancetype)
set_union:(NSArray *)args {
  return [self newTerm:reql_ast_set_union :args];
}

+(instancetype)
skip:(NSArray *)args {
  return [self newTerm:reql_ast_skip :args];
}

-(instancetype)
skip:(NSArray *)args {
  return [self newTerm:reql_ast_skip :args];
}

+(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_slice :args :kwargs];
}

-(instancetype)
slice:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_slice :args :kwargs];
}

+(instancetype)
splice_at:(NSArray *)args {
  return [self newTerm:reql_ast_splice_at :args];
}

-(instancetype)
splice_at:(NSArray *)args {
  return [self newTerm:reql_ast_splice_at :args];
}

+(instancetype)
split:(NSArray *)args {
  return [self newTerm:reql_ast_split :args];
}

-(instancetype)
split:(NSArray *)args {
  return [self newTerm:reql_ast_split :args];
}

+(instancetype)
status:(NSArray *)args {
  return [self newTerm:reql_ast_status :args];
}

-(instancetype)
status:(NSArray *)args {
  return [self newTerm:reql_ast_status :args];
}

+(instancetype)
sub:(NSArray *)args {
  return [self newTerm:reql_ast_sub :args];
}

-(instancetype)
sub:(NSArray *)args {
  return [self newTerm:reql_ast_sub :args];
}

+(instancetype)
sum:(NSArray *)args {
  return [self newTerm:reql_ast_sum :args];
}

-(instancetype)
sum:(NSArray *)args {
  return [self newTerm:reql_ast_sum :args];
}

+(instancetype)
sunday:(NSArray *)args {
  return [self newTerm:reql_ast_sunday :args];
}

-(instancetype)
sunday:(NSArray *)args {
  return [self newTerm:reql_ast_sunday :args];
}

+(instancetype)
sync:(NSArray *)args {
  return [self newTerm:reql_ast_sync :args];
}

-(instancetype)
sync:(NSArray *)args {
  return [self newTerm:reql_ast_sync :args];
}

+(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_table :args :kwargs];
}

-(instancetype)
table:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_table :args :kwargs];
}

+(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_table_create :args :kwargs];
}

-(instancetype)
table_create:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_table_create :args :kwargs];
}

+(instancetype)
table_drop:(NSArray *)args {
  return [self newTerm:reql_ast_table_drop :args];
}

-(instancetype)
table_drop:(NSArray *)args {
  return [self newTerm:reql_ast_table_drop :args];
}

+(instancetype)
table_list:(NSArray *)args {
  return [self newTerm:reql_ast_table_list :args];
}

-(instancetype)
table_list:(NSArray *)args {
  return [self newTerm:reql_ast_table_list :args];
}

+(instancetype)
thursday:(NSArray *)args {
  return [self newTerm:reql_ast_thursday :args];
}

-(instancetype)
thursday:(NSArray *)args {
  return [self newTerm:reql_ast_thursday :args];
}

+(instancetype)
time:(NSArray *)args {
  return [self newTerm:reql_ast_time :args];
}

-(instancetype)
time:(NSArray *)args {
  return [self newTerm:reql_ast_time :args];
}

+(instancetype)
timezone:(NSArray *)args {
  return [self newTerm:reql_ast_timezone :args];
}

-(instancetype)
timezone:(NSArray *)args {
  return [self newTerm:reql_ast_timezone :args];
}

+(instancetype)
time_of_day:(NSArray *)args {
  return [self newTerm:reql_ast_time_of_day :args];
}

-(instancetype)
time_of_day:(NSArray *)args {
  return [self newTerm:reql_ast_time_of_day :args];
}

+(instancetype)
to_epoch_time:(NSArray *)args {
  return [self newTerm:reql_ast_to_epoch_time :args];
}

-(instancetype)
to_epoch_time:(NSArray *)args {
  return [self newTerm:reql_ast_to_epoch_time :args];
}

+(instancetype)
to_geojson:(NSArray *)args {
  return [self newTerm:reql_ast_to_geojson :args];
}

-(instancetype)
to_geojson:(NSArray *)args {
  return [self newTerm:reql_ast_to_geojson :args];
}

+(instancetype)
to_iso8601:(NSArray *)args {
  return [self newTerm:reql_ast_to_iso8601 :args];
}

-(instancetype)
to_iso8601:(NSArray *)args {
  return [self newTerm:reql_ast_to_iso8601 :args];
}

+(instancetype)
to_json_string:(NSArray *)args {
  return [self newTerm:reql_ast_to_json_string :args];
}

-(instancetype)
to_json_string:(NSArray *)args {
  return [self newTerm:reql_ast_to_json_string :args];
}

+(instancetype)
tuesday:(NSArray *)args {
  return [self newTerm:reql_ast_tuesday :args];
}

-(instancetype)
tuesday:(NSArray *)args {
  return [self newTerm:reql_ast_tuesday :args];
}

+(instancetype)
type_of:(NSArray *)args {
  return [self newTerm:reql_ast_type_of :args];
}

-(instancetype)
type_of:(NSArray *)args {
  return [self newTerm:reql_ast_type_of :args];
}

+(instancetype)
ungroup:(NSArray *)args {
  return [self newTerm:reql_ast_ungroup :args];
}

-(instancetype)
ungroup:(NSArray *)args {
  return [self newTerm:reql_ast_ungroup :args];
}

+(instancetype)
union:(NSArray *)args {
  return [self newTerm:reql_ast_union :args];
}

-(instancetype)
union:(NSArray *)args {
  return [self newTerm:reql_ast_union :args];
}

+(instancetype)
upcase:(NSArray *)args {
  return [self newTerm:reql_ast_upcase :args];
}

-(instancetype)
upcase:(NSArray *)args {
  return [self newTerm:reql_ast_upcase :args];
}

+(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_update :args :kwargs];
}

-(instancetype)
update:(NSArray *)args :(NSDictionary *)kwargs {
  return [self newTerm:reql_ast_update :args :kwargs];
}

+(instancetype)
uuid:(NSArray *)args {
  return [self newTerm:reql_ast_uuid :args];
}

-(instancetype)
uuid:(NSArray *)args {
  return [self newTerm:reql_ast_uuid :args];
}

+(instancetype)
var:(NSArray *)args {
  return [self newTerm:reql_ast_var :args];
}

-(instancetype)
var:(NSArray *)args {
  return [self newTerm:reql_ast_var :args];
}

+(instancetype)
wait:(NSArray *)args {
  return [self newTerm:reql_ast_wait :args];
}

-(instancetype)
wait:(NSArray *)args {
  return [self newTerm:reql_ast_wait :args];
}

+(instancetype)
wednesday:(NSArray *)args {
  return [self newTerm:reql_ast_wednesday :args];
}

-(instancetype)
wednesday:(NSArray *)args {
  return [self newTerm:reql_ast_wednesday :args];
}

+(instancetype)
without:(NSArray *)args {
  return [self newTerm:reql_ast_without :args];
}

-(instancetype)
without:(NSArray *)args {
  return [self newTerm:reql_ast_without :args];
}

+(instancetype)
with_fields:(NSArray *)args {
  return [self newTerm:reql_ast_with_fields :args];
}

-(instancetype)
with_fields:(NSArray *)args {
  return [self newTerm:reql_ast_with_fields :args];
}

+(instancetype)
year:(NSArray *)args {
  return [self newTerm:reql_ast_year :args];
}

-(instancetype)
year:(NSArray *)args {
  return [self newTerm:reql_ast_year :args];
}

+(instancetype)
zip:(NSArray *)args {
  return [self newTerm:reql_ast_zip :args];
}

-(instancetype)
zip:(NSArray *)args {
  return [self newTerm:reql_ast_zip :args];
}

@end
