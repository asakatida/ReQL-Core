/*
Copyright 2014 Adam Grandquist

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

#include "ReQL.h"

@implementation libReQL_Connection {
  _ReQL_Conn_t *conn;
}

-(instancetype)initWithHost:(NSString *)host port:(NSNumber *)port key:(NSString *)key {
  if (self = [super init]) {
    self->conn = malloc(sizeof(_ReQL_Conn_t));

    char buf[500];

    _reql_connect(self->conn, buf, 500);

    NSLog(@"%s", buf);
  }

  return self;
}

-(instancetype)init {
  return [self initWithHost:nil port:nil key:nil];
}

-(instancetype)initWithConnection:(_ReQL_Conn_t *)old_conn {
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
  _reql_close_conn(self->conn);
}

@end

@implementation libReQL_expr {
  _ReQL_Op query;
}

+(instancetype)ReQLWithString:(NSString *)string {
  uint32_t c_str_len = (uint32_t)[string lengthOfBytesUsingEncoding:NSUnicodeStringEncoding];

  uint8_t *c_str = malloc(sizeof(uint8_t) * c_str_len);

  [string getBytes:c_str maxLength:c_str_len usedLength:NULL encoding:NSUnicodeStringEncoding options:NSStringEncodingConversionAllowLossy range:NSMakeRange(0, c_str_len) remainingRange:NULL];

  _ReQL_Op val = malloc(sizeof(_ReQL_Op_t));

  _reql_string_init(val, c_str, c_str_len);

  _ReQL_Op expr = malloc(sizeof(_ReQL_Op_t));

  _reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithNumber:(NSNumber *)number {
  _ReQL_Op val = malloc(sizeof(_ReQL_Op_t));

  _reql_number_init(val, [number doubleValue]);

  _ReQL_Op expr = malloc(sizeof(_ReQL_Op_t));

  _reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithBool:(BOOL)val {
  _ReQL_Op _val = malloc(sizeof(_ReQL_Op_t));

  _reql_bool_init(_val, val);

  _ReQL_Op expr = malloc(sizeof(_ReQL_Op_t));

  _reql_ast_datum(expr, _val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithArray:(NSArray *)array {
  uint32_t size = (uint32_t)[array count];

  _ReQL_Op val = malloc(sizeof(_ReQL_Op_t));
  _ReQL_Op *arr = malloc(sizeof(_ReQL_Op) * size);

  _reql_array_init(val, arr, size);

  uint32_t i = -1;

  for (libReQL_expr *elem in array) {
    _reql_array_insert(val, elem->query, ++i);
  }

  _ReQL_Op expr = malloc(sizeof(_ReQL_Op_t));

  _reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

+(instancetype)ReQLWithDict:(NSDictionary *)obj {
  uint32_t size = (uint32_t)[obj count];

  _ReQL_Op val = malloc(sizeof(_ReQL_Op_t));
  _ReQL_Pair pair = malloc(sizeof(_ReQL_Pair_t) * size);

  _reql_object_init(val, pair, size);

  for (NSString *key in [obj keyEnumerator]) {
    _reql_object_add(val, [libReQL_expr ReQLWithString:key]->query, ((libReQL_expr *)[obj valueForKey:key])->query);
  }

  _ReQL_Op expr = malloc(sizeof(_ReQL_Op_t));

  _reql_ast_datum(expr, val, NULL);

  return [[libReQL_expr alloc] initWithReQL:expr];
}

-(_ReQL_Op)ReQLValue {
  return self->query;
}

-(instancetype)initWithReQL:(_ReQL_Op)obj {
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
