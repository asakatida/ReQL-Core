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

#import "Result.h"

#import <Foundation/Foundation.h>

#import <string>

namespace ReQL {

static NSString *
to_string(const std::wstring &string) {
  return [[NSString alloc]
          initWithBytes:string.c_str()
          length:string.size()
          encoding:NSUTF16StringEncoding];
}

Result::Result() : p_value([NSNull null]) {}

Result::Result(const bool value) : p_value([NSNumber numberWithBool:value]) {}

Result::Result(const double value) : p_value([NSNumber numberWithDouble:value]) {}

Result::Result(const wchar_t *value, const size_t size) :
  p_value([[NSString alloc] initWithBytes:value length:size encoding:NSUTF16StringEncoding]) {}

Result::Result(const std::vector<Result> &value) :
  p_value([NSMutableArray arrayWithCapacity:value.size()]) {
  for (auto &&elem : value) {
    [p_value addObject:elem.p_value];
  }
}

Result::Result(const std::map<std::wstring, Result> &value) :
  p_value([NSMutableDictionary dictionaryWithCapacity:value.size()]) {
  for (auto &&pair : value) {
    p_value[to_string(pair.first)] = pair.second.p_value;
  }
}

Result::Result(const Result &other) : p_value([other.p_value copy]) {}

Result &Result::operator =(const Result &other) {
  if (this != &other) {
    p_value = [other.p_value copy];
  }
  return *this;
}

}
