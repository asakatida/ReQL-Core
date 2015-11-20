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

#import "Parser.h"

#import <Foundation/Foundation.h>

namespace ReQL {

static NSString *
to_string(const _ReQL::ImmutableString &string) {
  return [[NSString alloc]
          initWithBytes:string.c_str()
          length:string.size()
          encoding:NSUTF8StringEncoding];
}

Result::Result() : p_value([NSNull null]) {}

Result::Result(const bool value) : p_value([NSNumber numberWithBool:value]) {}

Result::Result(const double value) : p_value([NSNumber numberWithDouble:value]) {}

Result::Result(const _ReQL::ImmutableString &value) : p_value(to_string(value)) {}

Result::Result(const std::vector<Result> &value) {
  NSMutableArray *array = [NSMutableArray arrayWithCapacity:value.size()];
  for (auto &&elem : value) {
    [array addObject:elem.toObjC()];
  }
  p_value = [NSArray arrayWithArray:array];
}

Result::Result(const std::map<_ReQL::ImmutableString, Result> &value) {
  NSMutableDictionary *dict = [NSMutableDictionary dictionaryWithCapacity:value.size()];
  for (auto &&pair : value) {
    dict[to_string(pair.first)] = pair.second.toObjC();
  }
  p_value = [NSDictionary dictionaryWithDictionary:dict];
}

Result::Result(Result &&other) : p_value(other.p_value) {}

Result::Result(const Result &other) : p_value([other.p_value copy]) {}

Result &Result::operator =(Result &&other) {
  if (this != &other) {
    p_value = other.p_value;
  }
  return *this;
}

Result &Result::operator =(const Result &other) {
  if (this != &other) {
    p_value = [other.p_value copy];
  }
  return *this;
}

id Result::toObjC() const { return p_value; }

}
