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

#import "Parser.h"
#import "Query.h"

#import <libReQL/libReQL-Swift.h>

@interface ReQLCursor ()

@property(nonnull, nonatomic) ReQL::Cursor *cur;
@property(nonnull, nonatomic) Cursor *stream;

@end

@implementation ReQLCursor

@synthesize cur=p_cur;
@synthesize stream=p_stream;

-(instancetype)initWithCursor:(nonnull ReQL::Cursor *)cur {
  if ((self = [super init])) {
    p_stream = [Cursor new];
    cur->sink([self](ReQL::Result &&result) {
      id nsarray = result.toObjC();
      if ([nsarray isKindOfClass:[NSArray class]]) {
        for (id elem in reinterpret_cast<NSArray *>(nsarray)) {
          [p_stream next:elem];
        }
      } else {
        [p_stream next:nsarray];
      }
    });
    p_cur = cur;
    if (p_stream == nil) {
      return nil;
    }
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
  return self.cur->isOpen() ? NO : YES;
}

-(void)close {
  self.cur->close();
}

-(void)dealloc {
  [p_stream close];
}

@end
