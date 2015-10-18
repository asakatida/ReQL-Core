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

-(int)setNext:(id)res;

@end

static int
cursor_each_cb(void *res, void *data) {
  return [((__bridge ReQLCursor *)data) setNext:(__bridge id)(res)];
}

@interface ReQLCursor ()

@property ReQL_Cur_t *cur;
@property Cursor *stream;

@end

@implementation ReQLCursor

@synthesize cur=p_cur;
@synthesize stream=p_stream;

-(instancetype)initWithCursor:(ReQL_Cur_t *)cur {
  if ((self = [super init])) {
    p_cur = cur;
    p_stream = [Cursor new];
    if (p_cur == NULL || p_stream == nil) {
      return nil;
    }
    reql_cur_each(p_cur, cursor_each_cb, (__bridge void *)(self));
  } else {
    free(cur);
  }
  return self;
}

-(NSArray *)toArray {
  NSMutableArray *array = [NSMutableArray new];
  [self observe:^(id res, NSError *err) {
    if (res) {
      [array addObject:res];
    }
  }];
  reql_cur_drain(self.cur);
  return [NSArray arrayWithArray:array];
}

-(int)setNext:(id)res {
  if (res == nil) {
    return 1;
  }
  @try {
    [self.stream next:res];
  }
  @catch (NSException *) {
    return 1;
  }
  @finally {
    return 0;
  }
}

-(BOOL)isOpen {
  return reql_cur_open(self.cur) == 0 ? NO : YES;
}

-(void)observe:(void (^ __nonnull)(id __nullable, NSError * __nullable))next {
}

-(void)close {
  reql_cur_close(self.cur);
}

-(void)dealloc {
  reql_cur_destroy(p_cur);
  free(p_cur);
  [p_stream close];
}

@end
