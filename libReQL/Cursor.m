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

-(NSArray *)toArray {
  return nil;
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
