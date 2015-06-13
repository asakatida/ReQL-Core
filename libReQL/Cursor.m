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

#import "Cursor.h"

#import "Query.h"

#import "./reql/core.h"

@implementation ReQLBool

@end

@implementation ReQLCursor {
  ReQL_Cur_t *p_cur;
}

-(instancetype)init {
  if (self = [super init]) {
    p_cur = malloc(sizeof(ReQL_Cur_t));
    if (p_cur == NULL) {
      return nil;
    }
  }
  return self;
}

-(void)setDelegate:(id<NSStreamDelegate>)delegate {
  if (delegate) {
    [super setDelegate:delegate];
  }
}

-(void *)data {
  return p_cur;
}

-(id)convert:(ReQL_Obj_t *)obj {
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      NSMutableArray *array = [NSMutableArray arrayWithCapacity:reql_size(obj)];
      ReQL_Iter_t it = reql_new_iter(obj);
      ReQL_Obj_t *elem = NULL;
      while ((elem = reql_iter_next(&it)) != NULL) {
        [array addObject:[self convert:elem]];
      }
      return array;
    }
    case REQL_R_BOOL: {
      return [ReQLBool numberWithBool:reql_to_bool(obj)];
    }
    case REQL_R_JSON: {
      return nil;
    }
    case REQL_R_NULL: {
      return [NSNull null];
    }
    case REQL_R_NUM: {
      return [NSNumber numberWithDouble:reql_to_number(obj)];
    }
    case REQL_R_OBJECT: {
      NSObject *object = [NSObject new];
      ReQL_Iter_t it = reql_new_iter(obj);
      ReQL_Obj_t *key = NULL;
      while ((key = reql_iter_next(&it)) != NULL) {
        [object setValue:[self convert:reql_object_get(obj, key)] forKey:[self convert:key]];
      }
      return object;
    }
    case REQL_R_REQL: {
      return nil;
    }
    case REQL_R_STR: {
      return [[NSString alloc] initWithBytes:reql_string_buf(obj) length:reql_size(obj) encoding:NSUTF8StringEncoding];
    }
  }
  return nil;
}

-(NSArray *)toArray {
  ReQL_Obj_t *obj = reql_cur_to_array(p_cur);
  if (obj == NULL) {
    return nil;
  }
  NSArray *array = [self convert:obj];
  reql_json_destroy(obj);
  return array;
}

-(void)stream:(ReQLCursor *)aStream handleEvent:(NSStreamEvent)eventCode {
}

-(BOOL)error:(NSError * __strong *)err {
  if (err != nil) {
    *err = nil;
  }
  return NO;
}

-(void)close {
  reql_cur_close(p_cur);
}

-(void)dealloc {
  reql_cur_destroy(p_cur);
  free(p_cur);
}

@end
