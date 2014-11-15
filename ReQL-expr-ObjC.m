/**
 * @author Adam Grandquist
 */

#include "ReQL.h"

#import "ReQL-expr-ObjC.h"

@implementation libReQL_expr

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
  }
  return NULL;
}

+(instancetype)_reql_to_obj:(_ReQL_Op_t *)obj {
  return [self init];
}

-(instancetype)expr:(NSString *)string {
  return self;
}

@end
