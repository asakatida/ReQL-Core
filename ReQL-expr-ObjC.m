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

@implementation libReQL_expr {
  NSNumber *tt;
  NSNumber *dt;
  NSArray *arr;
  NSNumber *num;
  NSDictionary *obj;
  NSString *str;
}

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
  libReQL_expr *res = [libReQL_expr init];
  switch (obj->dt) {
    case _REQL_C_ARRAY: {
      unsigned long size;

      if (_reql_to_c_array(obj, &size)) {
        break;
      }

      NSMutableArray *arr = [NSMutableArray arrayWithCapacity:size];

      unsigned long i;

      for (i=0; i<size; ++i) {
        [arr insertObject:[libReQL_expr _reql_to_obj:_reql_c_array_index(obj, i)] atIndex:i];
      }

      res->arr = [NSArray arrayWithArray:arr];
      break;
    }
    case _REQL_R_ARRAY: {
      _ReQL_Op_t *iter = _reql_to_array(obj);
      if (!iter) {
        break;
      }

      NSMutableArray *arr = [NSMutableArray array];

      _ReQL_Op_t *elem;

      while (_reql_array_next(&iter, &elem)) {
        [arr addObject:[libReQL_expr _reql_to_obj:elem]];
      }

      res->arr = [NSArray arrayWithArray:arr];
      break;
    }
    case _REQL_R_BOOL: {
      int value;
      if (_reql_to_bool(obj, &value)) {
        break;
      }

      res->num = [NSNumber numberWithBool:value];
      break;
    }
    case _REQL_R_JSON: {
      break;
    }
    case _REQL_R_NULL: {
      break;
    }
    case _REQL_R_NUM: {
      double value;
      if (_reql_to_number(obj, &value)) {
        break;
      }

      res->num = [NSNumber numberWithDouble:value];
      break;
    }
    case _REQL_R_OBJECT: {
      _ReQL_Op_t *iter = _reql_to_object(obj);
      if (!iter) {
        break;
      }

      NSMutableDictionary *dict = [NSMutableDictionary dictionary];

      _ReQL_Op_t *key;
      _ReQL_Op_t *val;

      while (_reql_object_next(&iter, &key, &val)) {
        [dict setObject:[libReQL_expr _reql_to_obj:val] forKey:[libReQL_expr _reql_to_obj:key]];
      }

      res->obj = [NSDictionary dictionaryWithDictionary:dict];
      break;
    }
    case _REQL_R_STR: {
      unsigned long str_len;
      const char *str;
      if (_reql_to_string(obj, &str, &str_len)) {
        break;
      }

      res->str = [[NSString alloc] initWithBytes:str length:str_len encoding:NSUnicodeStringEncoding];
      break;
    }
    default:
      res = nil;
  }
  if (res) {
    res->tt = [NSNumber numberWithInt:obj->tt];
    res->dt = [NSNumber numberWithInt:obj->dt];
  }
  return res;
}

-(instancetype)copyWithZone:(NSZone *)zone {
  libReQL_expr *new_obj = [libReQL_expr allocWithZone:zone];
  return new_obj;
}

-(instancetype)expr:(NSString *)string {
  return [libReQL_expr _reql_to_obj:[libReQL_expr _reql_from_obj:string]];
}

@end
