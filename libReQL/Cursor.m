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

#import <libReQL/libReQL-Swift.h>

@interface ReQLCursor ()

-(int)setNext:(ReQL_Obj_t *)obj;

@end

static int
cursor_each_cb(void *res, void *data);

static id
convert(ReQL_Obj_t *obj);

static int
cursor_each_cb(void *res, void *data) {
  return [((__bridge ReQLCursor *)data) setNext:res];
}

static id
convert(ReQL_Obj_t *obj) {
  switch (reql_datum_type(obj)) {
    case REQL_R_ARRAY: {
      NSMutableArray *array = [NSMutableArray arrayWithCapacity:reql_size(obj)];
      ReQL_Iter_t it = reql_new_iter(obj);
      ReQL_Obj_t *elem = NULL;
      while ((elem = reql_iter_next(&it)) != NULL) {
        [array addObject:convert(elem)];
      }
      return [NSArray arrayWithArray:array];
    }
    case REQL_R_BOOL: {
      return [NSNumber numberWithBool:reql_to_bool(obj)];
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
      NSMutableDictionary *object = [NSMutableDictionary dictionaryWithCapacity:reql_size(obj)];
      ReQL_Iter_t it = reql_new_iter(obj);
      ReQL_Obj_t *key = NULL;
      while ((key = reql_iter_next(&it)) != NULL) {
        [object setObject:convert(reql_object_get(obj, key)) forKey:convert(key)];
      }
      return [NSDictionary dictionaryWithDictionary:object];
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

@implementation ReQLCursor {
  ReQL_Cur_t *p_cur;
  Cursor *p_stream;
}

-(instancetype)init {
  if ((self = [super init])) {
    p_cur = malloc(sizeof(ReQL_Cur_t));
    if (p_cur == NULL) {
      return nil;
    }
    p_stream = [Cursor new];
  }
  return self;
}

-(void *)data {
  return p_cur;
}

-(NSArray *)toArray {
  return nil;
}

-(void)start {
  reql_cur_each(p_cur, cursor_each_cb, (__bridge void *)(self));
}

-(int)setNext:(ReQL_Obj_t *)obj {
  id res = convert(obj);
  if (res == nil) {
    return 1;
  }
  @try {
    [p_stream next:res];
  }
  @catch (NSException *exception) {
    return 1;
  }
  @finally {
    return 0;
  }
}

-(BOOL)isOpen {
  return reql_cur_open(p_cur) == 0 ? NO : YES;
}

-(void)observe:(void (^ __nonnull)(id __nullable, NSError * __nullable))next {
  [self observe:next];
}

-(void)close {
  [p_stream close];
  reql_cur_close(p_cur);
}

-(void)dealloc {
  [p_stream close];
  reql_cur_destroy(p_cur);
  free(p_cur);
}

@end
