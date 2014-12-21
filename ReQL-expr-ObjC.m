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
    self->conn = _reql_new_connection(NULL);

    if (!self->conn) {
      return nil;
    }

    char *buf;

    _reql_connect(self->conn, &buf);

    if (self->conn->error) {
      NSLog(@"%s", buf);
      _reql_close_conn(self->conn);
      return nil;
    }
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
  const char *c_str = [string cStringUsingEncoding:NSUnicodeStringEncoding];
  unsigned long c_str_len = [string lengthOfBytesUsingEncoding:NSUnicodeStringEncoding];
  return [[libReQL_expr alloc] initWithReQL:_reql_expr_string(c_str, c_str_len)];
}

+(instancetype)ReQLWithNumber:(NSNumber *)number {
  double val = [number doubleValue];
  return [[libReQL_expr alloc] initWithReQL:_reql_expr_number(val)];
}

+(instancetype)ReQLWithBool:(BOOL)val {
  return [[libReQL_expr alloc] initWithReQL:_reql_expr_bool(val)];
}

+(instancetype)ReQLWithArray:(NSArray *)array {
  _ReQL_Op val = _reql_expr_c_array([array count]);

  unsigned long i = -1;

  for (id elem in array) {
    if ([elem isKindOfClass:[NSArray class]]) {
      _reql_c_array_insert(val, [[libReQL_expr ReQLWithArray:elem] ReQLValue], ++i);
    }
  }

  return [[libReQL_expr alloc] initWithReQL:val];
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
