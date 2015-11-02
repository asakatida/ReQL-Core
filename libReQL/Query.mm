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

#import "Cursor.h"

#import "./reql/core.h"

#import <libReQL/libReQL-Swift.h>

static int
add_bool(ReQL_Parse_t *p, char val) {
  [((__bridge Parser *)p->data) addBool:val];
  return 0;
}

static int
add_null(ReQL_Parse_t *p) {
  [((__bridge Parser *)p->data) addNull];
  return 0;
}

static int
add_number(ReQL_Parse_t *p, double val) {
  [((__bridge Parser *)p->data) addNumber:val];
  return 0;
}

static int
add_string(ReQL_Parse_t *p, const char *val, size_t length) {
  [((__bridge Parser *)p->data) addString:reinterpret_cast<const void *>(val) length:length];
  return 0;
}

static int
end_element(ReQL_Parse_t *p) {
  [((__bridge Parser *)p->data) endElement];
  return 0;
}

static int
end_key_value(ReQL_Parse_t *p, const char *val, size_t length) {
  [((__bridge Parser *)p->data) endKeyValue:reinterpret_cast<const void *>(val) length:length];
  return 0;
}

static int
end_parse(ReQL_Parse_t *p) {
  Parser *data = CFBridgingRelease(p->data);
  p->data = const_cast<void *>(CFBridgingRetain([data.stack lastObject]));
  return [data.stack count];
}

static void
error(ReQL_Parse_t *p) {
  CFBridgingRelease(p->data); p->data = nullptr;
}

static int
start_array(ReQL_Parse_t *p) {
  [((__bridge Parser *)p->data) startArray];
  return 0;
}

static int
start_object(ReQL_Parse_t *p) {
  [((__bridge Parser *)p->data) startObject];
  return 0;
}

static int
start_parse(ReQL_Parse_t *p) {
  Parser *data = [Parser new];
  p->data = const_cast<void *>(CFBridgingRetain(data));
  return 0;
}

static ReQL_Parse_t
get_parser() {
  ReQL_Parse_t parser;
  parser.add_bool = add_bool;
  parser.add_null = add_null;
  parser.add_number = add_number;
  parser.add_string = add_string;
  parser.data = nullptr;
  parser.end_array = nullptr;
  parser.end_element = end_element;
  parser.end_key_value = end_key_value;
  parser.end_object = nullptr;
  parser.end_parse = end_parse;
  parser.error = error;
  parser.start_array = start_array;
  parser.start_element = nullptr;
  parser.start_key_value = nullptr;
  parser.start_object = start_object;
  parser.start_parse = start_parse;
  return parser;
}

@interface ReQLCursor ()

-(nonnull instancetype)initWithCursor:(nonnull ReQL_Cur_t *)cur;

@end

@interface ReQLConnection ()

-(nonnull ReQL_Conn_t *)data;

@end

@interface FakeCursor : NSObject

@property(nonnull, nonatomic) ReQL_Cur_t *cur;
@property bool owned;

-(nonnull ReQL_Cur_t *)steal;

@end

@implementation FakeCursor

@synthesize cur=p_cur;
@synthesize owned=owned;

-(nonnull instancetype)init {
  if ((self = [super init])) {
    owned = YES;
    p_cur = new ReQL_Cur_t;
  }
  return self;
}

-(nonnull ReQL_Cur_t *)steal {
  self.owned = NO;
  return self.cur;
}

-(void)dealloc {
  if (owned) {
    delete p_cur;
  }
}

@end

@interface ReQLQuery ()

-(ReQL_Any_t *)build;

@end

@protocol Expr <NSObject>

-(ReQL_Any_t *)build;

@end

@interface ArrayExpr : NSObject <Expr>

@property(nonatomic) NSArray *p_array;

+(instancetype)arrayWithArray:(NSArray *)array;

-(ReQL_Array_t *)array;

@end

@interface BoolExpr : NSObject <Expr>

@property BOOL p_boolean;

+(instancetype)numberWithBool:(BOOL)boolean;

-(ReQL_Bool_t)boolean;

@end

@interface NullExpr : NSObject <Expr>

@end

@interface NumberExpr : NSObject <Expr>

@property double p_number;

+(instancetype)numberWithDouble:(double)number;

-(ReQL_Num_t)number;

@end

@interface DictionaryExpr : NSObject <Expr>

@property(nonatomic) NSDictionary *p_dictionary;

+(instancetype)dictionaryWithDictionary:(NSDictionary *)dictionary;

-(ReQL_Obj_t *)dictionary;

@end

@interface StringExpr : NSObject <Expr>

@property(nonatomic) NSString *p_string;

+(instancetype)stringWithString:(NSString *)string;

-(ReQL_String_t *)string;

@end

@interface TermExpr : NSObject <Expr>

@property ArrayExpr *args;
@property ReQL_AST_Function func;

+(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args;

@end

@interface TermKwargsExpr : NSObject <Expr>

@property ArrayExpr *args;
@property DictionaryExpr *kwargs;
@property ReQL_AST_Function_Kwargs func;

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

static ReQL_Any_t *
array_get(void *nsarray, ReQL_Size idx) {
  NSArray *array = (__bridge NSArray *)nsarray;
  return [toQuery(array[idx]) build];
}

static ReQL_Size
array_size(void *nsarray) {
  NSArray *array = (__bridge NSArray *)nsarray;
  return static_cast<ReQL_Size>([array count]);
}

@implementation ArrayExpr

@synthesize p_array=p_array;

+(instancetype)arrayWithArray:(NSArray *)array {
  ArrayExpr *inst = [super new];
  if (inst) {
    inst.p_array = array;
  }
  return inst;
}

-(ReQL_Array_t *)array {
  ReQL_Array_t *obj = new ReQL_Array_t;
  reql_array_init(obj, array_get, array_size, (__bridge void *)self.p_array);
  return obj;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_ARRAY;
  reql_array_init(&obj->any.array, array_get, array_size, (__bridge void *)self.p_array);
  return obj;
}

@end

@implementation BoolExpr

@synthesize p_boolean=p_boolean;

+(instancetype)numberWithBool:(BOOL)boolean {
  BoolExpr *inst = [super new];
  if (inst) {
    inst.p_boolean = boolean;
  }
  return inst;
}

-(ReQL_Bool_t)boolean {
  return self.p_boolean ? 1 : 0;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_BOOL;
  obj->any.boolean = [self boolean];
  return obj;
}

@end

@implementation NullExpr

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_NULL;
  return obj;
}

@end

@implementation NumberExpr

@synthesize p_number=p_number;

+(instancetype)numberWithDouble:(double)number {
  NumberExpr *inst = [super new];
  if (inst) {
    inst.p_number = number;
  }
  return inst;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_NUM;
  obj->any.num = [self number];
  return obj;
}

-(ReQL_Num_t)number {
  return self.p_number;
}

@end

static ReQL_Pair_t *
object_get(void *nsdict, ReQL_Size idx) {
  NSDictionary *dict = (__bridge NSDictionary *)nsdict;
  NSString *key = [[dict allKeys] sortedArrayUsingComparator:^(NSString * _Nonnull l, NSString * _Nonnull r) {
    if ([l isLessThan:r]) {
      return NSOrderedAscending;
    }
    return NSOrderedDescending;
  }][idx];
  ReQL_Pair_t *pair = new ReQL_Pair_t;
  pair->key = const_cast<ReQL_Byte *>(reinterpret_cast<const ReQL_Byte *>([key cStringUsingEncoding:NSUTF8StringEncoding]));
  pair->key_size = static_cast<ReQL_Size>([key lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
  pair->val = *[toQuery(dict[key]) build];
  return pair;
}

static ReQL_Size
object_size(void *nsdict) {
  NSDictionary *dict = (__bridge NSDictionary *)nsdict;
  return static_cast<ReQL_Size>([dict count]);
}

@implementation DictionaryExpr

@synthesize p_dictionary=p_dictionary;

+(instancetype)dictionaryWithDictionary:(NSDictionary *)dictionary {
  DictionaryExpr *inst = [super new];
  if (inst) {
    inst.p_dictionary = dictionary;
  }
  return inst;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_OBJECT;
  reql_object_init(&obj->any.object, object_get, object_size, (__bridge void *)self.p_dictionary);
  return obj;
}

-(ReQL_Obj_t *)dictionary {
  ReQL_Obj_t *obj = new ReQL_Obj_t;
  reql_object_init(obj, object_get, object_size, (__bridge void *)self.p_dictionary);
  return obj;
}

@end

static ReQL_Byte *
string_buf(void *nsstring) {
  NSString *string = (__bridge NSString *)nsstring;
  return const_cast<ReQL_Byte *>(reinterpret_cast<const ReQL_Byte *>([string cStringUsingEncoding:NSUTF8StringEncoding]));
}

static ReQL_Size
string_size(void *nsstring) {
  NSString *string = (__bridge NSString *)nsstring;
  return static_cast<ReQL_Size>([string lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
}

@implementation StringExpr

@synthesize p_string=p_string;

+(instancetype)stringWithString:(NSString *)string {
  StringExpr *inst = [super new];
  if (inst) {
    inst.p_string = string;
  }
  return inst;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_STR;
  reql_string_init(&obj->any.string, string_buf, string_size, (__bridge void *)self.p_string);
  return obj;
}

-(ReQL_String_t *)string {
  ReQL_String_t *obj = new ReQL_String_t;
  reql_string_init(obj, string_buf, string_size, (__bridge void *)self.p_string);
  return obj;
}

@end

static ReQL_Array_t
get_args(void *arrayexpr) {
  ArrayExpr *array = (__bridge ArrayExpr *)arrayexpr;
  return *[array array];
}

@implementation TermExpr

@synthesize args=p_args;
@synthesize func=p_func;

+(instancetype)newTerm:(ReQL_AST_Function)func :(NSArray *)args {
  TermExpr *inst = [super new];
  if (inst) {
    inst.args = [ArrayExpr arrayWithArray:args];
    inst.func = func;
  }
  return inst;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_REQL;
  self.func(&obj->any.reql, get_args, (__bridge void *)self.args);
  return obj;
}


@end

@implementation TermKwargsExpr

@synthesize args=p_args;
@synthesize kwargs=p_kwargs;
@synthesize func=p_func;

+(instancetype)newTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  return [[self alloc] initTerm:func :args :kwargs];
}

-(instancetype)initTerm:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  if ((self = [super init])) {
    p_args = [ArrayExpr arrayWithArray:args];
    p_kwargs = [DictionaryExpr dictionaryWithDictionary:kwargs];
    p_func = func;
  }
  return self;
}

-(ReQL_Any_t *)build {
  ReQL_Any_t *obj = new ReQL_Any_t;
  obj->dt = REQL_R_REQL;
  if (self.kwargs) {
    self.func(&obj->any.reql, nullptr, nullptr, (__bridge void *)self);
  } else {
    self.func(&obj->any.reql, nullptr, nullptr, (__bridge void *)self);
  }
  return obj;
}

@end

@interface ReQLQuery ()

@property NSObject <Expr> *i_build;
@property NSNumber *number;
@property BOOL b;

@end

@implementation ReQLQuery

@synthesize i_build=p_build;
@synthesize number=p_number;
@synthesize b=p_bool;

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
  if ((self = [super init])) {
    p_build = [NullExpr new];
  }
  return self;
}

-(instancetype)initTermWithArray:(NSArray *)val {
  if ((self = [super init])) {
    p_build = [ArrayExpr arrayWithArray:val];
  }
  return self;
}

-(instancetype)initTermWithBool:(BOOL)val {
  if ((self = [super init])) {
    p_build = nil;
    p_number = nil;
    p_bool = val;
  }
  return self;
}

-(instancetype)initTermWithNumber:(NSNumber *)val {
  if ((self = [super init])) {
    p_build = nil;
    p_number = val;
  }
  return self;
}

-(instancetype)initTermWithObject:(NSDictionary *)val {
  if ((self = [super init])) {
    p_build = [DictionaryExpr dictionaryWithDictionary:val];
  }
  return self;
}

-(instancetype)initTermWithString:(NSString *)val {
  if ((self = [super init])) {
    p_build = [StringExpr stringWithString:val];
  }
  return self;
}

-(instancetype)init:(ReQL_AST_Function)func :(NSArray *)args {
  if ((self = [super init])) {
    p_build = [TermExpr newTerm:func :args];
  }
  return self;
}

-(instancetype)init:(ReQL_AST_Function_Kwargs)func :(NSArray *)args :(NSDictionary *)kwargs {
  if ((self = [super init])) {
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

-(ReQLCursor *)run:(nonnull ReQLConnection *)conn {
  return [self run:conn withOpts:@{}];
}

-(ReQLCursor *)run:(nonnull ReQLConnection *)conn withOpts:(nonnull NSDictionary *)opts {
  FakeCursor *cur = [FakeCursor new];
  if (cur == nil) {
    return nil;
  }
  ReQL_Any_t *query = [self build];
  if (query == nil) {
    return nil;
  }
  ReQL_Obj_t *kwargs = [[DictionaryExpr dictionaryWithDictionary:opts] dictionary];
  if (kwargs == nullptr) {
    return nil;
  }
  if (reql_run_query(cur.cur, query, [conn data], kwargs, NULL) != 0) {
    return nil;
  }
  return [[ReQLCursor alloc] initWithCursor:[cur steal]];
}

-(void)noReply:(nonnull ReQLConnection *)conn {
  [self noReply:conn withOpts:@{}];
}

-(void)noReply:(nonnull ReQLConnection *)conn withOpts:(nonnull NSDictionary *)opts {
  ReQL_Any_t *query = [self build];
  if (!query) {
    return;
  }
  ReQL_Obj_t *kwargs = [[DictionaryExpr dictionaryWithDictionary:opts] dictionary];
  if (!kwargs) {
    return nil;
  }
  reql_run_query(NULL, query, [conn data], kwargs, NULL);
}

-(ReQL_Any_t *)build {
  if (self.i_build) {
    return [self.i_build build];
  }
  if (self.number) {
    return [reinterpret_cast<NumberExpr *>([NumberExpr numberWithDouble:[self.number doubleValue]]) build];
  }
  return [reinterpret_cast<BoolExpr *>([BoolExpr numberWithBool:self.b]) build];
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
values:(NSArray *)args {
  return [self newTerm:reql_ast_values :args];
}

-(instancetype)
values:(NSArray *)args {
  return [self newTerm:reql_ast_values :args];
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
