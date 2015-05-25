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

#import "ReQL-expr-ObjC.h"

#include "./reql/core.h"

@implementation libReQL_Connection {
  ReQL_Conn_t *conn;
}

-(instancetype)initWithHost:(NSString *)host port:(NSNumber *)port key:(NSString *)key {
  if (self = [super init]) {
    self->conn = malloc(sizeof(ReQL_Conn_t));

    uint8_t buf[500];

    reql_connect(self->conn, buf, 500);

    NSLog(@"%s", buf);
  }

  return self;
}

-(instancetype)init {
  return [self initWithHost:nil port:nil key:nil];
}

-(instancetype)initWithConnection:(ReQL_Conn_t *)old_conn {
  return [self initWithHost:[NSString stringWithUTF8String:old_conn->addr]
                       port:[NSNumber numberWithInteger:
                             [
                              [NSString stringWithUTF8String:old_conn->port]
                              integerValue
                              ]
                             ]
                        key:[NSString stringWithUTF8String:old_conn->auth]];
}

-(instancetype)copyWithZone:(NSZone *)zone {
  libReQL_Connection *new_obj = [[libReQL_Connection allocWithZone:zone]
                                 initWithConnection:self->conn];

  return new_obj;
}

-(void)close {
  reql_close_conn(self->conn);
}

@end

@implementation libReQL_expr {
  ReQL_Obj_t *query;
}

+(instancetype)ReQLWithString:(NSString *)string {
  uint32_t c_str_len = (uint32_t)[string lengthOfBytesUsingEncoding:NSUnicodeStringEncoding];

  uint8_t *c_str = malloc(sizeof(uint8_t) * c_str_len);

  [string getBytes:c_str maxLength:c_str_len usedLength:NULL encoding:NSUnicodeStringEncoding options:NSStringEncodingConversionAllowLossy range:NSMakeRange(0, c_str_len) remainingRange:NULL];

  ReQL_Obj_t *val = malloc(sizeof(ReQL_Obj_t));

  reql_string_init(val, c_str, c_str_len);

  ReQL_Obj_t *expr = malloc(sizeof(ReQL_Obj_t));

  reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithNumber:(NSNumber *)number {
  ReQL_Obj_t *val = malloc(sizeof(ReQL_Obj_t));

  reql_number_init(val, [number doubleValue]);

  ReQL_Obj_t *expr = malloc(sizeof(ReQL_Obj_t));

  reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithBool:(BOOL)val {
  ReQL_Obj_t *obj = malloc(sizeof(ReQL_Obj_t));

  reql_bool_init(obj, val);

  return [[libReQL_expr alloc] initWithReQL:obj];
}

+(instancetype)ReQLWithArray:(NSArray *)array {
  uint32_t size = (uint32_t)[array count];

  ReQL_Obj_t *val = malloc(sizeof(ReQL_Obj_t));
  ReQL_Obj_t **arr = malloc(sizeof(ReQL_Obj_t *) * size);

  reql_array_init(val, arr, size);

  uint32_t i = -1;

  for (libReQL_expr *elem in array) {
    reql_array_insert(val, elem->query, ++i);
  }

  ReQL_Obj_t *expr = malloc(sizeof(ReQL_Obj_t));

  reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithDict:(NSDictionary *)obj {
  uint32_t size = (uint32_t)[obj count];

  ReQL_Obj_t *val = malloc(sizeof(ReQL_Obj_t));
  ReQL_Pair_t *pair = malloc(sizeof(ReQL_Pair_t) * size);

  reql_object_init(val, pair, size);

  for (NSString *key in [obj keyEnumerator]) {
    reql_object_add(val, [libReQL_expr ReQLWithString:key]->query, ((libReQL_expr *)[obj valueForKey:key])->query);
  }

  ReQL_Obj_t *expr = malloc(sizeof(ReQL_Obj_t));

  reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

-(ReQL_Obj_t *)ReQLValue {
  return self->query;
}

-(instancetype)initWithReQL:(ReQL_Obj_t *)obj {
  if (self = [super init]) {
    self->query = obj;
  }

  return self;
}

-(instancetype)copyWithZone:(NSZone *)zone {
  libReQL_expr *new_obj = [libReQL_expr allocWithZone:zone];
  return new_obj;
}

@end
