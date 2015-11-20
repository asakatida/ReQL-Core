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

#import "Connection.h"

#import "Parser.h"
#import "Query.h"

#import "./reql/core.hpp"

@interface ReQLCursor ()

-(nonnull instancetype)initWithCursor:(const ReQL::Cursor &)cur;

@end

@interface ReQLQuery ()

-(_ReQL::Any)build;

@end

@interface ReQLConnection ()

@property(nonatomic) ReQL::Connection conn;

@end

@implementation ReQLConnection

@synthesize conn=p_conn;

-(nonnull instancetype)init {
  if ((self = [super init])) {
    p_conn._connect();
  }
  return self;
}

-(ReQLCursor *)run:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs {
  return [[ReQLCursor alloc] initWithCursor:self.conn.run([query build], [[ReQLQuery newWithObject:kwargs] build])];
}

-(void)noReply:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs {
  self.conn.noReply([query build], [[ReQLQuery newWithObject:kwargs] build]);
}

-(BOOL)isOpen {
  return self.conn.isOpen() ? YES : NO;
}

-(void)close {
  self.conn = ReQL::Connection();
}

@end
