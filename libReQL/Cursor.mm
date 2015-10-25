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

@property(nonnull, nonatomic) ReQL_Cur_t *cur;
@property(nonnull, nonatomic) Cursor *stream;

@end

static int
cursor_each_cb(void *res, void *data) {
  [((__bridge Cursor *)data) next:(__bridge id)(res)];
  return 0;
}

@implementation ReQLCursor

@synthesize cur=p_cur;
@synthesize stream=p_stream;

-(instancetype)initWithCursor:(nonnull ReQL_Cur_t *)cur {
  if ((self = [super init])) {
    p_cur = cur;
    p_stream = [Cursor new];
    if (p_stream == nil) {
      return nil;
    }
    reql_cur_each(p_cur, cursor_each_cb, (__bridge void *)(p_stream));
  } else {
    delete cur;
  }
  return self;
}

-(ReQLCursor *)observeCompleted:(void (^)())cb {
  [self.stream observeCompleted:cb];
  return self;
}

-(ReQLCursor *)observeFailed:(void (^)(NSError * _Nonnull))cb {
  [self.stream observeFailed:cb];
  return self;
}

-(ReQLCursor *)observeNext:(void (^)(id _Nonnull))cb {
  [self.stream observeNext:cb];
  return self;
}

-(nonnull NSArray *)toArray {
  return [self.stream toArray];
}

-(BOOL)isOpen {
  return reql_cur_open(self.cur) == 0 ? NO : YES;
}

-(void)close {
  reql_cur_close(self.cur);
}

-(void)dealloc {
  reql_cur_destroy(p_cur);
  delete p_cur;
  [p_stream close];
}

@end
