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

@implementation libReQL_expr

+(_ReQL_Op_t *)_reql_from_bool:(NSNumber*)obj {
  return _reql_expr_bool([obj boolValue]);
}

+(_ReQL_Op_t *)_reql_from_obj:(id)obj {
  if (!obj) {
    return _reql_expr_null();
  } else if ([obj isKindOfClass:[NSArray class]]) {
    _ReQL_Op_t *arr = _reql_expr_array();
    [(NSArray*)obj enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
      _reql_array_append(arr, [libReQL_expr _reql_from_obj:obj]);
    }];
    return arr;
  } else if ([obj isKindOfClass:[NSDictionary class]]) {
    _ReQL_Op_t *r_obj = _reql_expr_object();
    [(NSDictionary*)obj enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
      _reql_object_add(r_obj, [libReQL_expr _reql_from_obj:key], [libReQL_expr _reql_from_obj:obj]);
    }];
    return r_obj;
  } else if ([obj isKindOfClass:[NSString class]]) {
    return _reql_expr_string(
                             [(NSString *)obj cStringUsingEncoding:NSUnicodeStringEncoding],
                             [(NSString *)obj lengthOfBytesUsingEncoding:NSUnicodeStringEncoding]);
  } else if ([obj isKindOfClass:[NSNumber class]]) {
    return _reql_expr_number([(NSNumber *)obj doubleValue]);
  }
  return NULL;
}

+(instancetype)_reql_to_obj:(_ReQL_Op_t *)obj {
  switch (obj->dt) {
    case _REQL_R_ARRAY:
      return @[];
    case _REQL_R_BOOL:
      return @YES;
    case _REQL_R_JSON:
      return nil;
    case _REQL_R_NULL:
      return nil;
    case _REQL_R_NUM:
      return 0;
    case _REQL_R_OBJECT:
      return @{};
    case _REQL_R_STR:
      return @"";
  }
  return nil;
}

-(instancetype)expr:(NSString *)string {
  return self;
}

@end
