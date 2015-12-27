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

#import "Query.h"
#import "Result.h"

#import "./core/connection.hpp"

@interface ReQLQuery ()

-(std::string)build;

@end

@interface ReQLConnection ()

@property(nonatomic) _ReQL::Conn_t<ReQL::Result> *conn;

@end

static std::wstring
to_string(const NSString *string) {
  auto data = [string dataUsingEncoding:NSUTF16StringEncoding];
  return std::wstring(reinterpret_cast<const wchar_t *>([data bytes]), [data length]);
}

static ReQLQuery *
toQuery(id expr) {
  if ([expr isKindOfClass:[ReQLQuery class]]) {
    return expr;
  } else if ([expr isKindOfClass:[NSArray class]]) {
    return [ReQLQuery newWithArray:expr];
  } else if ([expr isKindOfClass:[NSNull class]]) {
    return [ReQLQuery new];
  } else if ([expr isKindOfClass:[NSNumber class]]) {
    return [ReQLQuery newWithNumber:expr];
  } else if ([expr isKindOfClass:[NSString class]]) {
    return [ReQLQuery newWithString:expr];
  } else if ([expr isKindOfClass:[NSDictionary class]]) {
    return [ReQLQuery newWithObject:expr];
  }
  return nil;
}

@implementation ReQLConnection

@synthesize conn=p_conn;

-(nonnull instancetype)init {
  if ((self = [super init])) {
    p_conn = new _ReQL::Conn_t<ReQL::Result>;
    p_conn->connect();
  }
  return self;
}

-(void)noReply:(ReQLQuery *)query kwargs:(NSDictionary *)kwargs {
  std::map<std::wstring, std::string> object;
  for (NSString *key in kwargs) {
    object.insert({to_string(key), [toQuery(kwargs[key]) build]});
  }
  self.conn->noReply([query build], object);
}

-(BOOL)isOpen {
  return self.conn->isOpen() ? YES : NO;
}

-(void)close {
  self.conn->close();
}

-(void)dealloc {
  delete p_conn;
}

@end
