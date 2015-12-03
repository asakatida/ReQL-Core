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

#import <ReactiveCocoa/ReactiveCocoa.h>

@interface ReQLStream : NSStream <NSStreamDelegate>

@property(atomic, weak) id<NSStreamDelegate> delegate;
@property(nonnull, nonatomic) NSMutableArray *store;

@end

@implementation ReQLStream

@synthesize delegate=p_delegate;
@synthesize store=p_store;

+(BOOL)supportsSecureCoding {
  return YES;
}

-(instancetype)init {
  if ((self = [super init])) {
    p_store = [NSMutableArray array];
  }
  return self;
}

-(instancetype)initWithCoder:(NSCoder *)aDecoder {
  if ((self = [super init])) {
    NSMutableArray *store = [aDecoder decodeObjectOfClass:[NSMutableArray class] forKey:@"ReQLCursor"];
    if (!store) {
      return nil;
    }
    self.store = store;
  }
  return self;
}

-(void)encodeWithCoder:(NSCoder *)aCoder {
  [aCoder encodeObject:self.store forKey:@"ReQLCursor"];
}

-(void)open {
}

-(void)close {
}

-(id<NSStreamDelegate>)delegate {
  return p_delegate;
}

-(void)setDelegate:(id<NSStreamDelegate>)delegate {
  p_delegate = delegate ? delegate : self;
}

-(void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode {
}

-(void)removeFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode {
}

-(id)propertyForKey:(NSString *)key {
}

-(BOOL)setProperty:(id)property forKey:(NSString *)key {
}

-(NSStreamStatus)streamStatus {
}

-(NSError *)streamError {
}

-(void)stream:(NSStream *)aStream handleEvent:(NSStreamEvent)eventCode {
}

@end

@interface ReQLQuery ()

-(_ReQL::Any)build;

@end

@interface ReQLConnection ()

@property(nonatomic) _ReQL::Conn_t<ReQL::Result, ReQL::Result, ReQL::Result, ReQL::Result> conn;

@end

@implementation ReQLConnection

@synthesize conn=p_conn;

-(nonnull instancetype)init {
  if ((self = [super init])) {
    p_conn.connect();
  }
  return self;
}

-(RACSequence *)run:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs {
  return [[RACSignal
          startEagerlyWithScheduler:[RACScheduler scheduler]
          block:^(id<RACSubscriber> subscriber) {
    self.conn.run([query build],
                  [[ReQLQuery newWithObject:kwargs] build],
                  [subscriber](const ReQL::Result &result) {
                    [subscriber sendNext:result.toObjC()];
                  });
          }] sequence];
}

-(void)noReply:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs {
  self.conn.noReply([query build], [[ReQLQuery newWithObject:kwargs] build]);
}

-(BOOL)isOpen {
  return self.conn.isOpen() ? YES : NO;
}

-(void)close {
  self.conn.close();
}

@end
