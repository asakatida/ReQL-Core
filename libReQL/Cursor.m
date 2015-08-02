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

@interface ReQLCursor ()

-(void)setNext:(ReQL_Obj_t *)obj;

@end

static int
cursor_each_cb(ReQL_Obj_t *res, void *data);

static int
cursor_each_cb(ReQL_Obj_t *res, void *data) {
  ReQLCursor *cursor = (__bridge ReQLCursor *)(data);
  [cursor setNext:res];
  return 0;
}

static id
convert(ReQL_Obj_t *obj);

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
  id p_next;
}

-(instancetype)init {
  if (self = [super init]) {
    p_cur = malloc(sizeof(ReQL_Cur_t));
    if (p_cur == NULL) {
      return nil;
    }
    p_next = nil;
  }
  return self;
}

-(void *)data {
  return p_cur;
}

-(NSArray *)toArray {
  ReQL_Obj_t *obj = reql_cur_to_array(p_cur);
  if (obj == NULL) {
    return nil;
  }
  NSArray *array = convert(obj);
  reql_json_destroy(obj);
  return array;
}

-(void)open {
  reql_cur_each(p_cur, cursor_each_cb, (__bridge void *)(self));
}

-(void)setNext:(ReQL_Obj_t *)obj {
  p_next = convert(obj);
}

-(id)next {
  id next = p_next;
  p_next = nil;
  return next;
}

-(void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode {
  switch (eventCode) {
    case NSStreamEventEndEncountered: {
      [aStream close];
      [aStream removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
      aStream = nil;
      break;
    }
    case NSStreamEventErrorOccurred: {
      [aStream close];
      break;
    }
    case NSStreamEventHasBytesAvailable: {
      id next = [self next];
      if (next == nil) {
        [aStream close];
      }
      break;
    }
    case NSStreamEventHasSpaceAvailable: {
      [aStream close];
      break;
    }
    case NSStreamEventNone: {
      break;
    }
    case NSStreamEventOpenCompleted: {
      break;
    }
  }
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
